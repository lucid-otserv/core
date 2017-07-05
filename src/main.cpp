#include "caf/config.hpp"

#ifdef WIN32
# define _WIN32_WINNT 0x0600
# include <Winsock2.h>
#endif

#include "caf/all.hpp"
#include "caf/io/all.hpp"

#include "config.hpp"
#include "broker.hpp"
#include "server.hpp"
#include "actor/pong.hpp"

namespace {

// utility function to print an exit message with custom name
void print_on_exit(const caf::actor& conn, const std::string& name) {
  conn->attach_functor([=](const caf::error& reason) {
    std::cout << name << " exited: " << to_string(reason) << std::endl;
  });
}

void caf_main(caf::actor_system& system, const config& cfg) {
  std::cout << "run in server mode" << std::endl;
  auto pong_actor2 = system.spawn<actor::typed_calculator>();
  auto server_actor = system.middleman().spawn_server(server, cfg.port, pong_actor2);
  if (!server_actor) {
    std::cerr << "failed to spawn server: "
               << system.render(server_actor.error()) << std::endl;
    return;
  }
  print_on_exit(*server_actor, "server");
  // print_on_exit(*pong_actor2, "pong");  
}

} // namespace <anonymous>

CAF_MAIN(caf::io::middleman)