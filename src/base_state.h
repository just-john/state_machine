#ifndef SRC_BASE_STATE_H
#define SRC_BASE_STATE_H

#include <boost/noncopyable.hpp>
#include <string>

class base_state : private boost::noncopyable
{
public:
    virtual ~base_state() {}

    virtual std::string const & state_name() const = 0;

    virtual void on_entry() =0;

    virtual void on_exit() =0;
};

#endif
