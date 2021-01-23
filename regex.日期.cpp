#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::regex ob_Exp("\\d{4}/[0|/[1-31]");
    std::string str_Msg="2020/1/19";
    std::cout<< std::regex_match(str_Msg, ob_Exp);
    return 0;
}
