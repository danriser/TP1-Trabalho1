#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include <stdexcept>
#include <iostream>
#include "Dominios.h"

using namespace std;

// EXEMPLO
// --------------------------------------------------------

// Teste de unidade de classe que representa um dom�nio.

class TUDominio {
private:
    // Definições de constantes com o intuito de evitar numeros mágicos.

    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Dominio *dominio;         // Referência para o objeto a ser testado.

    string estado;             // Estado do teste.

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    // Definições de constantes para reportar resultado do teste.

    const static string SUCESSO;
    const static string FALHA;
    string run();

};

class TUCodigo:public TUDominio {

private:

   Codigo *codigo;

public:


};

class TUEmail:TUDominio {
private:

    Email *email;
    
public:


};

class TULimite:TUDominio {
private:

    Limite *limite;
    
public:


};

class TUSenha:TUDominio {
private:

    Senha *senha;

public:


};

class TUTexto:TUDominio {
private:

    Texto *texto;
public:


};
#endif // TESTES_H_INCLUDED
