#include "Construction.h"

bool Construction::ConstruirSolucionFact(Solution *sol){

  int suma = 0;
  int cont = 0;
  for (Object* i: sol-> getpi() -> getTODOSObjetos()) {

    //Genero 0 o 1 y la guardo en una auxiliar, y después la agrego en cada casilla de repS.
    int aux = sol->generarSemilla(0,1);
    sol->modificarObj(cont,aux);
  
    //Hago la suma de la mochila, para saber cuánto pesa con estos resultados generados aleatoriamente
    suma = suma + aux*i->getPeso();

    //Voy modificando los resultados para cada FO
    for (int j = 0; j < sol -> getpi() -> getCantFO(); j++){
      sol->modificarfo(j, sol->getfo(j) + aux*i->getValor(j) );
    }
    cont = cont + 1;
  }

  //Seteo el peso total de la mochila
  sol->setpesoTotal(suma);

  //Compruebo si la solución es factible o no, viendo si sobrepasa la capacidad de la mochila. Retorna verdadero si es solución factible y false cuando no lo es.
  if (sol->getpesoTotal() <= sol->getpi()->getCapacidad() ){
    //cout << "Solución Factible" << endl;
    return true;
    
  } else {
    //cout << "Solución Infactible" << endl;  
    return false;
  }
}

void Construction::imprimirSolucion(Solution *sol){
  sol->imprimeResultado();
}