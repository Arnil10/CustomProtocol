#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>
#include <iostream>
#include "Protocol.h"

int main() {
    try {
        Poco::Net::ServerSocket server(9000);  // Listen on port 9000
        std::cout << "[Server] Listening on port 9000...\n";

        while (true) {
            Poco::Net::StreamSocket client = server.acceptConnection();
            std::cout << "[Server] Client connected.\n";

            char buffer[1024] = { 0 };
            int n = client.receiveBytes(buffer, sizeof(buffer));

            std::string message(buffer, n);
            std::cout << "[Server] Received raw: " << message << "\n";

            auto data = Protocol::deserialize(message);
            std::cout << "[Server] Parsed Message:\n";
            for (const auto& [key, value] : data) {
                std::cout << " - " << key << ": " << value << "\n";
            }
        }
    }
    catch (std::exception& ex) {
        std::cerr << "[Server] Error: " << ex.what() << "\n";
    }

    return 0;
}
