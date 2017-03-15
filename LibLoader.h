#pragma once
#include <string>
#include <stdexcept>

class LibLoader {
protected:
    void* handle = nullptr;
    void* getSymbol(const std::string& symbol_name);

public:
    LibLoader(const std::string& libname);
    ~LibLoader();

    template<typename symType>
    bool GetSymbol(const std::string& name, symType& sym) {
        auto s = getSymbol(name);
        if(s) {
            sym = (symType) s;
            return true;
        }
        return false;
    }

    struct Exception : std::runtime_error {
        using std::runtime_error::runtime_error;
    };
};
