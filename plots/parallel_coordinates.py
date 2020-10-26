import plotly
import plotly.express as px
import pandas as pd
import sys

#$ python3 parallel_coordinates.py Solucion3.txt 



df = pd.read_table(sys.argv[1], delim_whitespace=True, header=None)
cols = ['obj1', 'obj2', 'obj3']
df.columns = cols
fig = px.parallel_coordinates(df, color = "obj1", labels={"obj1": "Obj1", "obj2": "Obj2", "obj3": "Obj3",},
                             color_continuous_scale=px.colors.diverging.RdYlBu,
                             color_continuous_midpoint=15000)
#fig = px.parallel_coordinates(df, color="species_id", labels={"species_id": "Species",
                #"sepal_width": "Sepal Width", "sepal_length": "Sepal Length",
                #"petal_width": "Petal Width", "petal_length": "Petal Length", },
                             #color_continuous_scale=px.colors.diverging.Tealrose,
                             #color_continuous_midpoint=2)


fig.show()
