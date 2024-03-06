# O(N^3) - Bruteforce Editorial

## 1. Idea

The idea is a simple bruteforce approach. We try all possible substrings and check each of them if it is a palindrome.

## 2. Implementation

We fix the left and the right boundaries of the substring and check if the current substring is a palidrome. 
If it is a palindrome we check if the current LPS is smaller and if it is - we update the answer.

**Time complexity:**
O(N^2) possible substrings for each of them we check if it is a palindrome in O(N) time.

**Total Time complexity:**
O(N^3)

**Space complexity:**
If we check only using the left and right boundaries we could implement this solution without auxiliary space.

**Total Space complexity:**
O(1)
