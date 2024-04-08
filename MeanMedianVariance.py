import pandas as pd
import numpy as np
# Create a list of lists to store the data
data = [
    ["Alabama", 4779736, 5.7],
    ["Alaska", 710231, 5.6],
    ["Arizona", 6392017, 4.7],
    ["Arkansas", 2915918, 5.6],
    ["California", 37253956, 4.4],
    ["Colorado", 5029196, 2.8],
    ["Connecticut", 3574097, 2.4],
    ["Delaware", 897934, 5.8],
]

df = pd.DataFrame(data, columns=["State", "Population", "Murder Rate"])

murder=[]

df["Murder"] = df["Population"]*df["Murder Rate"]
#print(df["Murder"])

x=list(df["Murder"])
for i in range(0,len(x)):
    x[i] = x[i]/100000
#print(x)

mean=np.mean(x)
med=np.median(x)
var=np.var(x)
print("Mean: ",mean)
print("Median: ",med)
print("Variance: ",var)
