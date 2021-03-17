#include "StringCalculator.hpp"
#include <algorithm>

std::list<std::string> splitString(std::string_view inputString, const char delimiter) {
    std::string stdDelimiter;
    stdDelimiter.push_back(delimiter);
    std::regex reDelimiter(stdDelimiter);
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

    auto lines = splitString(calcString, '\n');
    char customDelimiter = 0;
    if (calcString.rfind("//", 0) == 0) {
        auto directive_line = lines.front();
        lines.pop_front();

        if (directive_line.size() < 3) {
            throw("Incorrect directive line size");
        }
        customDelimiter = directive_line[2];
    }

    const char defaultDelimiter = ',';
    std::list<int> digits;
    for (auto line: lines) {
        if (customDelimiter) {
            std::replace(line.begin(), line.end(), customDelimiter, defaultDelimiter);
        }
        auto strDigits = splitString(line, defaultDelimiter);
        for (auto digit: strDigits) {
            digits.push_back(std::stoi(digit));
        }
    }

    checkDigits(digits);
    return [=](){ int summ = 0; for (auto n: digits) summ += n; return summ; }();
}