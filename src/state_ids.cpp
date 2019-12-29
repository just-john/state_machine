#include "state_ids.h"

#include <map>
#include <boost/assign.hpp>

namespace state_ids
{

std::string get_state_name(state_id id)
{
    static std::map<state_id, std::string> const state_id_names =
        boost::assign::map_list_of
            (state_id::start,   "start")
            (state_id::splash,  "splash")
            (state_id::quit,    "quit");

    return state_id_names.find(id)->second;
}

}
