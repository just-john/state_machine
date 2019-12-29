#ifndef SRC_SKETCHES_QUIT_STATE_QUIT_H
#define SRC_SKETCHES_QUIT_STATE_QUIT_H

#include <state.h>
#include <context.h>

class state_quit : public state
{
private:
    context & ctx_;

public:
    explicit state_quit(context & c);

    std::string const & state_name() const;

    void on_entry();

    void on_exit();
};

#endif
