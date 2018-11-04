/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 1                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#ifndef _TELA_H_
#define _TELA_H_

#include "Projeto.h"

// limpa a tela do terminal
void clear();

// utilizada para aguardar o usuario pressionar enter
void aguardaEnter();

// apresenta o menu de opcoes iniciais
int menuDeOpcoes();

// apresenta a interface com o usuario,
// caso ele tenha escolhido a opcao um
void opcaoUm(Projeto* proj);

// apresenta a interface com o usuario,
// caso ele tenha escolhido a opcao dois
void opcaoDois(Projeto* proj);

#endif // _TELA_H_