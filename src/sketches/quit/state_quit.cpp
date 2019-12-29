#include "state_quit.h"


state_quit::state_quit(context & c) :
    ctx_ (c)
{
}

std::string const & state_quit::state_name() const
{
    static std::string const name("quit");
    return name;
}

void state_quit::on_entry()
{
    LOG(loglevel::notice)
        << state_name()
        << "::on_entry\n";
}

void state_quit::on_exit()
{
    LOG(loglevel::notice)
        << state_name()
        << "::on_exit\n";
}
