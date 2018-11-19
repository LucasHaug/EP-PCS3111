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

using namespace std;  //@

PersistenciaDeProjeto::PersistenciaDeProjeto() {
    // Construtor
}

PersistenciaDeProjeto::~PersistenciaDeProjeto() {
    // Destrutor
}

Projeto* PersistenciaDeProjeto::carregar(std::string arquivo) {
    ifstream entrada;
    entrada.open(arquivo);

    Projeto* p = new Projeto("");
    return p;
}

void PersistenciaDeProjeto::salvar(Projeto* p, std::string arquivo) {
    ofstream saida;
    saida.open(arquivo);

    if (!saida.good()) {
        throw new ErroDeArquivo("");
    }

    saida << p->getNome() << endl << p->getRecursos()->size() << endl;

    list<Recurso*>::iterator i = p->getRecursos()->begin();
    while (i != p->getRecursos()->end()) {                     //@ inclui o fim
        Pessoa* pessoaTemporaria = dynamic_cast<Pessoa*>(*i);  //@
        if (pessoaTemporaria != nullptr) {
            saida << "P " << pessoaTemporaria->getNome() << " ";

            if (pessoaTemporaria->recebeValorPadrao()) {
                saida << "-1 ";
            } else {
                saida << pessoaTemporaria->getValorPorHora() << " ";
            }

            saida << pessoaTemporaria->getHorasDiarias() << endl;
        }
        delete pessoaTemporaria;

        Ferramenta* ferramentaTemporaria = dynamic_cast<Ferramenta*>(*i);  //@
        if (ferramentaTemporaria != nullptr) {
            saida << "F " << ferramentaTemporaria->getNome() << " "
                  << ferramentaTemporaria->getCustoDiario() << endl;
        }
        delete ferramentaTemporaria;

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
                saida << ativEFTemporaria->getRecurso()[i]->getNome() << " ";
            }
            saida << endl;
        }
        delete ativEFTemporaria;

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
                saida << ativPFTemporaria->getRecurso()[i]->getNome() << " ";
            }
            saida << endl;
        }
        delete ativPFTemporaria;
    }
}
