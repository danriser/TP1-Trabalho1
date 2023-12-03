#include "../headers/telas.h"

//----------------------------------------------------------------------------------------------------------------------
void TelaMensagem::apresentar(string mensagem)
{
    initscr();
    getmaxyx(stdscr, linha, coluna);

    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", mensagem.c_str());

    noecho();
    getch();
    echo();

    endwin();
}

//----------------------------------------------------------------------------------------------------------------------
void TelaInicial::selecionar(int *campo)
{
    // Mensagens a serem apresentadas na tela inicial
    string titulo1 = "Selecione um dos servicos.";
    vector<string> texto1 = {"1 - Acessar sistema.",
                             "2 - Cadastrar conta",
                             "3 - Encerrar execucao do sistema.",
                             "Escolha uma opcao : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();
    *campo = getch() - '0';
    noecho();

    endwin();
}

//----------------------------------------------------------------------------------------------------------------------
void TelaAutenticacao::autenticar(Email *email, Senha *senha)
{
    string titulo1 = "Preencha os seguintes campos.";
    vector<string> texto1{"Email",
                          "Senha"};
    string textoErro = "Valor inválido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < texto1.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();

    mvprintw(linha / 4 + 1, coluna / 4 + texto1[0].size() + 1, " : ");
    getstr(emailAutenticacao);

    mvprintw(linha / 4 + 2, coluna / 4 + texto1[0].size() + 1, " : ");
    getstr(senhaAutenticacao);

    noecho();

    int l = 4;
    try
    {
        email->setValor(emailAutenticacao);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[0]).c_str());
        l++;
    }

    try
    {
        senha->setValor(senhaAutenticacao);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[1]).c_str());
        l++;
    }

    echo();
    getch();
    noecho();
    endwin();
}
//----------------------------------------------------------------------------------------------------------------------
void TelaUsuarioLogado::selecionar(int *campo)
{
    string titulo1 = "Selecione. ";
    vector<string> texto1{"1 - Servicos relacionados a conta.",
                          "2 - Servicos relacionados a cartao.",
                          "3 - Servicos relacionados a quadro.",
                          "4 - Encerrar sessao.",
                          "Escolha uma opcao : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();
    *campo = getch() - '0';
    noecho();

    endwin();
}

//----------------------------------------------------------------------------------------------------------------------
void TelaConta::mostrar(Conta conta)
{
    string titulo1 = "Valores atuais do conta.";
    vector<string> texto1{"Email : ",
                          "Nome      : ",
                          "Senha     : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    texto1[0] += conta.getEmail().getValor();
    texto1[1] += conta.getNome().getValor();
    texto1[3] += conta.getSenha().getValor();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    noecho();
    mvprintw(linha / 4 + 6, coluna / 4, "%s", "");
    getch();

    endwin();
}

void TelaConta::selecionar(int *campo)
{
    string titulo1 = "Selecione o servico desejado.";
    vector<string> texto1{"1 - Visualizar dados de conta",
                          "2 - Editar dados de conta",
                          "3 - Descadastrar conta",
                          "4 - Retornar.",
                          "Escolha uma opcao : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();
    *campo = getch() - '0';
    noecho();

    endwin();
}

void TelaConta::cadastrar(Conta *conta)
{
    string titulo1 = "Por favor, preencha os espacos com os seus dados.";
    vector<string> texto1{"Email",
                          "Nome",
                          "Senha"};

    string textoErro = "Valor invalido para atributo ";

    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < texto1.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();

    mvprintw(linha / 4 + 1, coluna / 4 + texto1[0].size() + 1, " : ");
    getstr(emailConta);

    mvprintw(linha / 4 + 2, coluna / 4 + texto1[0].size() + 1, " : ");
    getstr(nomeConta);

    mvprintw(linha / 4 + 4, coluna / 4 + texto1[0].size() + 1, " : ");
    getstr(senhaConta);

    noecho();

    int l = 5;
    try
    {
        email.setValor(emailConta);
        conta->setEmail(email);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[0]).c_str());
        l++;
    }
    try
    {
        nome.setValor(nomeConta);
        conta->setNome(nome);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[1]).c_str());
        l++;
    }
    try
    {
        senha.setValor(senhaConta);
        conta->setSenha(senha);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[3]).c_str());
        l++;
    }

    noecho;
    getch();
    endwin();
}

