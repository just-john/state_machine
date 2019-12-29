#ifndef SRC_STATE_H
#define SRC_STATE_H

#include "base_state.h"
#include "state_ids.h"
#include <logging/logger.hpp>



class state : public base_state
{
public:
    // add default implementations for handlers here

    void on_entry()
    {
        LOG(loglevel::notice)
            << "default on_entry called for state "
            << state_name()
            << "\n";
    }

    void on_exit()
    {
        LOG(loglevel::notice)
            << "default on_exit called for state "
            << state_name()
            << "\n";
    }

    // add handlers for this state machine
    // e.g. virtual void on_event_x() =0;
};


#endif
