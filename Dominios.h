#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

class Codigo {
    private:
        string valor;
        void validar(string); /*o codigo validar precisa seguir os seguintes requisitos LLDD*/
    public:                   /*L sendo uma letra maiuscula e D um numero*/
        void setValor(string);
        string getValor();
};

inline string Codigo::getValor(){
    return valor;
}


class Coluna {
    private:
        string valor;
        void validar(string);/*o codigo validar vai ser uma verificacao condicional com as seguintes possibilidades*/
    public:                  /*SOLICITADO, EM EXECUCAO, CONCLUIDO*/
        void setValor(string);
        string getValor();

};

inline string Coluna::getValor(){
    return valor;
}