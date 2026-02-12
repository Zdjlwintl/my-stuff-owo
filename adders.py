import string

def ask_input(inp_1, inp_2): # function to ask for user input of binary digits, including the validation
    while True:
        try:
            a = int(input(f"{inp_1}: "))
            b = int(input(f"{inp_2}: "))
            if (a not in (0,1) or b not in (0,1)):
                print("Invalid option(s). Inputs must be either 0 or 1.")
            else:
                break
        except ValueError:
            print("Invalid option(s). Inputs must be either 0 or 1.")
    inputs = [a, b]
    return inputs # the pair of inputs are returned as an array so both values can be accessed

def full(inputs):
    print("This is the full adder.")
    continued = False
    if inputs != [-1, -1]: # if this is continuing from the half adder demo
        a = inputs[0]
        b = inputs[1]
        print(f"We will continue using our values A: {a} and B: {b}.")
        continued = True
    else: # if this is selected from the start menu
        print("To continue, provide binary values for A and B.")
        inputs_1 = ask_input("A", "B")
        a = inputs_1[0]
        b = inputs_1[1]
    print("Now, provide binary values for new values C and D.")
    inputs_2 = ask_input("C", "D")
    c = inputs_2[0]
    d = inputs_2[1] # demonstrating the full adder with the addition of two bit numbers
    print("\nRemember, it's important to understand that these adders are used to perform bitwise addition.")
    print(f"You had just been asked to input values for A, B, C and D; to demonstrate, the bit number CA ({c}{a}) can be added to DB ({d}{b}) using half and full adders:\n")
    print(f"{c}{a}\n{d}{b}\n--- +\n")
    sum1 = a^b
    carry1 = a|b
    if continued == True: # [i]f this was continued from the half adder demo
        print(f"As we have just done earlier: when A and B are passed to the half adder, the sum is {sum1} and the carry is {carry1}.")
    else:
        print(f"Computing the sum and carry of A + B is explained in the half adder section, but for now just know that the sum of the LSBs is {sum1} and the carry is {carry1}.")
    print("Knowing this, the full adder takes the carry bit from the half adder and adds that to the current bitwise addition:\n")
    print(f"The MSBs of the two numbers ({c} and {d}) and the carry ({carry1}) are added to together as such:")
    sum2 = c ^ d ^ (carry1)
    carry2 = (a & c) | ((carry1) & (a ^ c))
    print(f"Sum: C XOR D XOR (Carry bit): {c} XOR {d} XOR {carry1} = {sum2}")
    print(f"Carry out: (A AND C) OR (Carry bit AND (A XOR C)): ({a} AND {c}) OR ({carry1} AND ({a} XOR {c})) = {carry2}\n")
    print(f"So what we have now is this:\n0{c}{a}\n0{d}{b}\n--- +\n{carry2}{sum2}{sum1}")
    print("\nWhich is indeed the result of doing it by hand. This was just a tiny example but this is what builds the basis of arithmetic using only logic gates.")
    # lots of printing for explanation

def half():
    print("This is the binary half adder.\nIn order to continue, provide the binary values for A and B.")
    inputs = ask_input("A", "B") 
    a = inputs[0]
    b = inputs[1]
    print(f"You now have two inputs: {a} and {b} respectively.")
    print("In a binary half adder, two operations happen: A XOR B, and A AND B; ", end="")
    print("The former is used for the sum and the latter is used for the carry out:")
    print(f"Sum: {a} XOR {b} = {a ^ b}\nCarry: {a} AND {b} = {a & b}\n")
    print("The purpose of the half adder is to compute the bitwise addition between the least significant bits of the two inputs. The full adder demonstration will show how addition between multiple digit binary numbers is done.")
    cont = input("Continue with the full adder? [Y/n]\n").strip().lower() # ask user if they want to exit or to continue to the full adder
    if cont in ('y', ''):
        full(inputs) # call the full function