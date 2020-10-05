#include <iostream>
#include <random>
#include <vector>

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

  //c->imprimirSolucion(slt);

  //Llamar a un Movimiento
  Movimiento *mov = new Movimiento();

  //Creo una nueva solucion, la cual será la actual que compararé con la nueva. 
  Solution *s_respaldo = new Solution(pi);
  Solution *s_res2 = new Solution(pi);

  //Para hacer HC-Restart. argv[4] es el número máx de iteraciones con restanrt y argv[5] es el estancamiento
  int j = 0;
  int k = 0;

  //Quiebre de linea
  cout << endl;
  //Parametro para contar el vaor maximo obtenido por cierto restart
  int l = 0;

  //Hace muchos movimientos (los cuales los puse en el Makefile)
  while (j < atoi(argv[4]) && k <= atoi(argv[5])) {

    cout << endl << "Restart: " << j+1 << endl;

    //Creo una solucion factible inicial. Si no es factible, se resetea la función
    do {
      // Resetear todos los valores en 0's
      slt->resetearSolucion(); 

    } while (c->ConstruirSolucionFact(slt) == false);

    //Mostrar la solución construida
    cout << "Solucion inicial: " << slt->evaluarSolucion() << endl;

    //Vamos a copiar la información de la solución actual 
    s_respaldo->copiarSolucion(slt);

    //Creamos un segundo respaldo para el Restart, solo para el primer restart
    if (j == 0){
      s_res2 -> copiarSolucion(slt);
    } 

    for (int i= 0; i < atoi(argv[3]); i++){

      //Hago los movimientos hasta que el prmero sea un mov. factible
      while (mov->modificarSolucion(slt) == false){
        mov->modificarSolucion(slt);
      }

      //Si la solucion nueva obtenida SI es peor:
      if ( slt->evaluarSolucion() <= s_respaldo->evaluarSolucion() ){
        slt->copiarSolucion(s_respaldo);
      }
      //Sino, dejamos el valor tal y como esta
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

    //Si es el resultado es peor: 
    if ( slt->evaluarSolucion() <= s_res2->evaluarSolucion() ){
      //Le sumo un valor al estancado
      k++;
    }
    //Si el resultado es mejor:
    else{
      s_res2->copiarSolucion(slt);
      k = 0;
      l = j;
    }
    // Avanzar al sgte restart
    j++;

  }
  cout << "Mejor solucion en iteración " << l+1 << " es: " << s_res2->evaluarSolucion() << endl;
  //Imprimo el detalle de la ultiam solucion 
  s_res2->imprimeResultado();

  return 0;
}
