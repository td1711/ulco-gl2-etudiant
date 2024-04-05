#include <hv/WebSocketServer.h>

#include <list>
#include <thread>

class Net {
    private:
        std::list<WebSocketChannelPtr> _channels;

    public:
        Net() = default;
        Net(const Net &) = delete;

        void add(const WebSocketChannelPtr & c) {
            _channels.push_front(c);
        }

        void del(const WebSocketChannelPtr & c) {
            auto it = std::find(_channels.begin(), _channels.end(), c);
            if (it != _channels.end())
                _channels.erase(it);
        }

        void map(std::function<void(const WebSocketChannelPtr &)> f) {
            for (const WebSocketChannelPtr & c : _channels)
                f(c);
        }
};

