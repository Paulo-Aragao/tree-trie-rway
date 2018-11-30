/// *******************
/// *by @PauloCosmico *
/// *******************

#ifndef ARVORERWAY_HPP_INCLUDED
#define ARVORERWAY_HPP_INCLUDED
#include "No.hpp"

class ArvoreRWay{
private:
    No root;
    int tamanho_alf;
public:
    ArvoreRWay(){
		tamanho_alf = 128;
        root.criarFilhos(tamanho_alf);
    }
    void imprimir(bool first,No *no = nullptr,std::string palavra =""){//fun��o recursiva para imprimir o conteudo da arvore
        if(first){
            no = &root;
        }
        for(int i=0;i<tamanho_alf;i++){
            if(no->filhos[i].getChave() != '$' && no->filhos[i].getChave() != '\0'){
                palavra +=  no->filhos[i].getChave();
                imprimir(false,&no->filhos[i],palavra);
                palavra.pop_back();
            }
        }
        if(no->getFim()){
            std::cout<<"# "<<palavra<<std::endl;
        }
    }
    void adicionar(std::string palavra){
        No* pt = &root;
        int aux;
        if(buscar(palavra)){//se verdadeiro, j� finaliza a fun��o
            std::cout<<"palavra ja existente"<<std::endl;
            return;
        }
        for(int i=0;i<palavra.size();i++){//Verifica��o se a palavra possui algum caractere especial, se positivo, finaliza a fun��o
            aux = int(palavra[i]);
            if(palavra[i] != '\0' && aux <= 0){
                std::cout<<"palavra com simbolo nao reconhecido pela tabela ASCII"<<std::endl;
                return;
            }
        }
        aux = -1;
        for (int i=0; i<=palavra.size();i++){
            aux = int(palavra[i]);
            if(!pt->getFolha()){//verifica��o se o no � uma folha, se for, cria nos filhos
                    pt->criarFilhos(tamanho_alf);
            }
            if(!(palavra[i] == pt->filhos[aux].getChave())){//verifica��o o caractere � igual a chave do no, se n�o for ele passa para o proximo caractere e ao proximo nivel
                pt->filhos[aux].setChave(palavra[i]);
                pt->filhos[aux].setPai(pt);
                pt = &pt->filhos[aux];

            }else{//se chave for igual ao caractere selecionado, � passado ao proximo nivel
                pt = &pt->filhos[aux];
            }
            if(i+1 == palavra.size()){//verifica��o se a palavra est� em seu ultimo caractere, para setar o no como terminal
                pt->setFim(true);
            }
        }
        std::cout<<"palavra adicionada"<<std::endl;
    }
    bool buscar(std::string palavra){
        No *pt = &root;
        for (int i=0; i<palavra.size();i++){//intera sobre a arvore at� encontrar toda a palavra, ou n�o
            if(palavra[i] == pt->filhos[int(palavra[i])].getChave()){
                pt = &pt->filhos[int(palavra[i])];
            }else{
                return false;
            }
        }
        //ao final do ciclo � verificado se o no selecionado � terminal ou n�o, se for terminal a palavra est� contida
        if(pt->getFim()){
            return true;
        }else{
            return false;
        }

    }
    void remover(std::string palavra){
        No *pt = &root;
        bool fim = true;
        if(buscar(palavra)){
            for (int i=0; i<palavra.size();i++){//interando na arvore
                if(palavra[i] == pt->filhos[int(palavra[i])].getChave()){
                    pt = &pt->filhos[int(palavra[i])];
                }
            }
            while(fim){//la�o para remover o no selecionado, e se necessario seus antecessores(so se n�o forem terminais)
                if(pt->getChave()=='$'){
                    break;
                }
                for(int i=0;i<tamanho_alf;i++){
                    if(pt->filhos[i].getChave()!='$'){
                        fim = false;
                        break;
                    }
                }
                if(fim){
                    pt->setChave('$');
                    pt->setFolha(false);
                    delete[] pt->filhos;
                    pt = pt->getPai();
                }else{
                    pt->setFim(false);
                }
            }
        }else {
            std::cout<<"palavra nao foi encontrada"<<std::endl;
        }
    }
};

#endif // ARVORERWAY_HPP_INCLUDED
