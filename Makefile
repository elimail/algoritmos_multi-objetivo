#Aquí se agregan los objetos para compilar
OBJS = main.o Object.o ProblemInstance.o FileHandler.o Solution.o Construction.o Movimiento.o FrentePareto.o
#Para poner opciones de la versión de C++ a ocupar 
FLAGS = -O3

#Que genere el archivo llamado así
all: MOPK

#Que se va a hacer cada vez que se llame al archivo
MOPK: $(OBJS)
	g++ -o MOPK $(OBJS) $(FLAGS)
  
#Para generar cualquier punto .o necesito cualquier punto .cpp
%.o: %.cpp %.h
	g++ -c $(FLAGS) $< -o $@

#Para que me lea el archivo de las instancias 

# nombreAlgoritmo nombreArchivo semilla itExt itInt

exe:
	./MOPK Instancias/KP_p-3_n-50_ins-1.txt 4 10000 10000

exe4:
	./MOPK Instancias/KP_p-4_n-10_ins-1.txt 10 500 500

exe5:
	./MOPK Instancias/KP_p-5_n-10_ins-1.txt 2 1000 1000

clean: 
	rm -rf *.o MOPK
