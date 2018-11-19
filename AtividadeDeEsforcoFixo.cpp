/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include "AtividadeDeEsforcoFixo.h"

#include <stdexcept>
#include <cmath>

using namespace std;

AtividadeDeEsforcoFixo::AtividadeDeEsforcoFixo(string nome, int horasNecessarias) : Atividade(nome) {
    if (horasNecessarias <= 0) {
        throw new invalid_argument(""); //@
    }
    this->nome = nome; //@
    this->horasNecessarias = horasNecessarias;
}

AtividadeDeEsforcoFixo::~AtividadeDeEsforcoFixo() {
    // Destrutor
}

int AtividadeDeEsforcoFixo::getHorasNecessarias() {
    return horasNecessarias;
}

int AtividadeDeEsforcoFixo::getDuracao() {
    double duracao;

    if (atividadeTerminada) { 
        return duracaoReal;
    }

    if (quantidadeDePessoas == 0) {
        throw new logic_error("");
    }

    if (horasDisponiveisPorDia > 0) {
        duracao = (double)horasNecessarias / horasDisponiveisPorDia;
        return ceil(duracao);
    }
    // impede a divisao por zero
    else {
        duracao = 0;
        return duracao;
    }
}