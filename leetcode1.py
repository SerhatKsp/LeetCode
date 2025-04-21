class Solution:
    def longestPalindrome(self, s: str) -> str:
        #implement functionality to find the longest palindrome in a string (subarray)
        #approach: use of stack datastructure and counter variable while iterating through string once.
        #Initialize an empty stack
        stack = Stack()


dict = {'a' : 1}

dict['5'] = 'string'

# Create a dictionary
student_scores = {
    "Alice": 85,
    "Bob": 90,
    "Charlie": 78
}

# Accessing values using keys
print("Alice's score:", student_scores["Alice"])

# Adding a new key-value pair
student_scores["Diana"] = 92
print("Updated dictionary:", student_scores)

# Updating a value
student_scores["Alice"] = 88
print("Alice's updated score:", student_scores["Alice"])

# Removing a key-value pair using `del`
del student_scores["Charlie"]
print("After removing Charlie:", student_scores)

# Removing a key-value pair using `pop`
removed_score = student_scores.pop("Bob")
print(f"Removed Bob's score ({removed_score}), remaining dictionary:", student_scores)

# Checking if a key exists
if "Alice" in student_scores:
    print("Alice is in the dictionary.")

# Looping through keys, values, and items
print("All students:")
for name in student_scores.keys():
    print(name)

print("All scores:")
for score in student_scores.values():
    print(score)

print("All students with scores:")
for name, score in student_scores.items():
    print(f"{name}: {score}")

# Getting a value with a default using `get`
eve_score = student_scores.get("Eve", "Not Found")
print("Eve's score:", eve_score)

Alice_score = student_scores.get("Alice")
print(f"alice's score: {Alice_score}")

# Clearing all key-value pairs
student_scores.clear()
print("Cleared dictionary:", student_scores)




class Stack: 
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)
    
    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        else:
            print("stack is empty!")
            return None
    
    def peek(self):
        if not self.is_empty():
            return self.stack[-1]
        else:
            print("stack is empty!")
            return None
    
    def is_empty(self):
        return len(self.stack) == 0
    
    def size(self):
        return len(self.stack)
    
#example usage:

stack = Stack()
stack.push(10)
stack.push(20)
stack.push(30)

print(stack.pop())
print(stack.peek())
print(stack.is_empty()) 

isPal = Solution()
s = "mein Name ist Serhat und das ist mein Palindrom Ananas"
print(f"longest palindrom in s = {isPal.longestPalindrome(s)}")