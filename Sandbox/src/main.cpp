#include <iostream>
#include <LNS.h>

class Sandbox : public LNS::Application
{
};

LNS::Application* LNS::createApplication(){
    return new Sandbox();
}