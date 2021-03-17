#pragma once
#include <string>
#include <list>
#include <regex>

extern std::list<std::string> splitString(std::string_view inputString, const char delimiter=',');
extern int add(std::string_view);

template <typename T>
void checkDigits(const std::list<T> digits) {
    std::list<T> negativeDigits;
    for (T digit: digits) {
        if (digit < 0) {
            negativeDigits.push_back(digit);
        }
    }
    if (negativeDigits.size() > 0) {
        std::string negativeDigitsString;
        for (T digit: negativeDigits) {
            negativeDigitsString += std::to_string(digit) + " ";
        }
        throw std::invalid_argument(negativeDigitsString);
    }
}