#include <hv/WebSocketServer.h>

#include "Net.hpp"

#include <chrono>
#include <iostream>
#include <thread>


int main() {
    Net net;

    hv::WebSocketService ws;
    ws.onopen = [&net](const WebSocketChannelPtr& channel, const HttpRequestPtr& req) {
        net.add(channel);
        std::cout << "client connected" << std::endl;
    };
    ws.onmessage = [&net](const WebSocketChannelPtr& channel, const std::string& msg) {
        auto send = [&msg](const WebSocketChannelPtr & channel) {
            channel->send(msg);
        };
        net.map(send);

    };
    ws.onclose = [&net](const WebSocketChannelPtr& channel) {
        net.del(channel);
        std::cout << "client disconnected" << std::endl;
    };

    hv::WebSocketServer server;
    server.registerWebSocketService(&ws);
    server.setPort(9000);
    std::cout << "waiting for clients..." << std::endl;
    server.run();

    return 0;
}

