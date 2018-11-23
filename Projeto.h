/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#ifndef _PROJETO_H_
#define _PROJETO_H_

#include "Atividade.h"
#include "Pessoa.h"

#include <list>
#include <string>
#include <vector>

using namespace std;

class Projeto {
   private:
    std::string nome = nullptr;
    std::vector<Atividade*>* atividades;     //@
    std::list<Recurso*>* recursosNoProjeto;  //@

   public:
    Projeto(std::string nome);
    virtual ~Projeto();
    virtual std::string getNome();

    virtual void adicionar(Atividade* a);
    virtual std::vector<Atividade*>* getAtividades();
    virtual void adicionar(Recurso* r);
    virtual std::list<Recurso*>* getRecursos();

    virtual int getDuracao();
    virtual int getDuracao(bool terminadas);
    virtual double getCusto();
    virtual void imprimir();
};

#endif  // _PROJETO_H_
