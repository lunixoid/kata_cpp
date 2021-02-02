#include "StringCalculator.hpp"

std::list<std::string> splitString(std::string_view inputString, std::string_view delimiter) {
    size_t pos = 0;
    std::string token;
    std::string data(inputString);
    std::list<std::string> result;
    while ((pos = data.find(delimiter)) != std::string::npos) {
        token = data.substr(0, pos);
        data.erase(0, pos + delimiter.length());
        result.push_back(token);
    }

    return result;
}

int Add(std::string_view calcString) {
    return 10;
}