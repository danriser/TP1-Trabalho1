#include "Dominios.h"

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