#ifndef GERENTE_HPP
#define GERENTE_HPP

#include "./funcionario.hpp"
#include "./pessoa.hpp"

using namespace std;

class Gerente : public Funcionario, public Pessoa{
    private:
    float participacaoLucros;

    public:
    Gerente();
    Gerente(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, float salario, string matricula, Data ingressoEmpresa, float participacaoLucros);
    void setParticipacaoLucros(float participacaoLucros);
    float getParticipacaoLucros();
    float calcularSalario(int diasFaltas);
    float calcularRecisao(Data desligamento);
};

#endif