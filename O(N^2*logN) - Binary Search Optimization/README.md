# O(N^2*logN) - Binary Search Optimization

## 1. Idea
>[!NOTE]
>This idea isn't very simple and most of the people get to the O(N^2) solution first.



We binary search the length of the LPS. The tricky part in this solution is that we can't check for each length because palindromes with different parity of their sizes have different transitions.
For example if the S = "abracadabra", a palindrome with length 3 exists ("aca"), but a palindrome with length 2 doesn't exist.
To solve this issue we will use 2 binary searches - one for each parity of the length.

## 2. Implementation
For this solution we could use 2 different binary search functions or just use 1 and for each change the values of the boundaries coresponding to the current parity.
We use a normal binary search algorithm. For the current value of the middle we check if there exists a palindrome substring with this length.
The check function could return an index to the start of the substring or -1 if there doesn't exist.

**Time complexity:**
O(logN) possible lengths and O(N^2) check if a palindrome with this length exists.

**Total Time complexity:**
O(N^2*logN) 

**Space complexity:**
This solution could be implemented without using auxiliary space.

**Total Space complexity:**
O(1)
