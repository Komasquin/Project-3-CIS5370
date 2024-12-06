# Simple Login System: Two Passwords Required
# Multi-Attempt Login

# User credentials
user_db = {
    "user1": ["pass1", "pass1"], # Multi-attempt login is defined as using two identical passwords
    #"user2": ["hello1", "world2"], # Sequence login is defined as using two different passwords
}

errM = "Username or password are incorrect."
prompt = "Enter Password: "

while True:
    print("Attempting Login...\n")
    
    username = input("Username: ").strip()
    
    # Validate username
    if username not in user_db:
        print(errM)
        continue
    
    # Validate first password
    password1 = input(prompt)
    if password1 != user_db[username][0]:
        print(errM)
        continue
    
    # Validate second password
    password2 = input(prompt)
    if password2 != user_db[username][1]:
        print(errM)
        continue
    
    print(f"Login successful! Welcome, {username}.\n")
    break