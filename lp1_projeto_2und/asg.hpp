#ifndef ASG_HPP
#define ASG_HPP

#include "funcionario.hpp"
#include "pessoa.hpp"

class Asg : public Funcionario, public Pessoa{
    private:
    float adicionalInsalubridade;

    public:
    Asg();
    Asg(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, float salario, string matricula, Data ingressoEmpresa, float adicionalInsalubridade, int faltas);
    void setAdicionalInsalubridade(float adicionalInsalubridade);
    float getAdicionalInsalubridade();
    float calcularSalario(int diasFaltas);
    float calcularRecisao(Data desligamento);
};

#endif