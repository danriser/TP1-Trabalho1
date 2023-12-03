#ifndef COMANDOS_SERVICOS_H_INCLUDED
#define COMANDOS_SERVICOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include <list>

#include "dominios.h"
#include "entidades.h"
#include "sqlite3.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
class EErroPersistencia
{
private:
    string mensagem;

public:
    EErroPersistencia(string);
    string what();
};

//----------------------------------------------------------------------------------------------------------------------
class ElementoResultado
{
private:
    string nomeColuna;
    string valorColuna;

public:
    void setNomeColuna(const string &);
    string getNomeColuna() const;
    void setValorColuna(const string &);
    string getValorColuna() const;
};

inline string ElementoResultado::getNomeColuna() const
{
    return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const
{
    return valorColuna;
}
//----------------------------------------------------------------------------------------------------------------------
class ComandoSQL
{
private:
    const char *nomeBancoDados;
    sqlite3 *bd;
    char *mensagem;
    int rc;

    void conectar();
    void desconectar();
    static int callback(void *, int, char **, char **);

protected:
    static list<ElementoResultado> listaResultado;
    string comandoSQL;

public:
    ComandoSQL()
    {
        nomeBancoDados = "database";
        // criartabelas();
    }
    void criartabelas();
    void executar();
};

//----------------------------------------------------------------------------------------------------------------------
class ComandoSQLLerSenha : public ComandoSQL
{
private:
public:
    ComandoSQLLerSenha(Email);
    string getResultado();
};

class ComandoSQLLerEmail : public ComandoSQL
{
private:
public:
    ComandoSQLLerEmail(Email);
    string getResultado();
};

class ComandoSQLLerCodigoCartao : public ComandoSQL
{
public:
    ComandoSQLLerCodigoCartao(Codigo);
    string getResultado();
};

class ComandoSQLLerCodigoQuadro : public ComandoSQL
{
public:
    ComandoSQLLerCodigoQuadro(Codigo);
    string getResultado();
};

//----------------------------------------------------------------------------------------------------------------------
class ComandoSQLVisualizarConta : public ComandoSQL
{
public:
    ComandoSQLVisualizarConta(Email);
    Conta getResultado();
};

class ComandoSQLCadastrarConta : public ComandoSQL
{
public:
    ComandoSQLCadastrarConta(Conta);
};

class ComandoSQLEditarConta : public ComandoSQL
{
public:
    ComandoSQLEditarConta(Conta);
};

class ComandoSQLDescadastrarConta : public ComandoSQL
{
public:
    ComandoSQLDescadastrarConta(Email);
};

//----------------------------------------------------------------------------------------------------------------------
class ComandoSQLContarCartao : public ComandoSQL
{
public:
    ComandoSQLContarCartao(Codigo);
    int getResultado();
};
class ComandoSQLAutenticarCartao : public ComandoSQL
{
public:
    ComandoSQLAutenticarCartao(Codigo);
    list<string> getResultado();
};
class ComandoSQLAutenticarQuadro : public ComandoSQL
{
public:
    ComandoSQLAutenticarQuadro(Email);
    ComandoSQLAutenticarQuadro(Codigo);
    list<string> getResultado();
};
// class ComandoSQLAutenticarAssociacoesTeste: public ComandoSQL{
//     public:
//     ComandoSQLAutenticarAssociacoesTeste(Email);
//     string getResultado();
// };
class ComandoSQLContarQuadro : public ComandoSQL
{
public:
    ComandoSQLContarQuadro(Email);
    int getResultado();
};

class ComandoSQLVisualizarCartao : public ComandoSQL
{
public:
    ComandoSQLVisualizarCartao(Codigo);
    Cartao getResultado();
};

class ComandoSQLCadastrarCartao : public ComandoSQL
{
public:
    ComandoSQLCadastrarCartao(Cartao);
};

class ComandoSQLEditarCartao : public ComandoSQL
{
public:
    ComandoSQLEditarCartao(Cartao);
};

class ComandoSQLDescadastrarCartao : public ComandoSQL
{
public:
    ComandoSQLDescadastrarCartao(Codigo);
};
class ComandoSQLDeletarCartao : public ComandoSQL
{
public:
    ComandoSQLDeletarCartao(Codigo);
};
class ComandoSQLListarCartao : public ComandoSQL
{
public:
    ComandoSQLListarCartao(Codigo);
    list<Codigo> getResultado();
};

//----------------------------------------------------------------------------------------------------------------------
class ComandoSQLListarQuadro : public ComandoSQL
{
public:
    ComandoSQLListarQuadro(Email);
    list<Email> getResultado();
};
class ComandoSQLDeletarQuadro : public ComandoSQL
{
public:
    ComandoSQLDeletarQuadro(Codigo);
    ComandoSQLDeletarQuadro(Email);
};
class ComandoSQLVisualizarQuadro : public ComandoSQL
{
public:
    ComandoSQLVisualizarQuadro(Codigo);
    Quadro getResultado();
};

class ComandoSQLCadastrarQuadro : public ComandoSQL
{
public:
    ComandoSQLCadastrarQuadro(Quadro);
};

class ComandoSQLEditarQuadro : public ComandoSQL
{
public:
    ComandoSQLEditarQuadro(Quadro);
};

class ComandoSQLDescadastrarQuadro : public ComandoSQL
{
public:
    ComandoSQLDescadastrarQuadro(Codigo);
};

#endif // COMANDOS_SERVICOS_H_INCLUDED