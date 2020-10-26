dir="Instancias"
outAll="Out.txt"
salida="salida.txt"
out="Solucion.txt"
paretoFront="PF.txt"

rm -rf ${outAll} ${salida} ${out} ${paretoFront}

itExt=1000
itInt=1000
params="${itExt} ${itInt}"

instanceList="KP_p-3_n-10_ins-1.txt KP_p-3_n-50_ins-1.txt KP_p-4_n-10_ins-1.txt KP_p-5_n-10_ins-1.txt"
seedList="129 137 279 672 195 666 429 762 821 483 999 729 318 349 287 241 476 555 581 573"

for instance in ${instanceList}; do
    echo "Ejecutando instancia: ${instance}" 
    
    #Busca puntos de referencia en el archivo respectivo
    exec<"puntosDeReferencia.dat"
    
    while read line
    do
#         echo "@line" 
        set -- $line
        name=$1
        if [[ ${instance} == ${name} ]]; 
        then
            puntosReferencia=${line#* }
            echo "nombre: ${name}, puntosReferencia: ${puntosReferencia}" 
        fi
    done
    #Puntos de referencia encontrados
    
    #Para cada semilla
    for seed in ${seedList}; do
	rm -rf ${paretoFront}

	#Ejecutar MOPK 
   	echo "/.MOPK ${dir}/${instance} ${seed} ${params}"
   	./MOPK ${dir}/${instance} ${seed} ${params}
    
    	#Agregar los # al frente para cálculo de hv
    	echo "#" >> ${paretoFront}
    	cat ${out} >> ${paretoFront}
    	echo "#" >> ${paretoFront}
 
	#Calcular los hv
    	echo "./wfg ${paretoFront} ${puntosReferencia} > ${salida}"
    	./wfg ${paretoFront} ${puntosReferencia} > ${salida}  

    	quality=`tail -3 ${salida} |head -1 |awk -F ' = ' '{print $2}'`

    	echo "${instance} ${seed} ${quality}" >> ${outAll}
    done
done
