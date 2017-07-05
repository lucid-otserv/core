#include "broker.hpp"

caf::behavior broker_impl(caf::io::broker* self, caf::io::connection_handle conn, const actor::pong_t& buddy) {
  // we assume io_fsm manages a broker with exactly one connection,
  // i.e., the connection ponted to by `conn`
//   assert(self->num_connections() == 1);
  // monitor buddy to quit broker if buddy is done
  self->monitor(buddy);
  self->set_down_handler([=](caf::down_msg& dm) {
    if (dm.source == buddy) {
      aout(self) << "our buddy is down" << std::endl;
      // quit for same reason
      self->quit(dm.reason);
    }
  });
  self->configure_read(conn, caf::io::receive_policy::at_least(2));

  return {
    [=](const caf::io::connection_closed_msg& msg) {
      // brokers can multiplex any number of connections, however
      // this example assumes io_fsm to manage a broker with
      // exactly one connection
      // if (msg.handle == conn) {
      //   aout(self) << "connection closed" << std::endl;
      //   // force buddy to quit
      //   self->send_exit(buddy, exit_reason::remote_link_unreachable);
      //   self->quit(exit_reason::remote_link_unreachable);
      // }
        aout(self) << "Connection closed" << std::endl;
    },
    [=](const caf::io::new_data_msg& msg) {
      std::string text = std::string(msg.buf.data());
      aout(self) << text << std::endl;
      self->send(buddy, actor::msg::foo{text});
    },
    [=](const actor::msg::foo_r& r) {
      self->write(conn, r.text.size(), r.text.c_str());
      self->flush(conn);
    }
  };
}