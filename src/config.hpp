#ifndef CONFIG_HPP
#define CONFIG_HPP 1

#include "caf/all.hpp"

#include "actor/pong.hpp"

class config : public caf::actor_system_config {
public:
  uint16_t port = 8888;
  std::string host = "localhost";

  config();
};

#endif