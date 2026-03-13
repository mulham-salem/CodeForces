# Problem 39A – C*++ Calculations

## Overview
This problem introduces a simplified programming language called **C*++**, which behaves similarly to :contentReference[oaicite:0]{index=0} but with **undefined evaluation order** for expressions.

An expression consists of several **summands** separated by `+` or `-`.  
Each summand has one of the following forms:

- `a++`
- `++a`
- `k*a++`
- `k*++a`

Where `k` is an integer coefficient (`0 ≤ k ≤ 1000`). If the coefficient is omitted, it is assumed to be `1`.

The variable `a` starts with a given initial value.

Your task is to compute the **maximum possible value of the expression**, since the summands may be evaluated **in any order**.

---

## Key Observations

### Increment Behavior

There are two types of increments:

| Expression | Behavior |
|---|---|
| `a++` | Use current value of `a`, then increment `a` |
| `++a` | Increment `a` first, then use the new value |

Example:

```

a = 5

a++  → value = 5, then a = 6
++a  → a = 6, value = 6

```

---

### Important Property

Each summand **increments `a` exactly once** after evaluation.

If the expression contains `n` summands, the value of `a` during execution will become:

```

a, a+1, a+2, ..., a+n

```

Since the **evaluation order is arbitrary**, we can reorder the summands to maximize the final result.

---

## Greedy Strategy

Each summand contributes roughly:

```

coefficient × current_value_of_a

```

Since `a` **increases over time**, we want:

- **Small coefficients first**
- **Large coefficients later**

This ensures large multipliers benefit from larger values of `a`.

Thus, we can:

1. Parse the expression into individual summands.
2. Extract:
   - the coefficient
   - the increment type (`a++` or `++a`)
   - the sign (`+` or `-`)
3. Sort summands by their effective coefficient.
4. Simulate evaluation in that order.

---

## Example 1

Input

```

a = 1
5*a++ - 3*++a + a++

```

Possible order (best):

```

-3*++a
1*a++
5*a++

```

Evaluation:

```

a = 1

++a → a=2 → value = -6
a++ → value = 2 → a=3
a++ → value = 15 → a=4

```

Result:

```

-6 + 2 + 15 = 11

```

Output

```

11

```

---

## Example 2

Input

```

a = 3
a+++++a

```

Parsed as:

```

a++ + ++a

```

Evaluation:

```

a = 3

a++ → value = 3 → a=4
++a → a=5 → value = 5

```

Result:

```

3 + 5 = 8

```

Output

```

8

```

---

## Pseudocode

```
read a
read expression

terms = empty list

parse the expression:
determine sign (+ or -)
read coefficient (default = 1)
detect increment type (a++ or ++a)

store (coefficient * sign, increment_type) in terms

sort terms by coefficient in ascending order

result = 0

for each term in sorted order:
if increment_type is a++:
result += coefficient * a
a = a + 1
else:
a = a + 1
result += coefficient * a

print result

```

---

## Complexity

- Parsing the expression: **O(n)**
- Sorting the summands: **O(n log n)**
- Simulation: **O(n)**

Where `n` is the number of summands (≤ 1000).

---