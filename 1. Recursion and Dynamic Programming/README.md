# Recursion and Dynamic Programming
## Recursion
Recursion is a problem solving method where we build the solution to a problem using solutions to subprobelms.  We combine the solutions of smaller problems to arrive at the solution for the original large problem.  

Think of the Fibonacci numbers as the classic example.  If you want to calculate the 3rd Fibonacci number, you take the sum of the first two Fibonacci numbers.  The first two Fibonacci numbers are the subproblems, and the 3rd Fibonacci number is your larger problem.

Generally, a recursive function contains two sections, a recursive section and a base case section.  The recursive section breaks the problem into smaller subproblems.  The base case returns a value because it is the smallest possible subproblem.  In out Fibonacci number example, the recursive case is when we call `Fibonacci(N-1) + Fibonacci(N-2)`, where N is our original number from the large problem.  Notice how we break up the problem into subproblems by subtracting from the original large problem.  The base case for the Fibonacci example is when we arrive at the values 1 and 0.  So the base case would look like: `Fibonacci(1) = 1` and `Fibonacci(0) = 0`.

### Example: Fibonacci Numbers
In Python3:
```python
def fib(int n):
	if n is 0:
		return 0
	elif n is 1:
		return 1

	return fib(n-1) + fib(n-2)	
```
In C/C++:
```c++
int fib(int n){
	if (n == 0) { return 0; }
	if (n == 1) { return 1; }

	return fib(n-1) + fib(n-2);
}
```

You can think of iteration as an opposite to recursion.  If you wanted to calculate the Nth Fibonacci number, you could start at 1 and iterate until you get to N.  We'll discuss this more when we get to Dynamic Programming.

### Advantages and Disadvantages of Recursion
Advantages:
- Recursion can be simple to understand
	- Makes it easier to write the code 
	- Makes it easier to understand the order of execution in the tree (the sequence of calls made by the recursive function)
	- When you understand the sequence of calls for a function, it's easier to determine the runtime complexity

Disadvantages:
- Generally, runtime complexity is worse for recursive solutions
	- It takes your computer more time to maintain a stack full of recursive function calls
	- Might have to traverse more nodes in the tree (i.e. the recursive function makes more calls)
- Recursive functions have a larger space complexity
	- Each recursive call adds takes up space on the stack
	- If there are N recursive calls, then the space complexity is O(N)

# Dynamic Programming
Dynamic programming optimizes recursive and iterative programming solutions by eliminating duplicate work.  Dynamic programming stores the results of subporblems so that we only have to compute them once.  We typically reducetime complexities from exponential to polynomial through dyanmic programming.

Notice in the Fibonacci example that the "left" side of the recursive case is always called first.  If you follow the left side of the recursive case a few times you'll see `fib(n-1)`, `fib(n-1-1)`, `fib(n-1-1-1)`, and so on until we reach `fib(1)` on the left side.  Then the "right" side of the recursive case will execute.  We'll see `fib(n-2)`, `fib(n-2-2)`, `fib(n-2-2-2)` and so on until we reach either 1 or 0.  But we already computed many of these subcases in the "left" side of the recursive case!  We computed `fib(n-2)` when we computed `fib(n-1-1)` on the "left" side!  Dynamic programming prevents the duplication in this case.

There are generally considered two methods in Dynamic Programming:
1. Top-Down or Memoization
2. Bottom-Up or Dynamic Programming or Tabulation

The top-down approach is also known as memoization.  It's similar to recursion because it starts with the large instance of the problem and builds the solution with solutions to subproblems.  

Bottom-up is mostly known as bottom-up, but can also go by Dynamic Programming (yes, confusing), and also by tabulation.  Bottom-up is a little different because it takes the recursive solution and turns it into an iterative solution.  To do this, you must understand the structure of the recursive problem: you must know the base case, and you must understand how the base case iterates into larger subproblems until it reaches the original large problem.  

## Top-Down Example: Fibonacci Numbers
Python:
```python
def fib(n):
	memo = {0:0, 1:1}
	fib_helper(n, memo)
	return memo[n]

def fib_helper(n, memo):
	if not n in memo:
		memo[n] = fib(n-1) + fib(n-2)

	return memo[n]
```
C/C++
```c++
int fib(int n){
	int memo[n]; // Shhhhh, I know this should be a dynamic array :)
	memo[0] = 0;
	memo[1] = 1;
	fib(n, memo);

	return memo[n];
}

void fib(int n, int* memo){
	if(!memo[n] && n > 1){
		memo[n] = fib(n-1, memo) + fib(n-2, memo);
	}
}
```

## Bottom-Up Example: Fibonacci Numbers
Python
```python
memo = {0:0, 1:1}

for i in range(0, n):
	f[i] = [i-1] + f[i-2];
return f[n]
```
C/C++
```c++
int fib(n)
	int a, b, c;
	a = 0;
	b = 1;
	for(int i = 2; i <= n; ++i){
		c = a + b;
		a = b;
		b = c;
	}
```