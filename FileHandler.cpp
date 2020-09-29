#include "FileHandler.h"

ProblemInstance *FileHandler::readInputFile(){

  //Se reserva el espacio (se invoca constructor) y sólo tiene una dirección de espacio memoria.
  // El New se hace para crear clases, no para metodos de clases
  ProblemInstance *pi = new ProblemInstance();

  //Ejecuta la lectura para la variable fs
  this->fs = fstream( this->instanceFilename );

  //Error por si uno el da mal la ruta
  if ( ! this->fs ) // Si la dirección está vacía, tira error 
	{
		cerr << "No se puede abrir archivo: "<< this-> instanceFilename << endl;
		exit(0);
	}

	//Se crea una línea de tipo string 
	string linea;
  //Se obtiene la primera linea 
  getline(this->fs,linea);

  //Imprimo que se está leyendo "linea"
  //cout << "Cantidad de objetivos: " << linea << endl;
	//Declaro una variable para que me reserve la cantidad de objetivos, y la transformo de string a int
  int n_objetivos = atoi(linea.c_str());  
  //Setear el valor de la instancia:
  pi->setCantFO(n_objetivos);
  // También podría ser: pi.setCantFO(n_Objetivos)


  //Se obtiene la segunda linea (se sobreescribe linea)
  getline(this->fs,linea);
  //Imprimir cantidad de objetos
  //cout << "Cantidad de objetos: " << linea << endl;  
  //Se vuelve a transformar el dato y a generar variable local
  int n_obj = atoi(linea.c_str());
  //Seteo el valor de la cantidad de objetos
  pi->setCantObj(n_obj);


  //Se crea dirección de memoria a objeto y se setea el ID de los objetos que van en la mochila
  for (int i = 0; i < n_obj; i++){
    Object * temp = new Object();
    // Creo un puntero temporal de tipo objeto para crear el espacio de memoria (new) de la clase objeto
    temp->setID(i);
    
    //Agrego el Objeto (temp) a través del método de agregar objeto
    pi->agregarObjeto(temp); 
  }
  
  //Se obtiene la tercera linea (se sobreescribe linea)
  getline(this->fs,linea);
  //Imprimir lineas 
  //cout << "Tercera linea: " << linea << endl;
  //Seteo el valor de la cantidad de objetos
  pi->setCapacidad(atoi(linea.c_str()));

  //Cuarta linea: Ganancias para cada objetivo:
  for (int i = 0; i < n_objetivos; i++){
    for (int j = 0; j < n_obj; j++){
      
      // Este formato lee hasta que encuentre el primer espacio. El ">>" me lee una entrada, que en este caso es una variable.
      this->fs >> this->read;
      

      //Se crea variable temporal para obtener los objetos (j)
      Object *temp = pi->getObjetos(j);

      temp->agregarValor(atoi(read.c_str()));
    }
  }

  //Quinta y última línea: para leer los pesos
  //Recorro toda la línea de los pesos de cada objetivo
  for (int i = 0; i < n_obj; i++){
    //Leo cada valor, hasta encontrar un espacio
    this->fs >> this->read; 

    //Seteo el valor de fs para los pesos 
    //Llamo a la función getObjetos para traer el objeto y seterale su peso
    Object * temp = pi->getObjetos(i) ;
    temp->setPeso(atoi(read.c_str())); 

  }

  return pi;

}

