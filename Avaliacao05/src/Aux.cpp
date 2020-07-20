#include<iomanip>
#include <sstream>

#include "../include/Aux.hpp"

std::string padronizar_casas_decimais(const double valor) {

    std::stringstream string_auxiliar;
        
    string_auxiliar << std::fixed << std::setprecision(2) << valor;

    return string_auxiliar.str();

}
