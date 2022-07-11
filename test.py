from MatrixOps import Operational1D as arr
import numpy as np

ls1 = [[1, 2, 3], [4, 5, 6], [7, 8, 10]]
ls2 = [[1, 2, 3], [4, 5, 6], [7, 8, 10]]

x = arr(ls1)
y = np.array(ls2)

from time import perf_counter

start = perf_counter()
for _ in range(10000):
    x.copy()
end = perf_counter()

start2 = perf_counter()
for _ in range(10000):
    y.copy()
end2 = perf_counter()

print("Custom time:", end - start)
print("Numpy time:", end2 - start2)
print("Speedup:", (end - start) / (end2 - start2))
print(np.array(x) == np.array(x.copy()))