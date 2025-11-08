# B20, Given char from a to h and natural number  n =< 8 . Example, a2. Given pair identifies a box in chessboard where Queen is placed. Print on screen the chessboard marked with X those boxes where the Queen can move.
# Program created on : 25/10/2025

ok = 1  # Variable to control the loop for multiple inputs
while ok == 1:
    a = input("Enter a letter from a to h: ").lower()
    if a.isalpha() == False: # Check if input is not a character
        print("Error message: Not a Character")
    elif len(a) != 1: # Check if input is more than one character
        print("Error message: More than one character")
        continue
    try:
        n = int(input("Enter a natural number from 1 to 8: "))
    except ValueError: # Check if input is not a number
        print("Error message: Not a Number")
        continue
    if (n < 1 or n > 8) and (a < 'a' or a > 'h'): # Check if both inputs are out of range
        print("Error message: Wrong Number and Wrong Letter")
    elif a < 'a' or a > 'h': # Check if letter input is out of range
        print("Error message: Wrong character")
    elif n < 1 or n > 8: # Check if number input is out of range
        print("Error message: Wrong Number")
    else:
        a_num = ord(a) - ord('a') + 1  # Convert letter to number
        for y in range(8, 0, -1):
            print(y, end="")  # Print row position number
            print(" ", end="")
            for x in range(1, 9):
                if x == a_num and y == n:
                    print("[Q]", end="")  # Print Q for Queen's position
                elif x == a_num or y == n or abs(x - a_num) == abs(y - n):
                    print("[X]", end="") # Print X for positions where the Queen can move
                else:
                    print("[ ]", end="")  # Print empty positions
            print()  # Move to the next line after printing each row
        print("   a  b  c  d  e  f  g  h  ")  # Print column position letters
    print()  # Print an empty line after the board
    ok = int(input("If you would like to continue, enter 1 and to exit, enter any other number : "))
