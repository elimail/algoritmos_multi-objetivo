#pragma once
#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

class FrentePareto{
  private:

    vector <Solution*> Soluciones;   //Vector con soluciones

  public:

    //Constructor y destructor
    FrentePareto(){};
    ~FrentePareto(){};

    //Función dominancia
    int Dominancia(Solution* sol1, Solution* sol2);

    //Función para modificar las soluciones al frente.
    void ModificarFrente(Solution* sol);

    //Función para imprimir frente
    void imprimirFrente();
};