void TelaConta::editar(Conta *conta)
{
    string titulo1 = "Informe o campo da conta para ser editado.";
    vector<string> texto1{"1 - Nome.",
                          "2 - Senha.",
                          "",
                          "3 - Salvar.",
                          "4 - Cancelar.",
                          "Escolha uma opcao : "};

    string titulo2 = "Informe novo valor.";
    vector<string> texto2{"Nome",
                          "Senha"};
    string textoErro = "Valor invalido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);

    bool apresentar = true;
    while (apresentar)
    {
        int campo;

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
        for (int i = 0; i < texto1.size(); i++)
        {
            mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
        }

        echo();
        campo = getch() - '0';
        noecho();

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo2.c_str());
        switch (campo)
        {
        case 1:
            mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[0] + " : ").c_str());
            echo();
            getstr(nomeConta);
            noecho();

            try
            {
                nome.setValor(nomeConta);
            }
            catch (invalid_argument &exp)
            {
                mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[0]).c_str());
                noecho();
                getch();
            }
            break;

        case 2:
            mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[2] + " : ").c_str());
            echo();
            getstr(senhaConta);
            noecho();

            try
            {
                senha.setValor(senhaConta);
            }
            catch (invalid_argument &exp)
            {
                mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[2]).c_str());
                noecho();
                getch();
            }
            break;

        case 3:
            conta->setNome(nome);
            conta->setSenha(senha);
            apresentar = false;
            break;

        case 4:
            apresentar = false;
            break;

        default:
            TelaMensagem telaMensagem;
            telaMensagem.apresentar("Opcao invalida. Pressione qualquer tecla para continuar.");
            break;
        }
    }
};

void TelaConta::descadastrar(Email *email)
{
    string titulo1 = "Confirme sua email para confirmar o descadastramento.";
    string texto1 = "Email";
    string textoErro = "Valor invalido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", (titulo1).c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto1 + " : ").c_str());

    echo();
    getstr(emailConta);
    noecho();

    try
    {
        email->setValor(emailConta);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1).c_str());
        noecho();
        getch();
    };
    endwin();
}

//----------------------------------------------------------------------------------------------------------------------
void TelaCartao::mostrar(Cartao cartao)
{
    string titulo1 = "Valores atuais do cartao.";
    vector<string> texto1{"Codigo : ",
                          "Nome   : ",
                          "Coluna : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    texto1[0] += cartao.getCodigo().getValor();
    texto1[1] += cartao.getNome().getValor();
    texto1[2] += cartao.getColuna().getValor();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < texto1.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    noecho();
    mvprintw(linha / 4 + 4, coluna / 4, "%s", "");
    getch();

    endwin();
}

void TelaCartao::selecionar(int *campo)
{
    string titulo1 = "Selecione um dos servicos.";
    vector<string> texto1{"1 - Visualizar cartao.",
                          "2 - Cadastrar cartao.",
                          "3 - Editar cartao.",
                          "4 - Descadastrar cartao.",
                          "5 - Retornar."};
    string texto2 = "Escolha uma opcao : ";

    initscr();
    getmaxyx(stdscr, linha, coluna);

    clear();
    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < texto1.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }
    mvprintw(linha / 4 + 7, coluna / 4, "%s", texto2.c_str());

    echo();
    *campo = getch() - '0';
    noecho();

    endwin();
}

void TelaCartao::visualizar(Cartao *cartao)
{
    string titulo1 = "Informe codigo do cartao.";
    string texto1 = "Codigo";
    string textoErro = "Valor invalido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto1 + " : ").c_str());

    echo();
    getstr(codigoCartao);
    noecho();

    try
    {
        codigo.setValor(codigoCartao);
        cartao->setCodigo(codigo);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1).c_str());
    };

    endwin();
}

void TelaCartao::cadastrar(Cartao *cartao)
{
    string titulo1 = "Preencha os seguintes campos.";
    vector<string> texto1{"Codigo",
                          "Nome",
                          "Classe"};
    string textoErro = "Valor invalido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < texto1.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();

    mvprintw(linha / 4 + 1, coluna / 4 + texto1[2].size() + 1, " : ");
    getstr(codigoCartao);

    mvprintw(linha / 4 + 2, coluna / 4 + texto1[2].size() + 1, " : ");
    getstr(nomeCartao);

    mvprintw(linha / 4 + 3, coluna / 4 + texto1[2].size() + 1, " : ");
    getstr(colunaCartao);

    noecho();

    int l = 5;
    try
    {
        codigo.setValor(codigoCartao);
        cartao->setCodigo(codigo);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[0]).c_str());
        l++;
    }

    try
    {
        nome.setValor(nomeCartao);
        cartao->setNome(nome);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[1]).c_str());
        l++;
    }

    try
    {
        coluna_cartao.setValor(colunaCartao);
        cartao->setColuna(coluna_cartao);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[2]).c_str());
        l++;
    }

    noecho;
    getch();
    endwin();
}

