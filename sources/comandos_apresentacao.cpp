#include "../headers/comandos_apresentacao.h"

//----------------------------------------------------------------------------------------------------------------------
bool ComandoIAAutenticacaoAutenticar::executar(ISAutenticacao* ctrlISAutenticacao) {
    telaAutenticacao.autenticar(email, &senha);
    Email login = *email;
    resultado = ctrlISAutenticacao->autenticar(login, senha);
    return resultado;
}

//----------------------------------------------------------------------------------------------------------------------
void ComandoIAContaVisualizar::executar(ISConta* ctrlISConta) {
    conta.setEmail(email);  // Já tem o email, conta só pode visualizar os próprios dados
    resultado = ctrlISConta->visualizar(&conta);
    if (resultado) {
        telaConta.mostrar(conta);
    } else {
        telaMensagem.apresentar("Conta informadaa não foi encontrada. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIAContaCadastrar::executar(ISConta* ctrlISConta) {
    telaConta.cadastrar(&conta);
    resultado = ctrlISConta->cadastrar(conta);
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Nao foi possível cadastrar conta. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIAContaEditar::executar(ISConta* ctrlISConta) {
    telaConta.editar(&conta);
    conta.setEmail(email);
    resultado = ctrlISConta->editar(conta);
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Nao foi possivel editar dados de conta. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIAContaDescadastrar::executar(ISConta* ctrlISConta) {
    Email emailConfirmacao;
    telaConta.descadastrar(&emailConfirmacao);
    if (emailConfirmacao.getValor() == email.getValor()) {
        resultado = ctrlISConta->descadastrar(email);
        if (resultado) {
            telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
        } else {
            telaMensagem.apresentar("Não foi possível descadastrar desenvolvedor. Pressione qualquer tecla para continuar.");
        }
    } else {
        telaMensagem.apresentar("Informe apenas email da conta logada. Pressione qualquer tecla para continuar.");
    }
}

//----------------------------------------------------------------------------------------------------------------------
void ComandoIACartaoVisualizar::executar(ISCartao* ctrlISCartao) {
    telaCartao.visualizar(&cartao);                 // Pede o código do cartao ao usuário.
    resultado = ctrlISCartao->visualizar(&cartao);  // Pesquisa no banco de dados e coloca os valores.
    if (resultado) {
        telaCartao.mostrar(cartao);  // Mostra os valores.
    } else {
        telaMensagem.apresentar("Cartao informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIACartaoCadastrar::executar(ISCartao* ctrlISCartao) {
    telaCartao.cadastrar(&cartao);                // Solicita dados do cartao ao usuário. .
    resultado = ctrlISCartao->cadastrar(cartao);  // Registra no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Cartao cadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Não foi possível cadastrar cartao. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIACartaoEditar::executar(ISCartao* ctrlISCartao) {
    telaCartao.visualizar(&cartao);                 // Obtém código do cartao que será editado
    resultado = ctrlISCartao->visualizar(&cartao);  // Verifica se está no banco de dados e coloca os valores.

    if (resultado) {
        telaCartao.editar(&cartao);  // Solicita novos dados ao usuário.

        if (ctrlISCartao->editar(cartao)) {                 // Substitui novas informaçoes no banco de dados.
            resultado = ctrlISCartao->visualizar(&cartao);  // Pesquisa no banco de dados e coloca os valores.
        } else {
            telaMensagem.apresentar("Não foi possível editar cartao. Pressione qualquer tecla para continuar.");
        }
    } else {
        telaMensagem.apresentar("Cartao informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIACartaoDescadastrar::executar(ISCartao* ctrlISCartao) {
    telaCartao.descadastrar(&codigo);                // Pede o código do cartao ao usuário.
    resultado = ctrlISCartao->descadastrar(codigo);  // Socilita descadastramento do banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Cartao descadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Cartao informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

//----------------------------------------------------------------------------------------------------------------------
void ComandoIAQuadroVisualizar::executar(ISQuadro* ctrlISQuadro) {
    telaQuadro.visualizar(&quadro);                 // Pede o código do quadro ao usuário.
    resultado = ctrlISQuadro->visualizar(&quadro);  // Pesquisa no banco de dados e coloca os valores.
    if (resultado) {
        telaQuadro.mostrar(quadro);  // Mostra os valores.
    } else {
        telaMensagem.apresentar("Quadro informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIAQuadroCadastrar::executar(ISQuadro* ctrlISQuadro) {
    telaQuadro.cadastrar(&quadro);                // Solicita dados do teste ao usuário. .
    resultado = ctrlISQuadro->cadastrar(quadro);  // Registra no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Quadro cadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Não foi possível cadastrar quadro. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIAQuadroEditar::executar(ISQuadro* ctrlISQuadro) {
    telaQuadro.visualizar(&quadro);                 // Obtém código do teste que será editado
    resultado = ctrlISQuadro->visualizar(&quadro);  // Verifica se está no banco de dados e coloca os valores.

    if (resultado) {
        telaQuadro.editar(&quadro);  // Solicita novos dados ao usuário.

        if (ctrlISQuadro->editar(quadro)) {                 // Substitui novas informaçoes no banco de dados.
            resultado = ctrlISQuadro->visualizar(&quadro);  // Pesquisa no banco de dados e coloca os valores.
        } else {
            telaMensagem.apresentar("Não foi possível editar quadro. Pressione qualquer tecla para continuar.");
        }
    } else {
        telaMensagem.apresentar("Quadro informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIAQuadroDescadastrar::executar(ISQuadro* ctrlISQuadro) {
    telaQuadro.descadastrar(&codigo);                // Pede o código do teste ao usuário.
    resultado = ctrlISQuadro->descadastrar(codigo);  // Socilita descadastramento do banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Quadro descadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Quadro informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}