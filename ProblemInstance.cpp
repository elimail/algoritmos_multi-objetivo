#include "ProblemInstance.h"
#include <vector>

// Métodos set
// Método para agregar objetos
void ProblemInstance::agregarObjeto(Object* ob1){
  //Encolar una variable ob1 al vector de Objetos de la instancia
  this->Objetos.push_back(ob1);
}

void ProblemInstance::setCapacidad(int capacidad){
  this->Capacidad = capacidad;
}

void ProblemInstance::setCantFO(int cant_fo){
  this->CantFO = cant_fo;
}

void ProblemInstance::setCantObj(int cant_obj){
  this->CantObj = cant_obj;
}

// Métodos get

// Método getObjetos
Object *ProblemInstance::getObjetos(int id_objeto){
  for (Object* i:this->Objetos){
    if (i->getID() == id_objeto){
      return i;
    }
  }
}


vector <Object*> ProblemInstance::getTODOSObjetos(){
  return this->Objetos;
}



int ProblemInstance::getCapacidad(){
  return this->Capacidad;
}

int ProblemInstance::getCantFO(){
  return this->CantFO;
}

int ProblemInstance::getCantObj(){
  return this->CantObj;
}

void ProblemInstance::ImprimirProblemInstance(){

  cout << "Cantidad de objetivos:" << this->CantFO << endl;
  cout << "Cantidad de objetos: " << this->CantObj << endl;
  cout << "Capacidad máx. mochila: " << this->Capacidad << endl;

  for (Object* i:this->Objetos){
    i->ImprimeObjeto();
    //cout << "ID: " << i->getID() << "\t" ;
    //cout << "peso: " << i->getPeso() << "\t";
    cout << "valores: " << "\t";

    for(int j = 0; j < this->CantFO; j++ ){
      cout << i->getValor(j) << "\t";
    }

    cout << endl;
  }

}