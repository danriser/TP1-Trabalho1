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
    if (valor.length() > LIMITE_NOME + LIMITE_DOMINIO + 1) {
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