void TelaCartao::editar(Cartao *cartao)
{
    string titulo1 = "Informe o campo do cartao para ser editado.";
    vector<string> texto1{"1 - Nome.",
                          "2 - Coluna.",
                          "",
                          "3 - Salvar.",
                          "4 - Cancelar.",
                          "Escolha uma opcao : "};

    string titulo2 = "Informe novo valor.";
    vector<string> texto2{"Nome",
                          "Coluna"};
    string textoErro = "Valor invalido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);

    bool apresentar = true;
    while (apresentar)
    {
        int campo;

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
        for (int i = 0; i < texto1.size(); i++)
        {
            mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
        }

        echo();
        campo = getch() - '0';
        noecho();

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo2.c_str());
        switch (campo)
        {
        case 1:
            mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[0] + " : ").c_str());
            echo();
            getstr(nomeCartao);
            noecho();

            try
            {
                nome.setValor(nomeCartao);
            }
            catch (invalid_argument &exp)
            {
                mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[0]).c_str());

                noecho();
                getch();
            }
            break;

        case 2:
            mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[1] + " : ").c_str());
            echo();
            getstr(colunaCartao);
            noecho();

            try
            {
                coluna_cartao.setValor(colunaCartao);
            }
            catch (invalid_argument &exp)
            {
                mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[1]).c_str());

                noecho();
                getch();
            }
            break;

        case 3:
            cartao->setNome(nome);
            cartao->setColuna(coluna_cartao);
            apresentar = false;
            break;

        case 4:
            apresentar = false;
            break;

        default:
            TelaMensagem telaMensagem;
            telaMensagem.apresentar("Opcao invalida. Pressione qualquer tecla para continuar.");
            break;
        }
    }
};

void TelaCartao::descadastrar(Codigo *codigo)
{
    string titulo1 = "Informe codigo do cartao para descadastramento.";
    string texto1 = "Codigo";
    string textoErro = "Valor invalido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto1 + " : ").c_str());

    echo();
    getstr(codigoCartao);
    noecho();

    try
    {
        codigo->setValor(codigoCartao);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1).c_str());
        echo();
        getch();
        noecho();
    };

    endwin();
}

//----------------------------------------------------------------------------------------------------------------------
void TelaQuadro::mostrar(Quadro quadro)
{
    string titulo1 = "Valores atuais do quadro.";
    vector<string> texto1{"Codigo      : ",
                          "Nome        : ",
                          "Descricao   : ",
                          "Limite      : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    texto1[0] += quadro.getCodigo().getValor();
    texto1[1] += quadro.getNome().getValor();
    texto1[2] += quadro.getDescricao().getValor();
    texto1[3] += quadro.getLimite().getValor();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    mvprintw(linha / 4 + 8, coluna / 4, "%s", "");
    noecho();
    getch();

    endwin();
}

void TelaQuadro::selecionar(int *campo)
{
    string titulo1 = "Selecione um dos servicos : ";
    vector<string> texto1{"1 - Visualizar quadro.",
                          "2 - Cadastrar quadro.",
                          "3 - Editar quadro.",
                          "4 - Descadastrar quadro.",
                          "5 - Retornar.",
                          "Escolha uma opcao : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    noecho();
    *campo = getch() - '0';
    echo();

    endwin();
}

void TelaQuadro::visualizar(Quadro *quadro)
{
    string titulo1 = "Informe codigo do quadro.";
    string texto1 = "Codigo";
    string textoErro = "Valor invalido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto1 + " : ").c_str());

    echo();
    getstr(codigoQuadro);
    noecho();

    try
    {
        codigo.setValor(codigoQuadro);
        quadro->setCodigo(codigo);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1).c_str());
    };

    endwin();
}

void TelaQuadro::cadastrar(Quadro *quadro)
{
    string titulo1 = "Preencha os seguintes campos.";
    vector<string> texto1{"Codigo",
                          "Nome",
                          "Descricao",
                          "Limite"};
    string textoErro = "Valor invalido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < texto1.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();

    mvprintw(linha / 4 + 1, coluna / 4 + texto1[5].size() + 1, " : ");
    getstr(codigoQuadro);

    mvprintw(linha / 4 + 2, coluna / 4 + texto1[5].size() + 1, " : ");
    getstr(nomeQuadro);

    mvprintw(linha / 4 + 3, coluna / 4 + texto1[5].size() + 1, " : ");
    getstr(descricaoQuadro);

    mvprintw(linha / 4 + 4, coluna / 4 + texto1[5].size() + 1, " : ");

    char limiteQuadroStr[10];

    getstr(limiteQuadroStr);

    limiteQuadro = atoi(limiteQuadroStr);

    noecho();

    int l = 8;
    try
    {
        codigo.setValor(codigoQuadro);
        quadro->setCodigo(codigo);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[0]).c_str());
        l++;
    }

    try
    {
        nome.setValor(nomeQuadro);
        quadro->setNome(nome);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[1]).c_str());
        l++;
    }

    try
    {
        descricao.setValor(descricaoQuadro);
        quadro->setDescricao(descricao);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[2]).c_str());
        l++;
    }

    try
    {
        limite.setValor(limiteQuadro);
        quadro->setLimite(limite);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[3]).c_str());
        l++;
    }

    noecho;
    getch();
    endwin();
}

