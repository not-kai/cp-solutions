def max_prefix_subsequence(t, test_cases):
    results = []
    for _ in range(t):
        n, m, a, b = test_cases[_]
        i = j = 0
        while i < n and j < m:
            if a[i] == b[j]:
                i += 1
            j += 1
        results.append(i)
    return results

# Reading input
t = int(input().strip())
test_cases = []
for _ in range(t):
    n, m = map(int, input().strip().split())
    a = input().strip()
    b = input().strip()
    test_cases.append((n, m, a, b))

# Getting results
results = max_prefix_subsequence(t, test_cases)

# Printing results
for res in results:
    print(res)
