# Problem 579A – Raising Bacteria

## Requirement
You are given:

- One integer `n` — the final number of bacteria.

Initially, there are **0 bacteria**.

You can perform two types of operations:
1. **Add 1 bacterium**.
2. **Double** the current number of bacteria.

Your task is to determine the **minimum number of times** you need to use the **add 1** operation to reach exactly `n` bacteria.

---

## Input
```

n

```

---

## Output
One integer — the minimum number of `+1` operations needed.

---

## Explanation
Doubling bacteria does **not cost anything**.
Only the `+1` operation is counted.

So the goal is to reach `n` using:
- free doubling
- minimum additions of `1`

---

## Key Observation
Any number `n` can be represented in **binary**.

Each `1` in the binary representation of `n` corresponds to **one required `+1` operation**.

➡️ Therefore:
```

Answer = number of set bits (1s) in binary representation of n

```

---

## Example 1

### Input
```

5

```

### Binary Representation
```

5 = 101₂

```

### Output
```

2

```

Explanation:
There are **two 1s** → need 2 add operations.

---

## Example 2

### Input
```

8

```

### Binary Representation
```

8 = 1000₂

```

### Output
```

1

```

Only one `+1` is needed, then keep doubling.

---

## Solution Idea
1. Read integer `n`.
2. Convert `n` to binary (or process bits directly).
3. Count how many times the last bit is `1`.
4. Output the count.

---

## Simple Implementation Logic
While `n > 0`:
- If `n` is odd → count++
- Divide `n` by 2

---

## Complexity
- **Time Complexity:** O(log n)
- **Space Complexity:** O(1)

---

## Key Insight
Doubling corresponds to shifting left in binary.
Only bits set to `1` require an actual `+1` operation.
So the problem reduces to **counting set bits**.
