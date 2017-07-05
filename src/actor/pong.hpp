#ifndef ACTOR_PONG_HPP
#define ACTOR_PONG_HPP 1

#include "caf/all.hpp"

#include "pong_msg.hpp"

namespace actor {

using pong_t = caf::typed_actor<caf::replies_to<actor::msg::foo>::with<actor::msg::foo_r>>;

class typed_calculator : public pong_t::base {
public:
  typed_calculator(caf::actor_config& cfg);
  behavior_type make_behavior() override;
};

} // namespace actor
#endif