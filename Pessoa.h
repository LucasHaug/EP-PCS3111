/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#ifndef _PESSOA_H_
#define _PESSOA_H_

#include "Recurso.h"

#include <iostream>
#include <string>

class Pessoa : public Recurso {
   private:
    double valorPorHora = 0;
    int horasDiarias = 0;
    static double valorPorHoraPadrao;
    bool usaValorPadrao;  //@

   public:
    Pessoa(std::string nome, double valorPorHora, int horasDiarias);
    Pessoa(std::string nome, int horasDiarias);  //@
    virtual ~Pessoa();

    virtual double getValorPorHora();
    virtual int getHorasDiarias();
    virtual bool recebeValorPadrao();  //@

    static void setValorPorHoraPadrao(double valor);  //@
    static double getValorPorHoraPadrao();            //@

    double getCusto(int dias);
    void imprimir();
};

#endif  // _PESSOA_H_
