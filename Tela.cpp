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

// para <streamsize>
#include <ios>

// para numeric_limits
#include <limits>

#include "Tela.h"
#include "Pessoa.h"
#include "Atividade.h"
#include "Projeto.h"
#include "Cores.h"

using namespace std;

// limpa a tela do terminal
void clear() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif // _WIN32
}

// utilizada para aguardar o usuario pressionar enter
void aguardaEnter() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (cin.get() != '\n');
}

// apresenta o menu de opcoes iniciais
int menuDeOpcoes() {
    int opcao;

    clear();

    cout << endl
        << " 1 - Adicionar pessoa" << endl
        << " 2 - Adicionar atividade" << endl
        << " 3 - Imprimir projeto" << endl
        << " 0 - Sair" << endl;

    cout << endl << " Escolha a opcao: ";
    cin >> opcao;

    // caso a entrada seja valida
    if (cin.good()) {
        return opcao;
    }
    // retorna um valor invalido do switch/case
    else {
        return 42;
    }
}

// apresenta a interface com o usuario,
// caso ele tenha escolhido a opcao um
void opcaoUm(Projeto* proj) {
    string nome;
    double valorPorHora;
    int horasDiarias;

    clear();

    cout << endl << " Adicionar Pessoa:" << endl << endl;

    // obtem as informacoes da pessoa
    cout << " Nome: " CBLUE;
    cin.ignore(100, '\n');
    getline(cin, nome);
    cout << CRESET " Valor por hora (em R$): " CPINK;
    cin >> valorPorHora;
    cout << CRESET " Horas diarias: " CGREEN;
    cin >> horasDiarias;
    cout << CRESET;

    // cria uma nova pessoa
    Pessoa* p = new Pessoa(nome, valorPorHora, horasDiarias);

    // adiciona a pessoa ao projeto, caso seja possivel
    if (proj->adicionarRecurso(p) == true) {
        cout << endl << " " CBLUE << nome << CRESET " foi adicionado(a) ao projeto." << endl;
        aguardaEnter();
    }
    else {
        cout << endl << CRED " Nao foi possivel adicionar " << nome << CRESET " ao projeto." << endl;
        aguardaEnter();
    }

    return;
}

// apresenta a interface com o usuario,
// caso ele tenha escolhido a opcao dois
void opcaoDois(Projeto* proj) {
    string nome;
    int horasNecessarias;

    clear();

    cout << endl << " Adicionar Atividade:" << endl << endl;

    // obtem as informacoes da atividade
    cout << " Nome: " CBLUE;
    cin.ignore(100, '\n');
    getline(cin, nome);
    cout << CRESET " Horas necessarias: " CYELLOW;
    cin >> horasNecessarias;
    cout << CRESET;

    // cria uma nova atividade
    Atividade* a = new Atividade(nome, horasNecessarias);

    // adiciona a atividade ao projeto, caso possivel
    if (proj->adicionar(a) == true) {
        cout << endl << CGREEN " A atividade " << nome <<
            " foi adicionada ao projeto." CRESET << endl;
        aguardaEnter();

        // adiciona recursos a atividade, se o usuario optar e caso possivel
        for (;;) {
            char opcaoDeRecurso;

            clear();
            cout << endl << " Atividade " CDARKBLUE << nome << CRESET ":" << endl;
            // cout << endl << " Quantidade atual de recursos: "  << a->getQuantidadeDePessoas() << endl;
            cout << endl << " Deseja adicionar um recurso (s/n)? ";
            cin >> opcaoDeRecurso;
            clear();

            switch (opcaoDeRecurso) {
                case 's':
                case 'S': {
                    int opcaoDeAdicao;
                    Pessoa** p = proj->getPessoas();
                    int quantidadeDePessoasNoProjeto = proj->getQuantidadeDePessoas();

                    cout << endl << " Adicionar recursos a atividade " << nome << endl << endl;

                    // mostra as opcoes de recursos disponiveis
                    for (int i = 0; i < quantidadeDePessoasNoProjeto; i++) {
                        cout << " " << i + 1 << " - ";
                        p[i]->imprimir();
                    }

                    cout << endl << " Escolha uma pessoa ou 0 para cancelar: ";
                    cin >> opcaoDeAdicao;

                    // adiciona a pessoa se possivel e se nao for cancelado
                    if (opcaoDeAdicao > 0 && opcaoDeAdicao <= quantidadeDePessoasNoProjeto) {
                        if (a->adicionar(p[opcaoDeAdicao - 1]) == true) {
                            cout << endl << " " CGREEN << p[opcaoDeAdicao - 1]->getNome()
                             << " foi adicionado(a) a atividade." CRESET << endl;
                             aguardaEnter();
                        }
                        else {
                            cout << endl << CRED " Nao foi possivel adicionar "
                            << p[opcaoDeAdicao - 1]->getNome()
                            << " a atividade." CRESET << endl;
                            aguardaEnter();
                        }
                    }
                    break;
                }
                case 'n':
                case 'N': {
                    return;
                }
                default:
                    cout << endl << CRED " Digite uma opcao valida..." CRESET;
                    aguardaEnter();
                    break;
            }
        }
    }
    else {
        cout << CRED " Nao eh possivel adicionar uma nova atividade." CRESET << endl;
        aguardaEnter();
    }
}