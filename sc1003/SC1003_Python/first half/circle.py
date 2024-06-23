import math

radiusString = input("Enter radius of your circle: ")
radiusInt = int(radiusString)

circumference = 2 * math.pi * radiusInt
area = math.pi *(radiusInt ** 2)

print(f"The circumference is: {circumference} and the area is: {area} ")
