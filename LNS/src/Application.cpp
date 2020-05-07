#include "Application.h"
#include <spdlog/spdlog.h>
namespace LNS{
    Application::Application()
    {
        spdlog::info("Application born");
    }

    Application::~Application()
    {
        spdlog::info("Application died");
    }
    void Application::Run(){
        spdlog::info("Application running");
    }
}