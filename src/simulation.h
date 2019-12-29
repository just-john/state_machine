#ifndef SRC_SIMULATION_H
#define SRC_SIMULATION_H

#include <boost/asio.hpp>

#include <logging/logger.hpp>
#include <context.h>

class simulation
{
private:
    boost::asio::io_context     io_;
    context                     ctx_;

public:
    simulation() :
        ctx_ (io_)
    {
        LOG(loglevel::info)
            << "simulation ctor\n";
    }

    ~simulation()
    {
        LOG(loglevel::info)
            << "simulation dtor\n";
    }

    void run()
    {
        io_.run();
    }
};


#endif
