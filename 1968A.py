# Function to solve the problem
def maximize_gcd(t, test_cases):
    results = []
    for x in test_cases:
        y = x - 1
        results.append(y)
    return results

# Input handling
t = int(input())
test_cases = [int(input()) for _ in range(t)]

# Getting the results
output = maximize_gcd(t, test_cases)

# Output the results
for result in output:
    print(result)
