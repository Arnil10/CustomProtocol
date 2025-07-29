#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <iostream>
#include "Protocol.h"

int main() {
    try {
        Poco::Net::SocketAddress serverAddress("127.0.0.1", 9000);
        Poco::Net::StreamSocket socket(serverAddress);
        std::cout << "[Client] Connected to server.\n";

        std::map<std::string, std::string> sensorData = {
            {"deviceId", "sensor001"},
            {"temperature", "28.7"},
            {"humidity", "68"}
        };

        std::string message = Protocol::serialize(sensorData);
        std::cout << "[Client] Sending message: " << message << "\n";

        socket.sendBytes(message.data(), (int)message.length());
        std::cout << "[Client] Message sent.\n";
    }
    catch (std::exception& ex) {
        std::cerr << "[Client] Error: " << ex.what() << "\n";
    }

    return 0;
}
