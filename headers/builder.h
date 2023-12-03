#ifndef BUILDERS_H_INCLUDED
#define BUILDERS_H_INCLUDED

#include "controladoras_apresentacao.h"


// 221020904
class BuilderSistema {
   private:
    CtrlIAInicializacao *ctrlIAInicializacao;

    IAAutenticacao *ctrlIAAutenticacao;
    IAConta *ctrlIAConta;
    IACartao *ctrlIACartao;
    IAQuadro *ctrlIAQuadro;

    CtrlISAutenticacao *ctrlISAutenticacao;
    CtrlISConta *ctrlISConta;
    CtrlISCartao *ctrlISCartao;
    CtrlISQuadro *ctrlISQuadro;

   public:
    CtrlIAInicializacao *construir();
    ~BuilderSistema();
};

#endif  // BUILDERS_H_INCLUDED