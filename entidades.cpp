#include "entidades.h"

// Conta
inline Email Conta::getEmail() {
    return email;
}

void Conta::setEmail(const Email& email) {
    this->email = email;
}

inline Texto Conta::getNome() {
    return nome;
}

void Conta::setNome(const Texto& nome) {
    this->nome = nome;
}

inline Senha Conta::getSenha() {
    return senha;
}

void Conta::setSenha(const Senha& senha) {
    this->senha = senha;
}

// Quadro
inline Codigo Quadro::getCodigo() {
    return codigo;
}

void Quadro::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

inline Texto Quadro::getNome() {
    return nome;
}

void Quadro::setNome(const Texto& nome) {
    this->nome = nome;
}

inline Texto Quadro::getDescricao() {
    return descricao;
}

void Quadro::setDescricao(const Texto& descricao) {
    this->descricao = descricao;
}

inline Limite Quadro::getLimite() {
    return limite;
}

void Quadro::setLimite(const Limite& limite) {
    this->limite = limite;
}

// Cartao
inline Codigo Cartao::getCodigo() {
    return codigo;
}

void Cartao::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

inline Texto Cartao::getNome() {
    return nome;
}

void Cartao::setNome(const Texto& nome) {
    this->nome = nome;
}

inline Texto Cartao::getDescricao() {
    return descricao;
}

void Cartao::setDescricao(const Texto& descricao) {
    this->descricao = descricao;
}

inline Coluna Cartao::getColuna() {
    return coluna;
}

void Cartao::setColuna(const Coluna& coluna) {
    this->coluna = coluna;
}
