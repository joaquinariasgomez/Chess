#pragma once
#include <string>

class Ficha {
    public:
        virtual std::string print() const = 0;
        virtual ~Ficha() {}
    private:
        bool oponente;  //true if it is oponent. false if not
};