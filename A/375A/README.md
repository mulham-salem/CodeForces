# Problem 375A – Divisible by Seven

## 📌 Problem Summary

You are given a large decimal number `a` (up to **10^6 digits**) that is guaranteed to contain at least one of each digit: **1, 6, 8, 9**. You must rearrange its digits so that the resulting number:

- Is divisible by **7**
- Has **no leading zeroes**
- Uses **all the digits** of the original number

If no valid arrangement exists, print `0`.

---

## 💡 Key Observation

The four digits **1, 6, 8, 9** can be permuted into **24 different 4-digit numbers**, and these 24 permutations cover **all possible remainders modulo 7**. 

This means:
> No matter what the rest of the number looks like, we can always pick one of the 24 permutations of `{1,6,8,9}` to fix the remainder.

So the strategy is:
1. Remove one occurrence of each of `1, 6, 8, 9` from the digit frequency.
2. Build the **prefix** from all remaining digits (sorted ascending, non-zero digits first).
3. Place all remaining **zeros** at the very end (after the 4-digit block) — this keeps the number valid and doesn't affect divisibility logic if we compute carefully.
4. Try all 24 permutations of `1689`, append them after the prefix, and check divisibility by 7.
5. Print the first valid one.

---

## 🧪 Examples

### Example 1
**Input:**
```

1689

```
**Output:**
```

1869

```
> Digits `1,6,8,9` permuted to `1869`, which is `7 × 267`. ✅

---

### Example 2
**Input:**
```

18906

```
**Output:**
```

18690

```
> Prefix from remaining digits: `0` → placed at end.  
> Permutation `1869` + `0` = `18690`, divisible by 7. ✅

---

### Example 3 (impossible case — hypothetical)
If the number somehow couldn't be fixed (which never happens here due to the 24-permutation trick), output would be:
```

0

```

---

## 🧾 Pseudocode

```

read string a
freq[10] = count of each digit in a

// reserve one of each: 1, 6, 8, 9
freq[1]--, freq[6]--, freq[8]--, freq[9]--

prefix = ""

for d from 1 to 9:
	append d repeated freq[d] times to prefix

remainder = value of prefix mod 7

for each permutation p of "1689":
	if (remainder * 10000 + int(p)) mod 7 == 0:
		print prefix + p + "0" * freq[0]
		exit

print 0

```

---

## ⏱ Complexity

- Building prefix: **O(n)**
- Trying 24 permutations: **O(24)**
- Total: **O(n)** — easily fits within limits for n ≤ 10^6.

---

## ✅ Notes

- Zeros are always placed **after** the 4-digit block, so they never create leading zeroes (since prefix or the 4-digit block starts with a nonzero digit).
- The trick relies on the fact that `{1,6,8,9}` permutations cover **all residues mod 7**, so a solution always exists.