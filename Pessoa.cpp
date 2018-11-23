/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include "Pessoa.h"

#include <cmath>
#include <stdexcept>

using namespace std;

double Pessoa::valorPorHoraPadrao = 10;

Pessoa::Pessoa(string nome, double valorPorHora, int horasDiarias)
    : Recurso(nome) {
    if (valorPorHora <= 0 || horasDiarias <= 0) {  //@
        throw new invalid_argument("");
    }

    this->valorPorHora = valorPorHora;
    this->usaValorPadrao = false; 
    this->horasDiarias = horasDiarias;
}

Pessoa::Pessoa(string nome, int horasDiarias) : Recurso(nome) {
    if (valorPorHoraPadrao <= 0 || horasDiarias <= 0) {  //@
        throw new invalid_argument("");
    }

    this->valorPorHora = Pessoa::valorPorHoraPadrao;
    this->usaValorPadrao = true; 
    this->horasDiarias = horasDiarias;
}

Pessoa::~Pessoa() {
    // Destrutor
}

double Pessoa::getValorPorHora() {
    if (usaValorPadrao) { 
        return valorPorHoraPadrao;
    } else {
        return valorPorHora;
    }
}

int Pessoa::getHorasDiarias() {
    return horasDiarias;
}

bool Pessoa::recebeValorPadrao() { 
    return usaValorPadrao;
}

void Pessoa::setValorPorHoraPadrao(double valor) {
    if (valor <= 0) {
        throw new invalid_argument("");
    }

    Pessoa::valorPorHoraPadrao = valor;
}

double Pessoa::getValorPorHoraPadrao() {
    return Pessoa::valorPorHoraPadrao;
}

double Pessoa::getCusto(int dias) {
    if (dias <= 0) {
        throw new invalid_argument("");
    }

    return (dias * horasDiarias * getValorPorHora());
}

void Pessoa::imprimir() {
    cout << "Pessoa: " << nome << " - R$" << getValorPorHora();
    cout << " - " << horasDiarias << "h por dia" << endl;
}
