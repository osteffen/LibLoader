#pragma once
#include <string>
#include <stdexcept>
#include <functional>

class LibLoader {
protected:
    void* handle = nullptr;
    void* getSymbol(const std::string& symbol_name);

public:
    LibLoader(const std::string& libname);

    LibLoader(LibLoader&) = delete;
    LibLoader& operator=(LibLoader&) = delete;

    LibLoader(LibLoader&&) = default;
    LibLoader& operator=(LibLoader&&) = default;

    ~LibLoader();

     template<typename T>
    std::function<T> getFunction(const std::string& name) {
        return reinterpret_cast<T*>(getSymbol(name));
    }

    struct Exception : std::runtime_error {
        using std::runtime_error::runtime_error;
    };
};
