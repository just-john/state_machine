#ifndef SRC_SKETCHES_SPLASH_STATE_SPLASH_H
#define SRC_SKETCHES_SPLASH_STATE_SPLASH_H

#include <state.h>
#include <context.h>


class state_splash : public state
{
private:
    context & ctx_;

public:
    explicit state_splash(context & c);

    std::string const & state_name() const;

    void on_entry();

    void on_exit();
};

#endif
