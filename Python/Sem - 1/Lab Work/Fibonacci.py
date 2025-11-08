# A19, Given natural number n. Find Fibonacci number f(n). (Fibonacci numbers are: f(1) = 1, f(2) = 1, f(n) = f(n-1) + f(n-2), t. i. f(3)=2, f(4)=3, f(5)=5 ...)
# Program created on : 24/09/2025

a = 1  # Variable declaration to loop the program later
while (a == 1):
    n = (int(input("Enter a natural number: ")))  # Natural number declaration
    n1 = n
    if n < 0:  # Error message for non-natural numbers
        print("Error message: Not a natural number")
    elif n == 0:  # Answer for 0
        print("f( 0 ) = 0")
    else:
        f1 = 0
        f2 = 1
        while n > 0:  # loop to find the Fibonacci number
            F = f1 + f2
            f2 = f1
            f1 = F
            n = n - 1
        print("f(", n1, ") = ", F, sep="")  # Output of the Fibonacci number
    a = int(input(
        # Loop to continue or exit the program
        "If you would like to continue, enter 1 and to exit, enter any other number : "))
