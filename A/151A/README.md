# Problem 151A – Soft Drinking

## Requirement

You are given a group of `n` friends who want to make toasts using a soft drink.

To make **one toast**, each person needs:

- `nl` milliliters of drink
- **1 slice of lime**
- `np` grams of salt

You are given the available resources:

- `k` bottles of drink, each with `l` milliliters
- `c` limes, each cut into `d` slices
- `p` grams of salt

**Goal:**  
Find the **maximum number of toasts each person can make**, such that all friends make the same number of toasts.

---

## Input

- Eight integers:

  - `n` – number of friends
  - `k` – number of drink bottles
  - `l` – milliliters per bottle
  - `c` – number of limes
  - `d` – slices per lime
  - `p` – grams of salt
  - `nl` – milliliters of drink per toast
  - `np` – grams of salt per toast

---

## Output

- One integer: the **maximum number of toasts per person**

---

## Examples

### Example 1

**Input**

```

3 4 5 10 8 100 3 1

```

**Output**

```

2

```

**Explanation**

```

Total drink = 4 * 5 = 20 ml
Total lime slices = 10 * 8 = 80
Total salt = 100 g

Toasts limited by drink = 20 / (3 * 3) = 2
Toasts limited by limes = 80 / 3 = 26
Toasts limited by salt  = 100 / (3 * 1) = 33

Minimum = 2

```

---

## Solution Idea

1. Compute the total available resources:
   - `totalDrink = k * l`
   - `totalLimes = c * d`
   - `totalSalt = p`

2. Determine how many toasts each resource allows **per person**:
   - By drink: `totalDrink / (n * nl)`
   - By limes: `totalLimes / n`
   - By salt: `totalSalt / (n * np)`

3. The answer is the **minimum** of these three values, since the weakest resource limits the result.

---

## Formula

```

answer = min(
totalDrink / (n * nl),
totalLimes / n,
totalSalt / (n * np)
)

```

---

## Implementation Notes

- Integer division is sufficient because partial toasts are not allowed.
- In C++ (C++11 and later), `min({a, b, c})` can be used to get the minimum of multiple values.