#include "config.hpp"

config::config() {
    opt_group{custom_options_, "global"}
    .add(port, "port,p", "set port")
    .add(host, "host,H", "set host (ignored in server mode)");
    add_message_type<actor::msg::foo>("foo");
    add_message_type<actor::msg::foo_r>("foo_r");
}