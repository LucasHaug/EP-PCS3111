/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#ifndef _RECURSO_H_
#define _RECURSO_H_

#include <string>

using namespace std;

class Recurso {
    protected: //@
        string nome;

    public:
        Recurso(string nome);
        virtual ~Recurso();

        virtual string getNome();
        virtual double getCusto(int dias) = 0;
        virtual void imprimir() = 0;
};

#endif // _RECURSO_H_
