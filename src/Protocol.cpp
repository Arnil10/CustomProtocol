#include "Protocol.h"
#include <sstream>

std::string Protocol::serialize(const std::map<std::string, std::string>& data) {
    std::ostringstream oss;
    for (const auto& pair : data) {
        oss << pair.first << "=" << pair.second << ";";
    }
    return oss.str();
}

std::map<std::string, std::string> Protocol::deserialize(const std::string& message) {
    std::map<std::string, std::string> data;
    std::istringstream iss(message);
    std::string token;

    while (std::getline(iss, token, ';')) {
        auto pos = token.find('=');
        if (pos != std::string::npos) {
            data[token.substr(0, pos)] = token.substr(pos + 1);
        }
    }
    return data;
}
