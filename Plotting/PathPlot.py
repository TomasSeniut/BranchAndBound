from solution import *
import numpy as np
import matplotlib.pyplot as plt

y, x = np.loadtxt('../cmake-build-debug/' + dataFileName, unpack=True)

alfa_omega = [solution[0], solution[-1]]

plt.scatter(x, y, c = 'k', alpha = 0.8, lw = 0)

plt.plot(x[solution], y[solution], c = 'b')
plt.plot(x[alfa_omega], y[alfa_omega], c = 'b')

plt.title(dataFileName)

plt.savefig(dataFileName + '_result.png')
plt.show()