#include <iostream>
#include <string>
#include <regex>

int main()
{
	// xxxx?Axxxxxxx?B
    std::regex ob_Exp("^.*A.+B$");
    std::string str_Msg="1256AmnbgB";
    std::cout<< std::regex_match(str_Msg, ob_Exp);
    return 0;
}
