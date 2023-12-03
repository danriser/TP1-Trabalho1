#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
// Declarações adiantadas
class ISAutenticacao;
class ISConta;
class ISCartao;
class ISQuadro;

//----------------------------------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de apresentação.
//211068379
class IAAutenticacao
{
public:
    virtual bool executar(Email *) = 0;
    virtual void setCtrlISAutenticacao(ISAutenticacao *) = 0;
    virtual ~IAAutenticacao(){};
};
//211068379
class IAConta
{
public:
    virtual void cadastrar() = 0;
    virtual void executar(Email) = 0;
    virtual void setCtrlISConta(ISConta *) = 0;
    virtual ~IAConta(){};
};
//211068379
class IACartao
{
public:
    virtual void executar(Email) = 0;
    virtual void setCtrlISCartao(ISCartao *) = 0;
    virtual ~IACartao(){};
};
//211068379
class IAQuadro
{
public:
    virtual void executar(Email) = 0;
    virtual void setCtrlISQuadro(ISQuadro *) = 0;
    virtual ~IAQuadro(){};
};

//----------------------------------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de serviço.
//211068379
class ISAutenticacao
{
public:
    virtual bool autenticar(Email, Senha) = 0;
    virtual ~ISAutenticacao(){};
};
//211068379
class ISConta
{
public:
    virtual bool visualizar(Conta *) = 0;
    virtual bool cadastrar(Conta) = 0;
    virtual bool editar(Conta) = 0;
    virtual bool descadastrar(Email) = 0;
    virtual ~ISConta(){};
};
//211068379
class ISCartao
{
public:
    virtual bool visualizar(Cartao *) = 0;
    virtual bool cadastrar(Cartao) = 0;
    virtual bool editar(Cartao) = 0;
    virtual bool descadastrar(Codigo) = 0;
    virtual ~ISCartao(){};
};
//211068379
class ISQuadro
{
public:
    virtual bool visualizar(Quadro *) = 0;
    virtual bool cadastrar(Quadro) = 0;
    virtual bool editar(Quadro) = 0;
    virtual bool descadastrar(Codigo) = 0;
    virtual ~ISQuadro(){};
};

#endif // INTERFACES_H_INCLUDED