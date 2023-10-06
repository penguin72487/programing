#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::regex ob_Exp("[a-zA-Z][12]\\d{8}");
    std::string str_Msg="F131742600";
    std::cout<< std::regex_match(str_Msg, ob_Exp);
    return 0;
}
