#ifndef BUILDERS_H_INCLUDED
#define BUILDERS_H_INCLUDED

#include "controladoras_apresentacao.h"

class BuilderSistema {
   private:
    CtrlIAInicializacao *ctrlIAInicializacao;

    IAAutenticacao *ctrlIAAutenticacao;
    IAConta *ctrlIAConta;
    IAQuadro *ctrlIAQuadro;
    IAQuadro *ctrlIAQuadro;

    CtrlISAutenticacao *ctrlISAutenticacao;
    CtrlISConta *ctrlISConta;
    CtrlISQuadro *ctrlISQuadro;
    CtrlISQuadro *ctrlISQuadro;

   public:
    CtrlIAInicializacao *construir();
    ~BuilderSistema();
};

#endif  // BUILDERS_H_INCLUDED