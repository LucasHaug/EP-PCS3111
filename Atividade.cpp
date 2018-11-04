/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 1                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include <cmath>

#include "Atividade.h"
#include "Pessoa.h"

using namespace std;

Atividade::Atividade(string nome, int horasNecessarias) :
    nome(nome), horasNecessarias(horasNecessarias) {
    pessoas = new Pessoa*[MAXIMO_RECURSOS];
}

Atividade::~Atividade() {
    delete[] pessoas;
}

string Atividade::getNome() {
    return nome;
}

int Atividade::getHorasNecessarias() {
    return horasNecessarias;
}

bool Atividade::adicionar(Pessoa* recurso) {
    // verificas se a pessoa ja esta na atividade
    bool estaNaAtividade = false;

    for (int i = 0; i < quantidadeDePessoas && !estaNaAtividade; i++) {
        if (pessoas[i] == recurso) {
                estaNaAtividade = true;
        }
    }

    // adiciona o recurso, caso seja possivel
    if (quantidadeDePessoas < MAXIMO_RECURSOS && !estaNaAtividade) {
        pessoas[quantidadeDePessoas] = recurso;
        horasDisponiveisPorDia += recurso->getHorasDiarias();
        quantidadeDePessoas++;
        return true;
    }
    else {
        return false;
    }
}

Pessoa** Atividade::getPessoas() {
    return pessoas;
}

int Atividade::getQuantidadeDePessoas() {
    return quantidadeDePessoas;
}

int Atividade::getDuracao() {
    double duracao;

    if (quantidadeDePessoas != 0 && horasDisponiveisPorDia != 0) {
        duracao = (double) horasNecessarias/horasDisponiveisPorDia;
        return ceil(duracao);
    }
    // impede a divisao por zero
    else if (quantidadeDePessoas != 0 && horasDisponiveisPorDia == 0) {
        duracao = 0;
        return duracao;
    }
    else {
        return -1;
    }
}

double Atividade::getCusto() {
    double custo = 0;
    int duracao = getDuracao();

    if (quantidadeDePessoas != 0) {
        for (int i = 0; i < quantidadeDePessoas; i++) {
            custo += pessoas[i]->getCusto(duracao);
        }
        return custo;
    }
    else {
        return -1;
    }
}

void Atividade::imprimir() {
    int duracaoAtividade = getDuracao();
    double custoAtividade = getCusto();

    if (duracaoAtividade != -1 && custoAtividade != -1) {
        cout << " " << nome << " - " << duracaoAtividade;
        cout  << " dia(s) - R$" << custoAtividade << endl;
    }
    else {
        cout << " " << nome << " - " << " NAO HA INFORMCAO ";
        cout  << " dia(s) - R$" << " NAO HA INFORMCAO " << endl;
    }
}
