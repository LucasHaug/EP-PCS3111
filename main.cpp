/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 1                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include <iostream>
#include <string>
#include <cmath>

#include "Pessoa.h"
#include "Atividade.h"
#include "Projeto.h"
#include "Tela.h"
#include "Cores.h"

using namespace std;

int main() {
    int opcao;
    string nomeDoProjeto;

    cout << endl << CDARKBLUE " Bem Vindo ao PoliTrello!" CRESET << endl;

    // obtem um nome e cria um projeto com ele
    cout << endl << " Digite o nome do projeto: " CBLUE;
    getline(cin, nomeDoProjeto);
    cout << CRESET;
    Projeto* proj = new Projeto(nomeDoProjeto);

    for(;;) {

        opcao = menuDeOpcoes();

        switch (opcao) {
            case 1:
                opcaoUm(proj);
                break;
            case 2:
                opcaoDois(proj);
                break;
            case 3:
                clear();
                proj->imprimir();
                aguardaEnter();
                break;
            case 0:
                cout << endl << CYELLOW " Ate mais " CRESET "(e obrigado pelos peixes)!" << endl << endl;
                aguardaEnter();
                delete proj;
                return 0;
            default:
                cout << endl << CRED " Digite uma opcao valida..." CRESET;
                aguardaEnter();
                break;
        }
    }
}

