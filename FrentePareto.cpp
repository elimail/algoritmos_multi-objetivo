#include "FrentePareto.h"
#include <fstream>

int FrentePareto::Dominancia(Solution* sol1, Solution* sol2){

  int aux1 = 0;   //Suma si sol1 es mejor
  int aux2 = 0;   //Suma si sol2 es mejor

  //Recorro cada valor objetivo 
  for (int i = 0; i < sol1->getpi()->getCantFO(); i++ ){
    if (sol1->getfo(i) > sol2->getfo(i)){
      aux1++;
    }
    else if (sol1->getfo(i) < sol2->getfo(i)){
      aux2++;
    }
  }

  //Si sol1 domina a sol2
  if (aux1 > 0 && aux2 == 0){
    return 1;
  } //Si sol2 domina a sol1 
  else if (aux1 == 0 && aux2 > 0){    
    return -1;
  } //Soluciones no dominadas
  else{
    return 0;       
  }

}


//Función para modificar las soluciones al frente.
void FrentePareto::ModificarFrente(Solution* sol){

  //Si el frente esta vacio:
  if (this->Soluciones.size() == 0){
    //Se pide espacio de memoria:
    Solution* sol1 = new Solution(sol->getpi());
    //Se copia la info. de sol en sol 1
    sol1->copiarSolucion(sol);
    //Lo agrego al vector 
    this->Soluciones.push_back(sol1);

    return;
  }

  //Declaro un iterador, el cual inicia con el inicio del vector de soluciones
  auto it = this->Soluciones.begin();

  //Ahora, si el vector tiene elementos....
  while (it != this->Soluciones.end() )  {
    //Una especie de casteo raro (accedo al contenido de lo apuntado por el iterador)
    Solution* s = *it;
    
    //Si s domina a solución nueva, se va solucion nueva
    if (Dominancia(s, sol) == 1){
      return;
    }
    //sol es mejor que s, por lo tanto tengo que reemplazar sol
    else if (Dominancia(s,sol) == -1){
      
      //Cuando se borra, automaticamente pasa al siguiente
      it = this->Soluciones.erase(it);
      //Se elimina el espacio de memoria de s
      delete s;   
    
    } else {
      //Como no paso nada, tengo que avanzar manualmente a la otra solución 
      it++;
    }
  }
  //Agregar sol al Frente.
  //Se pide espacio de memoria:
  Solution* sol1 = new Solution(sol->getpi());
  //Se copia la info. de sol en sol 1
  sol1->copiarSolucion(sol);
  //Lo agrego al vector 
  this->Soluciones.push_back(sol1);
}


void FrentePareto::imprimirFrente(){
  
  int aux = 0;  //Contaodr auxiliar

  for (Solution* i: this->Soluciones){
    cout << aux;
    for (int j = 0; j < i->getpi()->getCantFO(); j++){
      cout << "\t" << i->getfo(j);
    } 
    cout << endl;
    aux++;
  }
}


void FrentePareto::imprimirFrenteaArchivo(string nombre){

  ofstream archivo(nombre, ios::out);

  int aux = 0;  //Contaodr auxiliar

  for (Solution* i: this->Soluciones){
    for (int j = 0; j < i->getpi()->getCantFO(); j++){
      archivo << "\t" << i->getfo(j);
    } 
    archivo << endl;
    aux++;
  }

}



