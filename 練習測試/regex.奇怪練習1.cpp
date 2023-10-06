#include <iostream>
#include <string>
#include <regex>

int main()
{
	// ..0Ab...1Ab..0
    std::regex ob_Exp(".*Ab.+Ab.*");
    std::string str_Msg="mmAblllkAbgB";
    std::cout<< std::regex_match(str_Msg, ob_Exp);
    return 0;
}
