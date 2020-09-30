#pragma once
#include <iostream>
#include <vector>
#include "Object.h"

using namespace std;

class ProblemInstance{

  private:
    //Atributos
    vector <Object*> Objetos;
    int Capacidad;
    int CantFO;
    int CantObj;

  public:

    //Método constructor
    ProblemInstance(){};

    //Método destructor
    ~ProblemInstance(){};

    //Metodos
        
    //Métodos de seteo  (para ir agregando cosas)
    void agregarObjeto(Object*);     //es lo mismo que set
    void setCapacidad(int);
    void setCantFO(int);
    void setCantObj(int);

    //Métodos de getteo (para poder acceder a ella)
    Object *getObjetos(int);
    vector <Object*> getTODOSObjetos(void);
    int getCapacidad(void);
    int getCantFO(void);
    int getCantObj(void);

    //Métodos de impresión
    //Para imprimir la lectura de los datos:
    void ImprimirProblemInstance(void);

};