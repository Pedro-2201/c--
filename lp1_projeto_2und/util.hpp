#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>

typedef struct {
    int ano;
    int mes;
    int dia;
} Data;

typedef struct {
    string cidade;
    string bairro;
    string rua;
    string cep;
    int numero;
} Endereco;

#endif