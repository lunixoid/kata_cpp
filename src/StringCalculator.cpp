#include "StringCalculator.hpp"

std::list<std::string> splitString(std::string_view inputString, const std::string delimiter) {
    std::regex reDelimiter(delimiter);
    std::string strInputString(inputString);
    std::sregex_token_iterator tokens(strInputString.cbegin(), strInputString.cend(), reDelimiter, -1);
    std::sregex_token_iterator end;
    std::list<std::string> result;
    for(; tokens != end; ++tokens) {
        result.push_back(*tokens);
    }

    return result;
}

int add(std::string_view calcString) {
    if (calcString.length() == 0)
        return 0;

    std::list<int> numbers;
    for (auto line: splitString(calcString, "\n")) {
        auto digits = splitString(line);
        for (auto digit: digits) {
            numbers.push_back(std::stoi(digit));
        }
    }
    return [=](){ int summ = 0; for (auto n: numbers) summ += n; return summ; }();
}