#include "context.h"

#include <chrono>

#include <logging/logger.hpp>
#include <sketches/start/state_start.h>
#include <sketches/splash/state_splash.h>
#include <sketches/quit/state_quit.h>


context::context(boost::asio::io_service & io) :
    io_             (io),
    current_state_  (state_id::not_started)
{
    states_.emplace(
        state_id::start,
        std::make_unique<state_start>(*this));

    states_.emplace(
        state_id::splash,
        std::make_unique<state_splash>(*this));

    // states_.emplace(
    //     state_id::config,
    //     std::make_unique<state_config>(*this));

    // states_.emplace(
    //     state_id::loading,
    //     std::make_unique<state_loading>(*this));

    // states_.emplace(
    //     state_id::game,
    //     std::make_unique<state_game>(*this));

    // states_.emplace(
    //     state_id::game_paused,
    //     std::make_unique<state_game_paused>(*this));

    // states_.emplace(
    //     state_id::game_over,
    //     std::make_unique<state_game_over>(*this));

    states_.emplace(
        state_id::quit,
        std::make_unique<state_quit>(*this));

    set_state(state_id::start);
}

context::~context()
{
    if (current_state_ != state_id::stopped)
    {
        LOG(loglevel::notice)
            << " current_state at context destruction: "
            << state_ids::get_state_name(current_state_)
            << "\n";

        set_state(state_id::quit);
    }

    LOG(loglevel::notice)
        << " current_state after context destruction: "
        << state_ids::get_state_name(current_state_)
        << "\n";
}

void context::set_state(state_id id)
{
    // call on_exit on the current state

    if (current_state_ != state_id::not_started)
    {
        auto const itr_current_state = states_.find(current_state_);
        if (itr_current_state != states_.end())
        {
            itr_current_state->second->on_exit();
        }
        else
        {
            LOG(loglevel::critical)
                << "Failed to find current state: "
                << state_ids::get_state_name(current_state_)
                << "\n";
        }
    }

    if (id != state_id::stopped)
    {
        // call on_entry on the new state
        auto const itr_new_state = states_.find(id);
        if (itr_new_state != states_.end())
        {
            current_state_ = id;
            itr_new_state->second->on_entry();

            if (current_state_ == state_id::quit)
            {
                itr_new_state->second->on_exit();
            }
        }
        else
        {
            LOG(loglevel::critical)
                << "Failed to set requested state: "
                << state_ids::get_state_name(id)
                << "\n";

            // TODO: should you transition to an emergency state here
            // or perhaps throw?  Who would catch?
        }
    }
}

bool context::load_start_assets() const
{
    boost::asio::steady_timer t(io_);

    t.expires_after(std::chrono::seconds(2));
    t.wait();

    return true;
}
