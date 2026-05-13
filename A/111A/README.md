# Problem 111A – Petya and Inequiations

## 📌 Problem Summary

We need to find `n` positive integers such that:

- The sum of their squares is at least `x`
- The normal sum of the numbers is at most `y`

Formally:

a_1^2 + a_2^2 + .... + a_n^2  >=  x

a_1 + a_2 + .... + an  <=  y


If no valid solution exists, print `-1`.

---

## 💡 Idea

To keep the total sum as small as possible:

- Make `n-1` numbers equal to `1`
- Use one larger number `k`

So the numbers become:

```text
k, 1, 1, 1, ...
```

The `1`s already contribute:

n-1

to the sum of squares.

So we only need:

k^2 >= x - (n-1)

Then we check whether:

k + (n-1) <= y


If not, the answer is impossible.

---

## 🧠 Pseudocode

```text
read n, x, y

need = x - (n - 1)

k = smallest integer such that:
    k² >= need

if k + (n - 1) > y
    print -1
else
    print k
    print 1 exactly (n - 1) times
```

---

## ✅ Example 1

### Input

```text
5 15 15
```

### Output

```text
4
1
1
1
1
```

### Explanation

Sum of squares:

4^2 + 1 + 1 + 1 + 1 = 20


Normal sum:

4 + 1 + 1 + 1 + 1 = 8


Both conditions are satisfied.

---

## ❌ Example 2

### Input

```text
2 3 2
```

### Output

```text
-1
```

### Explanation

The only possible positive numbers are:

```text
1 1
```

But:

1^2 + 1^2 = 2

which is less than `3`.

---

## ⏱ Complexity

- Time Complexity: `O(n)`
- Space Complexity: `O(1)`

---