from solution import *
import numpy as np
import matplotlib.pyplot as plt

fileName = dataFileName.split('/')[-1]

y, x = np.loadtxt(dataFileName, unpack=True)

alfa_omega = [solution[0], solution[-1]]

plt.scatter(x, y, c = 'k', alpha = 0.8, lw = 0)

plt.plot(x[solution], y[solution], '->')
plt.plot(x[alfa_omega], y[alfa_omega], c = 'b')

for label, x, y in zip(range(len(x)), x, y):
	plt.annotate(label, xy = (x,y))

plt.title(fileName)

plt.savefig('../PlotResults/' + fileName + '.png')
plt.show()