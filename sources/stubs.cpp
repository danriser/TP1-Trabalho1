#include "../headers/stubs.h"

//----------------------------------------------------------------------------------------------------------------------
const string StubISAutenticacao::VALOR_VALIDO_SENHA = "abc123";
const string StubISAutenticacao::VALOR_VALIDO_EMAIL = "abc@de";
Senha StubISAutenticacao::senhaStub;
Email StubISAutenticacao::emailStub;

bool StubISAutenticacao::autenticar(Email email, Senha senha)
{
    if (email.getValor() == emailStub.getValor())
    {
        if (senha.getValor() == senhaStub.getValor())
        {
            return SUCESSO;
        }
        else
        {
            return FALHA;
        }
    }
    else
    {
        return FALHA;
    }
}
//----------------------------------------------------------------------------------------------------------------------
const string StubISConta::VALOR_VALIDO_EMAIL = "abc@de";
const string StubISConta::VALOR_VALIDO_NOME = "joazinho";
const string StubISConta::VALOR_VALIDO_SENHA = "abc123";
Conta StubISConta::contaStub;
Senha StubISConta::senhaConta;
;
Email StubISConta::emailConta;
Texto StubISConta::nomeConta;

bool StubISConta::visualizar(Conta *conta)
{
    if (conta->getEmail().getValor() == contaStub.getEmail().getValor())
    {
        conta->setNome(nomeConta);
        conta->setSenha(senhaConta);
    }
    else
    {
        return FALHA;
    }
    return SUCESSO;
}

bool StubISConta::cadastrar(Conta conta)
{
    if (conta.getEmail().getValor() == contaStub.getEmail().getValor())
    {
        return FALHA;
    }
    else if (conta.getEmail().getValor() == "")
    {
        return FALHA;
    }

    return SUCESSO; // Verificação dos dados já é feita nas telas
}

bool StubISConta::editar(Conta conta)
{
    try
    {
        if (conta.getNome().getValor() != "")
        {
            StubISConta::nomeConta.setValor(conta.getNome().getValor());
            StubISConta::contaStub.setNome(StubISConta::nomeConta);
        }
        if (conta.getSenha().getValor() != "")
        {
            StubISConta::senhaConta.setValor(conta.getSenha().getValor());
            StubISConta::contaStub.setSenha(StubISConta::senhaConta);
        }
    }
    catch (invalid_argument &exp)
    {
        return FALHA;
    }
    return SUCESSO;
}

bool StubISConta::descadastrar(Email email)
{
    if (email.getValor() != contaStub.getEmail().getValor())
    {
        return FALHA;
    }

    return SUCESSO; // Verificação dos dados já é feita nas telas
}

//----------------------------------------------------------------------------------------------------------------------
const string StubISCartao::VALOR_VALIDO_CODIGO = "UN12";
const string StubISCartao::VALOR_VALIDO_NOME = "Bolo";
const string StubISCartao::VALOR_VALIDO_DESCRICAO = "de chocolate";
const string StubISCartao::VALOR_VALIDO_COLUNA = "SOLICITADO";

Cartao StubISCartao::cartaoStub;
Codigo StubISCartao::codigoCartao;
Texto StubISCartao::nomeCartao;
Texto StubISCartao::descricaoCartao;
Coluna StubISCartao::colunaCartao;

bool StubISCartao::visualizar(Cartao *cartao)
{ // Passado apenas com o código
    if (cartao->getCodigo().getValor() == cartaoStub.getCodigo().getValor())
    { // Procura no BD e passa os valores pra cima
        cartao->setCodigo(codigoCartao);
        cartao->setNome(nomeCartao);
        cartao->setDescricao(descricaoCartao);
        cartao->setColuna(colunaCartao);
    }
    else
    {
        return FALHA;
    }

    return SUCESSO;
}

bool StubISCartao::cadastrar(Cartao cartao)
{
    if (cartao.getCodigo().getValor() == cartaoStub.getCodigo().getValor())
    {
        return FALHA;
    }
    else if (cartao.getCodigo().getValor() == "")
    {
        return FALHA;
        if (cartao.getCodigo().getValor() == cartaoStub.getCodigo().getValor())
        {
            return FALHA;
        }
        else if (cartao.getCodigo().getValor() == "")
        {
            return FALHA;
        }
    }
    return SUCESSO; // Verificação dos dados já é feita nas telas
}

