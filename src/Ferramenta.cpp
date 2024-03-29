/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include "Ferramenta.h"

#include <iostream>
#include <stdexcept>

using namespace std;

Ferramenta::Ferramenta(string nome, double custoDiario) : Recurso(nome) {
    if (custoDiario < 0) {
        throw new invalid_argument("");
    }
    
    this->custoDiario = custoDiario;
}

Ferramenta::~Ferramenta() {
    // Destrutor
}

double Ferramenta::getCustoDiario() {
    return custoDiario;
}

double Ferramenta::getCusto(int dias) {
    if (dias <= 0) {
        throw new invalid_argument("");
    }
    return (dias * custoDiario);
}

void Ferramenta::imprimir() {
    cout << "Ferramenta: " << nome << " - R$" << custoDiario << " por dia" << endl;
}