/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#ifndef _ATIVIDADE_DE_PRAZO_FIXO_H_
#define _ATIVIDADE_DE_PRAZO_FIXO_H_

#include "Atividade.h"

class AtividadeDePrazoFixo : public Atividade {
    private:
        int dias;
        
    public:
        AtividadeDePrazoFixo(std::string, int dias);
        virtual ~AtividadeDePrazoFixo();

        virtual int getPrazo();

        int getDuracao();
};

#endif // _ATIVIDADE_DE_PRAZO_FIXO_H_
