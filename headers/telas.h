#ifndef TELAS_H_INCLUDED
#define TELAS_H_INCLUDED

// Mudar o include quando for compilar
#include <ncurses.h>
// #include "curses.h"
#include <vector>

#include "interfaces.h"

class TelaMensagem;

//----------------------------------------------------------------------------------------------------------------------
//211068379
class Telas
{
public:
    int campo;
    int linha, coluna;
};

//----------------------------------------------------------------------------------------------------------------------
//211068379
class TelaMensagem : public Telas
{
public:
    void apresentar(string);
};
//----------------------------------------------------------------------------------------------------------------------
//211068379
class TelaInicial : public Telas
{
public:
    void selecionar(int *); // Método que retorna a opção escolhida.
};

//----------------------------------------------------------------------------------------------------------------------
//211068379
class TelaUsuarioLogado : public Telas
{
public:
    void selecionar(int *);
};

//----------------------------------------------------------------------------------------------------------------------
//211068379
class TelaAutenticacao : public Telas
{
private:
    char emailAutenticacao[100] = "";
    char senhaAutenticacao[100] = "";

public:
    void autenticar(Email *, Senha *);
};

//----------------------------------------------------------------------------------------------------------------------
//211068379
class TelaConta : public Telas
{
private:
    Email email;
    Texto nome;
    Senha senha;

    char emailConta[100] = "";
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
//211068379
class TelaCartao : public Telas
{
private:
    Codigo codigo;
    Texto nome;
    Texto descricao;
    Coluna coluna_cartao;

    char codigoCartao[100] = "";
    char nomeCartao[100] = "";
    char descricaoCartao[100] = "";
    char colunaCartao[100] = "";

public:
    void mostrar(Cartao);        // mostrar valores
    void selecionar(int *);      // tela de seleção
    void visualizar(Cartao *);   // obter codigo
    void cadastrar(Cartao *);    // defnir  valores Cartao
    void editar(Cartao *);       // definir novos valores
    void descadastrar(Codigo *); // definir codigo
};

//----------------------------------------------------------------------------------------------------------------------
//211068379
class TelaQuadro : public Telas
{
private:
    Codigo codigo;
    Texto nome;
    Texto descricao;
    Limite limite;

    char codigoQuadro[100] = "";
    char nomeQuadro[100] = "";
    char descricaoQuadro[100] = "";
    int limiteQuadro;

public:
    void mostrar(Quadro);        // mostrar valores
    void selecionar(int *);      // tela de seleção
    void visualizar(Quadro *);   // obter codigo
    void cadastrar(Quadro *);    // defnir  valores teste
    void editar(Quadro *);       // definir novos valores
    void descadastrar(Codigo *); // definir codigo
};

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//211068305
class TelaDepuracao : public Telas {
   public:
    void selecionar(int *);
};
//211068305
class TelaTestesUnitarios : public Telas {
   public:
    void selecionar(int *);
};
//211068305
class TelaTestesModulos : public Telas {
   public:
    void selecionar(int *);
};
//211068305
class TelaTestesIntegracao : public Telas {
   public:
    void selecionar(int *);
};


#endif // TELAS_H_INCLUDED