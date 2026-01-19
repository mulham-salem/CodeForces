# Problem 222A – Shooshuns and Sequence

## Problem Description

You are given a sequence of `n` integers. The shooshuns can perform the following operation:

1. Take the `k`-th element of the current sequence and append it to the end.
2. Remove the first element of the sequence.

Determine the **minimum number of operations** required to make all numbers in the sequence equal. If it is impossible, output `-1`.

### Input

- The first line contains two integers `n` and `k` (1 ≤ k ≤ n ≤ 10^5).
- The second line contains `n` integers `a1, a2, ..., an` (1 ≤ ai ≤ 10^5).

### Output

- Print the minimum number of operations to make all numbers equal, or `-1` if impossible.

---

## Example

**Input:**

```

3 2
3 1 1

```

**Output:**

```

1

```

**Explanation:**  

- Target number is the `k`-th element, `a[k-1] = 1`.  
- Check all elements after `k-1` → all equal to target ✅.  
- Count elements before `k-1` that are different → `[3]` → 1 operation required.  

---

**Input:**

```

3 1
3 1 1

```

**Output:**

```

-1

````

**Explanation:**  

- Target number is `a[0] = 3`.  
- There is `1` after `k-1` that differs → impossible to unify numbers.

---

## Approach / Pseudocode

1. Let `target = a[k-1]`.
2. Check all elements after `k-1`:
   - If any element ≠ `target`, output `-1` and exit.
3. Initialize `steps = 0`.
4. Traverse elements before `k-1` from right to left:
   - Find the **last element** that differs from `target`.
   - `steps = index of this element + 1`.
5. Output `steps`.

```pseudo
target = a[k-1]

# Check if solution is possible
for i = k to n-1:
    if a[i] != target:
        print -1
        exit

# Count minimum operations
steps = 0
for i = k-2 downto 0:
    if a[i] != target:
        steps = i + 1
        break

print steps
````

---

## Key Insight

* **Target number:** always the `k`-th element.
* **Impossible scenario:** any element after `k` differs from the target.
* **Minimum operations:** determined by the **last differing element before k**, because each operation effectively “shifts” the target forward.