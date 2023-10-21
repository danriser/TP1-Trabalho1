#include "testes.h"
#include <stdexcept>
#include <iostream>

using namespace std;

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

// Definições de métodos da classe TUDominio.

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
