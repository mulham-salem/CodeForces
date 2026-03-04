# Problem 29A – Spit Problem

## 📌 Problem Summary

In a zoo, each camel stands at a unique position `x` on a number line.  
Every camel spits exactly once, and the spit travels a distance `d`.

- If `d > 0`, the camel spits to the right.
- If `d < 0`, the camel spits to the left.
- A camel at position `x` hits only the camel at position `x + d` (if one exists).

Your task is to determine whether **there exists a pair of camels that spit at each other**.

---

## 🎯 Goal

Return:

- `YES` → if there are two camels that hit each other.
- `NO` → otherwise.

---

## 🧠 Key Observation

For two camels `A` and `B`:

They spit at each other **if and only if**:

```

xA + dA = xB
xB + dB = xA

```

Both conditions must be true at the same time.

---

## 📥 Example 1

### Input
```

2
0 1
1 -1

```

### Explanation

- Camel at `0` spits to `1`
- Camel at `1` spits to `0`

They hit each other → `YES`

---

## 📥 Example 2

### Input
```

3
0 1
1 1
2 -2

```

### Explanation

- Camel 0 hits Camel 1
- Camel 1 hits position 2
- Camel 2 hits position 0

No mutual pair → `NO`

---

## ⚙️ Approach

Since `n ≤ 100`, we can safely check all pairs of camels using a double loop.

For every pair `(i, j)`:

1. Compute where camel `i` spits.
2. Compute where camel `j` spits.
3. Check if they hit each other.

Time Complexity:

```

O(n²)

```

Which is efficient for the given constraints.

---

## 🧾 Pseudocode

```

read n
read all camels into array

for i from 0 to n-1:
for j from i+1 to n-1:
if (xi + di == xj) AND (xj + dj == xi):
print YES
stop program

print NO

```

---

## 💡 Why This Works

Each camel can hit only one exact position (`x + d`).  
We simply verify whether two camels form a two-way connection.

No sorting or advanced data structures are required.
Brute force is sufficient due to small constraints.

---

## 🔚 Conclusion

The problem reduces to checking whether a bidirectional hit exists between any pair of camels.  
A straightforward double-loop solution efficiently solves it.