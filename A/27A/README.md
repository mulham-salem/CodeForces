# Problem 27A – Next Test

## 📌 Problem Summary

In the system **Polygon**, when adding a new test to a problem, the platform suggests a default index for the test.

The default index is defined as:

> The smallest positive integer that has not been used as an index before.

You are given the indices of previously added tests.  
Your task is to determine the default index for the next test.

---

## 🧾 Input

- An integer `n` (1 ≤ n ≤ 3000) — number of existing tests.
- A list of `n` distinct integers `a1, a2, ..., an` (1 ≤ ai ≤ 3000) — the used test indices.

---

## 📤 Output

- Print the smallest positive integer that does **not** appear in the given list.

---

## 💡 Key Idea

We need to find the **Smallest Missing Positive Integer**.

Since:
- `n ≤ 3000`
- `ai ≤ 3000`

We can simply:
1. Mark which numbers are already used.
2. Start checking from `1` upward.
3. The first number not marked is the answer.

---

## 🔎 Example 1

### Input
```

3
1 7 2

```

### Explanation

Used indices: `{1, 2, 7}`

Check from 1:
- 1 → used
- 2 → used
- 3 → not used ✅

### Output
```

3

```

---

## 🔎 Example 2

### Input
```

4
1 2 3 4

```

### Explanation

All numbers from `1` to `4` are used.

The smallest missing positive integer is:

```

5

```

---

## 🧠 Pseudocode

```
read n
create boolean array used[1..3001] initialized to false

for i from 1 to n:
read x
used[x] = true

for i from 1 to 3001:
if used[i] is false:
print i
stop

```

---

## ⏱ Complexity

- Time Complexity: **O(n)**
- Space Complexity: **O(n)**

---

## 🎯 Conclusion

The task is a direct implementation problem:  
Find the smallest positive integer that is not present in the given list.
