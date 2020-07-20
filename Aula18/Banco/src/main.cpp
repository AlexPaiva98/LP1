#include <iostream>

#include "../include/Endereco.hpp"
#include "../include/ClientePF.hpp"
#include "../include/ClientePJ.hpp"

#include "../include/Gerente.hpp"
#include "../include/Seguranca.hpp"
#include "../include/Caixa.hpp"

int main(int argc, char const *argv[]){
    
    Endereco endereco("Rio Grande do Norte", "Natal", "Alecrim", "Avenida Coronel Estevam");

    std::cout << std::endl;

    ClientePF lucas("Lucas", "466.198.720-93", endereco);
    std::cout << "Cliente (Pessoa Física): " << lucas.getNome() << std::endl;
    std::cout << "CPF: " << lucas.getCPF() << std::endl;
    std::cout << "Estado de Residência: " << lucas.getEndereco().getEstado() << std::endl;        
    
    std::cout << std::endl;

    ClientePJ shoptime("Shoptime", "90.289.383/0001-52", endereco);
    std::cout << "Cliente (Pessoa Jurídica): " << shoptime.getRazaoSocial() << std::endl;
    std::cout << "CNPJ: " << shoptime.getCNPJ() << std::endl;
    std::cout << "Central(Estado): " << shoptime.getEndereco().getEstado() << std::endl;

    std::cout << std::endl;

    Gerente gustavo(endereco, "08:00:00", "17:00:00", "Gustavo", "Comercial", 5000);
    std::cout << "Gerente: " << gustavo.getNome() << std::endl;
    std::cout << "Perfil: " << gustavo.getPerfil() << std::endl;
    std::cout << "Início do Expediente: " << gustavo.getInicioExpediente() << std::endl;
    std::cout << "Fim do Expediente: " << gustavo.getFimExpediente() << std::endl;
    std::cout << "Salário: " << gustavo.getSalario() << std::endl;
    std::cout << "Estado de Residência: " << gustavo.getEndereco().getEstado() << std::endl;

    std::cout << std::endl;

    Seguranca joao(endereco, "08:00:00", "15:00:00", "João", 3000);
    std::cout << "Segurança: " << joao.getNome() << std::endl;
    std::cout << "Início do Expediente: " << joao.getInicioExpediente() << std::endl;
    std::cout << "Fim do Expediente: " << joao.getFimExpediente() << std::endl;
    std::cout << "Salário: " << joao.getSalario() << std::endl;
    std::cout << "Estado de Residência: " << joao.getEndereco().getEstado() << std::endl;

    std::cout << std::endl;
    
    Caixa igor(endereco, "08:00:00", "15:00:00", "João", 2000);
    std::cout << "Caixa: " << igor.getNome() << std::endl;
    std::cout << "Início do Expediente: " << igor.getInicioExpediente() << std::endl;
    std::cout << "Fim do Expediente: " << igor.getFimExpediente() << std::endl;
    std::cout << "Salário: " << igor.getSalario() << std::endl;
    std::cout << "Estado de Residência: " << igor.getEndereco().getEstado() << std::endl;

    return 0;

}
