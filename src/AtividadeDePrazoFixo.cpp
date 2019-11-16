/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include "AtividadeDePrazoFixo.h"

#include <stdexcept>

using namespace std;

AtividadeDePrazoFixo::AtividadeDePrazoFixo(string nome, int dias) : Atividade(nome) {
    if (dias <= 0) {
        throw new invalid_argument("");
    }
    this->dias = dias;
}

AtividadeDePrazoFixo::~AtividadeDePrazoFixo() {
    // Destrutor
}

int AtividadeDePrazoFixo::getPrazo() {
    return dias;
}

int AtividadeDePrazoFixo::getDuracao() {
    if (atividadeTerminada) {
        return duracaoReal;
    } else {
        return dias;
    }
}
