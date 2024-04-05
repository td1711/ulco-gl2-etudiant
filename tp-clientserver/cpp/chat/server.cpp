#include <hv/WebSocketServer.h>

#include "Net.hpp"

#include <chrono>
#include <iostream>
#include <thread>
#include <string>


int main() {
    Net net;

    hv::WebSocketService ws;
    ws.onopen = [&net](const WebSocketChannelPtr& channel, const HttpRequestPtr& req) {
        net.add(channel);
        std::cout << "client connected" << std::endl;
    };
    ws.onmessage = [&net](const WebSocketChannelPtr& channel, const std::string& msg) {
        if(net.isPending(channel)){
            if(net.giveName(channel, msg)){
                channel->send("Welcome " + msg);
            }
            else{
                channel->send("Incorrect name !");
            }
        }
        else{
            std::optional<std::string> name = net.findName(channel);
      
            auto send = [&msg, name](const WebSocketChannelPtr & channel) {
                channel->send(*name + " : " +msg);
            };
            net.map(send);
        }

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

