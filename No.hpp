/// *******************
/// *by @PauloCosmico *
/// *******************

#ifndef NO_HPP_INCLUDED
#define NO_HPP_INCLUDED
#include<iostream>
#include <string>

class No{
private:
    char chave='$';
    bool fim = false;
    No * pai;
    bool folha=false;//variavel para informar se o no tem filhos.
public:
    No *filhos;
public:
    No* getPai(){
        return pai;
    }
    void setPai(No* pai){
        this->pai = pai;
    }
    bool getFolha(){
        return folha;
    }
    void setFolha(bool folha){
        this->folha = folha;
    }
    char getChave(){
        return chave;
    }
    void setChave(char chave){
        this->chave = chave;
    }
    void setFim(bool fim){
        this->fim = fim;
    }
    bool getFim(){
        return fim;
    }
    void criarFilhos(int tam){//função para alocar os nos filhos de um no.
        filhos = new No[tam];
        folha = true;
    }
};


#endif // NO_HPP_INCLUDED
