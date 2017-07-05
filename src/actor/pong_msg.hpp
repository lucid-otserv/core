#ifndef MESSAGES_HPP
#define MESSAGES_HPP 1

#include "caf/all.hpp"

namespace actor::msg {

struct foo {
  std::string text;
};

template <class Inspector>
typename Inspector::result_type inspect(Inspector& f, foo& x) {
  return f(caf::meta::type_name("foo"), x.text);
}

struct foo_r {
  std::string text;
};

template <class Inspector>
typename Inspector::result_type inspect(Inspector& f, foo_r& x) {
  return f(caf::meta::type_name("foo_r"), x.text);
}

} // namespace actor::msg

#endif