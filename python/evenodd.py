#! /usr/bin/python3
def main():
    n=int(input("Enter the number:"))
    if(n%2==0):
        print("Given number is even")
        n=n**2
        print("Square of given number :",n)
    else:
        print("Given number is odd")
        n=n**3
        print("Cube of given number :",n)


if __name__ == "__main__":
    main()
