#ifndef COMANDOS_APRESENTACAO_H_INCLUDED
#define COMANDOS_APRESENTACAO_H_INCLUDED

#include "controladoras_servico.h"
#include "interfaces.h"
#include "telas.h"

//----------------------------------------------------------------------------------------------------------------------
class ComandoIAAutenticacao {
   protected:
    bool resultado;
    Email *email;
    Senha senha;
    TelaAutenticacao telaAutenticacao;

   public:
    virtual bool executar(ISAutenticacao *) = 0;
    virtual ~ComandoIAAutenticacao(){};
};

class ComandoIAAutenticacaoAutenticar : public ComandoIAAutenticacao {
   public:
    ComandoIAAutenticacaoAutenticar(Email *email) {
        this->email = email;
    };
    bool executar(ISAutenticacao *);
};

//----------------------------------------------------------------------------------------------------------------------
class ComandoIAConta {
   protected:
    bool resultado;
    Conta conta;
    Email email;
    TelaConta telaConta;
    TelaMensagem telaMensagem;

   public:
    virtual void executar(ISConta *) = 0;
};

class ComandoIAContaCadastrar : public ComandoIAConta {
   public:
    void executar(ISConta *);
};

class ComandoIAContaVisualizar : public ComandoIAConta {
   public:
    ComandoIAContaVisualizar(Email email) {
        this->email = email;
    }
    void executar(ISConta *);
};

class ComandoIAContaEditar : public ComandoIAConta {
   public:
    ComandoIAContaEditar(Email email) {
        this->email = email;
    }
    void executar(ISConta *);
};

class ComandoIAContaDescadastrar : public ComandoIAConta {
   public:
    ComandoIAContaDescadastrar(Email email) {
        this->email = email;
    }
    void executar(ISConta *);
};

//----------------------------------------------------------------------------------------------------------------------
class ComandoIACartao {
   protected:
    bool resultado;
    Cartao cartao;
    Codigo codigo;
    TelaCartao telaCartao;
    TelaMensagem telaMensagem;

   public:
    virtual void executar(ISCartao *) = 0;
    virtual ~ComandoIACartao() {}
};

class ComandoIACartaoVisualizar : public ComandoIACartao {
   public:
    void executar(ISCartao *);
};

class ComandoIACartaoCadastrar : public ComandoIACartao {
    void executar(ISCartao *);
};

class ComandoIACartaoEditar : public ComandoIACartao {
    void executar(ISCartao *);
};

class ComandoIACartaoDescadastrar : public ComandoIACartao {
    void executar(ISCartao *);
};

//----------------------------------------------------------------------------------------------------------------------
class ComandoIAQuadro {
   protected:
    bool resultado;
    Quadro quadro;
    Codigo codigo;
    TelaQuadro telaQuadro;
    TelaMensagem telaMensagem;

   public:
    virtual void executar(ISQuadro *) = 0;
    virtual ~ComandoIAQuadro() {}
};

class ComandoIAQuadroVisualizar : public ComandoIAQuadro {
    void executar(ISQuadro *);
};

class ComandoIAQuadroCadastrar : public ComandoIAQuadro {
    void executar(ISQuadro *);
};

class ComandoIAQuadroEditar : public ComandoIAQuadro {
    void executar(ISQuadro *);
};

class ComandoIAQuadroDescadastrar : public ComandoIAQuadro {
    void executar(ISQuadro *);
};

#endif  // COMANDOS_APRESENTACAO_H_INCLUDED