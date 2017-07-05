#ifndef BROKER_HPP
#define BROKER_HPP 1

#include "caf/all.hpp"
#include "caf/io/all.hpp"

#include "actor/pong.hpp"

caf::behavior broker_impl(caf::io::broker*, caf::io::connection_handle, const actor::pong_t&);

#endif