#include <stdexcept>
#include <iostream>

#include "testes.h"

using namespace std;

// --------------------------------------------------------------------------
/**
 * Testes de Dominio
 */

// Definções de constantes e valores validos/invalidos para testes de unidade de cada dominio.

const string TUCodigo::VALOR_VALIDO = "AZ09";
const string TUCodigo::VALOR_INVALIDO = "123teste";

const string TUEmail::VALOR_VALIDO = "ab@cde";
const string TUEmail::VALOR_INVALIDO = "P@.com";

const int TULimite::VALOR_VALIDO = 15;
const int TULimite::VALOR_INVALIDO = 12;

const string TUSenha::VALOR_VALIDO = "Te12!";
const string TUSenha::VALOR_INVALIDO = "senhafraca";

const string TUTexto::VALOR_VALIDO = "Este texto esta correto.";
const string TUTexto::VALOR_INVALIDO = "n  ..ao";

const string TUColuna::VALOR_VALIDO = "SOLICITADO";
const string TUColuna::VALOR_INVALIDO = "Nao sei";

// Codigo
void TUCodigo::setUp()
{
    codigo = new Codigo();
    estado = SUCESSO;
}

void TUCodigo::tearDown()
{
    delete codigo;
}

void TUCodigo::testarCenarioSucesso()
{
    try
    {
        codigo->setValor(VALOR_VALIDO);
        if (codigo->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUCodigo::testarCenarioFalha()
{
    try
    {
        codigo->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (codigo->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUCodigo::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

// Email
void TUEmail::setUp()
{
    email = new Email();
    estado = SUCESSO;
}

void TUEmail::tearDown()
{
    delete email;
}

void TUEmail::testarCenarioSucesso()
{
    try
    {
        email->setValor(VALOR_VALIDO);
        if (email->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
        cout << estado << endl;
    }
}

void TUEmail::testarCenarioFalha()
{
    try
    {
        email->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (email->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUEmail::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

// Limite
void TULimite::setUp()
{
    limite = new Limite();
    estado = SUCESSO;
}

void TULimite::tearDown()
{
    delete limite;
}

void TULimite::testarCenarioSucesso()
{
    try
    {
        limite->setValor(VALOR_VALIDO);
        if (limite->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TULimite::testarCenarioFalha()
{
    try
    {
        limite->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (limite->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TULimite::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

// Senha
void TUSenha::setUp()
{
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown()
{
    delete senha;
}

void TUSenha::testarCenarioSucesso()
{
    try
    {
        senha->setValor(VALOR_VALIDO);
        if (senha->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUSenha::testarCenarioFalha()
{
    try
    {
        senha->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (senha->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUSenha::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

// Texto
void TUTexto::setUp()
{
    texto = new Texto();
    estado = SUCESSO;
}

void TUTexto::tearDown()
{
    delete texto;
}

void TUTexto::testarCenarioSucesso()
{
    try
    {
        texto->setValor(VALOR_VALIDO);
        if (texto->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUTexto::testarCenarioFalha()
{
    try
    {
        texto->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (texto->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUTexto::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

// Coluna
void TUColuna::setUp()
{
    coluna = new Coluna();
    estado = SUCESSO;
}

void TUColuna::tearDown()
{
    delete coluna;
}

void TUColuna::testarCenarioSucesso()
{
    try
    {
        coluna->setValor(VALOR_VALIDO);
        if (coluna->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUColuna::testarCenarioFalha()
{
    try
    {
        coluna->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (coluna->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUColuna::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

// --------------------------------------------------------------------------
/**
 * Testes de Entidade
 */

// Definções de constantes e valores validos/invalidos para testes de unidade de cada entidade.

const string TUConta::VALOR_EMAIL_VALIDO = "ab@cde";
const string TUConta::VALOR_NOME_VALIDO = "Este texto esta correto.";
const string TUConta::VALOR_SENHA_VALIDO = "Te12!";

const string TUQuadro::VALOR_CODIGO_VALIDO = "AZ09";
const string TUQuadro::VALOR_NOME_VALIDO = "Este texto esta correto.";
const string TUQuadro::VALOR_DESCRICAO_VALIDO = "Este texto esta correto.";
const int TUQuadro::VALOR_LIMITE_VALIDO = 15;

const string TUCartao::VALOR_CODIGO_VALIDO = "AZ09";
const string TUCartao::VALOR_NOME_VALIDO = "Este texto esta correto.";
const string TUCartao::VALOR_DESCRICAO_VALIDO = "Este texto esta correto.";
const string TUCartao::VALOR_COLUNA_VALIDO = "SOLICITADO";

// Conta
void TUConta::setUp()
{
    conta = new Conta();
    estado = SUCESSO;
}

void TUConta::tearDown()
{
    delete conta;
}

void TUConta::testarCenarioSucesso()
{
    Email email;
    email.setValor(VALOR_EMAIL_VALIDO);
    conta->setEmail(email);
    if (conta->getEmail().getValor() != VALOR_EMAIL_VALIDO)
        estado = FALHA;

    Texto nome;
    nome.setValor(VALOR_NOME_VALIDO);
    conta->setNome(nome);
    if (conta->getNome().getValor() != VALOR_NOME_VALIDO)
        estado = FALHA;

    Senha senha;
    senha.setValor(VALOR_SENHA_VALIDO);
    conta->setSenha(senha);
    if (conta->getSenha().getValor() != VALOR_SENHA_VALIDO)
        estado = FALHA;
}

int TUConta::run()
{
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

// Quadro
void TUQuadro::setUp()
{
    quadro = new Quadro();
    estado = SUCESSO;
}

void TUQuadro::tearDown()
{
    delete quadro;
}

void TUQuadro::testarCenarioSucesso()
{
    Codigo codigo;
    codigo.setValor(VALOR_CODIGO_VALIDO);
    quadro->setCodigo(codigo);
    if (quadro->getCodigo().getValor() != VALOR_CODIGO_VALIDO)
        estado = FALHA;

    Texto nome;
    nome.setValor(VALOR_NOME_VALIDO);
    quadro->setNome(nome);
    if (quadro->getNome().getValor() != VALOR_NOME_VALIDO)
        estado = FALHA;

    Texto descricao;
    descricao.setValor(VALOR_DESCRICAO_VALIDO);
    quadro->setDescricao(descricao);
    if (quadro->getDescricao().getValor() != VALOR_DESCRICAO_VALIDO)
        estado = FALHA;

    Limite limite;
    limite.setValor(VALOR_LIMITE_VALIDO);
    quadro->setLimite(limite);
    if (quadro->getLimite().getValor() != VALOR_LIMITE_VALIDO)
        estado = FALHA;
}

int TUQuadro::run()
{
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

// Cartao
void TUCartao::setUp()
{
    cartao = new Cartao();
    estado = SUCESSO;
}

void TUCartao::tearDown()
{
    delete cartao;
}

void TUCartao::testarCenarioSucesso()
{
    Codigo codigo;
    codigo.setValor(VALOR_CODIGO_VALIDO);
    cartao->setCodigo(codigo);
    if (cartao->getCodigo().getValor() != VALOR_CODIGO_VALIDO)
        estado = FALHA;

    Texto nome;
    nome.setValor(VALOR_NOME_VALIDO);
    cartao->setNome(nome);
    if (cartao->getNome().getValor() != VALOR_NOME_VALIDO)
        estado = FALHA;

    Texto descricao;
    descricao.setValor(VALOR_DESCRICAO_VALIDO);
    cartao->setDescricao(descricao);
    if (cartao->getDescricao().getValor() != VALOR_DESCRICAO_VALIDO)
        estado = FALHA;

    Coluna coluna;
    coluna.setValor(VALOR_COLUNA_VALIDO);
    cartao->setColuna(coluna);
    if (cartao->getColuna().getValor() != VALOR_COLUNA_VALIDO)
    {
        estado = FALHA;
    }
}

int TUCartao::run()
{
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
