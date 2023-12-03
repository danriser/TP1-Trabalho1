#include "../headers/builder.h"
#include "../headers/comandos_apresentacao.h"
#include "../headers/comandos_servico.h"
#include "../headers/controladoras_apresentacao.h"
#include "../headers/controladoras_servico.h"
#include "../headers/dominios.h"
#include "../headers/drivers.h"
#include "../headers/entidades.h"
#include "../headers/interfaces.h"
#include "../headers/sqlite3.h"
#include "../headers/telas.h"
#include "../headers/testes.h"
// #include "builder.cpp"
// #include "comandos_apresentacao.cpp"
// #include "controladoras_apresentacao.cpp"
// #include "controladoras_servico.cpp"
// #include "dominios.cpp"
// #include "drivers.cpp"
// #include "telas.cpp"
// #include "testes.cpp"

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