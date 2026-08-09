# Codeforces 234A - Lefthanders and Righthanders

## 🧠 Idea

We have `n` students, and `n` is even.

We divide the students into two halves:

- First half: students `1 ... n/2`
- Second half: students `n/2 + 1 ... n`

For every student `i` in the first half, we pair them with:

```
i + n/2
```

So the pairs are:
```
1 ↔ 1 + n/2
2 ↔ 2 + n/2
...

n/2 ↔ n
```

The difference between the two student numbers is always:
```
n/2
```

Since `n >= 4`, we have:
```
n/2 >= 2
```
Therefore, the two students can never have consecutive numbers.

---

## 👈👉 Avoiding Elbow Collisions

The only forbidden arrangement is:
```
R L
```
where a right-handed student sits on the left and a left-handed student sits on the right.

Therefore, after choosing the pair `(a, b)`:

If `a` is `R` and b is L, swap them.

Otherwise, keep them as they are.

This guarantees that every desk is either:
```
L L
L R
R R
```
and never:
```
R L
```
---

## 🔢 Zero-Based Indexing

In `C++`, the string indices start from `0`, while student numbers start from `1`.

For example:
```
index 0 → student 1
index 1 → student 2
index 2 → student 3
...
```

Therefore, when printing the answer, we use:
```
a + 1
b + 1
```

---

## 💻 Algorithm

1. Read `n` and the string `s`.


2. Calculate `half = n / 2`.


3. Loop from `i = 0` to `half - 1`.


4. Set:

`a = i`
`b = i + half`


5. If s[a] == 'R' and s[b] == 'L', swap `a` and `b`.


6. Print `a + 1` and `b + 1`.

---

## ⏱️ Complexity

**Time:** `O(n)`

**Space:** `O(1)`

---

## 🔍 Example

### Input
```
6
LLRLLL
```
Here:

`half = 3`

The initial pairs are:

`0 3 → students 1 4`
`1 4 → students 2 5`
`2 5 → students 3 6`

The last pair is:

`3 = R`
`6 = L`

So `R` `L` is forbidden, and we swap them:

`6 3`

### Output
```
1 4
2 5
6 3
```
This satisfies both conditions.

---