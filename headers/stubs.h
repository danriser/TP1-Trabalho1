#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.h"

//----------------------------------------------------------------------------------------------------------------------
class StubISAutenticacao : public ISAutenticacao {
   private:
    static Email emailStub;
    static Senha senhaStub;

    const static string VALOR_VALIDO_EMAIL;
    const static string VALOR_VALIDO_SENHA;

    const static bool SUCESSO = true;
    const static bool FALHA = false;

    bool resultado;

   public:
    StubISAutenticacao() {
        emailStub.setValor(VALOR_VALIDO_EMAIL);
        senhaStub.setValor(VALOR_VALIDO_SENHA);
    }
    bool autenticar(Email, Senha);
};

//----------------------------------------------------------------------------------------------------------------------
class StubISConta : public ISConta {
   private:
    static Conta contaStub;
    static Email emailConta;
    static Texto nomeConta;
    static Senha senhaConta;

    const static string VALOR_VALIDO_EMAIL;
    const static string VALOR_VALIDO_NOME;
    const static string VALOR_VALIDO_SENHA;

    const static bool SUCESSO = true;
    const static bool FALHA = false;

    bool resultado;

   public:
    StubISConta() {
        emailConta.setValor(VALOR_VALIDO_EMAIL);
        nomeConta.setValor(VALOR_VALIDO_NOME);
        senhaConta.setValor(VALOR_VALIDO_SENHA);

        contaStub.setEmail(emailConta);
        contaStub.setNome(nomeConta);
        contaStub.setSenha(senhaConta);
    }
    bool visualizar(Conta *);
    bool cadastrar(Conta);
    bool editar(Conta);
    bool descadastrar(Email);
};

//----------------------------------------------------------------------------------------------------------------------
class StubISCartao : public ISCartao {
   private:
    static Cartao cartaoStub;

    static Codigo codigoCartao;
    static Texto nomeCartao;
    static Texto descricaoCartao;
    static Coluna colunaCartao;

    const static string VALOR_VALIDO_CODIGO;
    const static string VALOR_VALIDO_NOME;
    const static string VALOR_VALIDO_DESCRICAO;
    const static string VALOR_VALIDO_COLUNA;

    const static bool SUCESSO = true;
    const static bool FALHA = false;

    bool resultado;

   public:
    StubISCartao() {
        codigoCartao.setValor(VALOR_VALIDO_CODIGO);
        nomeCartao.setValor(VALOR_VALIDO_NOME);
        descricaoCartao.setValor(VALOR_VALIDO_DESCRICAO);
        colunaCartao.setValor(VALOR_VALIDO_COLUNA);

        cartaoStub.setCodigo(codigoCartao);
        cartaoStub.setNome(nomeCartao);
        cartaoStub.setDescricao(descricaoCartao);
        cartaoStub.setColuna(colunaCartao);
    };

    bool visualizar(Cartao *);
    bool cadastrar(Cartao);
    bool editar(Cartao);
    bool descadastrar(Codigo);
};

//----------------------------------------------------------------------------------------------------------------------
class StubISQuadro : public ISQuadro {
   private:
    static Quadro quadroStub;

    static Codigo codigoQuadro;
    static Texto nomeQuadro;
    static Texto descricaoQuadro;
    static Limite limiteQuadro;

    const static string VALOR_VALIDO_CODIGO;
    const static string VALOR_VALIDO_NOME;
    const static string VALOR_VALIDO_DESCRICAO;
    const static int VALOR_VALIDO_LIMITE;

    const static bool SUCESSO = true;
    const static bool FALHA = false;

   public:
    StubISQuadro() {
        codigoQuadro.setValor(VALOR_VALIDO_CODIGO);
        nomeQuadro.setValor(VALOR_VALIDO_NOME);
        descricaoQuadro.setValor(VALOR_VALIDO_DESCRICAO);
        limiteQuadro.setValor(VALOR_VALIDO_LIMITE);

        quadroStub.setCodigo(codigoQuadro);
        quadroStub.setNome(nomeQuadro);
        quadroStub.setDescricao(descricaoQuadro);
        quadroStub.setLimite(limiteQuadro);
    }

    bool visualizar(Quadro *);
    bool cadastrar(Quadro);
    bool editar(Quadro);
    bool descadastrar(Codigo);
};

#endif  // STUBS_H_INCLUDED