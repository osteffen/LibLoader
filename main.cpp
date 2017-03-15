#include <iostream>
#include <functional>
#include "LibLoader.h"
using namespace std;

int main(int argc, char *argv[])
{

    LibLoader l("./liblib1.so");

    auto f = l.getFunktion<int()>("hook");

    f();

    return 0;
}
