#ifndef CONTROLADORAS_APRESENTACAO_H_INCLUDED
#define CONTROLADORAS_APRESENTACAO_H_INCLUDED

#include "comandos_apresentacao.h"
#include "controladoras_servico.h"
#include "interfaces.h"
#include "telas.h"

//----------------------------------------------------------------------------------------------------------------------
class CtrlIAInicializacao {
   private:
    IAAutenticacao *ctrlIAAutenticacao;
    IAConta *ctrlIAConta;
    IACartao *ctrlIACartao;
    IAQuadro *ctrlIAQuadro;

    const static int AUTENTICAR = 1;
    const static int CADASTRAR = 2;
    const static int SAIR = 3;

    const static int CONTA = 1;
    const static int CARTAO = 2;
    const static int QUADRO = 3;
    const static int VOLTAR = 4;

   public:
    void executar();
    void setCtrlIAAutenticacao(IAAutenticacao *);
    void setCtrlIAConta(IAConta *);
    void setCtrlIACartao(IACartao *);
    void setCtrlIAQuadro(IAQuadro *);
};

inline void CtrlIAInicializacao::setCtrlIAAutenticacao(IAAutenticacao *ctrlIAAutenticacao) {
    this->ctrlIAAutenticacao = ctrlIAAutenticacao;
}

inline void CtrlIAInicializacao::setCtrlIAConta(IAConta *ctrlIAConta) {
    this->ctrlIAConta = ctrlIAConta;
}

inline void CtrlIAInicializacao::setCtrlIACartao(IACartao *ctrlIACartao) {
    this->ctrlIACartao = ctrlIACartao;
}

inline void CtrlIAInicializacao::setCtrlIAQuadro(IAQuadro *ctrlIAQuadro) {
    this->ctrlIAQuadro = ctrlIAQuadro;
}

//----------------------------------------------------------------------------------------------------------------------

class CtrlIAAutenticacao : public IAAutenticacao {
   private:
    ISAutenticacao *ctrlISAutenticacao;
    ComandoIAAutenticacao *comando;

   public:
    bool executar(Email *);
    void setCtrlISAutenticacao(ISAutenticacao *ctrlISAutenticacao);
};

inline void CtrlIAAutenticacao::setCtrlISAutenticacao(ISAutenticacao *ctrlISAutenticacao) {
    this->ctrlISAutenticacao = ctrlISAutenticacao;
}

//----------------------------------------------------------------------------------------------------------------------
class CtrlIAConta : public IAConta {
   private:
    const static int VISUALIZAR = 1;
    const static int EDITAR = 2;
    const static int DESCADASTRAR = 3;
    const static int RETORNAR = 4;

    ISConta *ctrlISConta;
    ComandoIAConta *comando;

   public:
    void setCtrlISConta(ISConta *);
    void cadastrar();
    void executar(Email);
};

inline void CtrlIAConta::setCtrlISConta(ISConta *ctrlISConta) {
    this->ctrlISConta = ctrlISConta;
}

//----------------------------------------------------------------------------------------------------------------------
class CtrlIACartao : public IACartao {
   private:
    const static int VISUALIZAR = 1;
    const static int CADASTRAR = 2;
    const static int EDITAR = 3;
    const static int DESCADASTRAR = 4;
    const static int RETORNAR = 5;

    ISCartao *ctrlISCartao;
    ComandoIACartao *comando;

   public:
    void executar(Email);
    void setCtrlISCartao(ISCartao *);
};

inline void CtrlIACartao::setCtrlISCartao(ISCartao *ctrlISCartao) {
    this->ctrlISCartao = ctrlISCartao;
}

//----------------------------------------------------------------------------------------------------------------------
class CtrlIAQuadro : public IAQuadro {
   private:
    const static int VISUALIZAR = 1;
    const static int CADASTRAR = 2;
    const static int EDITAR = 3;
    const static int DESCADASTRAR = 4;
    const static int RETORNAR = 5;

    ISQuadro *ctrlISQuadro;
    ComandoIAQuadro *comando;

   public:
    void executar(Email);
    void setCtrlISQuadro(ISQuadro *);
};

inline void CtrlIAQuadro::setCtrlISQuadro(ISQuadro *ctrlISQuadro) {
    this->ctrlISQuadro = ctrlISQuadro;
}

#endif  // CONTROLADORAS_APRESENTACAO_H_INCLUDED