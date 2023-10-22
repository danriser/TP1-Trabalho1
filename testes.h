#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include <stdexcept>
#include <iostream>
#include "entidades.h"
#include "dominios.h"

using namespace std;

/*! \brief Teste de Dominio de Codigo
 *
 * O teste verifica se a validação de codigo é feita com sucesso.
 */
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

/*! \brief Teste de Dominio de Email
 *
 * O teste verifica se a validação de email é feita com sucesso.
 */
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

/*! \brief Teste de Dominio de Limite
 *
 * O teste verifica se a validação de limite é feita com sucesso.
 */
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

/*! \brief Teste de Dominio de Senha
 *
 * O teste verifica se a validação de senha é feita com sucesso.
 */
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

/*! \brief Teste de Dominio de Texto
 *
 * O teste verifica se a validação de texto é feita com sucesso.
 */
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

/*! \brief Teste de Dominio de Coluna
 *
 * O teste verifica se a validação de coluna é feita com sucesso.
 */
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

/*! \brief Teste de Entidade de Conta
 *
 *
 * O teste valida se objetos de email, nome e senha são invocados com suceso.
 */

class TUConta
{
    /*! \brief Descrição breve
     *
     *
     * Inicio a descrição detalhada.
     */

private:
    const static string VALOR_EMAIL_VALIDO;
    const static string VALOR_NOME_VALIDO;
    const static string VALOR_SENHA_VALIDO;
    Conta *conta;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

/*! \brief Teste de Entidade de Quadro
 *
 * O teste valida se objetos de codigo, nome, descricao e limite são invocados com suceso.
 */
class TUQuadro
{
private:
    const static string VALOR_CODIGO_VALIDO;
    const static string VALOR_NOME_VALIDO;
    const static string VALOR_DESCRICAO_VALIDO;
    const static int VALOR_LIMITE_VALIDO;
    Quadro *quadro;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

/*! \brief Teste de Entidade de Cartao
 *
 * O teste valida se objetos de codigo, nome, coluna e descricao sao invocados com suceso.
 */
class TUCartao
{
private:
    const static string VALOR_CODIGO_VALIDO;
    const static string VALOR_NOME_VALIDO;
    const static string VALOR_DESCRICAO_VALIDO;
    const static string VALOR_COLUNA_VALIDO;
    Cartao *cartao;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

#endif // TESTES_H_INCLUDED