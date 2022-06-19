from MatrixOps import Operational1D as arr

ls1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
ls2 = [[1, 2, 3], [4, 5, 6], [7, 8, 10]]

x = arr(ls1)
y = arr(ls2)
z = x.copy()

print(x)
print(z)
print(z == x)