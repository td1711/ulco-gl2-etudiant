#include <hv/WebSocketClient.h>

#include <chrono>
#include <iostream>
#include <thread>

int main(int argc, char** argv) {

    hv::WebSocketClient ws;
    ws.onopen = []() {
        std::cout << "----- connected -----" << std::endl;
    };
    ws.onmessage = [](const std::string& msg) {
        std::cout << msg << std::endl;
    };
    ws.onclose = []() {
        std::cout << "----- disconnected -----" << std::endl;
        exit(0);
    };
    ws.open("ws://127.0.0.1:9000");

    std::string input;
    while (true) {
        std::getline(std::cin, input);
        
        if (input == "quit") {
            ws.close();
            break;
        }

        ws.send(input);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}

