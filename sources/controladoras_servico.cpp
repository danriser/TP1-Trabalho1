#include "../headers/controladoras_servico.h"

using namespace std;
//--------------------------------------------------------------------------------------------
bool CtrlISAutenticacao::autenticar(Email email, Senha senha)
{
    ComandoSQLLerEmail comandoLerEmail(email);
    comandoLerEmail.executar();
    if (comandoLerEmail.getResultado() != email.getValor())
    {
        // se não achar email informada
        return false;
    }

    ComandoSQLLerSenha comandoLerSenha(email);
    comandoLerSenha.executar();

    return (comandoLerSenha.getResultado() == senha.getValor());
}

//----------------------------------------------------------------------------------------------------------------------
bool CtrlISConta::visualizar(Conta *conta)
{
    try
    {
        ComandoSQLVisualizarConta comandoVisualizar(conta->getEmail());
        comandoVisualizar.executar();
        *conta = comandoVisualizar.getResultado();
    }
    catch (EErroPersistencia &exp)
    {
        return false;
    }

    return true;
}

bool CtrlISConta::cadastrar(Conta conta)
{
    try
    {
        ComandoSQLLerEmail comandoLerEmail(conta.getEmail());
        comandoLerEmail.executar();

        if (comandoLerEmail.getResultado() != "NULL")
        {
            // se matrícula já estiver cadastrada
            return false;
        }
        if (
            conta.getEmail().getValor().empty() or
            conta.getNome().getValor().empty() or
            conta.getSenha().getValor().empty())
        {
            return false;
        }

        ComandoSQLCadastrarConta comandoCadastrar(conta);
        comandoCadastrar.executar();
    }
    catch (EErroPersistencia &exp)
    {
        return false;
    }
    //
    return true;
}

bool CtrlISConta::editar(Conta conta)
{
    try
    {
        if (
            conta.getEmail().getValor().empty() or
            conta.getNome().getValor().empty() or
            conta.getSenha().getValor().empty())
        {
            return false;
        }
        ComandoSQLEditarConta comandoEditar(conta);
        comandoEditar.executar();
    }
    catch (EErroPersistencia &exp)
    {
        return false;
    }

    return true;
}

bool CtrlISConta::descadastrar(Email email)
{
    try
    {
        ComandoSQLContarQuadro contarQuadro(email);
        ComandoSQLDescadastrarConta comandoDescadastrar(email);
        ComandoSQLDeletarQuadro deletarQuadro(email);
        contarQuadro.executar();
        if (contarQuadro.getResultado() > 0)
        {
            deletarQuadro.executar();
            comandoDescadastrar.executar();
        }
        else
        {
            comandoDescadastrar.executar();
        }
    }
    catch (EErroPersistencia &exp)
    {
        return false;
    }

    return true;
}
//----------------------------------------------------------------------------------------------------------------------
bool CtrlISCartao::visualizar(Cartao *cartao)
{
    try
    {
        ComandoSQLLerCodigoCartao lerCodigo(cartao->getCodigo());
        lerCodigo.executar();
        if (lerCodigo.getResultado() == "NULL")
        {
            return false;
        }
        Codigo codigo_confirmacao = cartao->getCodigo();
        ComandoSQLAutenticarCartao autenticarCartao(codigo_confirmacao);
        autenticarCartao.executar();
        list<string> cartoes = autenticarCartao.getResultado();
        if (cartoes.empty())
        {
            return false;
        }
        string codigo;
        bool erro = true;
        while (!cartoes.empty())
        {
            codigo = cartoes.back();
            cartoes.pop_back();
            Codigo codigoteste = cartao->getCodigo();
            if (codigo == codigoteste.getValor())
            {
                erro = false;
                break;
            }
        }
        if (erro)
        {
            return false;
        }

        ComandoSQLVisualizarCartao comandoVisualizar(cartao->getCodigo());
        comandoVisualizar.executar();
        *cartao = comandoVisualizar.getResultado();
    }
    catch (EErroPersistencia &exp)
    {
        return false;
    }

    return true;
}

