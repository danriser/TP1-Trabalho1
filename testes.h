#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include <stdexcept>
#include <iostream>
#include "entidades.h"
#include "entidades.cpp"
#include "dominios.h"

using namespace std;

// Teste de unidade de classe que representa um domínio.

class TUCodigo
{
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Codigo *codigo; // Referência para o objeto a ser testado.

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    // Definições de constantes para reportar resultado do teste.

    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

class TUEmail
{
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Email *email; // Referência para o objeto a ser testado.

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    // Definições de constantes para reportar resultado do teste.

    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

class TULimite
{
private:
    const static int VALOR_VALIDO;
    const static int VALOR_INVALIDO;

    Limite *limite; // Referência para o objeto a ser testado.

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    // Definições de constantes para reportar resultado do teste.

    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

class TUSenha
{
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Senha *senha; // Referência para o objeto a ser testado.

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    // Definições de constantes para reportar resultado do teste.

    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

class TUTexto
{
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Texto *texto; // Referência para o objeto a ser testado.

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    // Definições de constantes para reportar resultado do teste.

    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

class TUColuna
{
private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Coluna *coluna; // Referência para o objeto a ser testado.

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    // Definições de constantes para reportar resultado do   teste.

    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

// --------------------------------------------------------------------------
/**
 * Testes de Entidade
 */

class TUConta{
private:
    Conta *conta;                      
    int estado;                            
    void setUp();                           
    void tearDown();                        
    void testarCenarioSucesso();          
public:
    const static int SUCESSO =  0;         
    const static int FALHA   = -1;         
    int run();                             
};

class TUQuadro {
private:
    Quadro *quadro;                      
    int estado;                            
    void setUp();                           
    void tearDown();                        
    void testarCenarioSucesso();            
public:
    const static int SUCESSO =  0;         
    const static int FALHA   = -1;         
    int run();                             
};

class TUCartao {
private:
    Cartao *cartao;                      
    int estado;                            
    void setUp();                           
    void tearDown();                        
    void testarCenarioSucesso();            
public:
    const static int SUCESSO =  0;         
    const static int FALHA   = -1;         
    int run();                             
};

#endif  // TESTES_H_INCLUDED