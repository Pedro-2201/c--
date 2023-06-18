#include "asg.hpp"

using namespace std;

Asg::Asg(){

}
Asg::Asg(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, float salario, string matricula, Data ingressoEmpresa, float adicionalInsalubridade){
    this->nome = nome;
    this->cpf = cpf;
    this->dataNascimento = dataNascimento;
    this->enderecoPessoal = enderecoPessoal;
    this->estadoCivil = estadoCivil;
    this->qtdFilhos = qtdFilhos;
    this->salario = salario;
    this->matricula = matricula;
    this->ingressoEmpresa = ingressoEmpresa;
    this->adicionalInsalubridade = adicionalInsalubridade;
}
void Asg::setAdicionalInsalubridade(float adicionalInsalubridade){
    this->adicionalInsalubridade = adicionalInsalubridade;
}
float Asg::getAdicionalInsalubridade(){
    return adicionalInsalubridade;
}
float Asg::calcularSalario(int diasFaltas){
    float salarioLiquido = salario;
    salarioLiquido -= salarioLiquido / 30 * faltas;
    salarioLiquido += 100 * qtdFilhos;
    salarioLiquido += salario * adicionalInsalubridade;
    return salarioLiquido;
}
float Asg::calcularRecisao(Data desligamento){
    float valorRescisao;
    int tempoTrabalho;
    if(desligamento.ano > ingressoEmpresa.ano){
        if(desligamento.mes > ingressoEmpresa.mes || desligamento.mes == ingressoEmpresa.mes && desligamento.dia >= ingressoEmpresa.dia){
            tempoTrabalho = desligamento.ano - ingressoEmpresa.ano;
        }else{
            tempoTrabalho = (desligamento.ano - ingressoEmpresa.ano) - 1;
        }
    }else{
        tempoTrabalho = 0;
    }
    valorRescisao = tempoTrabalho * salario;
    return valorRescisao;
}