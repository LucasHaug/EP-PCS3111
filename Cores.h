/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 1                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#ifndef _CORES_H_
#define _CORES_H_

// define macros para colorir o terminal com o código escape
// ANSI, suportado no Windows 10 e sistemas baseados em Unix

// se o sistema operacioanl for o Windows 10 ou baseado em Unix
#if defined (_WIN32_WINNT_WIN10) || defined (__unix__)

#define CRESET     "\033[0m"

#define CPINK      "\033[35;1m"
#define CBLUE      "\033[36;1m"
#define CYELLOW    "\033[33;1m"
#define CRED       "\033[31;1m"
#define CDARKBLUE  "\033[34;1m"
#define CGREEN     "\033[32;1m"

// caso nao esteja previsto o suporte do código escape ANSI
#else

#define CRESET

#define CPINK
#define CBLUE
#define CYELLOW
#define CRED
#define CGOLD
#define CPURPLE
#define CGREEN

#endif // _WIN32_WINNT_WIN10, __unix__, nao suportado



#endif // _CORES_H_
