#include "gerente.hpp"

Gerente::Gerente(){

}
Gerente::Gerente(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, float salario, string matricula, Data ingressoEmpresa, float participacaoLucros, int faltas){
    this->nome = nome;
    this->cpf = cpf;
    this->dataNascimento = dataNascimento;
    this->enderecoPessoal = enderecoPessoal;
    this->estadoCivil = estadoCivil;
    this->qtdFilhos = qtdFilhos;
    this->salario = salario;
    this->matricula = matricula;
    this->ingressoEmpresa = ingressoEmpresa;
    this->participacaoLucros = participacaoLucros;
    this->faltas = faltas;
}
void Gerente::setParticipacaoLucros(float participacaoLucros){
    this->participacaoLucros = participacaoLucros;
}
float Gerente::getParticipacaoLucros(){
    return participacaoLucros;
}

float Gerente::calcularSalario(int diasFaltas){
    float salarioLiquido = salario;
    salarioLiquido -= salarioLiquido / 30 * faltas;
    salarioLiquido += participacaoLucros; 
    salarioLiquido += 100 * qtdFilhos;
    return salarioLiquido;
}
float Gerente::calcularRecisao(Data desligamento){
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