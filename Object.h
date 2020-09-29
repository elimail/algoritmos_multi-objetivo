#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Object{
  //Atributos
  private:
    
    int ID;
    vector <int> valor;
    int peso;

  public:

  //Método constructor
    Object(){};

  //Método destructor
    ~Object(){};

  //Para setear los valores:
    void agregarValor(int valor);
    void setPeso(int peso);
    void setID(int ID);

//Este es para pedir un valor (de valor y de peso)
//m = # de función obejtivo
    int getValor(int m);
    int getPeso(void);
    int getID(void);

  //Este es para imprimir la info del objeto:
  void ImprimeObjeto(void);

};