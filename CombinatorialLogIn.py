#Combinatorial Login

errM = "Username or password are incorrect."
Prompt = "Enter Password: "

combo = input("Enter your combo 1-4: ")
#the below if-statement uses round robin and palindrome algorithms to create the password sequences.
if combo == "1":
    password = ["1234", "hole", "9876"]
elif combo == "2":
    password = ["hole", "9876", "1234"]  
elif combo == "3":
    password = ["9876", "1234", "hole"]
elif combo == "4":
    password = ["eloh", "4321", "6789"]
    
answer1 = input(Prompt)
#the below if-statement verifies the password sequences are entered correct.
if answer1 == password[0]: 
    answer2 = input(Prompt)
    if answer2 == password[1]:
        answer3 = input(Prompt)
        if answer3 == password[2]:
            print("You have successfully logged in! Hello Super User.")
        elif answer3 != password[2]:
            print(errM)
    elif answer2 != password[1]:
        print(errM)
elif answer1 != password[0]:
    print(errM)
