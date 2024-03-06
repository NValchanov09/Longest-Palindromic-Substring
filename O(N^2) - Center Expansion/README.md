# O(N^2) - Center Expansion

1. Idea
This solution is less intuitive than the DP solution but it is closer to the full solution - O(N).

The idea is simple. We fix an index as the "center" (middle element) of the palindrome. 
Then we expand by moving the left boundary to the left and the right boundary to the right.
We do this until the substring is a palindrome. 
>[!NOTE]
> Proof : We use the same observation as in the DP solution - [left, right] is a palindrome if and only if [left + 1, right - 1] is a palindrome and s[left] is equal to s[right].

We try all possible "centers" for our LPS. This sounds good right...

The problem with this solution is that we check only the palindromes with odd lengths (1 "center" and the left and the right sides are equal).
To solve the problem with the even lengths we can reduce the problem to the case where we only deal with palindromes with odd lengths.
We can do this by adding the same additional character between each character in the string.

2. Implementation
Firstly we add the additional characters between each character in the string. (In my implementation I use '#' as my additional character)

 **Example:**
 "abracadabra" -> "#a#b#r#a#c#a#d#a#b#r#a#"

 We try all different "centers" and calculate the LPS with this "center".

 **Time complexity:**
 O(N) possible "centers", O(N) for each center expansion

 **Total Time complexity:**
 O(N^2)

 **Space complexity:**
 We could use only the left and right boundaries when checking for the current "center" -> O(1) space.

 **Total Space complexity:**
 O(1)

 
