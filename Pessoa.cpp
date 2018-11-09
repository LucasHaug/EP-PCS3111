/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include <cmath>
#include <stdexcept>

#include "Pessoa.h"

using namespace std;

double Pessoa::valorPorHoraPadrao = 10;

Pessoa::Pessoa(std::string nome, double valorPorHora, int horasDiarias)
    : Recurso(nome) {
    if (valorPorHora <= 0 || horasDiarias <= 0) {  //@
        throw new invalid_argument(
            "valorPorHora e horasDiarias devem ser ambos positivos");  //@
    } else {
        this->nome = nome;  //@
        this->valorPorHora = valorPorHora;
        this->usaValorPadrao = false;  //@
        this->horasDiarias = horasDiarias;
    }
}

Pessoa::Pessoa(std::string nome, int horasDiarias) : Recurso(nome) {
    if (valorPorHoraPadrao <= 0 || horasDiarias <= 0) {  //@
        throw new invalid_argument(
            "valorPorHora e horasDiarias devem ser ambos positivos");  //@
    } else {
        this->nome = nome;  //@
        this->valorPorHora = Pessoa::valorPorHoraPadrao;
        this->usaValorPadrao = true;  //@
        this->horasDiarias = horasDiarias;
    }
}

Pessoa::~Pessoa() {
    // Destrutor
}

double Pessoa::getValorPorHora() {
    return valorPorHora;
}

int Pessoa::getHorasDiarias() {
    return horasDiarias;
}

bool Pessoa::recebeValorPadrao() {  //@
    return usaValorPadrao;
}

void Pessoa::setValorPorHoraPadrao(double valor) {
    if (valor <= 0) {
        throw new invalid_argument(
            "valorPorHora e horasDiarias devem ser ambos positivos");  //@
    } else {
        Pessoa::valorPorHoraPadrao = valor;
    }
}

double Pessoa::getValorPorHoraPadrao() {
    return Pessoa::valorPorHoraPadrao;
}

double Pessoa::getCusto(int dias) {
    double custo = dias * horasDiarias * valorPorHora;
    return custo;
}

void Pessoa::imprimir() {
    cout << "Pessoa: " << nome << " - R$" << valorPorHora;
    cout << " - " << horasDiarias << "h por dia" << endl;
}
