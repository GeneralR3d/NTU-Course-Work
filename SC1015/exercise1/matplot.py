# Basic Libraries
import numpy as np
import pandas as pd
import seaborn as sb
import matplotlib.pyplot as plt # we only need pyplot
sb.set() # set the default Seaborn style for graphics
pkmndata = pd.read_csv('pokemonData.csv')
pkmndata.head()
print(type(pkmndata['HP']))
hp = pd.DataFrame(pkmndata['HP'])# DataFrame not only takes in a python dict, but also a series and converts it back to a dataframes
print("Data type : ", type(hp))
print("Data dims : ", hp.size)
hp.head(10)
f = plt.figure(figsize=(24, 4))
sb.boxplot(data = hp, orient = "h")