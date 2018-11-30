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
    void imprimir(bool first,No *no = nullptr,std::string palavra =""){//função recursiva para imprimir o conteudo da arvore
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
        if(buscar(palavra)){//se verdadeiro, já finaliza a função
            std::cout<<"palavra ja existente"<<std::endl;
            return;
        }
        for(int i=0;i<palavra.size();i++){//Verificação se a palavra possui algum caractere especial, se positivo, finaliza a função
            aux = int(palavra[i]);
            if(palavra[i] != '\0' && aux <= 0){
                std::cout<<"palavra com simbolo nao reconhecido pela tabela ASCII"<<std::endl;
                return;
            }
        }
        aux = -1;
        for (int i=0; i<=palavra.size();i++){
            aux = int(palavra[i]);
            if(!pt->getFolha()){//verificação se o no é uma folha, se for, cria nos filhos
                    pt->criarFilhos(tamanho_alf);
            }
            if(!(palavra[i] == pt->filhos[aux].getChave())){//verificação o caractere é igual a chave do no, se não for ele passa para o proximo caractere e ao proximo nivel
                pt->filhos[aux].setChave(palavra[i]);
                pt->filhos[aux].setPai(pt);
                pt = &pt->filhos[aux];

            }else{//se chave for igual ao caractere selecionado, é passado ao proximo nivel
                pt = &pt->filhos[aux];
            }
            if(i+1 == palavra.size()){//verificação se a palavra está em seu ultimo caractere, para setar o no como terminal
                pt->setFim(true);
            }
        }
        std::cout<<"palavra adicionada"<<std::endl;
    }
    bool buscar(std::string palavra){
        No *pt = &root;
        for (int i=0; i<palavra.size();i++){//intera sobre a arvore até encontrar toda a palavra, ou não
            if(palavra[i] == pt->filhos[int(palavra[i])].getChave()){
                pt = &pt->filhos[int(palavra[i])];
            }else{
                return false;
            }
        }
        //ao final do ciclo é verificado se o no selecionado é terminal ou não, se for terminal a palavra está contida
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
            while(fim){//laço para remover o no selecionado, e se necessario seus antecessores(so se não forem terminais)
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
