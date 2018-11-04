/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 1                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#ifndef _PROJETO_H_
#define _PROJETO_H_

#include <string>
#include "Pessoa.h"
#include "Atividade.h"

#define MAXIMO_ATIVIDADES 10

using namespace std;

class Projeto
{
    private:
        string nome = nullptr;

        int quantidadeDePessoasNoProjeto = 0;
        Pessoa** pessoasNoProjeto;

        int quantidadeDeAtividades = 0;
        Atividade** atividades;

    public:
        Projeto(string nome);
        ~Projeto();

        string getNome();

        bool adicionar(Atividade* a);
        Atividade** getAtividades();
        int getQuantidadeDeAtividades();

        bool adicionarRecurso(Pessoa* p);
        Pessoa** getPessoas();
        int getQuantidadeDePessoas();

        int getDuracao();
        double getCusto();

        void imprimir();
};

#endif // _PROJETO_H_
