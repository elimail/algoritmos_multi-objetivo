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

  //Creo una nueva solucion, la cual será la actual que compararé con la nueva. 
  Solution *s_respaldo = new Solution(pi);

  //Vamos a copiar la información de la solución actual 
  s_respaldo->copiarSolucion(slt);

  //Hace muchos movimientos (los cuales los puse en el Makefile)
  for (int i= 0; i < atoi(argv[3]); i++){

    //Hago los movimientos hasta que el prmero sea un mov. factible
    while (mov->modificarSolucion(slt) == false){
      mov->modificarSolucion(slt);
    }

    //Si la solucion nueva obtenida es peor:
    if ( slt->evaluarSolucion() <= s_respaldo->evaluarSolucion() ){
      slt->copiarSolucion(s_respaldo);
    }
    else {

      //Imprimo la modificación
      //cout << "Modificacion (mejora) " << i+1 << endl;
      //slt->imprimeResultado();
      //cout << endl;

      cout << i+1 << "\t" << slt->evaluarSolucion() << endl;

      //Se vuelve a copiar  
      s_respaldo->copiarSolucion(slt);

    }

  }

  
  return 0;
}
