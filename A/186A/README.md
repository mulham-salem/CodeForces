# Problem 186A – Comparing Strings

## 🧬 Problem Description

You are given two non-empty strings representing dwarven genomes.
Each genome consists of lowercase Latin letters.

Two dwarves belong to the same race **if and only if** it is possible to
transform the first genome into the second one **by swapping exactly one pair of characters** in the first string.

Your task is to determine whether the two given genomes belong to the same race.

---

## 📥 Input

- The first line contains string `s` — the first genome.
- The second line contains string `t` — the second genome.

### Constraints
- `1 ≤ |s|, |t| ≤ 10^5`
- Strings contain only lowercase Latin letters.
- It is guaranteed that `s` and `t` are **different**.
- The two strings may have different lengths.

---

## 📤 Output

- Print `"YES"` if the two genomes can be made equal using **one swap** in the first string.
- Otherwise, print `"NO"`.

---

## 🧠 Key Observations

- A swap does **not** change the length of a string.
- Only **one swap** is allowed.
- The order of characters matters — having the same characters is not enough.

---

## ✅ Valid Case

Two strings belong to the same race **only if**:
1. They have the **same length**
2. They differ in **exactly two positions**
3. Swapping those two characters in the first string makes both strings identical

---

## ❌ Invalid Cases

- Different lengths
- More than two differing positions
- Only one differing position
- Two differing positions that do not match after a swap

---

## 🧪 Examples

### Example 1
```

Input:
ab
ba

Output:
YES

```
**Explanation:** Swapping `a` and `b` in `"ab"` produces `"ba"`.

---

### Example 2
```

Input:
aa
ab

Output:
NO

```
**Explanation:** No swap can introduce the character `b`.

---

## 🧩 Pseudo Code

```

read string s, t

if length(s) != length(t):
print NO
exit

create empty list diff_indices

for i from 0 to length(s) - 1:
if s[i] != t[i]:
add i to diff_indices

if size of diff_indices != 2:
print NO
exit

let i = diff_indices[0]
let j = diff_indices[1]

if s[i] == t[j] and s[j] == t[i]:
print YES
else:
print NO

```

---

## ⏱ Time Complexity
- **O(n)** — single pass comparison

## 💾 Space Complexity
- **O(1)** — only two indices are stored

---