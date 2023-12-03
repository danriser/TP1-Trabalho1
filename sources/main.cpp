#include "../headers/comandos_apresentacao.h"
#include "../headers/controladoras_apresentacao.h"
#include "../headers/dominios.h"
#include "../headers/drivers.h"
#include "../headers/entidades.h"
#include "../headers/interfaces.h"
#include "../headers/stubs.h"
#include "../headers/telas.h"
#include "../headers/testes.h"
#include "comandos_apresentacao.cpp"
#include "controladoras_apresentacao.cpp"
#include "dominios.cpp"
#include "drivers.cpp"
#include "stubs.cpp"
#include "telas.cpp"
#include "testes.cpp"

#define TESTE
// #define SISTEMA
using namespace std;

int main() {
#ifdef TESTE

    DriverDepuracao driverDepuracao;
    driverDepuracao.executar();

#endif  // TESTE

//----------------------------------------------------------------------------------------------------------------------
#ifdef SISTEMA

#endif  // SISTEMA

    return 0;
}