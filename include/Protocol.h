#pragma once
#include <string>
#include <map>

class Protocol {
public:
    static std::string serialize(const std::map<std::string, std::string>& data);
    static std::map<std::string, std::string> deserialize(const std::string& message);
};
