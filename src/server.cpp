#include "server.hpp"

caf::behavior server(caf::io::broker* self, const actor::pong_t& buddy2) {
  caf::aout(self) << "server is running" << std::endl;
  return {
    [=](const caf::io::new_connection_msg& msg) {
      caf::aout(self) << "server accepted new connection" << std::endl;
      // by forking into a new broker, we are no longer
      // responsible for the connection
      auto impl = self->fork(broker_impl, msg.handle, buddy2);
    //   print_on_exit(impl, "broker_impl");
      // aout(self) << "quit server (only accept 1 connection)" << endl;
      // self->quit();
    }
  };
}