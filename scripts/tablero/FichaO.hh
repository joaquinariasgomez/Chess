#include "Ficha.hh"
#include <string>

class FichaO: public Ficha {
    public:
        FichaO() {}
        std::string print() const {return value;}
    private:
        const std::string value = "O";
};