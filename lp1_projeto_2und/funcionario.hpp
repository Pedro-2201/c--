#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "util.hpp"
using namespace std;

class Funcionario{
    private:
    float salario; //mudei o salário para float
    string matricula;
    Data ingressoEmpresa;
    int faltas;

    public:
    void setSalario(float salario);
    float getSalario();
    void setMatricula(string matricula);
    string getMatricula();
    void setIngressoEmpresa(Data ingressoEmpresa);
    Data getIngressoEmpressa();
    void setFaltas(int faltas);
    float getFaltas();
    virtual float calcularSalario(int diasFaltas) = 0;
    virtual float calcularRecisao(Data desligamento) = 0;
};

#endif