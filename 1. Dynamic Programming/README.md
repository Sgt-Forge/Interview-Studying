# Dynamic Programming
Dynamic programming optimizes recursive and iterative programming solutions that make repeated calls for duplicate inputs.  Dynamic programming stores the results of subporblems so that the algorithm does not need to re-compute them later.  We typically reducetime complexities from exponential to polynomial through dyanmic programming.  The Fibonacci sequence is the quintessential example for using dynamic programming.  The recusive solution from dynamic programming yields exponential runtime:
```python
def fib(int n):
	if (n <= 1):
		return n
	return fib(n-1) + fib(n-2)
```
But with dynamic programming, we achieve linear runtime:
```python
f[0] = 0
f[1] = 1

for i in range(0, n):
	f[i] = [i-1] + f[i-2];
return f[n]
```
