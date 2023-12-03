#include "../headers/comandos_servico.h"

EErroPersistencia::EErroPersistencia(string mensagem)
{
    this->mensagem = mensagem;
}

string EErroPersistencia::what()
{
    return mensagem;
}

void ElementoResultado::setNomeColuna(const string &nomeColuna)
{
    this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string &valorColuna)
{
    this->valorColuna = valorColuna;
}
void ComandoSQL::conectar()
{
    rc = sqlite3_open(nomeBancoDados, &bd);
    if (rc != SQLITE_OK)
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ComandoSQL::desconectar()
{
    rc = sqlite3_close(bd);
    if (rc != SQLITE_OK)
        throw EErroPersistencia("Erro na desconexao ao banco de dados");
}

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna)
{
    NotUsed = 0;
    ElementoResultado elemento;
    int i;
    for (i = 0; i < argc; i++)
    {
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i] : "NULL");
        listaResultado.push_front(elemento);
    }
    return 0;
}

void ComandoSQL::executar()
{
    conectar();
    rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
    if (rc != SQLITE_OK)
    {
        sqlite3_free(mensagem);
        desconectar();
        throw EErroPersistencia("Erro na execucao do comando SQL");
    }
    desconectar();
}
//----------------------------------------------------------------------------------------------------------------------
list<ElementoResultado> ComandoSQL::listaResultado;

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLLerSenha::ComandoSQLLerSenha(Email email)
{
    comandoSQL = "SELECT senha FROM conta WHERE email = '";
    comandoSQL += email.getValor();
    comandoSQL += "'";
}

string ComandoSQLLerSenha::getResultado()
{
    ElementoResultado resultado;
    string senha;
    if (listaResultado.empty())
    {
        return "NULL";
    }

    resultado = listaResultado.back();
    listaResultado.pop_back();
    senha = resultado.getValorColuna();
    listaResultado.clear();
    return senha;
}

ComandoSQLAutenticarCartao::ComandoSQLAutenticarCartao(Codigo quadro)
{
    comandoSQL = "SELECT codigo FROM cartao WHERE quadro = '";
    comandoSQL += quadro.getValor();
    comandoSQL += "'";
}
list<string> ComandoSQLAutenticarCartao::getResultado()
{
    ElementoResultado resultado;
    list<string> lista;
    if (listaResultado.empty())
    {
        return lista;
    }

    while (!listaResultado.empty())
    {
        resultado = listaResultado.back();
        listaResultado.pop_back();
        lista.push_back(resultado.getValorColuna());
    }
    listaResultado.clear();
    return lista;
}

ComandoSQLAutenticarQuadro::ComandoSQLAutenticarQuadro(Codigo quadro)
{
    comandoSQL = "SELECT codigo FROM quadros WHERE quadro = '";
    comandoSQL += quadro.getValor();
    comandoSQL += "'";
}

ComandoSQLAutenticarQuadro::ComandoSQLAutenticarQuadro(Email email)
{
    comandoSQL = "SELECT codigo FROM quadro WHERE email = '";
    comandoSQL += email.getValor();
    comandoSQL += "'";
}
list<string> ComandoSQLAutenticarQuadro::getResultado()
{
    ElementoResultado resultado;
    list<string> lista;
    if (listaResultado.empty())
    {
        return lista;
    }

    while (!listaResultado.empty())
    {
        resultado = listaResultado.back();
        listaResultado.pop_back();
        lista.push_back(resultado.getValorColuna());
    }
    listaResultado.clear();
    return lista;
}

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLLerEmail::ComandoSQLLerEmail(Email email)
{
    comandoSQL = "SELECT email FROM conta WHERE email = '";
    comandoSQL += email.getValor();
    comandoSQL += "'";
}

