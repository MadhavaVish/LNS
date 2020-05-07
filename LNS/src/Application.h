#pragma once

#include "core.h"

namespace LNS{
    class LNS_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    Application* createApplication();
    
}