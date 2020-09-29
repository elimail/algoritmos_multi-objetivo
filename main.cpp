#include <iostream>
#include <random>

#include "ProblemInstance.h"
#include "FileHandler.h"
#include "Solution.h"
#include "Construction.h"
#include "Movimiento.h"


using namespace std;

int main(int argc, char **argv) {
  
  //Leo el archivo que tengo que leer xD
  string instancia = argv[1];
  
  //Creo la semilla
  int seed = atoi(argv[2]);

  //Inicio generador de números aleatorios
  srand(seed);

  //Aquí defino fh 
  FileHandler fh(instancia);

  //Se llama al método para leer al documento
  ProblemInstance* pi = fh.readInputFile();

  //Método para imprimir todo resumido y bonito
  pi->ImprimirProblemInstance();

  //Creo una nueva solucion llamada slt
  Solution* slt = new Solution(pi);
  //Hago que llame al método
  //slt->ImprimeResultado();

  //Llamar a Construction
  Construction *c = new Construction();

  while (c->ConstruirSolucionFact(slt) == false){
    c->ConstruirSolucionFact(slt);
  }

  c->imprimirSolucion(slt);

  //Llamar a un Movimiento
  Movimiento *mov = new Movimiento();

  while (mov->modificarSolucion(slt) == false){
    mov->modificarSolucion(slt);
  }
  
  c->imprimirSolucion(slt);

  return 0;
}