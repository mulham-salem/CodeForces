# Problem 382A – Ksenia and Pan Scales

## Problem Description

Ksenia has a pair of **pan scales** with two sides:
- **Left side**
- **Right side**

Initially, some weights are placed on both sides of the scale.  
Later, Ksenia finds additional weights and wants to place **all of them** onto the scales so that **both sides end up with the same number of weights**.

Your task is to determine:
- Whether it is possible to distribute the additional weights to balance the scales.
- If it is possible, output the final configuration.
- Otherwise, output `Impossible`.

---

## Input Format

- A single string representing the initial state of the scales.
  - Format:  
    ```
    left|right
    ```
- A second string representing the extra weights that must all be placed.

---

## Rules

1. The `|` character separates the left and right sides.
2. Each character (letter) represents one weight.
3. You must place **all extra weights**.
4. After placing them, the **number of weights on both sides must be equal**.
5. You cannot remove existing weights—only add new ones.

---

## Examples

### Example 1

**Input**
````

A|B
CD

```

**Analysis**

- Left side: `A` → 1 weight
- Right side: `B` → 1 weight
- Extra weights: `C`, `D` → 2 weights

Both sides are already equal.  
We can place:
- `C` on the left
- `D` on the right

Final configuration:
```

AC|BD

```

**Output**
```

AC|BD

```

---

### Example 2

**Input**
```

AB|C
D

```

**Analysis**

- Left side: `AB` → 2 weights
- Right side: `C` → 1 weight
- Extra weights: `D` → 1 weight

Place `D` on the right to balance both sides.

Final configuration:
```

AB|CD

```

**Output**
```

AB|CD

```

---

### Example 3

**Input**
```

A|BCD
EF

```

**Analysis**

- Left side: 1 weight
- Right side: 3 weights
- Extra weights: 2 weights

Even after adding both weights to the left:
- Left becomes 3
- Right is already 3

✔️ Balanced is possible.

---

### Example 4

**Input**
```

A|BC
D

```

**Analysis**

- Left side: 1
- Right side: 2
- Extra weights: 1

No matter where we place `D`, the sides cannot be equal.

**Output**
```

Impossible

```

---

## Step-by-Step Logic

1. Split the initial string using `|` into:
   - `left`
   - `right`
2. Count the number of characters on each side.
3. Add extra weights one by one to the side with fewer weights.
4. After all weights are placed:
   - If both sides have the same length → output the result.
   - Otherwise → output `Impossible`.

---

## Key Notes

- The order of extra weights does **not** matter.
- All extra weights must be used.
- Only the **count** of weights matters, not their values.
- This problem focuses on:
  - String manipulation
  - Careful condition checking
  - Simulation

This is a straightforward problem commonly used to practice string processing and logical reasoning.