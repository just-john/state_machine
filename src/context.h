#ifndef SRC_CONTEXT_H
#define SRC_CONTEXT_H

#include <map>
#include <memory>
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>

#include "state.h"
#include "state_ids.h"


class context : private boost::noncopyable
{
private:
    boost::asio::io_service &                       io_;
    std::map<state_id, std::unique_ptr<state> >     states_;
    state_id                                        current_state_;

public:
    explicit context(boost::asio::io_service & io);
    ~context();

    void set_state(state_id id);

    bool load_start_assets() const;
};

#endif
