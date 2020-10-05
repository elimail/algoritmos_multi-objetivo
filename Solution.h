#pragma once
#include <iostream>
#include <vector>
#include "ProblemInstance.h"
using namespace std;

class Solution{

  //Atributos
  private:

    vector <int> fo;     //Valor de las funciones objetivo
    vector <int> repS;   //Vector que me representa las soluciones
    int pesoTotal;       //Me calcula el peso total de la solución 
    ProblemInstance* pi;  //Puntero que tiene cada una de las soluciones

  //Métodos
  public:

    //Método constructor
    Solution(ProblemInstance *pi){
      this->pi = pi;
      this->pesoTotal = 0;

      //Para construir una Función Objetivo con 0's
      for (int j = 0; j < this->pi -> getCantFO(); j++){
        this->setfo(0);
      }

      //Para construir una solución con 0's
      for (int j = 0; j < this->pi->getCantObj(); j++){
        this->setrepS(0);
      }

    };

    //Método destructor
    ~Solution(){};

    //Cosas que se setean (por si tenemos que ir agregando)
    void setfo(int fo);
    void setrepS(int repS);
    void setpesoTotal(int pesoTotal);

    //Para obtener los valores 
    int getfo(int m);
    int getrepS(int m);
    int getpesoTotal(void);
    ProblemInstance* getpi(void);

    //Para modificar valores de la función obejtivo:
    void modificarfo(int indice, int valor);

    //Para modificar valores de la soluciones 
    void modificarObj(int indice, int valor);

    //Función para generar el número de la semilla
    int generarSemilla(int,int);

    //Función para determinar el tamaño de la solución (cantidad de objetos)
    int getrepSsize(void);

   //Para imprimir resultados!
    void imprimeResultado(void);

    //Método para copiar una clase 
    void copiarSolucion(Solution *slt);

    //Método para evaluar la función de evaluación
    int evaluarSolucion();

    //Método para resetear una solucion
    void resetearSolucion();

};