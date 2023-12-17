import matplotlib.pyplot as plt
import numpy as np

def out(path):
    x1, y1, z1 = np.loadtxt(f"random_{path}.txt", unpack=True)
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')

    x2, y2, z2 = np.loadtxt(f"ordered_{path}.txt", unpack=True)
    plt.plot(x2, y2, marker=".")
    plt.plot(x2, z2, marker='.')

    x3, y3, z3 = np.loadtxt(f"reversed_ordered_{path}.txt", unpack=True)
    plt.plot(x3, y3, marker=".")
    plt.plot(x3, z3, marker='.')

    plt.title('Scatter Plot of Points')
    plt.xlabel('The number of elements in the vector')

    plt.show()


out('bubble')
out('quick')
out('pyramid')