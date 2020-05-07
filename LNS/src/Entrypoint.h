#pragma once

#include "Application.h"
#include "Log.h"

extern LNS::Application* LNS::createApplication();

int main(int argc, char** argv){

    LNS::Log::Init();
    LNS_CORE_INFO("Initialized LNS");
    LNS_WARN("Application Initialized");
    
    auto app = LNS::createApplication();
    app->Run();
    delete app;
}