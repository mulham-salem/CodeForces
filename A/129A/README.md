# Problem 129A – Cookies

## Idea

Olga wants to steal exactly one bag of cookies such that the remaining total number of cookies is even.

### Observation

- Even − Even = Even
- Odd − Odd = Even

So:

- If the total sum is even, we must remove an even bag.
- If the total sum is odd, we must remove an odd bag.

The answer is simply the number of bags having the same parity as the total sum.

---

## Example 1

### Input
```text
1
1
```

### Explanation

The total number of cookies is `1` which is odd.

If Olga removes the only bag:

```text
1 - 1 = 0
```

`0` is even, so the answer is:

### Output
```text
1
```

---

## Example 2

### Input
```text
10
1 2 2 3 4 4 4 2 2 2
```

### Explanation

The total sum is:

```text
26
```

Since the sum is even, Olga must remove an even bag.

Even bags are:

```text
2 2 4 4 4 2 2 2
```

There are `8` valid choices.

### Output
```text
8
```

---

## Pseudocode

```text
read n

sum = 0
odd = 0
even = 0

for each bag:
    read x
    sum += x

    if x is even:
        even++
    else:
        odd++

if sum is even:
    print even
else:
    print odd
```

---

## Complexity

- Time Complexity: `O(n)`
- Space Complexity: `O(1)`

---