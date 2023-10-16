#include "Dominios.h"

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
    if (valor.length() > LIMITE) {
        throw invalid_argument("Argumento invalido.");
    }
}

void Texto::validar(string valor) {
    if (valor.length() > LIMITE) {
        throw invalid_argument("Argumento invalido.");
    }
}