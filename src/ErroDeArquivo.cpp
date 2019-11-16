/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#include "ErroDeArquivo.h"

using namespace std; 

ErroDeArquivo::ErroDeArquivo(string mensagem) : logic_error(mensagem) {
    // Construtor
}

ErroDeArquivo::~ErroDeArquivo() {
    // Destrutor
}