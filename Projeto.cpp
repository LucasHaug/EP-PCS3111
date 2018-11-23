/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include "Projeto.h"
#include "Pessoa.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

Projeto::Projeto(string nome) : nome(nome) {
    atividades = new vector<Atividade*>();     //@
    recursosNoProjeto = new list<Recurso*>();  //@ 
}

Projeto::~Projeto() {
    for (unsigned int i = 0; i < atividades->size(); i++) {
        delete atividades->at(i);  //@
    }
    delete[] atividades;

    list<Recurso*>::iterator i = recursosNoProjeto->begin();
    while (i != recursosNoProjeto->end()) {
        delete *i;  //@ iterador
        i++;
    }
    delete[] recursosNoProjeto;  //@
}

string Projeto::getNome() {
    return nome;
}

void Projeto::adicionar(Atividade* a) {
    getAtividades()->push_back(a);
}

vector<Atividade*>* Projeto::getAtividades() {
    return atividades;
}

void Projeto::adicionar(Recurso* r) {
    // verifica se a pessoa ja esta na atividade
    bool estaNoProjeto = false;

    list<Recurso*>::iterator i = recursosNoProjeto->begin();
    while (i != recursosNoProjeto->end()) {
        if (*i == r) {  //@ iterador
            estaNoProjeto = true;
        }
        i++;
    }

    if (estaNoProjeto) {
        throw new invalid_argument("");
    }

    // adiciona a pessoa, caso seja possivel
    getRecursos()->push_back(r);  //@
}

list<Recurso*>* Projeto::getRecursos() {
    return recursosNoProjeto;
}

int Projeto::getDuracao() {
    int duracao = 0;

    for (unsigned int i = 0; i < atividades->size(); i++) {
        int duracaoAtividade = atividades->at(i)->getDuracao();
        duracao += duracaoAtividade;
    }
    return duracao;
}

int Projeto::getDuracao(bool terminadas) {
    int duracao = 0;

    for (unsigned int i = 0; i < atividades->size(); i++) {
        int duracaoAtividade = atividades->at(i)->getDuracao();

        if (atividades->at(i)->estaTerminada() == terminadas) {
            duracao += duracaoAtividade;
        }
    }
    return duracao;
}

double Projeto::getCusto() {
    double custo = 0;

    for (unsigned int i = 0; i < atividades->size(); i++) {
        double custoAtividade = atividades->at(i)->getCusto();
        custo += custoAtividade;
    }
    return custo;
}

void Projeto::imprimir() {
    cout << getNome() << " - R$" << getCusto() << endl
         << "Duracao:" << endl
         << "- Feito " << getDuracao(true) << " dias" << endl
         << "- Falta " << getDuracao(false) << " dias" << endl
         << "- Total " << getDuracao() << " dias" << endl
         << "----" << endl;

    for (unsigned int i = 0; i < atividades->size(); i++) {
        atividades->at(i)->imprimir();
    }
}