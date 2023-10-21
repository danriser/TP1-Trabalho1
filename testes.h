#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include <stdexcept>
#include <iostream>
#include "Dominios.h"

using namespace std;

// Teste de unidade de classe que representa um domínio.

class TUCodigo {
private:

    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Codigo *codigo;         // Referência para o objeto a ser testado.

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

class TUEmail {
private:

    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Email *email;         // Referência para o objeto a ser testado.

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

class TULimite {
private:

    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Limite *limite;         // Referência para o objeto a ser testado.

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

class TUSenha {
private:

    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Senha *senha;         // Referência para o objeto a ser testado.

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

class TUTexto {
private:

    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Texto *texto;         // Referência para o objeto a ser testado.

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


#endif // TESTES_H_INCLUDED