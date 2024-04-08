import numpy as np

clas=['0-10','10-20','20-30','30-40','40-50','50-60','60-70','70-80']
frequency=[5,10,20,40,30,20,10,5]

midclass=[]
for i in clas:
    k=i.split('-');
    x=(int(k[1])+int(k[0]))//2
    midclass.append(x)
    
print(midclass)

mean = np.average(midclass,weights=frequency)

var = np.average((midclass - mean)**2, weights=frequency)

sd = np.sqrt(var)

cv = (sd/ mean)

print("Mean:",mean)
print("Variance: ",var)
print("Standard Deviation: ",sd)
print("Coefficient Of Variation: ",cv)
