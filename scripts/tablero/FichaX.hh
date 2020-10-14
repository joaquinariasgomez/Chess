#include "Ficha.hh"
#include <string>

class FichaX: public Ficha {
    public:
        FichaX() {}
        std::string print() const {return value;}
    private:
        const std::string value = "X";
};