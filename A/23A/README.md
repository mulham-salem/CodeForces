# Problem 23A – You're Given a String

## 📝 Problem Summary

You are given a non-empty string consisting of lowercase Latin letters (length ≤ 100).

Your task is to determine the **length of the longest substring that appears at least twice** in the string.

⚠️ The two occurrences **may overlap**.

If no substring appears more than once, output `0`.

---

## 🔎 Key Observations

- A **substring** is a continuous sequence of characters.
- We are looking for the **maximum length** substring that occurs at least twice.
- Since the maximum length of the string is 100, a brute-force solution is acceptable.

---

## 📌 Examples

### Example 1

**Input**
```

abcd

```

**Explanation**

All substrings:
- `a`, `b`, `c`, `d`
- `ab`, `bc`, `cd`
- `abc`, `bcd`
- `abcd`

None of them appears twice.

**Output**
```

0

```

---

### Example 2

**Input**
```

ababa

```

**Explanation**

Repeated substrings:
- `a`
- `ab`
- `ba`
- `aba`

The longest repeated substring is:

```

aba

```

It appears twice (overlapping is allowed):

```

ababa
^^^
^^^

```

**Output**
```

3

```

---

### Example 3

**Input**
```

zzz

```

**Explanation**

Repeated substrings:
- `z`
- `zz`

The longest one is:

```

zz

```

**Output**
```

2

```

---

## 💡 Approach

Instead of generating all substrings explicitly and counting occurrences,
we can compare every pair of starting positions in the string.

For each pair `(i, j)` where `j > i`:

- Compare characters one by one
- Count how many consecutive characters match
- Track the maximum matching length found

This works because any repeated substring must start at two different positions.

---

## 🧠 Pseudocode

```
read string s
n = length of s
maxLength = 0

for i from 0 to n-1:
	for j from i+1 to n-1:
	length = 0

		while i + length < n AND
			  j + length < n AND
			  s[i + length] == s[j + length]:
			  
			length = length + 1
			maxLength = max(maxLength, length)

print maxLength

```

---

## ⏱ Complexity

- Time Complexity: O(n³) in the worst case  
- Space Complexity: O(1)

Since `n ≤ 100`, this solution runs efficiently within limits.
