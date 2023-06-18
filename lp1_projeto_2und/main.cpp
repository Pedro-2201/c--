#include <iostream>
#include "empresa.hpp"
#include "util.hpp"

int main(){
    Empresa *atacadoDosCalcado = new Empresa("Atacado dos Calcados","40.101.588/0001-98", 156289.56);
    atacadoDosCalcado->carregarFuncoes();
    Data data;
    Data data2;
    data.ano = 2021;
    data.mes = 2;
    data.dia = 1;
    data2 = data;
    return 0;
}