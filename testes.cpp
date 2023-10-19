#include "testes.h"

//Definções de constantes e valores validos/invalidos para testes de unidade de cada dominio.

const string TUDominio::SUCESSO;
const string TUDominio::FALHA;
const string TUDominio::VALOR_VALIDO;
const string TUDominio::VALOR_INVALIDO;

const string TUCodigo::VALOR_VALIDO = "12";
const string TUCodigo::VALOR_INVALIDO = "123teste";

const string TUEmail::VALOR_VALIDO = "tes.te1@teste.com";
const string TUEmail::VALOR_INVALIDO = "P@.com";

const string TULimite::VALOR_VALIDO = "15";
const string TULimite::VALOR_INVALIDO = "s12";

const string TUSenha::VALOR_VALIDO = "Teste123!";
const string TUSenha::VALOR_INVALIDO = "senhafraca";

const string TUTexto::VALOR_VALIDO = "Este texto está correto.";
const string TUTexto::VALOR_INVALIDO = "n  ..ao";

// Definições de métodos da classe TUDominio.

void inline TUDominio::setUp(){
    dominio = new Dominio();
    estado = SUCESSO;
}

void TUDominio::tearDown(){
    delete dominio;
}

void TUDominio::testarCenarioSucesso(){
    try{
        dominio->setValor(VALOR_VALIDO);
        if (dominio->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUDominio::testarCenarioFalha(){
    try{
        dominio->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

string TUDominio::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}