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

#include "Pessoa.h"

#include <cstdint>
#include <string>

class Atividade {
   protected:
    std::string nome = nullptr;
    int horasDisponiveisPorDia = 0;
    Recurso** recursos;
    int quantidadeDeRecursos = 0;
    int quantidadeDePessoas = 0;
    int duracaoReal = 0; 
    bool atividadeTerminada = false;

   public:
    Atividade(std::string nome);
    virtual ~Atividade();

    virtual std::string getNome();

    virtual void adicionar(Recurso* r);
    virtual Recurso** getRecursos();
    virtual int getQuantidadeDeRecursos();

    virtual int getDuracao() = 0;
    virtual double getCusto();

    virtual void terminar(int duracaoReal);
    virtual bool estaTerminada();

    void imprimir();

    static const int MAXIMO_RECURSOS = 10;
};

#endif  // _ATIVIDADE_H_
