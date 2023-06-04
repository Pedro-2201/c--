#include <iostream>

using namespace std;

class No{
    public:
    int valor;
    No *prox;
    No(){

    }
    No(int valor){
        this->valor = valor;
        this->prox = NULL;
    }

};

class ListaEncadeada{
    public:
    int tamanho = 0;
    No *head;

    ListaEncadeada(){}

    void push_front(int valor){
        if(tamanho > 0){
            No *no = new No(head->valor);
            no->prox = head->prox;
            head->valor = valor;
            head->prox = no;
        }else{
            head = new No(valor);
        }
        tamanho++;
    }

    void push_back(int valor){
        if(tamanho == 1){
            No *no = new No(valor);
            head->prox = no;
        }else if(tamanho > 1){
            No *aux = head;
            for(int i = 0; i < tamanho - 1; i++){
                aux = aux->prox;
            }
            No *no = new No(valor);
            aux->prox = no;
        }else{
            head = new No(valor);
        }
        tamanho++;
    }

    void pop_front(){
        if(tamanho > 0){
            head->valor = head->prox->valor;
            head->prox = head->prox->prox;
        }else{
            head->prox = NULL;
            head = NULL;
        }
        tamanho--;
    }


    void pop_back(){
        No *aux = head;
        for(int i = 0; i < tamanho - 2; i++){
            aux = aux->prox;
        }
        aux->prox = NULL;
    }

    void remove(int elemento){
        No *aux = head;
        for(int i = 0; i < tamanho - 1; i++){
            if(aux->valor == elemento){
                if(tamanho > 0){
                    head->valor = head->prox->valor;
                    head->prox = head->prox->prox;
                }else{
                    head->prox = NULL;
                    head = NULL;
                }
            }else if(aux->prox->valor == elemento){
                aux->prox = aux->prox->prox;
            }
        }
        tamanho--;
    }

    int sizeOf(){
        return tamanho;
    }

    bool find(int elemento){
        No *aux = head;
        for(int i = 0; i < tamanho; i++){
            if(aux->valor == elemento){
                return true;
            }
            aux = aux->prox;
        }
        return false;
    }

    void deleta(){
        head = NULL;
        tamanho = 0; 
    }

    void print(){
        No *aux = head;
        for(int i = 0; i < tamanho; i++){
            cout << aux->valor << endl;
            if(aux->prox != NULL && head != NULL){
                aux = aux->prox;
            }else{
                i = tamanho;
            }
        }
    }
};

int main(){
    ListaEncadeada *lista = new ListaEncadeada();
    lista->push_back(1);
    lista->push_back(2);
    lista->push_back(3);
    lista->push_back(4);
    lista->push_front(0);
    lista->print();
    cout << "Tamanho = " << lista->sizeOf() << endl;
    cout << "Procurando valor 4: " << lista->find(4) << endl;
    cout << "----" << endl;
    lista->pop_front();
    lista->pop_back();
    lista->remove(2);
    lista->print();
    lista->deleta();
    lista->print();
    return 0;
}