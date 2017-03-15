#include "LibLoader.h"
#include <dlfcn.h>

void *LibLoader::getSymbol(const std::string &symbol_name)
{
    void* s = dlsym(handle, symbol_name.c_str());
    if(!s)
        throw Exception(dlerror());
    return s;
}

LibLoader::LibLoader(const std::string &libname):
    handle(dlopen(libname.c_str(), RTLD_NOW))
{
    if(!handle)
        throw Exception(dlerror());
}

LibLoader::~LibLoader()
{
    if(handle)
        dlclose(handle);
}
