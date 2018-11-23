/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include "Atividade.h"
#include "Pessoa.h"

#include <stdexcept>

using namespace std;

Atividade::Atividade(string nome) : nome(nome) {
    recursos = new Recurso*[MAXIMO_RECURSOS];
}

Atividade::~Atividade() {
    delete[] recursos;
}

string Atividade::getNome() {
    return nome;
}

void Atividade::adicionar(Recurso* r) {
    // verificas se o recurso ja esta na atividade
    bool estaNaAtividade = false;

    for (int i = 0; i < quantidadeDeRecursos && !estaNaAtividade; i++) {
        if (recursos[i] == r) {
            estaNaAtividade = true;
        }
    }

    if (quantidadeDeRecursos == MAXIMO_RECURSOS) {
        throw new overflow_error("");
    }

    if (estaNaAtividade) {
        throw new invalid_argument("");
    }

    // adiciona o recurso, caso seja possivel
    recursos[quantidadeDeRecursos] = r;
    quantidadeDeRecursos++;

    Pessoa* pessoaTemporaria = dynamic_cast<Pessoa*>(r);  //@
    if (pessoaTemporaria != nullptr) {
        horasDisponiveisPorDia += pessoaTemporaria->getHorasDiarias();
        quantidadeDePessoas++;
    }
    delete pessoaTemporaria;  //@
}

Recurso** Atividade::getRecurso() {
    return recursos;
}

int Atividade::getQuantidadeDeRecursos() {
    return quantidadeDeRecursos;
}

double Atividade::getCusto() {
    double custo = 0;
    int duracao = getDuracao();

    if (quantidadeDeRecursos > 0) {
        for (int i = 0; i < quantidadeDeRecursos; i++) {
            custo += recursos[i]->getCusto(duracao);
        }
        return custo;
    } else {
        return 0;
    }
}

void Atividade::terminar(int duracaoReal) {
    if (duracaoReal <= 0) {
        throw new invalid_argument("");
    }

    this->duracaoReal = duracaoReal;

    atividadeTerminada = true;
}

bool Atividade::estaTerminada() {
    return atividadeTerminada;
}

void Atividade::imprimir() {
    double custoAtividade = getCusto();
    int duracaoAtividade;
    duracaoAtividade = getDuracao();

    cout << nome << " - " << duracaoAtividade;
    cout << " dias - R$" << custoAtividade << endl;
}
