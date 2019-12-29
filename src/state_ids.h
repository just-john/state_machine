#ifndef SRC_STATE_IDS_H
#define SRC_STATE_IDS_H

#include <string>


enum state_id { not_started, start, splash, quit, stopped };


namespace state_ids
{

std::string get_state_name(state_id id);

}


#endif
