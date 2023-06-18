#include "pessoa.hpp"

Pessoa::Pessoa(){
    
}
Pessoa::Pessoa(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos){
  this->nome = nome;
  this->cpf = cpf;
  this->dataNascimento = dataNascimento;
  this->enderecoPessoal = enderecoPessoal;
  this->estadoCivil = estadoCivil;
  this->qtdFilhos = qtdFilhos;
}
void Pessoa::setNome(string nome){
  this->nome = nome;
}
string Pessoa::getNome(){
  return nome;
}
void Pessoa::setCpf(string cpf){
  this->cpf = cpf;
}
string Pessoa::getCpf(){
  return cpf;
}
void Pessoa::setDataNascimento(Data dataNascimento){
  this->dataNascimento = dataNascimento;
}
Data Pessoa::getDataNascimento(){
  return dataNascimento;
}
void Pessoa::setEnderecoPessoal(Endereco enderecoPessoal){
  this->enderecoPessoal = enderecoPessoal;
}
Endereco Pessoa::getEnderecoPessoal(){
  return enderecoPessoal;
}
void Pessoa::setEstadoCivil(string estadoCivil){
  this->estadoCivil = estadoCivil;
}
string Pessoa::getEstavoCival(){
  return estadoCivil;  
}
void Pessoa::setQtdFilhos(int qtdFilhos){
  this->qtdFilhos = qtdFilhos;
}
int Pessoa::getQtdFilhos(){
  return qtdFilhos;
}