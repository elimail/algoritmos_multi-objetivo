#include "Movimiento.h"


bool Movimiento::modificarSolucion(Solution *sol){

  int indice = sol->generarSemilla(0, sol->getrepSsize()-1);
  sol->modificarObj(indice, 1-sol->getrepS(indice));

  //Verificamos si excede la capacidad de la mochila
  int peso_nuevo = sol->getpesoTotal();

  //Calculo del nuevo peso de la mochila 
  if (sol->getrepS(indice) == 1){
    //Significa que se agrego un objeto, por lo tanto se le suma el valor del peso:
    peso_nuevo = peso_nuevo + sol->getpi()->getObjetos(indice)->getPeso();
  }
  //Aquí se elimina un objeto de la mochila 
  else{
    peso_nuevo = peso_nuevo - sol->getpi()->getObjetos(indice)->getPeso(); 
  }

  //Verificamos si la solución es factible o no:
  if ( peso_nuevo <= sol->getpi()->getCapacidad() ){
    cout << "Modificación factible" <<endl;
    
    //Aquí se actualiza el peso con el peso nuevo 
    sol->setpesoTotal(peso_nuevo);

    //Tengo que modificar las funciones objetivos.
    //Recorro todas las funciones objetivos
    for (int j = 0; j < sol->getpi()->getCantFO(); j++){
      
      if (sol->getrepS(indice) == 1){
        sol->modificarfo(j, sol->getfo(j) + sol->getpi()->getObjetos(indice)->getValor(j) );
      }
      else {
        sol->modificarfo(j, sol->getfo(j) - sol->getpi()->getObjetos(indice)->getValor(j) );
      }
    }
    return true;
  }
  else {
    cout << "Modificación infactible" <<endl;
    //Vuelve al valor original
    sol->modificarObj(indice, 1-sol->getrepS(indice));

    return false;
  }
}