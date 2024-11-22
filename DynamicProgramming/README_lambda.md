## Lambda function for Fibonacci with memoization

### Code details

std::function<int(int)>: 
This is a type-erased wrapper for callable objects (like functions, lambdas). It’s used here because the lambda function calls itself recursively.

in """if (memo.find(n) != memo.end()) return memo[n];"""  If n is already computed and stored in memo, return the cached result.

then if n is not in the memo, compute it recursively. The result is then stored in memo[n] for future use.