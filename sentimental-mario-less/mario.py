from cs50 import get_int

h = get_int("Height: ")
while(h < 1 or h > 8):
    h = get_int("Height: ")

for i in range(h):
    for j in range(h):
        if (h-i-j) > 1:
            print(" ", end="")
        else:
            print("#", end="")
    print()
