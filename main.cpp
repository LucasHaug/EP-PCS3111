/** : std::stringtringg*******************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

// para <streamsize>
#include <ios>

// para numeric_limits
#include <limits>

#include "Pessoa.h"
#include "Atividade.h"
#include "Projeto.h"
#include "PersistenciaDeProjeto.h"
#include "Ferramenta.h"
#include "AtividadeDeEsforcoFixo.h"
#include "AtividadeDePrazoFixo.h"

#include "ErroDeArquivo.h" //@

using namespace std;

// apresenta o menu de opcoes iniciais
int menuDeOpcoes();

// apresenta a interface com o usuario,
// caso ele tenha escolhido a opcao um
void opcaoUm(Projeto *proj);

// apresenta a interface com o usuario,
// caso ele tenha escolhido a opcao dois
void opcaoDois(Projeto *proj);

void opcaoTres(Projeto *proj);

void opcaoCinco();

void opcaoSeis(Projeto *proj);

int main() {
    cout << "Deseja carregar um novo projeto (s/n)?";
    char opcaoDeCarregar;
    cin >> opcaoDeCarregar;
    Projeto* proj;

    switch (opcaoDeCarregar) {
        case 's':
        case 'S': {
            cout << endl << "Digite o nome do projeto: ";
            string nomeDoProjeto;
            cin >> nomeDoProjeto;
            proj = new Projeto(nomeDoProjeto);
            break;
        }
        case 'n':
        case 'N': {
            cout << "Digite o nome do arquivo:";
            string nomeDoArquivo;
            cin >> nomeDoArquivo;
            PersistenciaDeProjeto* persist = new PersistenciaDeProjeto();
            proj = persist->carregar(nomeDoArquivo);
            break;
        }
    }

    int opcao;

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
                opcaoTres(proj);
                break;
            case 4:
                proj->imprimir();
                break;
            case 5:
                opcaoCinco();
                break;
            case 6:
                opcaoSeis(proj);
                break;
            case 0:
                delete proj;
                return 0;
            default:
                cout << endl << " Digite uma opcao valida..." << endl; //@
                break;
        }
    }
}

// apresenta o menu de opcoes iniciais
int menuDeOpcoes() {
    int opcao;

    cout << endl //@
         << "1 - Adicionar recurso" << endl
         << "2 - Adicionar atividade" << endl
         << "3 - Terminar atividade" << endl
         << "4 - Imprimir projeto" << endl
         << "5 - Definir valor por hora padrao" << endl
         << "6 - Salvar" << endl
         << "0 - Sair" << endl;

    cout << "Escolha a opcao: ";
    cin >> opcao;

    // caso a entrada seja valida
    if (cin.good()) {
        return opcao;
    }
    // retorna um valor invalido do switch/case
    else {
        return 42; //@
    }
}

// void opcaoUm(Projeto* proj) {
//     std::string nome;
//     double valorPorHora;
//     int horasDiarias;

//     cout << endl << " Adicionar Pessoa:" << endl << endl;

//     // obtem as informacoes da pessoa
//     cout << " Nome: ";
//     cin.ignore(100, '\n');
//     getline(cin, nome);
//     cout << " Valor por hora (em R$): ";
//     cin >> valorPorHora;
//     cout << " Horas diarias: ";
//     cin >> horasDiarias;

//     // cria uma nova pessoa
//     Pessoa* p = new Pessoa(nome, valorPorHora, horasDiarias);

//     // adiciona a pessoa ao projeto, caso seja possivel
//     if (proj->adicionarRecurso(p) == true) {
//         // cout << endl << " " << nome << " foi adicionado(a) ao projeto." << endl;
//     }
//     else {
//         cout << endl << " " << "Nao foi possivel adicionar " << nome << " ao projeto." << endl;
//     }
//     return;
// }

// void opcaoDois(Projeto* proj) {
//     std::string nome;
//     int horasNecessarias;

//     cout << endl << " Adicionar Atividade:" << endl << endl;

//     // obtem as informacoes da atividade
//     cout << " Nome: ";
//     cin.ignore(100, '\n');
//     getline(cin, nome);
//     cout << " Horas necessarias: ";
//     cin >> horasNecessarias;

//     // cria uma nova atividade
//     Atividade* a = new Atividade(nome, horasNecessarias);

//     // adiciona a atividade ao projeto, caso possivel
//     if (proj->adicionar(a) == true) {
//         // cout << endl << " A atividade " << nome <<
//         //     " foi adicionada ao projeto." << endl;

//         // adiciona recursos a atividade, se o usuario optar e caso possivel
//         for (;;) {
//             char opcaoDeRecurso;

//             cout << endl << " Atividade " << nome << ":" << endl;
//             cout << endl << " Deseja adicionar um recurso (s/n)? ";
//             cin >> opcaoDeRecurso;

//             switch (opcaoDeRecurso) {
//                 case 's':
//                 case 'S': {
//                     int opcaoDeAdicao;
//                     Pessoa** p = proj->getPessoas();
//                     int quantidadeDePessoasNoProjeto = proj->getQuantidadeDePessoas();

//                     cout << endl << " Adicionar recursos a atividade " << nome << endl << endl;

//                     // mostra as opcoes de recursos disponiveis
//                     for (int i = 0; i < quantidadeDePessoasNoProjeto; i++) {
//                         cout << " " << i + 1 << " - ";
//                         p[i]->imprimir();
//                     }

//                     cout << endl << " Escolha uma pessoa ou 0 para cancelar: ";
//                     cin >> opcaoDeAdicao;

//                     // adiciona a pessoa se possivel e se nao for cancelado
//                     if (opcaoDeAdicao > 0 && opcaoDeAdicao <= quantidadeDePessoasNoProjeto) {
//                         if (a->adicionar(p[opcaoDeAdicao - 1]) == true) {
//                             // cout << endl << " " << p[opcaoDeAdicao - 1]->getNome()
//                             //  << " foi adicionado(a) a atividade." << endl;
//                         }
//                         else {
//                             cout << endl << " " << "Nao foi possivel adicionar "
//                             << p[opcaoDeAdicao - 1]->getNome()
//                             << " a atividade." << endl;
//                         }
//                     }
//                     break;
//                 }
//                 case 'n':
//                 case 'N': {
//                     return;
//                 }
//                 default:
//                     cout << endl << " Digite uma opcao valida..." << endl;
//                     break;
//             }
//         }
//     }
//     else {
//         cout << " Nao eh possivel adicionar uma nova atividade." << endl;
//     }
// }

// Adicionar recurso
void opcaoUm(Projeto* proj) {
    cout << "Ferramenta (f) ou Pessoa (p): ";
    char opcaoDeTipoDeRecurso;
    cin >> opcaoDeTipoDeRecurso;

    Recurso* rec;

    switch (opcaoDeTipoDeRecurso) {
        case 'f': {
            cout << "Nome: ";
            string nomeFerramenta;
            cin >> nomeFerramenta;
            
            cout << "Custo diario: ";
            double custoDiario;
            cin >> custoDiario;

            rec = new Ferramenta(nomeFerramenta, custoDiario);
            break;
        }
        case 'p': {
            cout << "Nome: ";
            string nomeDaPessoa;
            cin >> nomeDaPessoa;

            cout << "Horas diarias: ";
            int horasDiarias;
            cin >> horasDiarias;

            cout << "Valor por hora padrao (s/n)?";
            char querValorPadrao;
            cin >> querValorPadrao;
            switch (querValorPadrao) {
                case 's':
                case 'S': {
                    rec = new Pessoa(nomeDaPessoa, horasDiarias);
                    break;
                }
                case 'n':
                case 'N': {
                    cout << "Valor por hora (em R$): ";
                    double valPHOras;
                    cin >> valPHOras;

                    rec = new Pessoa(nomeDaPessoa, valPHOras, horasDiarias);
                    break;
                }
            }

            break;
        }
    }

    //@ exceção
    proj->adicionar(rec);

    return;
}

// Adicionar atividade
void opcaoDois(Projeto* proj) {
    cout << "Nome: ";
    string nomeDaAtividade;
    cin >> nomeDaAtividade;

    cout << "Prazo fixo (p) ou trabalho fixo (t)? ";
    char opcaoDeTipoAtividade;
    cin >> opcaoDeTipoAtividade;

    Atividade* a;

    switch (opcaoDeTipoAtividade) {
        case 'p': {
            cout << "Dias necessarios: ";
            int diasNecessarios;
            cin >> diasNecessarios;

            a = new AtividadeDePrazoFixo(nomeDaAtividade, diasNecessarios);
            
            break;
        }
        case 't': {
            cout << "Horas necessarias: ";
            int horasNecessarias;
            cin >> horasNecessarias;

            a = new AtividadeDeEsforcoFixo(nomeDaAtividade, horasNecessarias);

            break;
        }
    }
    proj->adicionar(a);

    for (;;) {
        cout << "Deseja adicionar um recurso (s/n)? ";
        char opcaoDeRecurso;
        cin >> opcaoDeRecurso;

        switch (opcaoDeRecurso) {
            case 's':
            case 'S': {
                // mostra as opcoes de recursos disponiveis
                list<Recurso*>::iterator i = proj->getRecursos()->begin();
                while (i != proj->getRecursos()->end()) {
                    int j = 1; //@ usar j//@ inicializar j aqui
                    cout << j << " - ";
                    (*i)->imprimir();
                    j++;
                }

                cout << endl << "Escolha um recurso ou 0 para cancelar: ";
                unsigned int opcaoDeAdicao;
                cin >> opcaoDeAdicao;

                // adiciona a pessoa se possivel e se nao for cancelado
                if (opcaoDeAdicao > 0 && opcaoDeAdicao <= proj->getRecursos()->size()) {
                    try {
                        Recurso* rec;
                        i = proj->getRecursos()->begin();
                        for (unsigned int i = 1; i < opcaoDeAdicao; i++) { //@
                            i++; 
                        }
                        rec = (*i);
                        a->adicionar(rec);
                    } catch (overflow_error *e) {
                        cout << "Nao foi possivel adicionar recurso";
                        break;
                    } catch (invalid_argument *e) {
                        cout << "Nao foi possivel adicionar recurso";
                        break;
                    }
                }
                break;
            }
            case 'n':
            case 'N': {
                return;
            }
        }
    }
    //@ exceção

    return;
}

// Terminar atividade
void opcaoTres(Projeto* proj) {
    for (unsigned i = 0; i < proj->getAtividades()->size(); i++) {
        cout <<  i + 1 << " - " 
             << proj->getAtividades()->at(i)->getNome()
             << endl;
    }
    cout << "Escolha uma atividade ou 0 para cancelar: ";
    int numeroDaAtividade;
    cin >> numeroDaAtividade;
    numeroDaAtividade -= 1;

    if (proj->getAtividades()->at(numeroDaAtividade)->estaTerminada()) {
        cout << "Ativadade ja terminada";
    } else {
        cout << "Duracao real: ";
        int duracaoReal;
        cin >> duracaoReal;
        proj->getAtividades()->at(numeroDaAtividade)->terminar(duracaoReal);
    }
    return;
}

// Definir valor por hora padrao
void opcaoCinco() {
    cout << "Valor atual: R$" << Pessoa::getValorPorHoraPadrao() 
         << " por hora" << endl
         << "Novo valor: ";
    
    double novoValorPadrao;
    cin >> novoValorPadrao;
    Pessoa::setValorPorHoraPadrao(novoValorPadrao);
    return;
}

// Salvar
void opcaoSeis(Projeto* proj) {
    cout << "Nome do arquivo: ";
    string nomeArquivo;
    cin >> nomeArquivo;
    PersistenciaDeProjeto* persist = new PersistenciaDeProjeto();
    persist->salvar(proj, nomeArquivo); 
    return;
}