/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include "Recurso.h"

Recurso::Recurso(string nome) : nome(nome) {
}

Recurso::~Recurso() {
}

string Recurso::getNome() {
    return nome;
}
