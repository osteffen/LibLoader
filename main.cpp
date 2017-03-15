#include <iostream>
#include "LibLoader.h"
using namespace std;

int main(int argc, char *argv[])
{

    LibLoader l("./liblib1.so");

//    int(*f)();

//    if(! l.GetSymbol<int(*)()>("hook",f))
//        return 1;

//    f();

    auto f = l.GS<int(*)()>("hook");

    f();

    return 0;
}
