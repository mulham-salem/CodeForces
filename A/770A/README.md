# Problem 770A – New Password

## Problem Summary
Polycarp wants to choose a new password.

Rules for a valid password:
- It must be a string of lowercase Latin letters.
- Each password must **not contain any character more than once**.
- He wants to choose the **lexicographically smallest** password
  which is **strictly greater** than his old password.

Your task:

Given the old password, find the next valid password following these rules.
If no such password exists, print "NO".

---

## Key Idea
- The password can have a length **up to 26** (letters a-z).
- If the password length < 26:
  - Append the smallest unused character to make a new password.
- If the password length = 26:
  - Try to modify the last character to get the next lexicographical order
  - Ensure uniqueness of letters
  - If impossible, print "NO"

---

## Example 1

Input
ab

Explanation
Length < 26, letters a and b used.
Next smallest unused letter is 'c'.
New password = "ac"

Output
ac

---

## Example 2

Input
zyxwvutsrqponmlkjihgfedcba

Explanation
All 26 letters are used, already the largest possible.
No valid next password exists.

Output
NO

---

## Example 3

Input
abc

Explanation
Length < 26, letters a, b, c used.
Next smallest unused letter is 'd'.
New password = "abd"

Output
abd

---

## Pseudocode
read old_password
if length(old_password) < 26:
    find smallest letter not in old_password
    append it to old_password
    print new password
else:
    for i from last index down to 0:
        find smallest character > old_password[i] not used before
        if found:
            replace old_password[i] with it
            truncate rest
            print new password
            return
    print NO

---

## Final Notes
- Use a set to track used characters.
- Lexicographical ordering is important.
- Time complexity: O(26) = O(1)
- Works for all valid inputs efficiently.
