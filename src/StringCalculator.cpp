#include "StringCalculator.hpp"
#include <regex>

std::list<std::string> splitString(std::string_view inputString, std::string_view delimiter) {
    std::string strDelimiter(delimiter);
    std::string strInputString(inputString);
    std::regex sep(strDelimiter);
    std::sregex_token_iterator tokens(strInputString.cbegin(), strInputString.cend(), sep, -1);
    std::sregex_token_iterator end;
    std::list<std::string> result;
    for(; tokens != end; ++tokens) {
        result.push_back(*tokens);
    }

    return result;
}

int Add(std::string_view calcString) {
    return 10;
}