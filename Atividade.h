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

#include <cstdint>
#include <string>

#include "Pessoa.h"

class Atividade {
   private:
    std::string nome = nullptr;
    int horasNecessarias = 0; //@
    int horasDisponiveisPorDia = 0;
    Pessoa** pessoas;
    int quantidadeDePessoas = 0;

   public:
    // Atividade(std::string nome, int horasNecessarias); //@
    Atividade(std::string nome);
    virtual ~Atividade();

    virtual std::string getNome();
    // int getHorasNecessarias(); //@

    // bool adicionar(Pessoa* recurso); //@
    virtual void adicionar(Recurso* r);
    // Pessoa** getPessoas(); //@
    virtual Recurso** getRecurso();
    // int getQuantidadeDePessoas(); //@
    virtual int getQuantidadeDeRecursos();

    virtual int getDuracao();
    virtual double getCusto();

    virtual void terminar(int duracaoReal); //@
    virtual bool estaTerminada(); //@

    void imprimir();

    static const MAXIMO_RECURSOS = 10;
};

#endif  // _ATIVIDADE_H_
