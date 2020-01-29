#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include <stdlib.h>
#include <document.h>
#include <Arduino.h>

using namespace std;


namespace Utils {
    /* Utilities for converting between the Standard String, an Array of Characters, and the Arduino System String */
    char      * const stdStrToChar      (std::string const & stdstr_msg);
    String      const stdStrToSysString (std::string const & stdstr_msg);
    std::string const charToStdStr      (char const * const & char_msg);
    String      const charToSysStr      (char const * const & char_msg);
    std::string const sysStrToStdStr    (String const & sysstr_msg);
    char      * const sysStrToChar      (String const & sysstr_msg);
};

#endif