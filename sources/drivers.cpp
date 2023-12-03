#include "../headers/drivers.h"

//----------------------------------------------------------------------------------------------------------------------
void Drivers::showResult(bool resultado, string nome, int l)
{
    string texto1 = "SUCESSO";
    string texto2 = "FALHA";

    int linha, coluna;
    getmaxyx(stdscr, linha, coluna);

    int linha_atual = linha / 4 + l;

    texto1 = nome + string(16 - nome.length(), '.') + texto1;
    texto2 = nome + string(16 - nome.length(), '.') + texto2;

    if (resultado)
    {
        mvprintw(linha_atual, coluna / 4, "%s", texto1.c_str());
    }
    else
    {
        mvprintw(linha_atual, coluna / 4, "%s", texto2.c_str());
    }
}

//----------------------------------------------------------------------------------------------------------------------
void DriverDepuracao::executar()
{
    DriverTestesUnitarios testesUnitarios;
    DriverTestesIntegracao testesIntegracao;

    int campo;

    bool apresentar = true;
    while (apresentar)
    {
        TelaDepuracao telaDepuracao;
        telaDepuracao.selecionar(&campo);

        switch (campo)
        {
        case TESTE_UNITARIO:
            testesUnitarios.executar();
            break;
        case TESTE_INTEGRACAO:
            testesIntegracao.executar();
            break;
        case TESTE_SISTEMA:
            break;
        case SAIR:
            apresentar = false;
            break;
        default:
            TelaMensagem telaMensagem;
            telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
            break;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------
void DriverTestesUnitarios::executar()
{
    DriverTestesDominios testesDominios;
    DriverTestesEntidades testesEntidades;
    DriverTestesModulos testesModulos;

    int campo;
    bool apresentar = true;
    while (apresentar)
    {
        TelaTestesUnitarios telaTestesUnitarios;
        telaTestesUnitarios.selecionar(&campo);

        switch (campo)
        {
        case DOMINIOS:
            testesDominios.executar();
            break;
        case ENTIDADES:
            testesEntidades.executar();
            break;
        case MODULOS:
            testesModulos.executar();
            break;
        case RETORNAR:
            apresentar = false;
            break;
        default:
            TelaMensagem telaMensagem;
            telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
            break;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------
void DriverTestesDominios::executar()
{
    int linha, coluna;
    string title = "DOMINIOS";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", title.c_str());
    showResult(testeCodigo.run(), "Codigo", 1);
    showResult(testeEmail.run(), "Email", 2);
    showResult(testeColuna.run(), "Coluna", 3);
    showResult(testeSenha.run(), "Senha", 4);
    showResult(testeLimite.run(), "Telefone", 5);
    showResult(testeTexto.run(), "Texto", 6);

    mvprintw(linha / 4 + 9, coluna / 4, "%s", "");
    echo();
    getch();
    noecho();

    endwin();
}

//----------------------------------------------------------------------------------------------------------------------
void DriverTestesEntidades::executar()
{
    int linha, coluna;
    string title = "ENTIDADES";

    initscr();
    getmaxyx(stdscr, linha, coluna);

    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", title.c_str());
    showResult(testeConta.run(), "Conta", 1);
    showResult(testeCartao.run(), "Teste", 2);
    showResult(testeQuadro.run(), "Quadro", 3);

    mvprintw(linha / 4 + 4, coluna / 4, "%s", "");
    echo();
    getch();
    noecho();

    endwin();
}

//----------------------------------------------------------------------------------------------------------------------
void DriverTestesModulos::executar()
{
    TUIAAutenticacao testeAutenticacao;
    TUIAConta testeConta;
    TUIACartao testeCartao;
    TUIAQuadro testeQuadro;

    int campo;
    bool apresentar = true;
    while (apresentar)
    {
        TelaTestesModulos telaTestesModulos;
        telaTestesModulos.selecionar(&campo);

        switch (campo)
        {
        case AUTENTICACAO:
            testeAutenticacao.executar();
            break;
        case CONTA:
            testeConta.executar();
            break;
        case CARTAO:
            testeCartao.executar();
            break;
        case QUADRO:
            testeQuadro.executar();
            break;
        case RETORNAR:
            apresentar = false;
            break;
        default:
            TelaMensagem telaMensagem;
            telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
            break;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------
void DriverTestesIntegracao::executar()
{
    TIApresentacao testeApresentacao;

    int campo;
    bool apresentar = true;
    while (apresentar)
    {
        TelaTestesIntegracao telaTestesIntegracao;
        telaTestesIntegracao.selecionar(&campo);

        switch (campo)
        {
        case CAMADA_APRESENTACAO:
            testeApresentacao.executar();
            break;
        case RETORNAR:
            apresentar = false;
            break;
        default:
            TelaMensagem telaMensagem;
            telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
            break;
        }
    }
}