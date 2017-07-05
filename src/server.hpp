#ifndef SERVER_HPP
#define SERVER_HPP 1

#include "caf/all.hpp"
#include "caf/io/all.hpp"

#include "broker.hpp"
#include "actor/pong.hpp"

caf::behavior server(caf::io::broker* self, const actor::pong_t& buddy2);

#endif