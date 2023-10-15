#include "Dominios.h"

void Codigo::validar(string valor) {
    if (valor.length() > LIMITE) {
        throw invalid_argument("Argumento invalido.");
    }
}

void Coluna::validar(string valor) {
    
}

void Email::validar(string valor) {
    
}

void Limite::validar(string valor) {
    
}

void Senha::validar(string valor) {
    
}

void Texto::validar(string valor) {
    
}