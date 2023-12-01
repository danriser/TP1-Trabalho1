#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

/*! \brief Domínio Codigo
 *
 * Há uma validacao para o codigo, que deve ser composto por 4 caracteres, sendo os dois primeiros letras maiusculas e os dois ultimos numeros.
 */
class Codigo
{
private:
    string valor;
    static const int LIMITE = 4;
    void validar(string);

public:
    void setValor(const string &);
    string getValor();
};

inline string Codigo::getValor()
{
    return valor;
}

/*! \brief Domínio Email
 *
 * Há uma validacao para o email, que deve ser composto por um nome de ate 10 caracteres, seguido de @ e um dominio de ate 20 caracteres.
 */
class Email
{
private:
    string valor;
    static const int LIMITE_NOME = 10;
    static const int LIMITE_DOMINIO = 20;
    void validar(string);

public:
    void setValor(const string &);
    string getValor();
};

inline string Email::getValor()
{
    return valor;
}

/*! \brief Domínio Senha
 *
 * Há uma validacao para a senha, que deve ser composto por uma letra maiuscula,
 * uma letra minuscula, um numero e um caractere especial.
 */
class Senha
{
private:
    string valor;
    static const int LIMITE = 5;
    void validar(string);

public:
    void setValor(const string &);
    string getValor();
};

inline string Senha::getValor()
{
    return valor;
}

/*! \brief Domínio Texto
 *
 * Ha uma validacao para o texto, que deve ser composto por ate 30 caracteres.
 */
class Texto
{
private:
    string valor;
    static const int LIMITE = 30;
    void validar(string);

public:
    void setValor(const string &);
    string getValor();
};

inline string Texto::getValor()
{
    return valor;
}

/*! \brief Domínio Limite
 *
 * Há uma validacao para o limite, que deve ser composto por um numero
 * entre 5 à 20 de 5 em cinco.
 */
class Limite
{
private:
    int valor;
    void validar(int);

public:
    void setValor(const int &);
    int getValor();
};

inline int Limite::getValor()
{
    return valor;
}

/*! \brief Domínio Coluna
 *
 * Há uma validacao para a coluna, que deve ser composto por uma string
 * SOLICITADO, EM EXECUCAO ou CONCLUIDO.
 */
class Coluna
{
private:
    string valor;
    void validar(string);

public:
    void setValor(const string &);
    string getValor();
};

inline string Coluna::getValor()
{
    return valor;
}

#endif // DOMINIOS_H_INCLUDED