bool CtrlISCartao::cadastrar(Cartao cartao)
{
    try
    {
        if (
            cartao.getDescricao().getValor().empty() or
            cartao.getNome().getValor().empty() or
            cartao.getColuna().getValor().empty() or
            cartao.getQuadro().getValor().empty() or
            cartao.getCodigo().getValor().empty())
        {
            return false;
        }
        ComandoSQLLerCodigoCartao comandoLerCodigo(cartao.getCodigo());
        comandoLerCodigo.executar();
        if (comandoLerCodigo.getResultado() != "NULL")
        {
            // se não achar codigo informado
            return false;
        }
        ComandoSQLCadastrarCartao comandoCadastrarCartao(cartao);
        comandoCadastrarCartao.executar();
    }
    catch (EErroPersistencia &exp)
    {
        return false;
    }

    return true;
}

bool CtrlISCartao::editar(Cartao cartao)
{
    try
    {
        if (
            cartao.getDescricao().getValor().empty() or
            cartao.getNome().getValor().empty() or
            cartao.getColuna().getValor().empty() or
            cartao.getQuadro().getValor().empty() or
            cartao.getCodigo().getValor().empty())
        {
            return false;
        }
        ComandoSQLLerCodigoCartao lerCodigo(cartao.getCodigo());
        lerCodigo.executar();
        if (lerCodigo.getResultado() == "NULL")
        {
            return false;
        }

        ComandoSQLEditarCartao comandoEditar(cartao);
        comandoEditar.executar();
    }
    catch (EErroPersistencia &exp)
    {
        return false;
    }

    return true;
}

bool CtrlISCartao::descadastrar(Codigo codigo)
{
    try
    {
        ComandoSQLDescadastrarCartao comandoDescadastrar(codigo);
        comandoDescadastrar.executar();
    }
    catch (EErroPersistencia &exp)
    {
        return false;
    }

    return true;
}

//----------------------------------------------------------------------------------------------------------------------
bool CtrlISQuadro::visualizar(Quadro *quadro)
{
    try
    {
        ComandoSQLLerCodigoQuadro lerCodigo(quadro->getCodigo());
        lerCodigo.executar();
        if (lerCodigo.getResultado() == "NULL")
        {
            return false;
        }
        ComandoSQLAutenticarQuadro autenticar(quadro->getEmail());
        autenticar.executar();
        list<string> casotestes = autenticar.getResultado();
        if (casotestes.empty())
        {
            return false;
        }
        string codigo;
        bool erro = true;
        while (!casotestes.empty())
        {
            codigo = casotestes.back();
            casotestes.pop_back();
            Codigo codigoteste = quadro->getCodigo();
            if (codigo == codigoteste.getValor())
            {
                erro = false;
                break;
            }
        }
        if (erro)
        {
            return false;
        }
        ComandoSQLVisualizarQuadro comandoVisualizar(quadro->getCodigo());
        comandoVisualizar.executar();
        *quadro = comandoVisualizar.getResultado();
    }
    catch (EErroPersistencia &exp)
    {
        return false;
    }

    return true;
}

bool CtrlISQuadro::cadastrar(Quadro quadro)
{
    try
    {
        if (
            quadro.getLimite().getValor() == 0 or
            quadro.getNome().getValor().empty() or
            quadro.getCodigo().getValor().empty() or
            quadro.getDescricao().getValor().empty() or
            quadro.getEmail().getValor().empty())
        {
            return false;
        }
        ComandoSQLLerCodigoQuadro lerCodigo(quadro.getCodigo());
        ComandoSQLContarQuadro comandoSQLContarQuadro(quadro.getEmail());
        string codigo;
        bool erro = true;

        ComandoSQLCadastrarQuadro comandoCadastrar(quadro);
        comandoCadastrar.executar();
    }
    catch (EErroPersistencia &exp)
    {
        return false;
    }

    return true;
}

bool CtrlISQuadro::editar(Quadro quadro)
{
    try
    {
        ComandoSQLLerCodigoQuadro lerCodigo(quadro.getCodigo());
        lerCodigo.executar();
        if (lerCodigo.getResultado() == "NULL")
        {
            return false;
        }

        ComandoSQLEditarQuadro comandoEditar(quadro);
        comandoEditar.executar();
    }
    catch (EErroPersistencia &exp)
    {
        return false;
    }

    return true;
}

bool CtrlISQuadro::descadastrar(Codigo codigo)
{
    try
    {
        
        ComandoSQLDescadastrarQuadro comandoDescadastrar(codigo);
        comandoDescadastrar.executar();
    }
    catch (EErroPersistencia &exp)
    {
        return false;
    }

    return true;
}