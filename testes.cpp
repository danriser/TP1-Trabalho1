#include "testes.h"

//Defini��es de constantes.

const string TUDominio::SUCESSO;
const string TUDominio::FALHA;
const string TUDominio::VALOR_VALIDO;
const string TUDominio::VALOR_INVALIDO;

// EXEMPLO
// --------------------------------------------------------

// Defini��es de m�todos da classe TUDominio.

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