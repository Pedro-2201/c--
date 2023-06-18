#include <iostream>
#include "./empresa.hpp"

int main(){
    Empresa* atacadoDosCalcado = new Empresa("Atacado dos Calcados","40.101.588/0001-98", 156289.56);
    atacadoDosCalcado->carregarFuncoes();
}