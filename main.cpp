#include <iostream>
#include <random>
#include <vector>
#include <time.h>

#include "ProblemInstance.h"
#include "FileHandler.h"
#include "Solution.h"
#include "Construction.h"
#include "Movimiento.h"
#include "FrentePareto.h"

using namespace std;

int main(int argc, char **argv) {

  //Defino tiempo inicial y tiempo final
  clock_t t_inicial;
  clock_t t_final;
  
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

  //Inicio el reloj
  t_inicial = clock();

  //Creo una nueva solucion llamada sc
  Solution* sc = new Solution(pi);

  //Llamar a Construction
  Construction *c = new Construction();

  //Llamar a un Movimiento
  Movimiento *mov = new Movimiento();

  //Creo una nueva solucion, la cual será la actual que compararé con la nueva. 
  Solution *sn = new Solution(pi);
  Solution *sbest = new Solution(pi); //ese es sbest

  //inicializo iteracion
  float T = 100000;         //Temperatura en valor alto
  int itExt = atoi(argv[3]);    //Cant. max. iteraciones
  int itInt = atoi(argv[4]);   //Cant. max iteraciones

  //Se construye una solución inicial fuera del ciclo 
  //Creo una solucion factible inicial. Si no es factible, se resetea la función
    do {
      // Resetear todos los valores en 0's
      sc->resetearSolucion(); 
    } while (c->ConstruirSolucionFact(sc) == false);

  //Se crea el frente de pareto:
  FrentePareto *fp = new FrentePareto();

  //Repetir hasta el criterio de término
  for(int it = 0; it < itExt; it++){
    //Repetir hasta el criterio de halting (recalentamiento)
    for(int t= 0; t < itInt; t++){

      //Selecciono un nuevo punto.
      sn->copiarSolucion(sc);
      
      //Aplico el movimiento a sn
      while (mov->modificarSolucion(sn) == false){
        mov->modificarSolucion(sn);
      }
      
      //Reemplazo el valor si es mejor segun lo siguiente:
      if (sn->evaluarSolucion() >= sc->evaluarSolucion()){
        sc->copiarSolucion(sn);
      }
      else if (sc->generarSemilla(0, 10)/10.0 < exp((sn->evaluarSolucion() - sc->evaluarSolucion() )/ T ) ){
        sc->copiarSolucion(sn);
      }

      //Actualizo el mejor valor de la solución 
      if (sc->evaluarSolucion() > sbest->evaluarSolucion()){
        sbest->copiarSolucion(sc);
        cout << "Imprimir it:" << it << endl;
        cout << "Mejor solución:" << sbest->evaluarSolucion() << endl;
      }
    }

    //Se van agregando elementos al frente 
    fp->ModificarFrente(sc);
    fp->imprimirFrente();
    //getchar();

    //Falta la parte de las funciones de escalarización
    //Definir vectores de peso

    //Actualizar Temperatura:
    T = 0.9*T;
    //cout << "Temperatura:" << T << endl;
    if (T < 1){
      T = 10000;
    }
  }

  t_final = clock();

  clock_t timeToBest = ((double) (t_final - t_inicial)) / CLOCKS_PER_SEC;

  cout << "Tiempo de ejecución:" << timeToBest << endl;

  return 0;
}