/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#ifndef _PERSISTENCIA_DE_PROJETO_H_
#define _PERSISTENCIA_DE_PROJETO_H_

#include "Projeto.h"

class PersistenciaDeProjeto {
    private: //@
    public:
    PersistenciaDeProjeto();
    virtual ~PersistenciaDeProjeto();

    Projeto* carregar(std::string arquivo);
    void salvar(Projeto* p, std::string arquivo);
};

#endif // _PERSISTENCIA_DE_PROJETO_H_
