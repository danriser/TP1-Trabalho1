#include "../headers/controladoras_apresentacao.h"

//----------------------------------------------------------------------------------------------------------------------
// Implementações dos métodos de classes controladoras.

void CtrlIAInicializacao::executar() {
    Email email;
    int campo1, campo2;  // Campo de entrada.

    bool apresentar = true;  // Controle de laço.
    while (apresentar) {     // Apresenta tela inicial.

        TelaInicial telaInicial;
        telaInicial.selecionar(&campo1);

        switch (campo1) {
            case AUTENTICAR:
                if (ctrlIAAutenticacao->executar(&email)) {  // Solicita autenticação e obtem o email.

                    bool apresentar = true;  // Controle de laço.
                    while (apresentar) {     // Apresenta tela de seleção de serviço.

                        TelaUsuarioLogado telaUsuarioLogado;
                        telaUsuarioLogado.selecionar(&campo2);  // Pergunta e define o serviço.

                        switch (campo2) {
                            case CONTA:
                                ctrlIAConta->executar(email);  // Solicita serviço de Conta.
                                break;                                     //
                            case CARTAO:                                    //
                                ctrlIACartao->executar(email);          // Solicita serviço de Cartao.
                                break;                                     //
                            case QUADRO:                              //
                                ctrlIAQuadro->executar(email);    // Solicita serviço de Quadro.
                                break;
                            case VOLTAR:
                                apresentar = false;
                                break;
                            default:
                                TelaMensagem telaMensagem;
                                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                                break;
                        }
                    }
                } else {
                    TelaMensagem telaMensagem;
                    telaMensagem.apresentar("Falha na autenticacao. Pressione qualquer tecla para continuar.");
                }
                break;

            case CADASTRAR:                        // Solicitação de cadastro de Conta.
                ctrlIAConta->cadastrar();  // Abre a tela de cadastro.
                break;

            case SAIR:
                apresentar = false;  // Encerra o programa.
                break;

            default:
                TelaMensagem telaMensagem;
                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                break;
        }
    }
};

//----------------------------------------------------------------------------------------------------------------------
bool CtrlIAAutenticacao::executar(Email* email) {
    comando = new ComandoIAAutenticacaoAutenticar(email);
    return comando->executar(ctrlISAutenticacao);
    delete comando;
}

//----------------------------------------------------------------------------------------------------------------------
void CtrlIAConta::cadastrar() {
    comando = new ComandoIAContaCadastrar();
    comando->executar(ctrlISConta);
    delete comando;
}

void CtrlIAConta::executar(Email email) {
    int opcao;
    bool apresentar = true;
    while (apresentar) {
        TelaConta telaConta;
        telaConta.selecionar(&opcao);

        switch (opcao) {
            case VISUALIZAR:
                comando = new ComandoIAContaVisualizar(email);
                comando->executar(ctrlISConta);
                delete comando;
                break;

            case EDITAR:
                comando = new ComandoIAContaEditar(email);
                comando->executar(ctrlISConta);
                delete comando;
                break;

            case DESCADASTRAR:
                comando = new ComandoIAContaDescadastrar(email);
                comando->executar(ctrlISConta);
                delete comando;
                break;

            case RETORNAR:
                apresentar = false;
                break;

            default:
                TelaMensagem telaMensagem;
                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                break;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------
void CtrlIACartao::executar(Email email) {
    int opcao;  // Campo de entrada.

    bool apresentar = true;  // Controle de laço.
    while (apresentar) {     // Apresenta tela inicial.
        TelaCartao telaCartao;
        telaCartao.selecionar(&opcao);

        switch (opcao) {
            case VISUALIZAR:
                comando = new ComandoIACartaoVisualizar();
                comando->executar(ctrlISCartao);
                delete comando;
                break;

            case CADASTRAR:
                comando = new ComandoIACartaoCadastrar();
                comando->executar(ctrlISCartao);
                delete comando;
                break;

            case EDITAR:
                comando = new ComandoIACartaoEditar();
                comando->executar(ctrlISCartao);
                delete comando;
                break;

            case DESCADASTRAR:
                comando = new ComandoIACartaoDescadastrar();
                comando->executar(ctrlISCartao);
                delete comando;
                break;

            case RETORNAR:
                apresentar = false;
                break;

            default:
                TelaMensagem telaMensagem;
                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                break;
        }
    }
};

//----------------------------------------------------------------------------------------------------------------------
void CtrlIAQuadro::executar(Email email) {
    int opcao;  // Campo de entrada.

    bool apresentar = true;  // Controle de laço.
    while (apresentar) {     // Apresenta tela inicial.

        TelaQuadro telaQuadro;
        telaQuadro.selecionar(&opcao);

        switch (opcao) {
            case VISUALIZAR:
                comando = new ComandoIAQuadroVisualizar();
                comando->executar(ctrlISQuadro);
                delete comando;
                break;

            case CADASTRAR:
                comando = new ComandoIAQuadroCadastrar();
                comando->executar(ctrlISQuadro);
                delete comando;
                break;

            case EDITAR:
                comando = new ComandoIAQuadroEditar();
                comando->executar(ctrlISQuadro);
                delete comando;
                break;

            case DESCADASTRAR:
                comando = new ComandoIAQuadroDescadastrar();
                comando->executar(ctrlISQuadro);
                delete comando;
                break;

            case RETORNAR:
                apresentar = false;
                break;

            default:
                TelaMensagem telaMensagem;
                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                break;
        }
    };
}