bool StubISCartao::editar(Cartao cartao)
{
    try
    {
        if (cartao.getNome().getValor() != "")
        {
            StubISCartao::nomeCartao.setValor(cartao.getNome().getValor());
            StubISCartao::cartaoStub.setNome(StubISCartao::nomeCartao);
        }
        if (cartao.getDescricao().getValor() != "")
        {
            StubISCartao::descricaoCartao.setValor(cartao.getDescricao().getValor());
            StubISCartao::cartaoStub.setDescricao(StubISCartao::descricaoCartao);
        }
        if (cartao.getColuna().getValor() != "")
        {
            StubISCartao::colunaCartao.setValor(cartao.getColuna().getValor());
            StubISCartao::cartaoStub.setColuna(StubISCartao::colunaCartao);
        }
    }
    catch (invalid_argument &exp)
    {
        return FALHA;
    }

    return SUCESSO;
}

bool StubISCartao::descadastrar(Codigo codigo)
{
    if (codigo.getValor() != cartaoStub.getCodigo().getValor())
    {
        return FALHA;
    }

    return SUCESSO; // Verificação dos dados já é feita nas telas
}

//----------------------------------------------------------------------------------------------------------------------
const string StubISQuadro::VALOR_VALIDO_CODIGO = "UN12";
const string StubISQuadro::VALOR_VALIDO_NOME = "Bolo";
const string StubISCartao::VALOR_VALIDO_DESCRICAO = "de chocolate";
const int StubISQuadro::VALOR_VALIDO_LIMITE = 15;

Quadro StubISQuadro::quadroStub;

Codigo StubISQuadro::codigoQuadro;
Texto StubISQuadro::nomeQuadro;
Texto StubISQuadro::descricaoQuadro;
Limite StubISQuadro::limiteQuadro;

bool StubISQuadro::visualizar(Quadro *quadro)
{ // Passado apenas com o código
    if (quadro->getCodigo().getValor() == quadroStub.getCodigo().getValor())
    { // Não achou no BD
        quadro->setCodigo(codigoQuadro);
        quadro->setNome(nomeQuadro);
        quadro->setDescricao(descricaoQuadro);
        quadro->setLimite(limiteQuadro);
    }
    else
    {
        return FALHA;
    }

    return SUCESSO;
}

bool StubISQuadro::cadastrar(Quadro quadro)
{
    if (quadro.getCodigo().getValor() == quadroStub.getCodigo().getValor())
    {
        return FALHA;
    }
    else if (quadro.getCodigo().getValor() == "")
    {
        return FALHA;
    }

    return SUCESSO; // Verificação dos dados já é feita nas telas
}

bool StubISQuadro::editar(Quadro quadro)
{
    try
    {
        if (quadro.getNome().getValor() != "")
        {
            StubISQuadro::nomeQuadro.setValor(quadro.getNome().getValor());
            StubISQuadro::quadroStub.setNome(StubISQuadro::nomeQuadro);
        }
        if (quadro.getDescricao().getValor() != "")
        {
            StubISQuadro::descricaoQuadro.setValor(quadro.getDescricao().getValor());
            StubISQuadro::quadroStub.setDescricao(StubISQuadro::descricaoQuadro);
        }
        if (quadro.getLimite().getValor() != 7)
        {
            StubISQuadro::limiteQuadro.setValor(quadro.getLimite().getValor());
            StubISQuadro::quadroStub.setLimite(StubISQuadro::limiteQuadro);
        }
    }
    catch (invalid_argument &exp)
    {
        return FALHA;
    }

    return SUCESSO;
}

bool StubISQuadro::descadastrar(Codigo codigo)
{
    if (codigo.getValor() != quadroStub.getCodigo().getValor())
    {
        return FALHA;
    }

    return SUCESSO; // Verificação dos dados já é feita nas telas
}