#ifndef SRC_LOGGING_LOGGER_HPP
#define SRC_LOGGING_LOGGER_HPP

#include <iostream>
#include <string>


namespace loglevel
{

enum level { debug, info, notice, warning, error, critical };

std::string get_level(level l);

}

#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ?    \
    __builtin_strrchr(__FILE__, '/') + 1 :                  \
    __FILE__)


#define LOG(level)                                          \
    std::cerr                                               \
        << "[" << __FILENAME__ << ":" << __LINE__ << "] "   \
        << " [" << get_level(level) << "] "

#endif
