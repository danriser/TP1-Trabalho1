#ifndef TELAS_H_INCLUDED
#define TELAS_H_INCLUDED

// Mudar o include quando for compilar
// #include <ncurses.h>
#include "curses.h"

#include "interfaces.h"

class TelaMensagem;

//----------------------------------------------------------------------------------------------------------------------
class Telas {
   public:
    int campo;
    int linha, coluna;
};

//----------------------------------------------------------------------------------------------------------------------
class TelaMensagem : public Telas {
   public:
    void apresentar(string);
};
//----------------------------------------------------------------------------------------------------------------------
class TelaInicial : public Telas {
   public:
    void selecionar(int *);  // Método que retorna a opção escolhida.
};

//----------------------------------------------------------------------------------------------------------------------
class TelaUsuarioLogado : public Telas {
   public:
    void selecionar(int *);
};

//----------------------------------------------------------------------------------------------------------------------
class TelaAutenticacao : public Telas {
   private:
    char matriculaAutenticacao[100] = "";
    char senhaAutenticacao[100] = "";

   public:
    void autenticar(Email *, Senha *);
};

//----------------------------------------------------------------------------------------------------------------------
class TelaConta : public Telas {
   private:
    Email email;
    Texto nome;
    Senha senha;

    char matriculaConta[100] = "";
    char nomeConta[100] = "";
    char senhaConta[100] = "";

   public:
    void selecionar(int *);
    void mostrar(Conta);
    void visualizar(Conta *);
    void descadastrar(Email *);
    void cadastrar(Conta *);
    void editar(Conta *);
};

//----------------------------------------------------------------------------------------------------------------------
class TelaCartao : public Telas {
   private:
    Codigo codigo;
    Texto nome;
    Texto descricao;
    Coluna coluna;

    char codigoCartao[100] = "";
    char nomeCartao[100] = "";
    char descricaoCartao[100] = "";
    char colunaCartao[100] = "";

   public:
    void mostrar(Cartao);          // mostrar valores
    void selecionar(int *);       // tela de seleção
    void visualizar(Cartao *);     // obter codigo
    void cadastrar(Cartao *);      // defnir  valores Cartao
    void editar(Cartao *);         // definir novos valores
    void descadastrar(Codigo *);  // definir codigo
};

//----------------------------------------------------------------------------------------------------------------------
class TelaQuadro : public Telas {
   private:
    Codigo codigo;
    Texto nome;
    Texto descricao;
    Limite limite;

    char codigoQuadro[100] = "";
    char nomeQuadro[100] = "";
    char descricaoQuadro[100] = "";
    char limiteQuadro[100] = "";

   public:
    void mostrar(Quadro);       // mostrar valores
    void selecionar(int *);          // tela de seleção
    void visualizar(Quadro *);  // obter codigo
    void cadastrar(Quadro *);   // defnir  valores teste
    void editar(Quadro *);      // definir novos valores
    void descadastrar(Codigo *);     // definir codigo
};

//----------------------------------------------------------------------------------------------------------------------
class TelaVer : public Telas {
   public:
    void selecionar(int *);
};

#endif  // TELAS_H_INCLUDED