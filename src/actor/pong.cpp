#include "pong.hpp"

namespace actor {

typed_calculator::typed_calculator(caf::actor_config& cfg) : actor::pong_t::base(cfg) {
  // nop
}

actor::pong_t::behavior_type typed_calculator::make_behavior() {
  return {
    [](const actor::msg::foo& f) {
      return actor::msg::foo_r{"PONG\n"};
    }
  };
}

} // namespace actor