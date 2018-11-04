/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include <iostream>
#include <cmath>

#include "Projeto.h"
#include "Pessoa.h"

using namespace std;

Projeto::Projeto(string nome) :
    nome(nome) {
    pessoasNoProjeto = new Pessoa*[MAXIMO_RECURSOS];
    atividades = new Atividade*[MAXIMO_ATIVIDADES];
}

Projeto::~Projeto() {
    for (int i = 0; i < quantidadeDePessoasNoProjeto; i++) {
        delete pessoasNoProjeto[i];
    }
    delete[] pessoasNoProjeto;

    for (int i = 0; i < quantidadeDeAtividades; i++) {
        delete atividades[i];
    }
    delete[] atividades;
}

string Projeto::getNome() {
    return nome;
}

bool Projeto::adicionar(Atividade* a) {

    if (quantidadeDeAtividades < MAXIMO_ATIVIDADES) {
        atividades[quantidadeDeAtividades] = a;
        quantidadeDeAtividades++;
        return true;
    }
    else {
        return false;
    }
}

Atividade** Projeto::getAtividades() {
    return atividades;
}

int Projeto::getQuantidadeDeAtividades() {
    return quantidadeDeAtividades;
}

bool Projeto::adicionarRecurso(Pessoa* p) {
    // verificas se a pessoa ja esta na atividade
    bool estaNaAtividade = false;

    for (int i = 0; i < quantidadeDePessoasNoProjeto && !estaNaAtividade; i++) {
        if (pessoasNoProjeto[i] == p) {
                estaNaAtividade = true;
        }
    }

    // adiciona a pessoa, caso seja possivel
    if (quantidadeDePessoasNoProjeto < MAXIMO_RECURSOS && !estaNaAtividade) {
        pessoasNoProjeto[quantidadeDePessoasNoProjeto] = p;
        quantidadeDePessoasNoProjeto++;
        return true;
    }
    else {
        return false;
    }
}

Pessoa** Projeto::getPessoas() {
    return pessoasNoProjeto;
}

int Projeto::getQuantidadeDePessoas() {
    return quantidadeDePessoasNoProjeto;
}

int Projeto::getDuracao() {
    int duracao = 0;

    for (int i = 0; i < quantidadeDeAtividades; i++) {

        int duracaoAtividade = atividades[i]->getDuracao();

        // soma a duracao da atividade na do projeto,
        // caso ela seja diferente de -1
        if (duracaoAtividade != -1) {
            duracao += duracaoAtividade;
        }
        else {
            duracao += 0;
        }
    }
    return duracao;
}

double Projeto::getCusto() {
    double custo = 0;

    for (int i = 0; i < quantidadeDeAtividades; i++) {

        double custoAtividade = atividades[i]->getCusto();

        // soma o custo da atividade no do projeto, caso ele
        // seja um valor positivo ou 0 (diferente de -1)
        if (custoAtividade >= 0) {
            custo += custoAtividade;
        }
        else {
            custo += 0;
        }
    }
    return custo;
}

void Projeto::imprimir() {
    cout << endl << " " << nome << " - " << getDuracao();
    cout << " dia(s) - R$" << getCusto() << endl;
    cout << endl << " ----" << endl << endl;

    if (quantidadeDeAtividades > 0) {
        for (int i = 0; i < quantidadeDeAtividades; i++) {
            atividades[i]->imprimir();
        }
    }
    else {
        cout << " NAO HA ATIVIDADES NO PROJETO";
    }
}