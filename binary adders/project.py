import adders
# importing the module that includes the half and full functions to be used
def main(): # main
    while True:
        try:
            mode = int(input("Binary Adder Circuit Simulator\n1: Half adder\n2: Full adder\nType the number to enter the mode: "))
            if mode == 1:
                adders.half()
                break
            elif mode == 2:
                adders.full([-1, -1])
                break
            else: # validation of user menu option choice
                print("Invalid option. Try again.\n")
        except ValueError:
            print("Invalid option. Try again.\n")

if __name__ == "__main__":
    main()
