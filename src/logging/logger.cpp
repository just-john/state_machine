#include "logger.hpp"

#include <map>
#include <string>
#include <boost/assign.hpp>

namespace loglevel
{

std::string get_level(level l)
{
    static std::map<level, std::string> const levels =
        boost::assign::map_list_of
            (debug,     "debug")
            (info,      "info")
            (notice,    "notice")
            (warning,   "warning")
            (error,     "error")
            (critical,  "critical");

    return levels.find(l)->second;
}

}
