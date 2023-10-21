#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

// Codigo
class Codigo {
    private:
        string valor;
        static const int LIMITE = 4;
        void validar(string);
    public:
        void setValor(const string&);
        string getValor();    
};

inline string Codigo::getValor() {
    return valor;
}

// Email
class Email {
    private:
        string valor;
        static const int LIMITE_NOME = 10;
        static const int LIMITE_DOMINIO = 20;
        void validar(string);
    public:
        void setValor(const string&);
        string getValor();    
};

inline string Email::getValor() {
    return valor;
}

// Senha
class Senha {
    private:
        string valor;
        static const int LIMITE = 5;
        void validar(string);
    public:
        void setValor(const string&);
        string getValor();    
};

inline string Senha::getValor() {
    return valor;
}

// Texto
class Texto {
    private:
        string valor;
        static const int LIMITE = 30;
        void validar(string);
    public:
        void setValor(const string&);
        string getValor();    
};

inline string Texto::getValor() {
    return valor;
}

// Limite
class Limite {
    private:
        int valor;
        void validar(int);
    public:
        void setValor(const int&);
        int getValor();    
};

inline int Limite::getValor() {
    return valor;
}

// Coluna
class Coluna {
    private:
        string valor;
        void validar(string);
    public:
        void setValor(const string&);
        string getValor();    
};

inline string Coluna::getValor() {
    return valor;
}

#endif // DOMINIOS_H_INCLUDED