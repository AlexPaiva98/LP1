#include <iostream>

#include "usage.h"

void show_usage(const std::string &prog_name) {
  std::cout << "Uso: " << prog_name << " add <mensagem>" << std::endl;
}