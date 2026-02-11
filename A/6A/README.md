# Problem 6A – Triangle

## 📝 Problem Summary

You are given four positive integers representing the lengths of four sticks.  
You must choose **exactly three sticks** and determine:

- If they can form a **non-degenerate triangle** → print `TRIANGLE`
- If they can form a **degenerate triangle (segment)** → print `SEGMENT`
- If neither is possible → print `IMPOSSIBLE`

You are not allowed to break sticks or use partial lengths.

---

## 🔺 Triangle Rules

For three lengths `x ≤ y ≤ z`:

- If `x + y > z` → **Non-degenerate triangle**
- If `x + y = z` → **Degenerate triangle (segment)**
- If `x + y < z` → **Impossible**

---

## 💡 Approach

1. Read the four stick lengths.
2. Sort them in ascending order.
3. Check all possible combinations of three sticks:
   - (a, b, c)
   - (a, b, d)
   - (a, c, d)
   - (b, c, d)
4. Apply triangle conditions.
5. Print result according to priority:

Priority order:
1. `TRIANGLE`
2. `SEGMENT`
3. `IMPOSSIBLE`

If at least one valid triangle exists, print `TRIANGLE` immediately.

---

## 📌 Examples

### Example 1

Input:
```

4 2 1 3

```

Sorted:
```

1 2 3 4

```

Check (2,3,4):

```

2 + 3 > 4

```

Output:
```

TRIANGLE

```

---

### Example 2

Input:
```

7 2 2 4

```

Sorted:
```

2 2 4 7

```

Check (2,2,4):

```

2 + 2 = 4

```

Output:
```

SEGMENT

```

---

### Example 3

Input:
```

3 5 9 1

```

Sorted:
```

1 3 5 9

```

All combinations satisfy:

```

x + y < z

```

Output:
```

IMPOSSIBLE

```

---

## 🧠 Pseudocode

```

read a, b, c, d

put them in array
sort array in ascending order

assign:
a = arr[0]
b = arr[1]
c = arr[2]
d = arr[3]

if (a + b > c) OR (a + c > d) OR (b + c > d)
print "TRIANGLE"

else if (a + b == c) OR (a + c == d) OR (b + c == d)
print "SEGMENT"

else
print "IMPOSSIBLE"

```

---

## ⏱ Complexity

- Sorting: `O(1)` (fixed size 4)
- Checks: constant time

Overall complexity: **O(1)**

---

✅ Simple implementation, constant time solution.