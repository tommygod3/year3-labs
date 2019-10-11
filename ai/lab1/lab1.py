import random
import numpy as np

rows = 3
identity_matrix = np.identity(rows)

def random_list(length):
    base = []
    for index in range(length):
        base.append(random.randint(1, 101))
    return base

two_dimensional_list = []
for row in range(rows):
    two_dimensional_list.append(random_list(rows))

random_array = np.array(two_dimensional_list)

print(f"random_array = \n{random_array}")

print(f"random_array + identity_matrix = \n{random_array + identity_matrix}")

print(f"random_array * identity_matrix = \n{random_array * identity_matrix}")

print(f"random_array.dot(identity_matrix) = \n{random_array.dot(identity_matrix)}")

print(f"Maximum: {np.amax(random_array)}")

for row in range(rows):
    print(f"{row}: {np.amax(random_array[row])}")

print(f"random_array < 2: \n{random_array < 2}")

three_dimensional = np.zeros((4,3,2))
print(three_dimensional)
print(f"Shape: {three_dimensional.shape}")

print(np.append(random_array,random_list(rows)))

