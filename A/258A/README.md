# Problem 258A – Little Elephant and Bits

## 🐘 Problem Summary
You are given a binary number `a` (without leading zeros).  
You must **delete exactly one binary digit** (either `0` or `1`) from it.

After deleting the digit:
- The remaining digits keep their original order
- The resulting number may contain leading zeros internally
- The final printed answer must be **without leading zeros**

Your goal is to obtain the **maximum possible value** after deleting exactly one digit.

---

## 🔍 Key Observation
In binary numbers:
- Digits on the **left** are more significant
- Removing a `1` usually decreases the value more than removing a `0`

So, to maximize the result:
- Prefer deleting a `0` instead of a `1`
- Especially if that `0` appears early enough to let more significant bits shift left

---

## 🧠 Strategy (Greedy Idea)

1. Traverse the binary string from left to right
2. After encountering the first `1`, look for the **first `0`**
3. Deleting this `0` produces the largest possible result
4. If the binary number consists of only `1`s:
   - Any deletion gives the same effect
   - Delete the **last digit**

This approach works in linear time `O(n)` and is optimal.

---

## ✏️ Pseudocode

```

read binary string s
flag = false

for i from 0 to length(s) - 2:
if s[i] == '1' and s[i+1] == '0':
delete character at position i+1
flag = true
break

if flag is false:
delete the last character of s

remove leading zeros from s
print s

```

---

## 📌 Examples

### Example 1
**Input**
```

101

```

**Explanation**
- Best choice is deleting the `0`
- Result: `11`

**Output**
```

11

```

---

### Example 2
**Input**
```

110010

```

**Explanation**
- Deleting the first suitable `0` after a `1` gives the maximum value

**Output**
```

11010

```

---

## ✅ Complexity
- **Time:** `O(n)`
- **Space:** `O(1)` (in-place modification)

---

## 🎯 Conclusion
By greedily removing the first `0` after the most significant `1`,  
we guarantee the maximum possible binary value after one deletion.