#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

class Dominio {
    private:
        string valor;
        void validar(string);
    public:
        void setValor(string);
        string getValor();
};


inline string Dominio::getValor(){
    return valor;
}

void Dominio::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

class Codigo:public Dominio {
    private:
        static const int LIMITE = 4;
        void validar(string);
};

class Coluna:public Dominio {
    private:
        void validar(string);
};

class Email:public Dominio {
    private:
        static const int LIMITE_NOME = 10;
        static const int LIMITE_DOMINIO = 20;
        void validar(string);
};

class Limite:public Dominio {
    private:
        void validar(string);
};

class Senha:public Dominio {
    private:
        static const int LIMITE = 5;
    public:
        void validar(string);
};

class Texto:public Dominio {
    private:
        static const int LIMITE = 30;
    public:
        void validar(string);
};

#endif // DOMINIOS_H_INCLUDED