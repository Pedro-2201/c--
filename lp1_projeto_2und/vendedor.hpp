#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include "./funcionario.hpp"
#include "./pessoa.hpp"

class Vendedor : public Funcionario, public Pessoa{
    private:
    char tipoVendedor;

    public:
    Vendedor();
    Vendedor(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, float salario, string matricula, Data ingressoEmpresa, char tipoVendedor, int faltas);
    void setTipoVendedor(char tipoVendedor);
    char getTipoVendedor();
    float calcularSalario(int diasFaltas);
    float calcularRecisao(Data desligamento);
};

#endif