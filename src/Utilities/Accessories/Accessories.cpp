#include <Utilities/Accessories/Accessories.h>



char * const Accessories::stdStrToChar(std::string const & stdstr_msg) {
    char const * const charSource = stdstr_msg.c_str();
    int strSize = stdstr_msg.size();
    char * const dest = (char * const) std::malloc((strSize * sizeof(char)) + 1);

    return std::strcpy(dest,charSource);
}
String const Accessories::stdStrToSysString(std::string const & stdstr_msg) {
    return String(stdstr_msg.c_str());
}
std::string const Accessories::charToStdStr(char const * const & char_msg) {
    return std::string(char_msg);
}
String const Accessories::charToSysStr(char const * const & char_msg) {
    return String(char_msg);
}
std::string const Accessories::sysStrToStdStr(String const & sysstr_msg) {
    return std::string(sysstr_msg.c_str());
}
char * const Accessories::sysStrToChar(String const & sysstr_msg) {
    char const * const charSource = sysstr_msg.c_str();
    int strSize = sysstr_msg.length();
    char * const dest = (char * const) std::malloc((strSize * sizeof(char)) + 1);

    return std::strcpy(dest,charSource);
}