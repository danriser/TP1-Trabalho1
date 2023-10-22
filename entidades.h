#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"

class Conta {
    private:
        Email email;
        Texto nome;
        Senha senha;
    public:
        Email getEmail();
        void setEmail(const Email&);
        Texto getNome();
        void setNome(const Texto&);
        Senha getSenha();
        void setSenha(const Senha&);
};

class Quadro {
    private:
        Codigo codigo;
        Texto nome;
        Texto descricao;
        Limite limite;
    public:
        Codigo getCodigo();
        void setCodigo(const Codigo&);
        Texto getNome();
        void setNome(const Texto&);
        Texto getDescricao();
        void setDescricao(const Texto&);
        Limite getLimite();
        void setLimite(const Limite&);
};

class Cartao {
    private:
        Codigo codigo;
        Texto nome;
        Texto descricao;
        Coluna coluna;
    public:
        Codigo getCodigo();
        void setCodigo(const Codigo&);
        Texto getNome();
        void setNome(const Texto&);
        Texto getDescricao();
        void setDescricao(const Texto&);
        Coluna getColuna();
        void setColuna(const Coluna&);
};

// Conta
inline Email Conta::getEmail() {
    return email;
}

inline void Conta::setEmail(const Email& email) {
    this->email = email;
}

inline Texto Conta::getNome() {
    return nome;
}

inline void Conta::setNome(const Texto& nome) {
    this->nome = nome;
}

inline Senha Conta::getSenha() {
    return senha;
}

inline void Conta::setSenha(const Senha& senha) {
    this->senha = senha;
}

// Quadro
inline Codigo Quadro::getCodigo() {
    return codigo;
}

inline void Quadro::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

inline Texto Quadro::getNome() {
    return nome;
}

inline void Quadro::setNome(const Texto& nome) {
    this->nome = nome;
}

inline Texto Quadro::getDescricao() {
    return descricao;
}

inline void Quadro::setDescricao(const Texto& descricao) {
    this->descricao = descricao;
}

inline Limite Quadro::getLimite() {
    return limite;
}

inline void Quadro::setLimite(const Limite& limite) {
    this->limite = limite;
}

// Cartao
inline Codigo Cartao::getCodigo() {
    return codigo;
}

inline void Cartao::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

inline Texto Cartao::getNome() {
    return nome;
}

inline void Cartao::setNome(const Texto& nome) {
    this->nome = nome;
}

inline Texto Cartao::getDescricao() {
    return descricao;
}

inline void Cartao::setDescricao(const Texto& descricao) {
    this->descricao = descricao;
}

inline Coluna Cartao::getColuna() {
    return coluna;
}

inline void Cartao::setColuna(const Coluna& coluna) {
    this->coluna = coluna;
}

#endif // ENTIDADES_H_INCLUDED