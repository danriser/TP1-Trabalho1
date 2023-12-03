#include "builder.h"
#include "comandos_apresentacao.h"
#include "comandos_servico.h"
#include "controladoras_apresentacao.h"
#include "controladoras_servico.h"
#include "dominios.h"
#include "drivers.h"
#include "entidades.h"
#include "interfaces.h"
#include "sqlite3.h"
#include "telas.h"
#include "testes.h"

// #define TESTE
#define SISTEMA

using namespace std;

#ifdef TESTE
int main() {
    DriverDepuracao driverDepuracao;
    driverDepuracao.executar();

    return 0;
};
#endif  // TESTE

#ifdef SISTEMA
int main() {
    BuilderSistema *builder;
    builder = new BuilderSistema();

    CtrlIAInicializacao *ctrlIAInicializao;
    ctrlIAInicializao = builder->construir();

    ctrlIAInicializao->executar();

    delete builder;
    return EXIT_SUCCESS;
}
#endif  // SISTEMA