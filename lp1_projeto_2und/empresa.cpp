#include "./empresa.hpp"

using namespace std;

Empresa::Empresa(){

}
Empresa::Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal){
    this->nomeEmpresa = nomeEmpresa;
    this->cnpj = cnpj;
    this->faturamentoMensal = faturamentoMensal;
}
void Empresa::setFaturamentoMensal(float faturamentoMensal){
    this->faturamentoMensal = faturamentoMensal;
}
float Empresa::getFaturamentoMensal(){
    return faturamentoMensal;
}
void Empresa::setNomeEmpresa(string nomeEmpresa){
    this->nomeEmpresa = nomeEmpresa;
}
string Empresa::getNomeEmpresa(){
    return nomeEmpresa;
}
void Empresa::setCnpj(string cnpj){
    this->cnpj = cnpj;
}
string Empresa::getCnpj(){
    return cnpj;
}
void Empresa::setDono(Pessoa dono){
    this->dono = dono;
}
Pessoa Empresa::getDono(){
    return dono;
}
void Empresa::setAsg(Asg asgs){
    this->asgs.push_back(asgs);
}
vector<Asg> Empresa::getAsg(){
    return asgs;
}
void Empresa::setVendedor(Vendedor vendedores){
    this->vendedores.push_back(vendedores);   
}
vector<Vendedor> Empresa::getVendedor(){
    return vendedores;
}
void Empresa::setGerente(Gerente gerentes){
    this->gerentes.push_back(gerentes);
}
vector<Gerente> Empresa::getGerente(){
    return gerentes;
}
void Empresa::carregarFuncoes(){
    vector<string> funcoes;
    fstream arquivoFuncao;
    arquivoFuncao.open("./arquivosLeita/funcoes.txt", ios::in | ios::app);
    while(!arquivoFuncao.eof()){
        string aux;
        getline(arquivoFuncao, aux);
        funcoes.push_back(aux);
    }
    arquivoFuncao.close();
    for(int i = 0; i < funcoes.size(); i++){
        if(funcoes[i] == "carregarEmpresa()"){
            carregarEmpresa();
        }else if(funcoes[i] == "carregarAsg()"){
            carregarAsg();
        }else if(funcoes[i] == "carregarVendedor()"){
            carregarVendedor();
        }else if(funcoes[i] == "carregarGerente()"){
            carregarGerente();
        }else if(funcoes[i] == "carregaDono()"){
            carregarDono();
        }else if(funcoes[i] == "imprimeAsgs()"){
            imprimeAsgs();
        }else if(funcoes[i] == "imprimeVendedores()"){
            imprimeVendedores();
        }else if(funcoes[i] == "imprimeGerentes()"){
            imprimeGerentes();
        }else if(funcoes[i] == "imprimeDono()"){
            imprimeDono();
        }else if(funcoes[i] == "buscaFuncionario()"){
            buscaFuncionario(funcoes[i + 1]);
            i++;
        }else if(funcoes[i] == "calculaSalarioFuncionario()"){
            calculaSalarioFuncionario(funcoes[i + 1]);
            i++;
        }else if(funcoes[i] == "calculaTodoOsSalarios()"){
            calculaTodosOsSalarios();
        }else if(funcoes[i] == "calcularRecisao()"){
            Data data;
            data.ano = stoi(funcoes[i + 2]);
            data.mes = stoi(funcoes[i + 3]);
            data.dia = stoi(funcoes[i + 4]);
            calculaRecisao(funcoes[i + 1], data);
            i += 4;
        }
    }
}
void Empresa::carregarEmpresa(){
    vector<string> empresaDados;
    fstream arquivoEmpresa;
    arquivoEmpresa.open("./arquivosLeita/empresa.txt", ios::in | ios::app);
    while(!arquivoEmpresa.eof()){
        string aux;
        getline(arquivoEmpresa, aux);
        empresaDados.push_back(aux);
    }
    nomeEmpresa = empresaDados[2];
    cnpj = empresaDados[3];
    faturamentoMensal = stof(empresaDados[4]);
}
void Empresa::carregarAsg(){
    vector<string> asgsDados;
    fstream arquivoAsg;
    arquivoAsg.open("../arquivosLeita/asg.txt", ios::in | ios::app);
    while(!arquivoAsg.eof()){
        string aux;
        getline(arquivoAsg, aux);
        asgsDados.push_back(aux);
    }
    
}
void Empresa::carregarVendedor(){

}
void Empresa::carregarGerente(){

}
void Empresa::carregarDono(){

}
void Empresa::imprimeAsgs(){

}
void Empresa::imprimeVendedores(){

}
void Empresa::imprimeGerentes(){

}
void Empresa::imprimeDono(){

}
void Empresa::buscaFuncionario(string matricula){

}
void Empresa::calculaSalarioFuncionario(string matricula){

}
void Empresa::calculaTodosOsSalarios(){

}
void Empresa::calculaRecisao(string matricula, Data desligamento){

}