/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#ifndef _ERRO_DE_ARQUIVO_H_
#define _ERRO_DE_ARQUIVO_H_

#include <stdexcept>

class ErroDeArquivo : public std::logic_error {
    public:
        ErroDeArquivo(std::string mensagem);
        virtual ~ErroDeArquivo();
};

#endif // _ERRO_DE_ARQUIVO_H_
