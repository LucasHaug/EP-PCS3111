/***************************************************************/
/**                                                           **/
/**   Aluno: Lucas Haug                                       **/
/**   Número USP: 10773565                                    **/
/**   Exercicio-Programa 2                                    **/
/**   Disciplina: PCS3111                                     **/
/**   Turma: T3T                                              **/
/**                                                           **/
/***************************************************************/

#ifndef _ATIVIDADE_H_
#define _ATIVIDADE_H_

#include <string>
#include <cstdint>
#include "Pessoa.h"

#define MAXIMO_RECURSOS 10

using namespace std;

class Atividade {
    private:
        string nome = nullptr;
        int horasNecessarias = 0;
        int horasDisponiveisPorDia = 0;
        Pessoa** pessoas;
        int quantidadeDePessoas = 0;

    public:
        Atividade(string nome, int horasNecessarias);
        ~Atividade();

        string getNome();
        int getHorasNecessarias();

        bool adicionar(Pessoa* recurso);
        Pessoa** getPessoas();
        int getQuantidadeDePessoas();

        int getDuracao();

        double getCusto();

        void imprimir();
};

#endif // _ATIVIDADE_H_
