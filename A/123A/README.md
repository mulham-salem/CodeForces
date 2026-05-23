# Problem 123A – Prime Permutation

## 🧠 Problem Idea

You are given a string `s` consisting of lowercase English letters.  
You are allowed to rearrange its characters.

The goal is to check whether it is possible to rearrange the string so that:

For every prime number `p ≤ n`, all positions that are multiples of `p` must contain the same character.

In other words, for each prime `p`:

s[p] = s[2p] = s[3p] = ...

---

## 📥 Input

- A single string `s`
- `1 ≤ |s| ≤ 1000`

---

## 📤 Output

- Print `"YES"` and one valid rearranged string if possible
- Otherwise print `"NO"`

---

## 🔍 Key Observation

Some positions in the string are *linked together* because they share prime divisors.

All positions that are affected by prime multiples form groups, and each group must contain identical characters.

So the problem reduces to:

> Assign characters to these groups while respecting frequency constraints.

---

## 🧪 Example 1

### Input

abc

### Output

YES abc

### Explanation

No conflicting constraints exist, so any permutation is valid.

---

## 🧪 Example 2

### Input

abcd

### Output

NO

### Explanation

For `p = 2`, positions 2 and 4 must be equal:

s2 = s4

But all letters are distinct, so it's impossible.

---

## 🧪 Example 3

### Input

xxxyxxx

### Output

YES xxxxxxy

### Explanation

Many positions are forced to be equal due to prime multiples.  
The most frequent character is assigned to all required positions.

---

## 💡 Approach (Pseudo Idea)

- Find all positions that must be equal using prime multiples
- Build groups of linked indices
- Count frequency of each character
- Assign the most frequent character to the largest group requirement
- Fill remaining positions arbitrarily with leftover characters

---

## 🧩 Complexity

- Prime checking + grouping: `O(n sqrt n)`
- Filling string: `O(n)`
- Total: efficient for `n ≤ 1000`

---