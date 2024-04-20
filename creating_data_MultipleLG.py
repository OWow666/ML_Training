import numpy as np

'''
y = beta_0 + beta_1*x_1 + beta_2*x_2 + e
'''
beta_0 = 2
beta_1 = 3
beta_2 = -1
n = 100

np.random.seed(42)
x1 = np.random.normal(0, 1, n)
x2 = np.random.normal(0, 1, n)
e = np.random.normal(0, 1, n)

Y = beta_0 + beta_1*x1 + beta_2*x2 + e

with open("MLG_data.txt", "w") as f:
    for i in range(n):
        f.write(str(x1[i])+' '+str(x2[i])+' '+str(Y[i])+'\n')
    f.close()
