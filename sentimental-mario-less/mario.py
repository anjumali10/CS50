import cs50

# Get the pyramid height from the user
height = cs50.get_int("Height: ")
while height <= 0 or height > 8:
    height = cs50.get_int("Height: ")

for i in range(height):

    # Loop for printing spaces
    for j in range(i + 1, height):
        print(" ", end = '')

    # Loop for printing bricks of pyramid
    for k in range(i + 1, 0, -1):
        print("#", end = '')
    print("")
