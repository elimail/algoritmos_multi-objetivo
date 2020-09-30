#pragma once
#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

class Movimiento{
  private:

  public:
    //Constructor y destructor
    Movimiento(){};
    ~Movimiento(){};

    //Para hacer el movimiento 
    bool modificarSolucion(Solution *sol);

};