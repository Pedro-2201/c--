#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include "./pessoa.hpp"
#include "./asg.hpp"
#include "./vendedor.hpp"
#include "./gerente.hpp"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Empresa{
    private:
    float faturamentoMensal;
    string nomeEmpresa;
    string cnpj;
    Pessoa dono;
    vector<Asg> asgs;
    vector<Vendedor> vendedores;
    vector<Gerente> gerentes;

    public:
    Empresa();
    Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal);
    void setFaturamentoMensal(float faturamentoMensal);
    float getFaturamentoMensal();
    void setNomeEmpresa(string nomeEmpresa);
    string getNomeEmpresa();
    void setCnpj(string cnpj);
    string getCnpj();
    void setDono(Pessoa dono);
    Pessoa getDono();
    void setAsg(Asg asgs);
    vector<Asg> getAsg();
    void setVendedor(Vendedor vendedores);
    vector<Vendedor> getVendedor();
    void setGerente(Gerente gerentes);
    vector<Gerente> getGerente();
    void carregarFuncoes();
    void carregarEmpresa();
    void carregarAsg();
    void carregarVendedor();
    void carregarGerente();
    void carregarDono();
    void imprimeAsgs();
    void imprimeVendedores();
    void imprimeGerentes();
    void imprimeDono();
    void buscaFuncionario(string matricula);
    void calculaSalarioFuncionario(string matricula);
    void calculaTodosOsSalarios();
    void calculaRecisao(string matricula, Data desligamento);
};

#endif