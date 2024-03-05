# O(N^2) - Dynamic Programming

## 1. Idea
We could use a dynamic programming approach. Lets denote the boolean function ***f(left, right)***. 
Where ***f(left, right)*** will return if the substring starting from index left and ending in index right (inclusive) is a palindrome.
Then the transition is very simple -> the substring *[left,right]* is a palindrome if and only if : *s[left] = s[right]* and ***f(left + 1, right - 1)*** is true.
The base cases are for *left > right* we always say it is a palindrome.

## 2. Implementation
We use a recursive function ***f(left, right)*** which calculates the answer. Because we may call the function with the same parameters many times we could use memoization to speed-up the calculation.

**Time complexity:**
O(N^2) states, each of them is calculated in O(1) time.

**Total Time complexity:**
O(N^2)

**Space complexity:**
We use a table to memoize the states which is O(N^2) space.

**Total Space complexity:**
O(N^2)
