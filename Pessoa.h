/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 1                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#ifndef _PESSOA_H_
#define _PESSOA_H_

#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
    private:
        string nome = nullptr;
        double valorPorHora = 0;
        int horasDiarias = 0;

    public:
        Pessoa(string nome, double valorPorHora, int horasDiarias);
        ~Pessoa();

        string getNome();
        double getValorPorHora();
        int getHorasDiarias();
        double getCusto(int dias);

        void imprimir();
};

#endif // _PESSOA_H_
