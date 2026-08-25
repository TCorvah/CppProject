#pragma once

#include <map>
namespace Symbol {

    class SymbolTable {
    public:
        void addSymbol(const std::string& name, double value) {
            table[name] = value;
        }

        bool getSymbol(const std::string& name, double& value) const {
            auto it = table.find(name);
            if (it != table.end()) {
                value = it->second;
                return true;
            }
            return false;
        }

    private:
        std::map<std::string, double> table;
    };
}