#include "./vendedor.hpp"

using namespace std;

Vendedor::Vendedor(){

}
Vendedor::Vendedor(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, float salario, string matricula, Data ingressoEmpresa, char tipoVendedor){
    this->nome = nome;
    this->cpf = cpf;
    this->dataNascimento = dataNascimento;
    this->enderecoPessoal = enderecoPessoal;
    this->estadoCivil = estadoCivil;
    this->qtdFilhos = qtdFilhos;
    this->salario = salario;
    this->matricula = matricula;
    this->ingressoEmpresa = ingressoEmpresa;
    this->tipoVendedor = tipoVendedor;
}
void Vendedor::setTipoVendedor(char tipoVendedor){
    this->tipoVendedor = tipoVendedor;
}
char Vendedor::getTipoVendedor(){
    return tipoVendedor;
}
float Vendedor::calcularSalario(int diasFaltas){
    float salarioLiquido = salario;
    salarioLiquido -= salarioLiquido / 30 * faltas;
    if(tipoVendedor == 'a' || tipoVendedor == 'A'){
        salarioLiquido += salario * 0,25;
    }else if(tipoVendedor == 'b' || tipoVendedor == 'B'){
        salarioLiquido += salario * 0,10;
    }else{
        salarioLiquido += salario * 0,05;
    }
    salarioLiquido += 100 * qtdFilhos;
    return salarioLiquido;
}
float Vendedor::calcularRecisao(Data desligamento){
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