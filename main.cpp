/// *******************
/// *by @PauloCosmico *
/// *******************
#include <stdlib.h>
#include "ArvoreRWay.hpp"

//O codigo stá configurado para ler textos em ASCII, pois é o padrão de c++
//Abaixo estão alguns testes da TAD
int main(){
    ArvoreRWay x = ArvoreRWay();//inicialização de um objeto ArvoreRWay.
    //escolhir palavras em inglês, pois usa a tabela ASCII
    //adiconando palavras que possuem o mesmo prefixo "run"
    char opcao;
    std::string s;
    std::string aux = "";
    while(true){
        std::cout<<"----------------------------------------------"<<std::endl;
        std::cout<<"------------------ESTRUTURAS------------------"<<std::endl;
        std::cout<<"----------------------DE----------------------"<<std::endl;
        std::cout<<"-------------- DADOS BASICAS II---------------"<<std::endl;
        std::cout<<"---------------ARVORE TRIE RWAY---------------"<<std::endl;
        std::cout<<"----------------------------------------------"<<std::endl<<std::endl<<std::endl;
        std::cout<<"->Escolha uma opcao              "<<std::endl<<std::endl<<std::endl;
        std::cout<<"1----------------------Adicionar palavra/frase"<<std::endl;
        std::cout<<"2------------------------------Remover palavra"<<std::endl;
        std::cout<<"3-------------------------------Buscar palavra"<<std::endl;
        std::cout<<"4----------------Imprimir palavras armazenadas"<<std::endl<<std::endl;
        std::cout<<"> ";
        std::cin>>opcao;
        std::cout<<"----------------------------------------------"<<std::endl;
        //tratamento com a variavel opcao de string para int deito para evitar erros com entradas erradas
        switch(int(opcao)){
            case 49:
                std::cout<<"Digite a palavra ou frase a ser adicionada"<<std::endl;
                std::cin.ignore (80, '\n');
                std::getline(std::cin,s);
                s +=' ';
                for(int i=0;i<s.size();i++){
                    aux += s[i];
                    if(s[i] == ' '){
                        aux.pop_back();
                        x.adicionar(aux);
                        aux = "";
                    }
                }
                break;
            case 50:
                std::cout<<"Digite a palavra a ser removida"<<std::endl;
                std::cin.ignore (80, '\n');
                std::getline(std::cin,s);
                x.remover(s);
                break;
            case 51:
                std::cout<<"Digite a palavra a ser removida"<<std::endl;
                std::cin.ignore (80, '\n');
                std::getline(std::cin,s);
                if(x.buscar(s)){
                    std::cout<<"Palavra encontrada"<<std::endl;
                }else{
                    std::cout<<"Palavra nao encontrada"<<std::endl;
                }
                break;
            case 52:
                x.imprimir(true);
                break;
            default:
               std::cout<<"Opcao invalida"<<std::endl;
        }
        std::cout<<std::endl;
        std::cout<<"pressione digite 0 e enter para voltar"<<std::endl;
        std::cin>>opcao;
        system("cls");
    }


}
