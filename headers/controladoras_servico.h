#ifndef CONTROLADORAS_SERVICOS_H_INCLUDED
#define CONTROLADORAS_SERVICOS_H_INCLUDED

// #include "comandos_servicos.h"
#include "interfaces.h"
#include "comandos_servico.h"

//----------------------------------------------------------------------------------------------------------------------
//221020904
// Declarações de classes controladoras da camada de serviços e implementações de métodos inline.

class CtrlISAutenticacao : public ISAutenticacao
{
public:
    bool autenticar(Email, Senha);
};

//----------------------------------------------------------------------------------------------------------------------
//221020904
class CtrlISConta : public ISConta
{
public:
    bool visualizar(Conta *);
    bool cadastrar(Conta);
    bool editar(Conta);
    bool descadastrar(Email);
};

//----------------------------------------------------------------------------------------------------------------------
//221020904
class CtrlISCartao : public ISCartao
{
public:
    bool visualizar(Cartao *);
    bool cadastrar(Cartao);
    bool editar(Cartao);
    bool descadastrar(Codigo);
};

//----------------------------------------------------------------------------------------------------------------------
//221020904
class CtrlISQuadro : public ISQuadro
{
public:
    bool visualizar(Quadro *);
    bool cadastrar(Quadro);
    bool editar(Quadro);
    bool descadastrar(Codigo);
};

#endif // CONTROLADORAS_SERVICOS_H_INCLUDED