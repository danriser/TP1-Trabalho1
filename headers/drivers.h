#ifndef DRIVERS_H_INCLUDED
#define DRIVERS_H_INCLUDED

#include "testes.h"

//----------------------------------------------------------------------------------------------------------------------
//200058151
class Drivers
{
public:
    void showResult(bool, string, int);
    virtual void executar() = 0;
};

//----------------------------------------------------------------------------------------------------------------------
//200058151
class DriverDepuracao
{
private:
    const static int TESTE_UNITARIO = 1;
    const static int TESTE_INTEGRACAO = 2;
    const static int TESTE_SISTEMA = 3;
    const static int SAIR = 4;

public:
    void executar();
};

//----------------------------------------------------------------------------------------------------------------------
//200058151
class DriverTestesUnitarios : public Drivers
{
private:
    const static int DOMINIOS = 1;
    const static int ENTIDADES = 2;
    const static int MODULOS = 3;
    const static int RETORNAR = 4;

public:
    void executar();
};

//----------------------------------------------------------------------------------------------------------------------
//200058151
class DriverTestesDominios : public Drivers
{
private:
    TUCodigo testeCodigo;
    TUEmail testeEmail;
    TULimite testeLimite;
    TUSenha testeSenha;
    TUTexto testeTexto;
    TUColuna testeColuna;

public:
    void executar();
};

//----------------------------------------------------------------------------------------------------------------------
class DriverTestesEntidades : public Drivers
{
private:
    TUConta testeConta;
    TUCartao testeCartao;
    TUQuadro testeQuadro;

public:
    void executar();
};

//----------------------------------------------------------------------------------------------------------------------
//200058151
class DriverTestesModulos : public Drivers
{
private:
    const static int AUTENTICACAO = 1;
    const static int CONTA = 2;
    const static int CARTAO = 3;
    const static int QUADRO = 4;
    const static int RETORNAR = 5;

public:
    void executar();
};

//----------------------------------------------------------------------------------------------------------------------
//200058151
class DriverTestesIntegracao : public Drivers
{
private:
    const static int CAMADA_APRESENTACAO = 1;
    const static int RETORNAR = 2;

public:
    void executar();
};

#endif // DRIVERS_H_INCLUDED