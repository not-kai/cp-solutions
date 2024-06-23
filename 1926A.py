# Function to find the letter that appears most frequently
def most_frequent_letter(s):
    count_A = s.count('A')
    count_B = s.count('B')
    if count_A > count_B:
        return 'A'
    else:
        return 'B'

# Input number of test cases
t = int(input())

# Iterate through each test case
for _ in range(t):
    # Input the string
    s = input()
    # Find and output the most frequent letter
    print(most_frequent_letter(s))
