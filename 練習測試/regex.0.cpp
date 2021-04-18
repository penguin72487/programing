#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::regex ob_Exp("\\d{2}-\\d{8}");
    std::string str_Msg="02-86318034";
    std::cout<< std::regex_match(str_Msg, ob_Exp);
    return 0;
}
