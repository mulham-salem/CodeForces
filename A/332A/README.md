# Problem 332A – Down the Hatch!

## Problem Summary

A group of `n` students sit in a circle and take turns (starting with person `0`). Each turn, the current player points at the next person using either an **elbow** (`'a'`) or a **nod** (`'b'`).

A player drinks a glass of juice on their turn if:
- It is at least the **4th turn** of the game (`j ≥ 4`), **and**
- The previous three turns (`j-1`, `j-2`, `j-3`) were all made with the **same move** as the current turn.

Vasya is player `0`, so he plays on turns `1, n+1, 2n+1, ...` (every `n`-th turn starting from index `0` in the string). The other players' moves are fixed, but Vasya can choose his own moves optimally to maximize how many glasses he drinks.

Given the string of moves (where Vasya's actual recorded moves are ignored/replaceable), determine the **maximum** number of glasses Vasya could drink.

---

## Key Observations

- Vasya only controls the characters at positions `0, n, 2n, ...` in the string.
- For a turn `i` (0-indexed) to give Vasya a drink, we need:
  - `i >= 3`
  - `s[i] == s[i-1] == s[i-2] == s[i-3]`
- Since Vasya can freely choose `s[i]` at his turns, he can always make it match the previous three characters **if those three are equal**.
- Therefore, for each of Vasya's turns (except the first one, since index must be ≥ 3), check whether the previous three moves (which are fixed, made by others) are all equal. If yes, Vasya drinks by choosing the same move.

---

## Examples

**Example 1:**
```

n = 4
s = "abbba"

```
Vasya's turns: indices `0` and `4` (turns 1 and 5).
- Index 4: previous three are `s[1]='b'`, `s[2]='b'`, `s[3]='b'` → all equal.
- Vasya can set `s[4]='b'` → drinks.
- Answer = **1**

---

**Example 2:**
```

n = 4
s = "abbab"

```
Vasya's turns: indices `0` and `4`.
- Index 4: previous three are `s[1]='b'`, `s[2]='b'`, `s[3]='a'` → not all equal.
- Vasya cannot drink.
- Answer = **0**

---

## Pseudocode
```

read n
read string s
answer = 0

for i from n to length(s)-1 step n:
	if s[i-1] == s[i-2] and s[i-2] == s[i-3]:
		answer = answer + 1

print answer

```

---

## Time Complexity
```

O(L / n)

```
Where `L` is the length of the string (number of turns). Since Vasya plays once every `n` turns, we only check `L / n` positions. Given `L ≤ 2000`, this is effectively **O(L)** at worst, and very fast.

## Space Complexity
```

O(L)

```
For storing the input string `s`.
