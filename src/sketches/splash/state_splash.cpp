#include "state_splash.h"


state_splash::state_splash(context & c) :
    ctx_ (c)
{
}

std::string const & state_splash::state_name() const
{
    static std::string const name("splash");
    return name;
}

void state_splash::on_entry()
{
    state::on_entry();
}

void state_splash::on_exit()
{
    state::on_exit();
}
