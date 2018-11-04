/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#ifndef _FERRAMENTA_H_
#define _FERRAMENTA_H_

#include <string>

using namespace std;

class Ferramenta : public Recurso {
    private: //@
        double custoDiario;

    public:
        Ferramenta(string nome, double custoDiario);
        virtual ~Ferramenta();

        virtual double getCustoDiario();

        double getCusto(int dias);
        void imprimir();
};

#endif // _FERRAMENTA_H_
