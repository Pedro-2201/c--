#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "./util.hpp"

using namespace std;

class Pessoa{
  private:
  string nome;
  string cpf;
  Data dataNascimento;
  Endereco enderecoPessoal;
  string estadoCivil; //Como limitar as opção de preenchimento
  int qtdFilhos;

  public:
  Pessoa();
  Pessoa(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos);
  void setNome(string nome);
  string getNome();
  void setCpf(string cpf);
  string getCpf();
  void setDataNascimento(Data dataNascimento);
  Data getDataNascimento();
  void setEnderecoPessoal(Endereco enderecoPessoal);
  Endereco getEnderecoPessoal();
  void setEstadoCivil(string estadoCivil);
  string getEstavoCival();
  void setQtdFilhos(int qtdFilhos);
  int getQtdFilhos();
};

#endif