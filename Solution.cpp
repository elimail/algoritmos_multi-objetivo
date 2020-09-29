#include "Solution.h"

//Métodos de seteo
void Solution::setfo(int fo){
  this->fo.push_back(fo);
}

void Solution::setrepS(int repS){
  this->repS.push_back(repS);
}

void Solution::setpesoTotal(int pesoTotal){
  this->pesoTotal = pesoTotal;
}

//Método para obtener variables (los get's):
int Solution::getfo(int m){
  //Verifico si el objeto está dentro del largo del vector 
  if (m > this->fo.size()){
    cout << "Error en getFO() de Objeto." << endl;
    getchar();
  }
  else {
    //Accede al elemento de la posición m
    return this->fo.at(m);
  }
}

int Solution::getrepS(int m){
  //Verifico si el objeto está dentro del largo del vector 
  if (m > this->repS.size()){
    cout << "Error en getrepS() de Objeto." << endl;
    getchar();
  }
  else {
    //Accede al elemento de la posición m
    return this->repS.at(m);
  }
}

int Solution::getpesoTotal(){
  return this -> pesoTotal;
}


ProblemInstance* Solution::getpi(void){
  return this->pi;
}


void Solution::modificarfo(int indice, int valor){
  this->fo.at(indice) = valor; 
}


void Solution::modificarObj(int indice, int valor){
  this->repS.at(indice) = valor; 
}


int Solution::generarSemilla(int minimo, int maximo){

  int numero = rand() % abs(maximo - minimo + 1) + minimo;

  return numero;

}


int Solution::getrepSsize(){
  return this->repS.size();
}


void Solution::imprimeResultado(void){


  cout << "Resultados: " << "\t";
  //Que imprima los valores objetivos 
  for (int i = 0; i < this->fo.size(); i++){
    cout << getfo(i) << "\t";
  } 
  cout << endl;
  
  cout << "Soluciones: " << "\t";
  //Que imprima las soluciones
  for (int i = 0; i < this->repS.size(); i++){
    cout << getrepS(i) << "\t";
  }
  cout << endl;

  //Que imprima el peso total 
  cout << "Peso total ocupado: " << this->pesoTotal <<endl;
}