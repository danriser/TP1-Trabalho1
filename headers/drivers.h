#ifndef DRIVERS_H_INCLUDED
#define DRIVERS_H_INCLUDED

#include "testes.h"

//----------------------------------------------------------------------------------------------------------------------
class Drivers {
   public:
    void showResult(bool, string, int);
    virtual void executar() = 0;
};

//----------------------------------------------------------------------------------------------------------------------
class DriverDepuracao {
   private:
    const static int TESTE_UNITARIO = 1;
    const static int TESTE_INTEGRACAO = 2;
    const static int TESTE_SISTEMA = 3;
    const static int SAIR = 4;

   public:
    void executar();
};

//----------------------------------------------------------------------------------------------------------------------
class DriverTestesUnitarios : public Drivers {
   private:
    const static int DOMINIOS = 1;
    const static int ENTIDADES = 2;
    const static int RETORNAR = 4;

   public:
    void executar();
};

//----------------------------------------------------------------------------------------------------------------------
class DriverTestesDominios : public Drivers {
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
class DriverTestesEntidades : public Drivers {
   private:
    TUConta testeConta;
    TUCartao testeCartao;
    TUQuadro testeQuadro;

   public:
    void executar();
};

//----------------------------------------------------------------------------------------------------------------------
class DriverTestesModulos : public Drivers {
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
class DriverTestesIntegracao : public Drivers {
   private:
    const static int CAMADA_APRESENTACAO = 1;
    const static int SUBSISTEMA_AUTENTICACAO = 2;
    const static int SUBSISTEMA_CONTA = 3;
    const static int SUBSISTEMA_CARTAO = 4;
    const static int SUBSISTEMA_QUADRO = 5;
    const static int RETORNAR = 6;

   public:
    void executar();
};

#endif  // DRIVERS_H_INCLUDED