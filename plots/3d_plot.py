import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import sys
import pandas as pd

#$ python 3d_plot.py Solucion2.txt Solucion3.txt 

inPF1 = pd.read_table(sys.argv[1], delim_whitespace=True)
inPF2 = pd.read_table(sys.argv[2], delim_whitespace=True)

fig = plt.figure()
ax = Axes3D(fig)

x1 = inPF1.iloc[:,0].values
y1 = inPF1.iloc[:,1].values
z1 = inPF1.iloc[:,2].values

x2 = inPF2.iloc[:,0].values
y2 = inPF2.iloc[:,1].values
z2 = inPF2.iloc[:,2].values


ax.scatter(y1,x1,z1,label='PF1',)#,marker="o",label='EVOCA',c='blue',alpha=0.5,edgecolor='black', linewidth='0.5')
ax.scatter(y2,x2,z2,label='PF2',)#,marker="s",label='ParamILS',c='red',alpha=0.7, edgecolor='black', linewidth='0.5')


ax.set_title("Instancia: KP_p-3_n-50_ins-1.txt",size=16)
ax.set_ylabel("Obj2")
ax.set_xlabel("Obj1")
ax.set_zlabel("Obj3")
ax.legend(loc='upper left')

plt.savefig('3d_plot.png')
#plt.savefig("plot.pdf")
