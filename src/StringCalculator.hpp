#pragma once
#include <string>
#include <list>
#include <regex>

extern std::list<std::string> splitString(std::string_view inputString, const std::string delimiter=",");
extern int add(std::string_view);