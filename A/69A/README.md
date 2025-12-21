# Problem 69A – Young Physicist

## Problem Description
A physicist is analyzing forces acting on an object in 3D space.

You are given:
- An integer `n` — the number of force vectors.
- `n` lines follow, each containing three integers `x`, `y`, `z` representing a force vector.

Your task is to determine whether the object is in **equilibrium**.

---

## Equilibrium Condition
The object is in equilibrium **if and only if**:
- The sum of all `x` components is `0`
- The sum of all `y` components is `0`
- The sum of all `z` components is `0`

---

## How the Solution Works
1. Read the number of vectors `n`.
2. Initialize three variables to store the sums of `x`, `y`, and `z`.
3. For each vector:
   - Add its `x` value to the total `x` sum.
   - Add its `y` value to the total `y` sum.
   - Add its `z` value to the total `z` sum.
4. After processing all vectors:
   - If all three sums are zero, print `YES`.
   - Otherwise, print `NO`.

---

## Example

### Input
```

3
4 1 7
-2 4 -1
-2 -5 -6

```

### Calculation
- Sum of x-components: `4 + (-2) + (-2) = 0`
- Sum of y-components: `1 + 4 + (-5) = 0`
- Sum of z-components: `7 + (-1) + (-6) = 0`

### Output
```

YES

```

---

## Another Example

### Input
```

2
1 2 3
-1 1 -2

```

### Calculation
- x-sum = `0`
- y-sum = `3`
- z-sum = `1`

### Output
```

NO

```

---

## Key Notes
- The order of vectors does not matter.
- If any component sum is not zero, the system is not in equilibrium.
- This problem tests basic loops and integer accumulation.

This is a simple and classic problem for practicing array traversal and conditional logic.
