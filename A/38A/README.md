# Problem 38A – Army

## Overview
The army in Berland has **n ranks**, numbered from **1 to n**, where:

- Rank **1** is the lowest
- Rank **n** is the highest

To move from rank **i** to rank **i + 1**, a soldier must serve **dᵢ years**.

A soldier cannot skip ranks.  
Therefore, to reach a higher rank, they must pass through **all intermediate ranks sequentially**.

Vasya has currently reached rank **a** and dreams of achieving rank **b**.  
Your task is to determine **how many additional years** he must serve to move from rank **a** to rank **b**.

---

## Key Idea
The array `d` represents the years required for each promotion:

| Promotion | Years Required |
|-----------|---------------|
| 1 → 2 | d₁ |
| 2 → 3 | d₂ |
| 3 → 4 | d₃ |
| ... | ... |

To reach rank **b** starting from **a**, Vasya must complete all promotions:

```

a → a+1
a+1 → a+2
...
b-1 → b

```

So the result is simply the **sum of the required years for those promotions**.

---

## Example 1

### Input
```

n = 3
d = [5, 6]
a = 1
b = 2

```

### Promotions
```

1 → 2 = 5 years

```

### Output
```

5

```

---

## Example 2

### Input
```

n = 3
d = [5, 6]
a = 1
b = 3

```

### Promotions
```

1 → 2 = 5 years
2 → 3 = 6 years

```

### Output
```

11

```

---

## Pseudocode

```
read n

create array d of size n-1
read values into d

read a, b

sum = 0

for i from (a - 1) to (b - 2)
sum += d[i]

print sum

```

---

## Complexity

**Time Complexity:**  
```

O(n)

```

**Space Complexity:**  
```

O(n)

```

Since we only iterate through part of the array once, the solution is very efficient.
