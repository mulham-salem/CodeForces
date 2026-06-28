# Problem 175A – Robot Bicorn Attack

## 📖 Problem Summary

You are given a string `s` formed by concatenating the scores of **three game rounds** without separators.

Your task is to split the string into **exactly three valid integers** such that:

- Each number has **no leading zeros** (except the number `0` itself).
- Each number is between `0` and `1,000,000` inclusive.
- The sum of the three numbers is **maximized**.

If no valid split exists, print `-1`.

---

## 💡 Idea

Since the string length is at most **30**, we can simply try every possible way to place **two split points**.

For every split:

1. Extract the three parts.
2. Check that each part is valid:
   - No leading zeros.
   - Value ≤ `1,000,000`.
3. Compute their sum.
4. Keep the maximum valid sum.

If no valid partition is found, the answer is `-1`.

---

## ✅ Pseudocode

```text
read string s
answer = -1

for first split position i
    for second split position j
        first  = s[0 ... i-1]
        second = s[i ... j-1]
        third  = s[j ... end]

        if all three numbers are valid
            sum = first + second + third
            answer = max(answer, sum)

print answer
```

---

## 📊 Example

### Input
```text
1234
```

Possible valid splits:

```text
1 | 2 | 34  -> 37
1 | 23 | 4  -> 28
12 | 3 | 4  -> 19
```

### Output
```text
37
```

---

## ⏱ Complexity

- **Time:** `O(n²)`
- **Space:** `O(1)`

Where `n ≤ 30`.

---