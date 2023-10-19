#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include <stdexcept>
#include <iostream>
#include "Dominios.h"

using namespace std;

// Teste de unidade de classe que representa um domínio.

class TUDominio {
private:

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
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO; 
    Codigo *codigo;

public:

};


class TUEmail:public TUDominio {
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO; 
    Email *email;
    
public:


};



class TULimite:public TUDominio {
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO; 
    Limite *limite;
    
public:


};

class TUSenha:public TUDominio {
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO; 
    Senha *senha;

public:


};

class TUTexto:TUDominio {
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO; 
    Texto *texto;
public:


};

#endif // TESTES_H_INCLUDED
