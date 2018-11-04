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

// para <streamsize>
#include <ios>

// para numeric_limits
#include <limits>

#include "Pessoa.h"
#include "Atividade.h"
#include "Projeto.h"

using namespace std;

// apresenta o menu de opcoes iniciais
int menuDeOpcoes();

// apresenta a interface com o usuario,
// caso ele tenha escolhido a opcao um
void opcaoUm(Projeto *proj);

// apresenta a interface com o usuario,
// caso ele tenha escolhido a opcao dois
void opcaoDois(Projeto *proj);

int main() {
    int opcao;
    string nomeDoProjeto;

    cout << endl << " Bem Vindo ao PoliTrello!" << endl;

    // obtem um nome e cria um projeto com ele
    cout << endl << " Digite o nome do projeto: ";
    getline(cin, nomeDoProjeto);
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
                proj->imprimir();
                break;
            case 0:
                cout << endl << " Ate mais (e obrigado pelos peixes)!" << endl << endl;
                delete proj;
                return 0;
            default:
                cout << endl << " Digite uma opcao valida..." << endl;
                break;
        }
    }
}

// apresenta o menu de opcoes iniciais
int menuDeOpcoes() {
    int opcao;

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

    cout << endl << " Adicionar Pessoa:" << endl << endl;

    // obtem as informacoes da pessoa
    cout << " Nome: ";
    cin.ignore(100, '\n');
    getline(cin, nome);
    cout << " Valor por hora (em R$): ";
    cin >> valorPorHora;
    cout << " Horas diarias: ";
    cin >> horasDiarias;

    // cria uma nova pessoa
    Pessoa* p = new Pessoa(nome, valorPorHora, horasDiarias);

    // adiciona a pessoa ao projeto, caso seja possivel
    if (proj->adicionarRecurso(p) == true) {
        // cout << endl << " " << nome << " foi adicionado(a) ao projeto." << endl;
    }
    else {
        cout << endl << " " << "Nao foi possivel adicionar " << nome << " ao projeto." << endl;
    }
    return;
}

// apresenta a interface com o usuario,
// caso ele tenha escolhido a opcao dois
void opcaoDois(Projeto* proj) {
    string nome;
    int horasNecessarias;

    cout << endl << " Adicionar Atividade:" << endl << endl;

    // obtem as informacoes da atividade
    cout << " Nome: ";
    cin.ignore(100, '\n');
    getline(cin, nome);
    cout << " Horas necessarias: ";
    cin >> horasNecessarias;

    // cria uma nova atividade
    Atividade* a = new Atividade(nome, horasNecessarias);

    // adiciona a atividade ao projeto, caso possivel
    if (proj->adicionar(a) == true) {
        // cout << endl << " A atividade " << nome <<
        //     " foi adicionada ao projeto." << endl;

        // adiciona recursos a atividade, se o usuario optar e caso possivel
        for (;;) {
            char opcaoDeRecurso;

            cout << endl << " Atividade " << nome << ":" << endl;
            cout << endl << " Deseja adicionar um recurso (s/n)? ";
            cin >> opcaoDeRecurso;

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
                            // cout << endl << " " << p[opcaoDeAdicao - 1]->getNome()
                            //  << " foi adicionado(a) a atividade." << endl;
                        }
                        else {
                            cout << endl << " " << "Nao foi possivel adicionar "
                            << p[opcaoDeAdicao - 1]->getNome()
                            << " a atividade." << endl;
                        }
                    }
                    break;
                }
                case 'n':
                case 'N': {
                    return;
                }
                default:
                    cout << endl << " Digite uma opcao valida..." << endl;
                    break;
            }
        }
    }
    else {
        cout << " Nao eh possivel adicionar uma nova atividade." << endl;
    }
}
