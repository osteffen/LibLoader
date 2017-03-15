#include <iostream>
#include "libInterface.h"
#include <dlfcn.h>
using namespace std;

int main(int argc, char *argv[])
{

    auto handle = dlopen("./liblib1.so", RTLD_NOW);
    if(!handle) {
        cout << "DL ERROR: " << dlerror() << endl;
    }

    void* fct = dlsym(handle, "hook");

    if(!fct) {
        cout << "symbol not found" << endl;
    } else {
        auto f = (int (*)()) fct;
        f();
    }

    cout << "Hello World!" << endl;

    dlclose(handle);
    return 0;
}
