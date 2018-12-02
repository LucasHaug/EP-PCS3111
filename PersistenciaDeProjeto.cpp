/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include "PersistenciaDeProjeto.h"
#include "AtividadeDeEsforcoFixo.h"
#include "AtividadeDePrazoFixo.h"
#include "ErroDeArquivo.h"
#include "Ferramenta.h"
#include "Pessoa.h"

#include <fstream>

using namespace std; 

PersistenciaDeProjeto::PersistenciaDeProjeto() {
    // Construtor
}

PersistenciaDeProjeto::~PersistenciaDeProjeto() {
    // Destrutor
}

Projeto* PersistenciaDeProjeto::carregar(string arquivo) {
    ifstream entrada;
    entrada.open(arquivo);

    if (!entrada.good()) {
        throw new ErroDeArquivo("");
    }

    string nome;
    entrada >> nome;
    int numeroDeRecursos;
    entrada >> numeroDeRecursos;

    Projeto* p = new Projeto(nome);

    for (int i = 0; i < numeroDeRecursos; i++) {
        char tipoDeRecurso;
        entrada >> tipoDeRecurso;
        string nomeDoRecurso;
        entrada >> nomeDoRecurso;
        Recurso* r;

        if (tipoDeRecurso == 'P') {
            double valPorH;
            entrada >> valPorH;
            int hDiarias;
            entrada >> hDiarias;

            if (valPorH == -1) {
                r = new Pessoa(nomeDoRecurso, hDiarias);
            } else {
                r = new Pessoa(nomeDoRecurso, valPorH, hDiarias);
            }
        } else { // tipoDeRecurso == "F"
            double custoD;
            entrada >> custoD;
            
            r = new Ferramenta(nomeDoRecurso, custoD);

        }
            p->adicionar(r);
    }

    int numeroDeAtividades;
    entrada >> numeroDeAtividades;
    
    for (int i = 0; i < numeroDeAtividades; i++) {
        char tipoDeAtividade;
        entrada >> tipoDeAtividade;
        string nomeDaAtividade;
        entrada >> nomeDaAtividade;
        Atividade* a;

        if (tipoDeAtividade == 'E') {
            int hNecessarias;
            entrada >> hNecessarias;
            char ativTerminada;
            entrada >> ativTerminada;
            a = new AtividadeDeEsforcoFixo(nomeDaAtividade, hNecessarias);

            if (ativTerminada == 'T') {
                int duracao;
                entrada >> duracao;
                a->terminar(duracao);
            }

                p->adicionar(a);
        } else { // tipoDeAtividade == "P"
            int prazo;
            entrada >> prazo;
            char ativTerminada;
            entrada >> ativTerminada;
            a = new AtividadeDePrazoFixo(nomeDaAtividade, prazo);

            if (ativTerminada == 'T') {
                int duracao;
                entrada >> duracao;
                a->terminar(duracao);
            }

                p->adicionar(a);
        }

        int numeroDeRecNaAtiv;
        entrada >> numeroDeRecNaAtiv;

        for (int j = 0; j < numeroDeRecNaAtiv; j++) {
            string nomeDoRec;
            entrada >> nomeDoRec;

            list<Recurso*>::iterator k = p->getRecursos()->begin();
            while (k != p->getRecursos()->end()) {
                if ((*k)->getNome() == nomeDoRec) {
                    a->adicionar(*k);
                    break;
                }
                k++;
            }
        }
    }

    if (!entrada.good()) {
        throw new ErroDeArquivo("");
    }

    return p;
}

void PersistenciaDeProjeto::salvar(Projeto* p, string arquivo) {
    ofstream saida;
    saida.open(arquivo);

    if (!saida.good()) {
        throw new ErroDeArquivo("");
    }

    saida << p->getNome() << endl << p->getRecursos()->size() << endl;

    list<Recurso*>::iterator i = p->getRecursos()->begin();
    while (i != p->getRecursos()->end()) {
        Pessoa* pessoaTemporaria = dynamic_cast<Pessoa*>(*i);  
        if (pessoaTemporaria != nullptr) {
            saida << "P " << pessoaTemporaria->getNome() << " ";

            if (pessoaTemporaria->recebeValorPadrao()) {
                saida << "-1 ";
            } else {
                saida << pessoaTemporaria->getValorPorHora() << " ";
            }

            saida << pessoaTemporaria->getHorasDiarias() << endl;
        }

        Ferramenta* ferramentaTemporaria = dynamic_cast<Ferramenta*>(*i);  
        if (ferramentaTemporaria != nullptr) {
            saida << "F " << ferramentaTemporaria->getNome() << " "
                  << ferramentaTemporaria->getCustoDiario() << endl;
        }
        i++;
    }

    saida << p->getAtividades()->size() << endl;

    for (unsigned int i = 0; i < p->getAtividades()->size(); i++) {
        AtividadeDeEsforcoFixo* ativEFTemporaria =
            dynamic_cast<AtividadeDeEsforcoFixo*>(p->getAtividades()->at(i)); 
        if (ativEFTemporaria != nullptr) {
            saida << "E " << ativEFTemporaria->getNome() << " "
                  << ativEFTemporaria->getHorasNecessarias() << " ";

            if (ativEFTemporaria->estaTerminada()) {
                saida << "T " << ativEFTemporaria->getDuracao() << endl;
            } else {
                saida << "N " << endl;
            }

            saida << ativEFTemporaria->getQuantidadeDeRecursos() << endl;

            for (int i = 0; i < ativEFTemporaria->getQuantidadeDeRecursos(); i++) {
                saida << ativEFTemporaria->getRecursos()[i]->getNome() << " ";
            }
            saida << endl;
        }

        AtividadeDePrazoFixo* ativPFTemporaria =
            dynamic_cast<AtividadeDePrazoFixo*>(p->getAtividades()->at(i)); 
        if (ativPFTemporaria != nullptr) {
            saida << "P " << ativPFTemporaria->getNome() << " "
                  << ativPFTemporaria->getPrazo() << " ";

            if (ativPFTemporaria->estaTerminada()) {
                saida << "T " << ativPFTemporaria->getDuracao() << endl;
            } else {
                saida << "N " << endl;
            }

            saida << ativPFTemporaria->getQuantidadeDeRecursos() << endl;

            for (int i = 0; i < ativPFTemporaria->getQuantidadeDeRecursos(); i++) {
                saida << ativPFTemporaria->getRecursos()[i]->getNome() << " ";
            }
            saida << endl;
        }
    }
    saida << endl; 
}
