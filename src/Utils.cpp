#include <Utils.h>



char * const Utils::stdStrToChar(std::string const & stdstr_msg) {
    char const * const charSource = stdstr_msg.c_str();
    int strSize = stdstr_msg.size();
    char * const dest = (char * const) std::malloc((strSize * sizeof(char)) + 1);

    return std::strcpy(dest,charSource);
}
std::string const Utils::charToStdStr(char const * const & char_msg) {
    return std::string(char_msg);
}
std::string const Utils::charToStdStr(char const * const & char_msg) {
    return std::string(char_msg);
}
String const Utils::charToSysStr(char const * const & char_msg) {
    return String(char_msg);
}
std::string const Utils::sysStrToStdStr(String const & sysstr_msg) {
    return std::string(sysstr_msg.c_str());
}
char * const sysStrToChar(String const & sysstr_msg) {
    char const * const charSource = sysstr_msg.c_str();
    int strSize = sysstr_msg.length();
    char * const dest = (char * const) std::malloc((strSize * sizeof(char)) + 1);

    return std::strcpy(dest,charSource);
}