#include "../headers/builder.h"

CtrlIAInicializacao *BuilderSistema::construir() {
    ctrlIAInicializacao = new CtrlIAInicializacao();
    ctrlIAAutenticacao = new CtrlIAAutenticacao();
    ctrlIAConta = new CtrlIAConta();
    ctrlIACartao = new CtrlIACartao();
    ctrlIAQuadro = new CtrlIAQuadro();

    ctrlISAutenticacao = new CtrlISAutenticacao();
    ctrlISConta = new CtrlISConta();
    ctrlISCartao = new CtrlISCartao();
    ctrlISQuadro = new CtrlISQuadro();

    ctrlIAAutenticacao->setCtrlISAutenticacao(ctrlISAutenticacao);
    ctrlIAConta->setCtrlISConta(ctrlISConta);
    ctrlIACartao->setCtrlISCartao(ctrlISCartao);
    ctrlIAQuadro->setCtrlISQuadro(ctrlISQuadro);

    ctrlIAInicializacao->setCtrlIAAutenticacao(ctrlIAAutenticacao);
    ctrlIAInicializacao->setCtrlIAConta(ctrlIAConta);
    ctrlIAInicializacao->setCtrlIACartao(ctrlIACartao);
    ctrlIAInicializacao->setCtrlIAQuadro(ctrlIAQuadro);

    return ctrlIAInicializacao;
}

BuilderSistema::~BuilderSistema() {
    delete ctrlIAInicializacao;
    delete ctrlIAAutenticacao;
    delete ctrlIAConta;
    delete ctrlIACartao;
    delete ctrlIAQuadro;
    delete ctrlISAutenticacao;
    delete ctrlISConta;
    delete ctrlISCartao;
    delete ctrlISQuadro;
}