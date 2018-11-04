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

#include "Pessoa.h"

using namespace std;

Pessoa::Pessoa(string nome, double valorPorHora, int horasDiarias) :
    nome(nome), valorPorHora(valorPorHora), horasDiarias(horasDiarias) {
}

Pessoa::~Pessoa() {
}

string Pessoa::getNome() {
    return nome;
}

double Pessoa::getValorPorHora() {
    return valorPorHora;
}

int Pessoa::getHorasDiarias() {
    return horasDiarias;
}

double Pessoa::getCusto(int dias) {
    double custo = dias*horasDiarias*valorPorHora;
    return custo;
}

void Pessoa::imprimir() {
    cout << nome << " - R$" << valorPorHora;
    cout << " - " << horasDiarias << "h por dia" << endl;
}
