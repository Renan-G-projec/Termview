// Ad Maiorem Dei Gloriam!
#ifndef LOG_HPP
#define LOG_HPP

#ifdef NDEBUG

#define LOG(message) 
#define LOG_ERROR(message) 

#else

#include <iostream>

#define _RESET_ESCAPE "\033[0m"
#define _ERROR_ESCAPE "\033[31m\033[1m"
#define _LOG_ESCAPE "\033[36m\033[1m"

#define LOG(message) std::cout << _LOG_ESCAPE "LOG" _RESET_ESCAPE ": [" << __FILE_NAME__ << ":" << __LINE__ << "] " << message << '\n'
#define LOG_ERROR(message) std::cerr << _ERROR_ESCAPE "ERROR" _RESET_ESCAPE ": ["  << __FILE_NAME__ << ":" << __LINE__ << "] " << message << '\n'

#endif

#endif