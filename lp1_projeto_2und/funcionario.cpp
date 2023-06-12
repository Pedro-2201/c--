#include "funcionario.hpp"

using namespace std;

void Funcionario::setSalario(float salario){
    this->salario = salario;
}
float Funcionario::getSalario(){
    return this->salario;
}
void Funcionario::setMatricula(string matricula){
    this->matricula = matricula;
}
string Funcionario::getMatricula(){
    return this->matricula;
}
void Funcionario::setIngressoEmpresa(Data ingressoEmpresa){
    this->ingressoEmpresa = ingressoEmpresa;
}
Data Funcionario::getIngressoEmpressa(){
    return this->ingressoEmpresa;
}
void Funcionario::setFaltas(int faltas){
    this->faltas = faltas;
}
float Funcionario::getFaltas(){
    return this->faltas;
}