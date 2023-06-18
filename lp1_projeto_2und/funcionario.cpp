#include "funcionario.hpp"

void Funcionario::setSalario(float salario){
    this->salario = salario;
}
float Funcionario::getSalario(){
    return salario;
}
void Funcionario::setMatricula(string matricula){
    this->matricula = matricula;
}
string Funcionario::getMatricula(){
    return matricula;
}
void Funcionario::setIngressoEmpresa(Data ingressoEmpresa){
    this->ingressoEmpresa = ingressoEmpresa;
}
Data Funcionario::getIngressoEmpresa(){
    return ingressoEmpresa;
}
void Funcionario::setFaltas(int faltas){
    this->faltas = faltas;
}
int Funcionario::getFaltas(){
    return faltas;
}