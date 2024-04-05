#include <hv/WebSocketClient.h>

#include <chrono>
#include <iostream>
#include <thread>

int main(int argc, char** argv) {

    hv::WebSocketClient ws;
    ws.onopen = []() {
        std::cout << "connected" << std::endl;
    };
    ws.onmessage = [](const std::string& msg) {
        std::cout << "received: " << msg << std::endl;
    };
    ws.onclose = []() {
        std::cout << "disconnected" << std::endl;
        exit(0);
    };
    ws.open("ws://127.0.0.1:9000");
    // ws.open("wss://ws.ifelse.io");

    std::string input;
    std::cout << "enter messages:" << std::endl;
    while (true) {
        std::getline(std::cin, input);
        
        if (input == "") {
            ws.close();
            break;
        }

        ws.send(input);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}

