#include <map>
#include <string>

using Description = std::map<std::string, std::string>;
class Descriptible {

    public:
        virtual Description toDescription() const = 0;
};