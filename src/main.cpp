/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include <cmath>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>

#include "Atividade.h"
#include "AtividadeDeEsforcoFixo.h"
#include "AtividadeDePrazoFixo.h"
#include "ErroDeArquivo.h"
#include "Ferramenta.h"
#include "PersistenciaDeProjeto.h"
#include "Pessoa.h"
#include "Projeto.h"

using namespace std;

int menuDeOpcoes();

void opcaoUm(Projeto* proj);

void opcaoDois(Projeto* proj);

void opcaoTres(Projeto* proj);

void opcaoCinco();

void opcaoSeis(Projeto* proj);

int main() {
    cout << "Deseja carregar um novo projeto (s/n)? ";
    char opcaoDeCarregar;
    cin >> opcaoDeCarregar;
    Projeto* proj;

    switch (opcaoDeCarregar) {
        case 's':
        case 'S': {
            cout << "Digite o nome do projeto: ";
            string nomeDoProjeto;
            cin >> nomeDoProjeto;
            proj = new Projeto(nomeDoProjeto);
            break;
        }
        case 'n':
        case 'N': {
            cout << "Digite o nome do arquivo: ";
            string nomeDoArquivo;
            cin >> nomeDoArquivo;
            PersistenciaDeProjeto* persist = new PersistenciaDeProjeto();
            try {
                proj = persist->carregar(nomeDoArquivo);
            } catch (ErroDeArquivo* e) {
                delete e;
                return 0;
            }
            break;
        }
    }

    int opcao;

    for (;;) {
        opcao = menuDeOpcoes();

        try {
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
            }
        } catch (overflow_error* e) {
            delete e;
            return 0;
        } catch (invalid_argument* e) {
            delete e;
            return 0;
        } catch (ErroDeArquivo* e) {
            delete e;
            return 0;
        } catch (logic_error* e) {
            delete e;
            return 0;
        }
    }
}

// apresenta o menu de opcoes iniciais
int menuDeOpcoes() {
    int opcao;

    cout << "1 - Adicionar recurso" << endl
         << "2 - Adicionar atividade" << endl
         << "3 - Terminar atividade" << endl
         << "4 - Imprimir projeto" << endl
         << "5 - Definir valor por hora padrao" << endl
         << "6 - Salvar" << endl
         << "0 - Sair" << endl;

    cout << "Escolha a opcao: ";
    cin >> opcao;

    return opcao;
}

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

            cout << "Valor por hora padrao (s/n)? ";
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
                int j = 1;
                for (auto& i : *(proj->getRecursos())) {
                    cout << j << " - ";
                    i->imprimir();
                    j++;
                }

                cout << endl << "Escolha um recurso ou 0 para cancelar: ";
                unsigned int opcaoDeAdicao;
                cin >> opcaoDeAdicao;

                // adiciona a pessoa se possivel e se nao for cancelado
                if (opcaoDeAdicao > 0 &&
                    opcaoDeAdicao <= proj->getRecursos()->size()) {
                    try {
                        Recurso* rec;
                        list<Recurso*>::iterator k =
                            proj->getRecursos()->begin();
                        advance(k, opcaoDeAdicao - 1);
                        rec = (*k);

                        a->adicionar(rec);
                    } catch (overflow_error* e) {
                        cout << "Nao foi possivel adicionar recurso" << endl;
                        delete e;
                        break;
                    } catch (invalid_argument* e) {
                        cout << "Nao foi possivel adicionar recurso" << endl;
                        delete e;
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

    return;
}

// Terminar atividade
void opcaoTres(Projeto* proj) {
    for (unsigned i = 0; i < proj->getAtividades()->size(); i++) {
        cout << i + 1 << " - " << proj->getAtividades()->at(i)->getNome()
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
    cout << "Valor atual: R$" << Pessoa::getValorPorHoraPadrao() << " por hora"
         << endl
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