void TelaQuadro::editar(Quadro *quadro)
{
    string titulo1 = "Informe o campo do quadro para ser editado:";
    vector<string> texto1{"1 - Nome.",
                          "2 - Descricao.",
                          "3 - Limite.",
                          "",
                          "4 - Salvar.",
                          "5 - Cancelar.",
                          "Escolha uma opcao : "};

    string titulo2 = "Informe novo valor.";
    vector<string> texto2{"Nome",
                          "Descricao",
                          "Limite"};
    string textoErro = "Valor invalido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);

    bool apresentar = true;
    while (apresentar)
    {
        int campo;

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
        for (int i = 0; i < texto1.size(); i++)
        {
            mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
        }

        echo();
        campo = getch() - '0';
        noecho();

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo2.c_str());
        switch (campo)
        {
        case 1:
            mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[0] + " : ").c_str());
            echo();
            getstr(nomeQuadro);
            noecho();

            try
            {
                nome.setValor(nomeQuadro);
            }
            catch (invalid_argument &exp)
            {
                mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[0]).c_str());
                noecho();
                getch();
            }
            break;

        case 2:
            mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[1] + " : ").c_str());
            echo();
            getstr(descricaoQuadro);
            noecho();

            try
            {
                descricao.setValor(descricaoQuadro);
            }
            catch (invalid_argument &exp)
            {
                mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[1]).c_str());
                noecho();
                getch();
            }
            break;

        case 3:
            mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[2] + " : ").c_str());
            echo();

            char limiteQuadroStr[10];

            getstr(limiteQuadroStr);

            limiteQuadro = atoi(limiteQuadroStr);

            noecho();

            try
            {
                limite.setValor(limiteQuadro);
            }
            catch (invalid_argument &exp)
            {
                mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[2]).c_str());
                noecho();
                getch();
                noecho();
                getch();
            }
            break;

        case 4:
            quadro->setNome(nome);
            quadro->setDescricao(descricao);
            quadro->setLimite(limite);
            apresentar = false;
            break;

        case 5:
            apresentar = false;
            break;

        default:
            TelaMensagem telaMensagem;
            telaMensagem.apresentar("Opcao invalida. Pressione qualquer tecla para continuar.");
            break;
        }
    }
};

void TelaQuadro::descadastrar(Codigo *codigo)
{
    string titulo1 = "Informe codigo do quadro para descadastramento.";
    string texto1 = "Codigo";
    string textoErro = "Valor invalido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4 + texto1.size(), " : ");
    echo();
    getstr(codigoQuadro);
    noecho();

    try
    {
        codigo->setValor(codigoQuadro);
    }
    catch (invalid_argument &exp)
    {
        mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1).c_str());
        noecho();
        getch();
    };

    endwin();
}
//----------------------------------------------------------------------------------------------------------------------
void TelaDepuracao::selecionar(int *campo)
{
    string titulo1 = "Selecione tipo de teste a ser executado : ";
    vector<string> texto1{"1 - Executar testes unitarios.",
                          "2 - Executar testes integracao.",
                          "3 - Executar testes sistema.",
                          "4 - Encerrar depuracao.",
                          "Digite a opcao : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();
    *campo = getch() - '0';
    noecho();

    endwin();
}

void TelaTestesUnitarios::selecionar(int *campo)
{
    string titulo1 = "Selecione unidades de teste: ";
    vector<string> textos{"1 - Executar testes dominios.",
                          "2 - Executar testes entidades.",
                          "3 - Executar testes modulos.",
                          "4 - Retornar.",
                          "Digite a opcao : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < textos.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", textos[i].c_str());
    }

    echo();
    *campo = getch() - '0';
    noecho();

    endwin();
}

void TelaTestesModulos::selecionar(int *campo)
{
    string titulo1 = "Selecione modulo a ser testado :";
    vector<string> textos{"1 - Modulo Apresentacao Autenticacao.",
                          "2 - Modulo Apresentacao Conta.",
                          "3 - Modulo Apresentacao Cartao.",
                          "4 - Modulo Apresentacao Quadro.",
                          "5 - Retornar.",
                          "Digite a opcao : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < textos.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", textos[i].c_str());
    }

    echo();
    *campo = getch() - '0';
    noecho();

    endwin();
}

void TelaTestesIntegracao::selecionar(int *campo)
{
    string titulo1 = "Selecione teste integração :";
    vector<string> textos{"1 - Integração entre modulos da camada de Apresentacao.",
                          "2 - Retornar.",
                          "Digite a opcao : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < textos.size(); i++)
    {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", textos[i].c_str());
    }

    echo();
    *campo = getch() - '0';
    noecho();

    endwin();
}