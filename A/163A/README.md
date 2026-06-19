# Problem 163A – Substring and Subsequence

## Problem Statement
You are given two strings `s` and `t` consisting of lowercase Latin letters.

You must count the number of pairs `(x, y)` such that:
- `x` is a **substring** of `s`
- `y` is a **subsequence** of `t`
- `x` and `y` are equal as strings
- Different positions in `s` or `t` mean different pairs even if the string content is the same

Return the answer modulo `1e9 + 7`.

---

## Key Idea
Instead of generating all substrings and subsequences (which is impossible), we use dynamic programming to count how many valid matches end at each position.

We process:
- all characters of `s`
- all characters of `t`

and build matches incrementally.

---

## DP Idea (Conceptual)
We maintain:

- `dp[i][j]` → number of ways to form matching strings where:
  - substring ends at `s[i]`
  - subsequence uses characters from `t[1..j]`

If `s[i] == t[j]`:
- We can start a new match: `"s[i]"`
- Or extend previous matches from `dp[i-1][j-1]`

So:

add = 1 + dp[i-1][j-1]

Then we accumulate results.

---

## Transitions (Pseudo Code)
```
for i in [1..n]: 
	for j in [1..m]:
		dp[i][j] = dp[i][j-1]   // ignore t[j]

			if s[i] == t[j]:
				add = 1 + dp[i-1][j-1]
				dp[i][j] += add
				ans += add
```
---

## Why it works
- `dp[i][j-1]` keeps all previous ways without using `t[j]`
- `dp[i-1][j-1]` allows extending previous matches safely
- `+1` accounts for starting a new match at `(i, j)`
- `ans` collects all valid pairs

---

## Complexity
- Time: `O(n * m)`
- Memory: `O(n * m)`

---

## Summary
We count every possible substring of `s` and match it as a subsequence in `t` using dynamic programming, while carefully tracking how new matches are formed and old ones are extended.

---