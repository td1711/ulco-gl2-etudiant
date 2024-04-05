#include <hv/WebSocketServer.h>

#include <iostream>

int main() {

    hv::WebSocketService ws;
    ws.onopen = [](const WebSocketChannelPtr& channel, const HttpRequestPtr& req) {
        std::cout << "client connected" << std::endl;
    };
    ws.onmessage = [](const WebSocketChannelPtr& channel, const std::string& msg) {
        std::cout << "echo: " << msg << std::endl;
        channel->send(msg);
    };
    ws.onclose = [](const WebSocketChannelPtr& channel) {
        std::cout << "client disconnected" << std::endl;
    };

    hv::WebSocketServer server(&ws);
    server.setPort(9000);
    std::cout << "waiting for clients..." << std::endl;
    server.run();

    return 0;
}

