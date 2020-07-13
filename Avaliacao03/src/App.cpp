#include <iostream>
#include <vector>

#include "../include/App.h"
#include "../include/Message.h"
#include "../include/Aux.h"

App::App(const Config* config_default): 
    diary(config_default->path), 
    default_format(config_default->default_format) {
}

int App::run(int argc, char* argv[]) {

    if (argc == 1) {
        return show_usage(argv[0]);
    }

    std::string action = argv[1];

    if (action =="interactive") {
        interactive();
    } else if(action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        if (argc == 2) {
            list();
        } else {
            list(argv[2]);
        }
    } else if (action == "search") {
        if (argc == 2) {
            search();
        } else {
            search(argv[2]);
        }
    } else {
        return show_usage(argv[0]);
    }

    return 0;

}

void App::add() {

    std::string message;
    std::cout << "Informe a mensagem: " << std::endl;
    std::getline(std::cin, message);

    add(message);

}

void App::add(const std::string &message) {
    
    diary.add(message);
    diary.write();

    // Deixar uma linha em branco antes da lista
    std::cout << std::endl;

    std::cout << "Mensagem Adicionada" << std::endl;

    // Deixar uma linha em branco depois da lista
    std::cout << std::endl;

}

void App::list() {

    list(default_format);
    
}

void App::list(const std::string &model) {
    
    // Deixar uma linha em branco antes da lista
    std::cout << std::endl;

    std::string print = model;
    for (auto i: diary.messages) {
        
        print = replace_all(print, "%d", i.date.to_string());
        print = replace_all(print, "%t", i.time.to_string());
        print = replace_all(print, "%m", i.content);

        std::cout << print << std::endl;

        print = model;

    }

    // Deixar uma linha em branco depois da lista
    std::cout << std::endl;

}

void App::search() {

    std::string what;
    std::cout << "Informe o parâmetro de busca: " << std::endl;
    std::getline(std::cin, what);
    search(what);

}

void App::search(const std::string &what) {
    
    std::vector<Message*> filtered_messages = diary.search(what);
    if (filtered_messages.begin() != filtered_messages.end()) {
        
        // Deixar uma linha em branco antes da lista
        std::cout << std::endl;

        std::string print = default_format;
        for(auto i: filtered_messages) {
        
            print = replace_all(print, "%d", i->date.to_string());
            print = replace_all(print, "%t", i->time.to_string());
            print = replace_all(print, "%m", i->content);

            std::cout << print << std::endl;

            print = default_format;
                    
        }

        // Deixar uma linha em branco depois da lista
        std::cout << std::endl;
    
    } else {

        std::cout << "Nenhum resultado encontrado" << std::endl;

    }
}

void App::interactive() {

    std::cout << std::endl << "Diário 1.0" << std::endl;
    std::cout << std::endl << "Lista de ações" << std::endl << std::endl;
    std::cout << "1) Listar mensagens" << std::endl;
    std::cout << "2) Adicionar nova mensagem" << std::endl;
    std::cout << "3) Buscar mensagens" << std::endl << std::endl;
    std::cout << "0) Finalizar" << std::endl << std::endl;

    int option = 1;
    while (option) {
       
        std::cout << "Digite o nº da opção e aperte enter: ";
        std::cin >> option;

        if (option < 0 || option > 3) {
            std::cout << std::endl << "Escolha inválida" << std::endl << std::endl;
            continue;
        }
        
        switch (option){
            case 1:
                list();
                break;
            case 2:
                std::cin.ignore();
                add();
                break;
            case 3:
                std::cin.ignore();
                search();
                break;
            default:
                break;
        }

    }
}

int App::show_usage(const std::string &prog_name) {

    std::cout << "1. Uso: " << prog_name << " interactive" << std::endl;
    std::cout << "2. Uso: " << prog_name << " add <mensagem>" << std::endl;
    std::cout << "3. Uso: " << prog_name << " list <formato de saída>" << std::endl;
    std::cout << "4. Uso: " << prog_name << " search <termo de busca>" << std::endl;

    return 1;
}
