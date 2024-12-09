#Combinatorial Login

errM = "Username or password are incorrect."
Prompt = "Enter Password: "
answer2 =""
answer3 =""
combo = input("Enter your combo 1-3: ")
#the below if-statement uses round robin and palindrome algorithms to create the password sequences.
if combo == "1":
    password = ["1234", "hole", "9876"]
elif combo == "2":
    password = ["eloh", "4321", "6789"]  
elif combo == "3":
    password = ["9876", "1234", "hole"]
elif combo == "4":
    password = ["hole", "9876", "1234"]
    
#the below if-statement verifies the password sequences are entered correct.
while True:

    answer1 = input(Prompt)
    print(errM)
    
    if answer1 == password[0]:
        answer2 = input(Prompt)
        print(errM)
        if answer2 == password[1]:
            answer3 = input(Prompt)
            print(errM)
            if answer3 == password[2]:
                print("You have successfully logged in! Hello Super User.")
                break
