#include "state_start.h"

#include <context.h>

#include <future>


state_start::state_start(context & c) :
    ctx_ (c)
{
}

std::string const & state_start::state_name() const
{
    static std::string const name("start");
    return name;
}

void state_start::on_entry()
{
    LOG(loglevel::notice)
        << state_name()
        << "::on_entry\n";

    std::future<bool> is_loaded =
        std::async(&context::load_start_assets, &ctx_);

    bool const loaded = is_loaded.get();
    if (loaded)
    {
        ctx_.set_state(state_id::splash);
    }
    else
    {
        ctx_.set_state(state_id::quit);
    }
}

void state_start::on_exit()
{
    LOG(loglevel::notice)
        << state_name()
        << "::on_exit\n";
}
