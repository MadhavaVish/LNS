#include <LNS.h>
#include <spdlog/spdlog.h>

namespace LNS
{
    std::string TestFunction()
    {
        spdlog::error("Some error message with arg: {}", 1);
        return std::string("First Commit Testing 1...2...3...!");
    }
}