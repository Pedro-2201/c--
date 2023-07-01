#include "empresa.hpp"

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
/*void Empresa::setDono(Pessoa dono){
    this->dono = dono;
}
Pessoa Empresa::getDono(){
    return dono;
}*/
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
    arquivoFuncao.open("arquivosLeitura/funcoes.txt", ios::in | ios::app);
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
        }else if(funcoes[i] == "calculaRecisaoFuncionario()"){
            Data data;
            data.ano = stoi(funcoes[i + 2]);
            data.mes = stoi(funcoes[i + 3]);
            data.dia = stoi(funcoes[i + 4]);
            calculaRecisaoFuncionario(funcoes[i + 1], data);
            i += 4;
        }
    }
}
void Empresa::carregarEmpresa(){
    vector<string> empresaDados;
    fstream arquivoEmpresa;
    arquivoEmpresa.open("arquivosLeitura/empresa.txt", ios::in | ios::app);
    while(!arquivoEmpresa.eof()){
        string aux;
        getline(arquivoEmpresa, aux);
        empresaDados.push_back(aux);
    }
    arquivoEmpresa.close();
    nomeEmpresa = empresaDados[2];
    cnpj = empresaDados[3];
    faturamentoMensal = stof(empresaDados[4]);
}
void Empresa::carregarAsg(){
    vector<string> asgsDados;
    fstream arquivoAsg;
    arquivoAsg.open("arquivosLeitura/asg.txt", ios::in | ios::app);
    while(!arquivoAsg.eof()){
        string aux;
        getline(arquivoAsg, aux);
        asgsDados.push_back(aux);
    }
    arquivoAsg.close();
    for(int i = 3; i < asgsDados.size(); i += 26){
        Asg asg;
        Data auxData;
        Endereco auxEndereco;
        asg.setNome(asgsDados[i]);
        asg.setCpf(asgsDados[i + 1]);
        asg.setQtdFilhos(stoi(asgsDados[i + 2]));
        asg.setEstadoCivil(asgsDados[i + 3]);
        auxEndereco.cidade = asgsDados[i +  5];
        auxEndereco.cep = asgsDados[i + 6];
        auxEndereco.bairro = asgsDados[i + 7];
        auxEndereco.rua = asgsDados[i + 8];
        auxEndereco.numero = stoi(asgsDados[i + 9]);
        asg.setEnderecoPessoal(auxEndereco);
        auxData.ano = stoi(asgsDados[i + 11]);
        auxData.mes = stoi(asgsDados[i + 12]);
        auxData.dia = stoi(asgsDados[i + 13]);
        asg.setDataNascimento(auxData);
        asg.setMatricula(asgsDados[i + 15]);
        asg.setSalario(stof(asgsDados[i + 16]));
        asg.setAdicionalInsalubridade(stof(asgsDados[i + 17]));
        asg.setFaltas(stoi(asgsDados[i + 18]));
        auxData.ano = stoi(asgsDados[i + 20]);
        auxData.mes = stoi(asgsDados[i + 21]);
        auxData.dia = stoi(asgsDados[i + 22]);
        asg.setIngressoEmpresa(auxData);
        asgs.push_back(asg);
    }
}
void Empresa::carregarVendedor(){
    vector<string> vendedoresDados;
    fstream arquivoVendedor;
    arquivoVendedor.open("arquivosLeitura/vendedor.txt", ios::in | ios::app);
    while(!arquivoVendedor.eof()){
        string aux;
        getline(arquivoVendedor, aux);
        vendedoresDados.push_back(aux);
    }
    arquivoVendedor.close();
    for(int i = 3; i < vendedoresDados.size(); i += 26){
        Vendedor vendedor;
        Data auxData;
        Endereco auxEndereco;
        vendedor.setNome(vendedoresDados[i]);
        vendedor.setCpf(vendedoresDados[i + 1]);
        vendedor.setQtdFilhos(stoi(vendedoresDados[i + 2]));
        vendedor.setEstadoCivil(vendedoresDados[i + 3]);
        auxEndereco.cidade = vendedoresDados[i +  5];
        auxEndereco.cep = vendedoresDados[i + 6];
        auxEndereco.bairro = vendedoresDados[i + 7];
        auxEndereco.rua = vendedoresDados[i + 8];
        auxEndereco.numero = stoi(vendedoresDados[i + 9]);
        vendedor.setEnderecoPessoal(auxEndereco);
        auxData.ano = stoi(vendedoresDados[i + 11]);
        auxData.mes = stoi(vendedoresDados[i + 12]);
        auxData.dia = stoi(vendedoresDados[i + 13]);
        vendedor.setDataNascimento(auxData);
        vendedor.setMatricula(vendedoresDados[i + 15]);
        vendedor.setSalario(stof(vendedoresDados[i + 16]));
        vendedor.setTipoVendedor(vendedoresDados[i + 17][0]);
        vendedor.setFaltas(stoi(vendedoresDados[i + 18]));
        auxData.ano = stoi(vendedoresDados[i + 20]);
        auxData.mes = stoi(vendedoresDados[i + 21]);
        auxData.dia = stoi(vendedoresDados[i + 22]);
        vendedor.setIngressoEmpresa(auxData);
        vendedores.push_back(vendedor);
    }
}
void Empresa::carregarGerente(){
    vector<string> gerentesDados;
    fstream arquivoGerente;
    arquivoGerente.open("arquivosLeitura/gerente.txt", ios::in | ios::app);
    while(!arquivoGerente.eof()){
        string aux;
        getline(arquivoGerente, aux);
        gerentesDados.push_back(aux);
    }
    arquivoGerente.close();
    for(int i = 3; i < gerentesDados.size(); i += 26){
        Gerente gerente;
        Data auxData;
        Endereco auxEndereco;
        gerente.setNome(gerentesDados[i]);
        gerente.setCpf(gerentesDados[i + 1]);
        gerente.setQtdFilhos(stoi(gerentesDados[i + 2]));
        gerente.setEstadoCivil(gerentesDados[i + 3]);
        auxEndereco.cidade = gerentesDados[i +  5];
        auxEndereco.cep = gerentesDados[i + 6];
        auxEndereco.bairro = gerentesDados[i + 7];
        auxEndereco.rua = gerentesDados[i + 8];
        auxEndereco.numero = stoi(gerentesDados[i + 9]);
        gerente.setEnderecoPessoal(auxEndereco);
        auxData.ano = stoi(gerentesDados[i + 11]);
        auxData.mes = stoi(gerentesDados[i + 12]);
        auxData.dia = stoi(gerentesDados[i + 13]);
        gerente.setDataNascimento(auxData);
        gerente.setMatricula(gerentesDados[i + 15]);
        gerente.setSalario(stof(gerentesDados[i + 16]));
        gerente.setParticipacaoLucros(stof(gerentesDados[i + 17]));
        gerente.setFaltas(stoi(gerentesDados[i + 18]));
        auxData.ano = stoi(gerentesDados[i + 20]);
        auxData.mes = stoi(gerentesDados[i + 21]);
        auxData.dia = stoi(gerentesDados[i + 22]);
        gerente.setIngressoEmpresa(auxData);
        gerentes.push_back(gerente);
    }
}
void Empresa::carregarDono(){
    Data auxData;
    Endereco auxEndereco;
    vector<string> donoDados;
    fstream arquivoDono;
    arquivoDono.open("arquivosLeitura/dono.txt", ios::in | ios::app);
    while(!arquivoDono.eof()){
        string aux;
        getline(arquivoDono, aux);
        donoDados.push_back(aux);
    }
    arquivoDono.close();
    dono->setNome(donoDados[3]);
    dono->setCpf(donoDados[4]);
    dono->setQtdFilhos(stoi(donoDados[5]));
    dono->setEstadoCivil(donoDados[6]);
    auxEndereco.cidade = donoDados[7];
    auxEndereco.cep = donoDados[8];
    auxEndereco.bairro = donoDados[9];
    auxEndereco.rua = donoDados[10];
    auxEndereco.numero = stoi(donoDados[11]);
    dono->setEnderecoPessoal(auxEndereco);
    auxData.ano = stoi(donoDados[12]);
    auxData.mes = stoi(donoDados[13]);
    auxData.dia = stoi(donoDados[14]);
    dono->setDataNascimento(auxData);
}
void Empresa::imprimeAsgs(){
    cout << endl << "#########################################################" << endl; 
    for(int i = 0; i < asgs.size(); i++){
        cout << "##### DADOS PESSOAIS #####" << endl;
        cout << "Nome: " << asgs[i].getNome() << endl;
        cout << "CPF: " << asgs[i].getCpf() << endl;
        cout << "Número de filhos: " << asgs[i].getQtdFilhos() << endl;
        cout << "Estado civil: " << asgs[i].getEstavoCival() << endl;
        cout << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
        cout << "Cidade: " << asgs[i].getEnderecoPessoal().cidade << endl;
        cout << "Cep: " << asgs[i].getEnderecoPessoal().cep << endl;
        cout << "Bairro: " << asgs[i].getEnderecoPessoal().bairro << endl;
        cout << "Rua: " << asgs[i].getEnderecoPessoal().rua << endl;
        cout << "Número: " << asgs[i].getEnderecoPessoal().numero << endl;
        cout << "***** Data de nascimento (ano, mes, dia) **** - Essa linha deve ser ignorada" << endl;
        cout << "Ano: " << asgs[i].getDataNascimento().ano << endl;
        cout << "Mês: " << asgs[i].getDataNascimento().mes << endl;
        cout << "Dia: " << asgs[i].getDataNascimento().dia<< endl;
        cout << "##### DADOS FUNCIONAIS #####" << endl;
        cout << "Matrícula: " << asgs[i].getMatricula() << endl;
        cout << "Salário: " << asgs[i].getSalario() << endl;
        cout << "Insalubridade: " << asgs[i].getAdicionalInsalubridade() << endl;
        cout << "Faltas: " << asgs[i].getFaltas() << endl;
        cout << "***** Data de ingresso (ano, mes, dia) ****" << endl;
        cout << "Ano: " << asgs[i].getIngressoEmpresa().ano << endl;
        cout << "Mês: " << asgs[i].getIngressoEmpresa().mes << endl;
        cout << "Dia: " << asgs[i].getIngressoEmpresa().dia << endl;
    }
    cout << endl << "#########################################################" << endl; 
}
void Empresa::imprimeVendedores(){
    cout << endl << "#########################################################" << endl; 
    for(int i = 0; i < vendedores.size(); i++){
        cout << "##### DADOS PESSOAIS #####" << endl;
        cout << "Nome: " << vendedores[i].getNome() << endl;
        cout << "CPF: " << vendedores[i].getCpf() << endl;
        cout << "Número de filhos: " << vendedores[i].getQtdFilhos() << endl;
        cout << "Estado civil: " << vendedores[i].getEstavoCival() << endl;
        cout << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
        cout << "Cidade: " << vendedores[i].getEnderecoPessoal().cidade << endl;
        cout << "Cep: " << vendedores[i].getEnderecoPessoal().cep << endl;
        cout << "Bairro: " << vendedores[i].getEnderecoPessoal().bairro << endl;
        cout << "Rua: " << vendedores[i].getEnderecoPessoal().rua << endl;
        cout << "Número: " << vendedores[i].getEnderecoPessoal().numero << endl;
        cout << "***** Data de nascimento (ano, mes, dia) **** - Essa linha deve ser ignorada" << endl;
        cout << "Ano: " << vendedores[i].getDataNascimento().ano << endl;
        cout << "Mês: " << vendedores[i].getDataNascimento().mes << endl;
        cout << "Dia: " << vendedores[i].getDataNascimento().dia<< endl;
        cout << "##### DADOS FUNCIONAIS #####" << endl;
        cout << "Matrícula: " << vendedores[i].getMatricula() << endl;
        cout << "Salário: " << vendedores[i].getSalario() << endl;
        cout << "Tipo de vendedor: " << vendedores[i].getTipoVendedor() << endl;
        cout << "Faltas: " << vendedores[i].getFaltas() << endl;
        cout << "***** Data de ingresso (ano, mes, dia) ****" << endl;
        cout << "Ano: " << vendedores[i].getIngressoEmpresa().ano << endl;
        cout << "Mês: " << vendedores[i].getIngressoEmpresa().mes << endl;
        cout << "Dia: " << vendedores[i].getIngressoEmpresa().dia << endl;
    }
    cout << endl << "#########################################################" << endl; 
}
void Empresa::imprimeGerentes(){
    cout << endl << "#########################################################" << endl; 
    for(int i = 0; i < gerentes.size(); i++){
        cout << "##### DADOS PESSOAIS #####" << endl;
        cout << "Nome: " << gerentes[i].getNome() << endl;
        cout << "CPF: " << gerentes[i].getCpf() << endl;
        cout << "Número de filhos: " << gerentes[i].getQtdFilhos() << endl;
        cout << "Estado civil: " << gerentes[i].getEstavoCival() << endl;
        cout << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
        cout << "Cidade: " << gerentes[i].getEnderecoPessoal().cidade << endl;
        cout << "Cep: " << gerentes[i].getEnderecoPessoal().cep << endl;
        cout << "Bairro: " << gerentes[i].getEnderecoPessoal().bairro << endl;
        cout << "Rua: " << gerentes[i].getEnderecoPessoal().rua << endl;
        cout << "Número: " << gerentes[i].getEnderecoPessoal().numero << endl;
        cout << "***** Data de nascimento (ano, mes, dia) **** - Essa linha deve ser ignorada" << endl;
        cout << "Ano: " << gerentes[i].getDataNascimento().ano << endl;
        cout << "Mês: " << gerentes[i].getDataNascimento().mes << endl;
        cout << "Dia: " << gerentes[i].getDataNascimento().dia<< endl;
        cout << "##### DADOS FUNCIONAIS #####" << endl;
        cout << "Matrícula: " << gerentes[i].getMatricula() << endl;
        cout << "Salário: " << gerentes[i].getSalario() << endl;
        cout << "Participação nos lucros: " << gerentes[i].getParticipacaoLucros() << endl;
        cout << "Faltas: " << gerentes[i].getFaltas() << endl;
        cout << "***** Data de ingresso (ano, mes, dia) ****" << endl;
        cout << "Ano: " << gerentes[i].getIngressoEmpresa().ano << endl;
        cout << "Mês: " << gerentes[i].getIngressoEmpresa().mes << endl;
        cout << "Dia: " << gerentes[i].getIngressoEmpresa().dia << endl;
    }
    cout << endl << "#########################################################" << endl; 
}
void Empresa::imprimeDono(){
    cout << endl << "#########################################################" << endl; 
    cout << "##### DADOS PESSOAIS #####" << endl;
    cout << "Nome: " << dono->getNome() << endl;
    cout << "CPF: " << dono->getCpf() << endl;
    cout << "Número de filhos: " << dono->getQtdFilhos() << endl;
    cout << "Estado civil: " << dono->getEstavoCival() << endl;
    cout << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
    cout << "Cidade: " << dono->getEnderecoPessoal().cidade << endl;
    cout << "Cep: " << dono->getEnderecoPessoal().cep << endl;
    cout << "Bairro: " << dono->getEnderecoPessoal().bairro << endl;
    cout << "Rua: " << dono->getEnderecoPessoal().rua << endl;
    cout << "Número: " << dono->getEnderecoPessoal().numero << endl;
    cout << "***** Data de nascimento (ano, mes, dia) **** - Essa linha deve ser ignorada" << endl;
    cout << "Ano: " << dono->getDataNascimento().ano << endl;
    cout << "Mês: " << dono->getDataNascimento().mes << endl;
    cout << "Dia: " << dono->getDataNascimento().dia<< endl;
    cout << endl << "#########################################################" << endl; 
}
void Empresa::buscaFuncionario(string matricula){
    int encontrado = 0;
    cout << endl << "#########################################################" << endl; 
    for(int i = 0; i < asgs.size() && encontrado == 0; i++){
        if(asgs[i].getMatricula() == matricula){
            cout << "Funcionário encontrado" << endl;
            cout << "Nome:" << asgs[i].getNome() << endl;
            encontrado = 1;
            return;
        }
    }
    for(int i = 0; i < vendedores.size() && encontrado == 0; i++){
        if(vendedores[i].getMatricula() == matricula){
            cout << "Funcionário encontrado" << endl;
            cout << "Nome:" << vendedores[i].getNome() << endl;
            encontrado = 1;
            return;
        }
    }
    for(int i = 0; i < gerentes.size() && encontrado == 0; i++){
        if(gerentes[i].getMatricula() == matricula){
            cout << "Funcionário encontrado" << endl;
            cout << "Nome:" << gerentes[i].getNome() << endl;
            encontrado = 1;
            return;
        }
    }
    if(encontrado == 0){
        cout << "Funcionário não contrado" << endl;
    }
    cout << endl << "#########################################################" << endl; 
}
void Empresa::calculaSalarioFuncionario(string matricula){
    int encontrado = 0;
    cout << endl << "#########################################################" << endl; 
    for(int i = 0; i < asgs.size() && encontrado == 0; i++){
        if(asgs[i].getMatricula() == matricula){
            cout << "Nome:" << asgs[i].getNome() << endl;
            cout << "Salário: " << asgs[i].calcularSalario(asgs[i].getFaltas()) << endl;
            encontrado = 1;
        }
    }
    for(int i = 0; i < vendedores.size() && encontrado == 0; i++){
        if(vendedores[i].getMatricula() == matricula){
            cout << "Nome:" << vendedores[i].getNome() << endl;
            cout << "Salário: " << vendedores[i].calcularSalario(vendedores[i].getFaltas()) << endl;
            encontrado = 1;
        }
    }
    for(int i = 0; i < gerentes.size() && encontrado == 0; i++){
        if(gerentes[i].getMatricula() == matricula){
            cout << "Nome:" << gerentes[i].getNome() << endl;
            cout << "Salário: " << gerentes[i].calcularSalario(gerentes[i].getFaltas()) << endl;
            encontrado = 1;
        }
    }
    if(encontrado == 0){
        cout << "Funcionário não contrado" << endl;
    }
    cout << endl << "#########################################################" << endl; 
}
void Empresa::calculaTodosOsSalarios(){
    float totalSalarios = 0;
    cout << endl << "#########################################################" << endl; 

    cout << "***** ASGs ****" << endl;
    for(int i = 0; i < asgs.size(); i++){
        cout << "Nome:" << asgs[i].getNome() << endl;
        cout << "Salário: " << asgs[i].calcularSalario(asgs[i].getFaltas()) << endl;
        totalSalarios += asgs[i].calcularSalario(asgs[i].getFaltas());
    }

    cout << "***** Vendedores ****" << endl;
    for(int i = 0; i < vendedores.size(); i++){
        cout << "Nome:" << vendedores[i].getNome() << endl;
        cout << "Salário: " << vendedores[i].calcularSalario(vendedores[i].getFaltas()) << endl;
        totalSalarios += vendedores[i].calcularSalario(vendedores[i].getFaltas());
    }

    cout << "***** Gerentes ****" << endl;
    for(int i = 0; i < gerentes.size(); i++){
        cout << "Nome:" << gerentes[i].getNome() << endl;
        cout << "Salário: " << gerentes[i].calcularSalario(gerentes[i].getFaltas()) << endl;
        totalSalarios += gerentes[i].calcularSalario(gerentes[i].getFaltas());
    }

    cout << endl << "Total dos salários: " << totalSalarios << endl;
    cout << endl << "#########################################################" << endl; 
}
void Empresa::calculaRecisaoFuncionario(string matricula, Data desligamento){
    int encontrado = 0;
    cout << endl << "#########################################################" << endl; 
    for(int i = 0; i < asgs.size() && encontrado == 0; i++){
        if(asgs[i].getMatricula() == matricula){
            cout << "Nome:" << asgs[i].getNome() << endl;
            cout << "Valor da rescisão: " << asgs[i].calcularRecisao(desligamento) << endl;
            encontrado = 1;
        }
    }
    for(int i = 0; i < vendedores.size() && encontrado == 0; i++){
        if(vendedores[i].getMatricula() == matricula){
            cout << "Nome:" << vendedores[i].getNome() << endl;
            cout << "Valor da rescisão: " << vendedores[i].calcularRecisao(desligamento) << endl;
            encontrado = 1;
        }
    }
    for(int i = 0; i < gerentes.size() && encontrado == 0; i++){
        if(gerentes[i].getMatricula() == matricula){
            cout << "Nome:" << gerentes[i].getNome() << endl;
            cout << "Valor da rescisão: " << gerentes[i].calcularRecisao(desligamento) << endl;
            encontrado = 1;
        }
    }
    if(encontrado == 0){
        cout << "Funcionário não contrado" << endl;
    }
    cout << endl << "#########################################################" << endl; 
}