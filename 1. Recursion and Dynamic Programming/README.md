# Recursion and Dynamic Programming
## Recursion
Recursion is a problem solving method where a function calls itself repeatedly to solve subproblems.  The solutions to the subproblems are used to build the solution of the initial problem.  Generally, a recursive function contains two sections, a recursive section and a base case section.  The recursive section calls breaks the problem into smaller subproblems.  The base case returns a value because it is the smallest possible subproblem.

### Example: Fibonacci Numbers
```python
def fib(int n):
	if n is 0:
		return 0
	elif n is 1:
		return 1

	return fib(n-1) + fib(n-2)	
```

```c++
int fib(int n){
	if (n == 0) { return 0; }
	if (n == 1) { return 1; }

	return fib(n-1) + fib(n-2);
}
```

### Advantages and Disadvantages of Recursion
Advantages:
- Recursion can be simple to understand
	- Makes it easier to write the code 
	- Makes it easier to understand the order of execution in the tree (the sequence of calls made by the recursive function)
	- When you understand the sequence of calls for a function, it's easier to determine the runtime complexity
Disadvantages:
- Generally, it takes longer for a recursive function to solve a problem
	- Has to maintain the stack
	- Might have to traverse more nodes in the tree (i.e. the recursive function makes more calls)
- Recursive functions have a larger space complexity
	- Each recursive call adds takes up space on the stack
	- If there are N recursive calls, then the space complexity is O(N)

# Dynamic Programming
Dynamic programming optimizes recursive and iterative programming solutions that make repeated calls for duplicate inputs.  Dynamic programming stores the results of subporblems so that the algorithm does not need to re-compute them later.  We typically reducetime complexities from exponential to polynomial through dyanmic programming.  The Fibonacci sequence is the quintessential example for using dynamic programming.  

There are generally considered two methods in Dynamic Programming:
1. Top-Down or Memoization
2. Bottom-Up or Dynamic Programming or Tabulation

The top-down approach is also known as memoization.  It's similar to recursion because it starts with the large instance of the problem and builds the solution with solutions to subproblems.  

Bottom-up is mostly known as bottom-up, but can also go by Dynamic Programming (yes, confusing), and also by tabulation.  Bottom-up is a little different because it takes the recursive solution and turns it into an iterative solution.  To do this, you must understand the structure of the recursive problem: you must know the base case, and you must understand how the base case iterates into larger subproblems until it reaches the original large problem.  

## Example: Fibonacci Numbers

The recusive solution from dynamic programming yields exponential runtime:
```python
def fib(int n):
	if (n <= 1):
		return n
	return fib(n-1) + fib(n-2)
```
But with Dynamic Programming, we achieve linear runtime.  Here's the bottom-up approach
```python
memo = {0:0, 1:1}

for i in range(0, n):
	f[i] = [i-1] + f[i-2];
return f[n]
```
Here's the top-down approach:

```python
memo = {0:0, 1:1}

for i in range(0, n+1):
	memo[i] = memo[i-1] + memo[i-2];
return memo[n]
```