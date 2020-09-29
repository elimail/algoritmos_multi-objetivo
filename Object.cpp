//Hay que llamar a la clase objeto 
#include "Object.h"

//Va a ir agregando los valores al final de la fila 
void Object::agregarValor(int valor){
  this->valor.push_back(valor);
}

int Object::getValor(int m){
  //Verifico si el objeto está dentro del largo del vector 
  if (m > this->valor.size()){
    cout << "Error en getValor() de Objeto." << endl;
    getchar();
  }
  else {
    //Accede al elemento de la posición m
    return this->valor.at(m);
  }
}

void Object::setPeso(int peso){
  //Se setea el atributo del objeto
  this->peso=peso;
}

int Object::getPeso(void){
  //Se retorna el valor del peso 
  return this->peso; 
}

int Object::getID(void){
  //Se retorna el valor del peso 
  return this->ID; 
}

void Object::setID(int id){
  //Se retorna el valor del peso 
  this->ID = id; 
}

void Object::ImprimeObjeto(){
  cout << "ID: " << this->ID << "\t" ;
  cout << "Peso: " << this->peso << "\t" ;  
}