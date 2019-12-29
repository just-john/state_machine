#ifndef SRC_SKETCHES_START_STATE_START_H
#define SRC_SKETCHES_START_STATE_START_H

#include <state.h>
#include <context_fwd.h>

class state_start : public state
{
private:
    context & ctx_;

public:
    explicit state_start(context & c);

    std::string const & state_name() const;

    void on_entry();

    void on_exit();
};


#endif
