/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#ifndef _ATIVIDADE_DE_ESFORCO_FIXO_H_
#define _ATIVIDADE_DE_ESFORCO_FIXO_H_

#include "Atividade.h"

class AtividadeDeEsforcoFixo : public Atividade {
    private:
        int horasNecessarias;

    public:
        AtividadeDeEsforcoFixo(std::string nome, int horasNecessarias);
        virtual ~AtividadeDeEsforcoFixo();

        virtual int getHorasNecessarias();

        int getDuracao();
};

#endif // _ATIVIDADE_DE_ESFORCO_FIXO_H_
