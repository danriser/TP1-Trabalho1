#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

// Codigo
class Codigo {
    /**
     * @brief 
     * Esta é a classe que denomina os metodos relacionado ao codigo
     */
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
     /**
     * @brief 
     * Esta é a classe que denomina os metodos relacionado ao Email do usuario
     */
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
     /**
     * @brief 
     * Esta é a classe que denomina os metodos relacionadas a senha do usuario
     */
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
     /**
     * @brief 
     * Esta é a classe que denomina os metodos relacionado aos "textos"
     * como o nome e a descricao
     */
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
     /**
     * @brief 
     * Esta é a classe que denomina os metodos relacionado ao limite
     */
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
     /**
     * @brief 
     * Esta é a classe que denomina os metodos relacionado à coluna
     */
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