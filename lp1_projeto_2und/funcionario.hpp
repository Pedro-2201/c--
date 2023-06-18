#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "util.hpp"

class Funcionario{
    protected:
    float salario;
    string matricula;
    Data ingressoEmpresa;
    int faltas;

    public:
    void setSalario(float salario);
    float getSalario();
    void setMatricula(string matricula);
    string getMatricula();
    void setIngressoEmpresa(Data ingressoEmpresa);
    Data getIngressoEmpresa();
    void setFaltas(int faltas);
    int getFaltas();
    virtual float calcularSalario(int diasFaltas) = 0;
    virtual float calcularRecisao(Data desligamento) = 0;
};

#endif