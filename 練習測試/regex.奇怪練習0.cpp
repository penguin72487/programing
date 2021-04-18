#include <iostream>
#include <string>
#include <regex>

int main()
{
	// ..AbXXXXXAb....
    std::regex ob_Exp("[a-zB-Z0-9][ac-zA-Z0-9]Ab.+Ab.+");
    std::string str_Msg="mmAblllkAbgB";
    std::cout<< std::regex_match(str_Msg, ob_Exp);
    return 0;
}
