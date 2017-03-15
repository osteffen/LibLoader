#include "LibLoader.h"
#include <dlfcn.h>

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
