#include "Dominios.h"
#include <stdexcept>
#include <iostream>

void Dominio::validar(string){
}

void Codigo::validar(string valor) {
    if (valor.length() > LIMITE) {
        throw invalid_argument("Argumento invalido.");
    }

    for (int i = 0; i < valor.length(); i++) {
        if (i < 2) {
            if (valor[i] < 'A' || valor[i] > 'Z') {
                throw invalid_argument("Argumento invalido.");
            }
        }
        else {
            if (valor[i] < '0' || valor[i] > '9') {
                throw invalid_argument("Argumento invalido.");
            }
        }
    }
}

void Coluna::validar(string valor) {
    if (valor != "SOLICITADO" && valor != "EM EXECUCAO" && valor != "CONCLUIDO") {
        throw invalid_argument("Argumento invalido.");
    }
}

void Email::validar(string valor) {
    string nome;
    string dominio;

    if (valor.length() > LIMITE_NOME + LIMITE_DOMINIO + 1) {
        throw invalid_argument("Argumento invalido.");
    }

    if (valor.find('@') == string::npos) {  // verifica se existe @
        throw invalid_argument("Argumento invalido.");
    }

    if (valor.find('@') == 0 || valor.find('@') == valor.length() - 1) {
        throw invalid_argument("Argumento invalido.");
    }

    if (valor.find('@') != valor.rfind('@')) {  // verifica se ha dois @
        throw invalid_argument("Argumento invalido.");
    }

    if (valor.find('@') - 1 == '.' || valor.find('@') + 1 == '.') {
        throw invalid_argument("Argumento invalido.");
    }

    for (int i = 0; i < valor.length() - 1; i++) {
        if (   valor[i] < 'A' || valor[i] > 'Z' 
            && valor[i] < 'a' || valor[i] > 'z' 
            && valor[i] < '0' || valor[i] > '9' 
            && valor[i] != '.' 
            && valor[i] != '@')
        {
            throw invalid_argument("Argumento invalido.");
        }
        if (valor[i] == '.' && valor[i + 1] == '.') {
            throw invalid_argument("Argumento invalido.");
        }
    }

    size_t posicaoArroba = valor.find('@');
    nome = valor.substr(0, posicaoArroba);
    dominio = valor.substr(posicaoArroba + 1, valor.length() - posicaoArroba - 1);

    if (nome.length() < 2 || nome.length() > LIMITE_NOME) {
        throw invalid_argument("Argumento invalido.");
    }

    if (dominio.length() < 2 || dominio.length() > LIMITE_DOMINIO) {
        throw invalid_argument("Argumento invalido.");
    }
}

void Limite::validar(string valor) {
    if (valor != "5" && valor != "10" && valor != "15" && valor != "20") {
        throw invalid_argument("Argumento invalido.");
    }
}

void Senha::validar(string valor) {
    // Verifica se a senha possui o formato XXXXX
    if (valor.length() != LIMITE) {
        throw invalid_argument("A senha deve ter exatamente 5 caracteres.");
    }

    bool temLetraMaiuscula = false;
    bool temLetraMinuscula = false;
    bool temDigito = false;
    bool temPontoExclamacaoOuPontoVirgula = false;

    for (char c : valor) {
        if (isupper(c)) {
            temLetraMaiuscula = true;
        }
        else if (islower(c)) {
            temLetraMinuscula = true;
        }
        else if (isdigit(c)) {
            temDigito = true;
        }
        else if (c == '.' || c == ',' || c == ';' || c == '?' || c == '!') {
            temPontoExclamacaoOuPontoVirgula = true;
        }
        else {
            throw invalid_argument("A senha contém caracteres inválidos.");
        }
    }

    if (!temLetraMaiuscula || !temLetraMinuscula || !temDigito || !temPontoExclamacaoOuPontoVirgula) {
        throw invalid_argument("A senha não atende aos critérios de complexidade.");
    }
}

/*int main() {
    Senha senha;

    try {
        // Teste de senha válida
        string senhaValida = "Abc.9";
        cout << "Testando senha válida: " << senhaValida << endl;
        senha.validar(senhaValida);
        cout << "Senha válida." << endl;
    } catch (const invalid_argument &e) {
        cerr << "Erro: " << e.what() << endl;
    }

    try {
        // Teste de senha inválida (não possui caracteres especiais)
        string senhaInvalida = "abcde";
        cout << "\nTestando senha inválida: " << senhaInvalida << endl;
        senha.validar(senhaInvalida);
        cout << "Senha válida." << endl;
    } catch (const invalid_argument &e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}
*/

void Texto::validar(string valor) {
    int tamanho = valor.length();

    if (tamanho < 5 || tamanho > LIMITE) {
        throw invalid_argument("O texto deve ter entre 5 e 30 caracteres.");
    }

    bool espacoEmBranco = false;
    bool pontuacaoEmSequencia = false;
    bool acentuacao = false;
    bool primeiroCaractereMaiuscula = isupper(valor[0]);

    for (int i = 0; i < tamanho; i++) {
        char c = valor[i];

        if (!(isalpha(c) || isdigit(c) || c == '.' || c == ',' || c == ';' || c == '?' || c == '!' || isspace(c))) {
            throw invalid_argument("O texto contém caracteres inválidos.");
        }

        if (isspace(c) && i < tamanho - 1 && isspace(valor[i + 1])) {
            throw invalid_argument("O texto possui espaços em branco em sequência.");
        }

        if ((c == '.' || c == ',' || c == ';' || c == '?' || c == '!') && i < tamanho - 1 &&
            (valor[i + 1] == '.' || valor[i + 1] == ',' || valor[i + 1] == ';' || valor[i + 1] == '?' || valor[i + 1] == '!')) {
            throw invalid_argument("O texto possui sinais de pontuação em sequência.");
        }

        if (isalnum(c) && !isascii(c)) {
            throw invalid_argument("O texto contém acentuação.");
        }

        if (i > 0 && (c == '.' || c == '?' || c == '!') && isspace(valor[i - 1]) && i < tamanho - 1 && islower(valor[i + 1])) {
            throw invalid_argument("O primeiro caractere após sinal de pontuação deve ser letra maiúscula.");
        }

        if (isspace(c)) {
            espacoEmBranco = true;
        }
    }

    if (!primeiroCaractereMaiuscula) {
        throw invalid_argument("O primeiro caractere do texto deve ser letra maiúscula.");
    }
}

/*
int main() {
    Texto texto;

    try {
        // Teste de texto válido
        string textoValido = "Exemplo de Texto.";
        cout << "Testando texto válido: " << textoValido << endl;
        texto.validar(textoValido);
        cout << "Texto válido." << endl;
    } catch (const invalid_argument &e) {
        cerr << "Erro: " << e.what() << endl;
    }

    try {
        // Teste de texto inválido (primeira letra minúscula)
        string textoInvalido = "texto com lestra minuscula";
        cout << "\nTestando texto inválido: " << textoInvalido << endl;
        texto.validar(textoInvalido);
        cout << "Texto válido." << endl;
    } catch (const invalid_argument &e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}
*/