string ComandoSQLLerEmail::getResultado()
{
    ElementoResultado resultado;
    string email;

    if (listaResultado.empty())
    {
        return "NULL";
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
    email = resultado.getValorColuna();
    listaResultado.clear();
    return email;
}

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLLerCodigoCartao::ComandoSQLLerCodigoCartao(Codigo codigo)
{
    comandoSQL = "SELECT codigo FROM cartao WHERE codigo = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}

string ComandoSQLLerCodigoCartao::getResultado()
{
    ElementoResultado resultado;
    string codigo;

    if (listaResultado.empty())
        return "NULL";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    codigo = resultado.getValorColuna();
    listaResultado.clear();
    return codigo;
}

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLLerCodigoQuadro::ComandoSQLLerCodigoQuadro(Codigo codigo)
{
    comandoSQL = "SELECT codigo FROM quadro WHERE codigo = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}

string ComandoSQLLerCodigoQuadro::getResultado()
{
    ElementoResultado resultado;
    string codigo;

    if (listaResultado.empty())
        return "NULL";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    codigo = resultado.getValorColuna();
    listaResultado.clear();
    return codigo;
}

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLVisualizarConta::ComandoSQLVisualizarConta(Email email)
{
    comandoSQL = "SELECT * FROM conta WHERE email = ";
    comandoSQL += email.getValor();
}

Conta ComandoSQLVisualizarConta::getResultado()
{
    ElementoResultado resultado;
    Conta conta;
    Texto nome;
    Email email;
    Senha senha;
    for (int i = 0; i < 4; i++)
    {
        if (listaResultado.empty())
        {
            throw EErroPersistencia("Lista de resultados vazia.");
        }

        resultado = listaResultado.back(); // obtem último elemento
        listaResultado.pop_back();         // retira ele da lista

        switch (i)
        {
        case 2:
            senha.setValor(resultado.getValorColuna());
            break;
        case 1:
            email.setValor(resultado.getValorColuna());
            break;
        case 0:
            nome.setValor(resultado.getValorColuna());
            break;
        }
    }
    conta.setNome(nome);
    conta.setEmail(email);
    conta.setSenha(senha);
    listaResultado.clear();
    return conta;
}

ComandoSQLCadastrarConta::ComandoSQLCadastrarConta(Conta conta)
{
    comandoSQL = "INSERT INTO conta(nome,email,senha) VALUES (";
    comandoSQL += "'" + conta.getNome().getValor() + "', ";
    comandoSQL += "'" + conta.getEmail().getValor() + "', ";
    comandoSQL += "'" + conta.getSenha().getValor() + "', ";
    comandoSQL += ")";
}

ComandoSQLEditarConta::ComandoSQLEditarConta(Conta conta)
{
    comandoSQL = "UPDATE conta ";
    comandoSQL += "SET nome = '" + conta.getNome().getValor();
    comandoSQL += "', senha = '" + conta.getSenha().getValor();
    comandoSQL += "' WHERE email = " + conta.getEmail().getValor();
}

ComandoSQLDescadastrarConta::ComandoSQLDescadastrarConta(Email email)
{
    comandoSQL = "DELETE FROM conta WHERE email = ";
    comandoSQL += email.getValor();
}

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLContarQuadro::ComandoSQLContarQuadro(Email email)
{
    comandoSQL = "SELECT COUNT(codigo) from quadro where email = '";
    comandoSQL += email.getValor();
    comandoSQL += "'";
}
//-----------------------------------------------------------------------------------------------------------------------

ComandoSQLContarCartao::ComandoSQLContarCartao(Codigo quadro)
{
    comandoSQL = "SELECT COUNT(codigo) from cartao where quadro = '";
    comandoSQL += quadro.getValor();
    comandoSQL += "'";
}
int ComandoSQLContarCartao::getResultado()
{
    if (listaResultado.empty())
    {
        return 0;
    }

    ElementoResultado resultado;
    resultado = listaResultado.back();
    listaResultado.pop_back();
    string v = resultado.getValorColuna();
    int valor = stoi(v);
    listaResultado.clear();
    return valor;
}
ComandoSQLListarCartao::ComandoSQLListarCartao(Codigo codigo)
{
    comandoSQL = "SELECT codigo from cartao where email = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}
list<Codigo> ComandoSQLListarCartao::getResultado()
{
    list<Codigo> cartoes;
    Codigo codigo;
    if (listaResultado.empty())
    {
        return cartoes;
    }

    ElementoResultado resultado;
    for (int i = 0; i < 10; i++)
    {
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigo.setValor(resultado.getValorColuna());
        cartoes.push_back(codigo);
    }
    listaResultado.clear();
    return cartoes;
}
ComandoSQLListarQuadro::ComandoSQLListarQuadro(Email email)
{
    comandoSQL = "SELECT codigo from quadro where email = '";
    comandoSQL += email.getValor();
    comandoSQL += "'";
}
list<Email> ComandoSQLListarQuadro::getResultado()
{
    list<Email> quadro;
    Email email;
    if (listaResultado.empty())
    {
        return quadro;
    }

    ElementoResultado resultado;
    for (int i = 0; i < 10; i++)
    {
        resultado = listaResultado.back();
        listaResultado.pop_back();
        email.setValor(resultado.getValorColuna());
        quadro.push_back(email);
    }
    listaResultado.clear();
    return quadro;
}

ComandoSQLContarQuadro::ComandoSQLContarQuadro(Email email)
{
    comandoSQL = "SELECT COUNT(codigo) from email where email = '";
    comandoSQL += email.getValor();
    comandoSQL += "'";
}
//-----------------------------------------------------------------------------------------------------------------------
int ComandoSQLContarQuadro::getResultado()
{
    if (listaResultado.empty())
    {
        return 0;
    }

    ElementoResultado resultado;
    resultado = listaResultado.back();
    listaResultado.pop_back();
    string v = resultado.getValorColuna();
    int valor = stoi(v);
    listaResultado.clear();
    return valor;
}
//----------------------------------------------------------------------------------------------------------------------
ComandoSQLVisualizarCartao::ComandoSQLVisualizarCartao(Codigo codigo)
{
    comandoSQL = "SELECT * from cartao WHERE codigo = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}

Cartao ComandoSQLVisualizarCartao::getResultado()
{
    if (listaResultado.empty())
    {
        throw EErroPersistencia("Lista de resultados vazia.");
    }

    ElementoResultado resultado;
    Cartao cartao;
    Texto nome;
    Texto descricao;
    Codigo codigo;
    Coluna coluna;

    for (int i = 0; i < 3; i++)
    {
        resultado = listaResultado.back(); // obtem último elemento
        listaResultado.pop_back();         // retira ele da lista

        switch (i)
        {
        case 3:
            coluna.setValor(resultado.getValorColuna());
            break;    
        case 2:
            descricao.setValor(resultado.getValorColuna());
            break;
        case 1:
            codigo.setValor(resultado.getValorColuna());
            break;
        case 0:
            nome.setValor(resultado.getValorColuna());
            break;
        }
    }
    cartao.setColuna(coluna);
    cartao.setDescricao(descricao);
    cartao.setCodigo(codigo);
    cartao.setNome(nome);
    listaResultado.clear();
    return cartao;
}

ComandoSQLCadastrarCartao::ComandoSQLCadastrarCartao(Cartao cartao)
{
    comandoSQL = "INSERT INTO cartao(nome,codigo,coluna, descricao, quadro) VALUES (";
    comandoSQL += "'" + cartao.getNome().getValor() + "', ";
    comandoSQL += "'" + cartao.getCodigo().getValor() + "', ";
    comandoSQL += "'" + cartao.getDescricao().getValor() + "', ";
    comandoSQL += "'" + cartao.getQuadro().getValor() + "'";
    comandoSQL += ")";
}

ComandoSQLEditarCartao::ComandoSQLEditarCartao(Cartao cartao)
{
    comandoSQL = "UPDATE cartao ";
    comandoSQL += "SET nome = '" + cartao.getNome().getValor();
    comandoSQL += "', descricao = '" + cartao.getDescricao().getValor();
    comandoSQL += "', coluna = '" + cartao.getColuna().getValor();
    comandoSQL += "' WHERE codigo = '" + cartao.getCodigo().getValor();
    comandoSQL += "'";
}

ComandoSQLDescadastrarCartao::ComandoSQLDescadastrarCartao(Codigo codigo)
{
    comandoSQL = "DELETE FROM cartao WHERE codigo = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLVisualizarQuadro::ComandoSQLVisualizarQuadro(Codigo codigo)
{
    comandoSQL = "SELECT * from quadro WHERE codigo = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}

Quadro ComandoSQLVisualizarQuadro::getResultado()
{
    if (listaResultado.empty())
    {
        throw EErroPersistencia("Lista de resultados vazia.");
    }

    ElementoResultado resultado;
    Quadro quadro;
    Texto nome;
    Codigo codigo;
    Texto descricao;
    Limite limite;
    Email email;
    for (int i = 0; i < 7; i++)
    {
        resultado = listaResultado.back(); // obtem último elemento
        listaResultado.pop_back();         // retira ele da lista
        switch (i)
        {
        case 4:
            email.setValor(resultado.getValorColuna());
            break;
        case 3:
            limite.setValor(std::stoi(resultado.getValorColuna()));
            break;
        case 2:
            descricao.setValor(resultado.getValorColuna());
            break;
        case 1:
            codigo.setValor(resultado.getValorColuna());
            break;
        case 0:
            nome.setValor(resultado.getValorColuna());
            break;
        }
    }
    quadro.setDescricao(descricao);
    quadro.setCodigo(codigo);
    quadro.setLimite(limite);
    quadro.setNome(nome);
    quadro.setEmail(email);
    listaResultado.clear();
    return quadro;
}

ComandoSQLCadastrarQuadro::ComandoSQLCadastrarQuadro(Quadro quadro)
{
    comandoSQL = "INSERT INTO quadro(nome,codigo,descricao,limite, email) VALUES (";
    comandoSQL += "'" + quadro.getNome().getValor() + "', ";
    comandoSQL += "'" + quadro.getCodigo().getValor() + "', ";
    comandoSQL += "'" + quadro.getDescricao().getValor() + "', ";
    comandoSQL += quadro.getLimite().getValor() + " , ";
    comandoSQL += "'" + quadro.getEmail().getValor() + "'";
    comandoSQL += ")";
}

ComandoSQLEditarQuadro::ComandoSQLEditarQuadro(Quadro quadro)
{
    comandoSQL = "UPDATE quadro ";
    comandoSQL += "SET nome = '" + quadro.getNome().getValor();
    comandoSQL += "', descricao = '" + quadro.getDescricao().getValor();
    comandoSQL += "', limite = '" + quadro.getLimite().getValor();
    comandoSQL += "' WHERE codigo = '" + quadro.getCodigo().getValor();
    comandoSQL += "'";
}

ComandoSQLDescadastrarQuadro::ComandoSQLDescadastrarQuadro(Codigo codigo)
{
    comandoSQL = "DELETE FROM quadro WHERE codigo = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}
ComandoSQLDeletarQuadro::ComandoSQLDeletarQuadro(Email email)
{
    comandoSQL = "DELETE FROM quadro WHERE email = '";
    comandoSQL += email.getValor();
    comandoSQL += "'";
}
ComandoSQLDeletarCartao::ComandoSQLDeletarCartao(Codigo codigo)
{
    comandoSQL = "DELETE FROM testes WHERE codigo = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}