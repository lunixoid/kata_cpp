#include "StringCalculator.hpp"

std::list<std::string> splitString(std::string_view inputString) {
    std::regex reDelimiter("(?:,|\n)");
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
    auto digits = splitString(calcString);
    std::list<int> numbers;
    for (auto digit: digits) {
        numbers.push_back(std::stoi(digit));
    }
    return [=](){ int summ = 0; for (auto n: numbers) summ += n; return summ; }();
}