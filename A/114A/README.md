# Problem 114A - Cifera

## Explanation

We are given two numbers:

- `k` → the base number
- `l` → the target number

We need to check whether `l` can be represented as a power of `k`.

Example:

```text
l = k^n
```

If such a power exists:

- Print `"YES"`
- Print the importance of the number

The importance equals:

```text
n - 1
```

Because:

```text
k^1 -> importance = 0
k^2 -> importance = 1
k^3 -> importance = 2
```

---

## Observation

We repeatedly divide `l` by `k`.

If:

- `l` is always divisible by `k`
- and finally becomes `1`

then `l` is a power of `k`.

Otherwise, it is not.

---

## Example 1

### Input

```text
5
25
```

### Process

```text
25 / 5 = 5
5 / 5 = 1
```

So:

```text
25 = 5^2
```

Number of divisions = `2`

Importance:

```text
2 - 1 = 1
```

### Output

```text
YES
1
```

---

## Example 2

### Input

```text
3
8
```

Since `8` is not divisible by `3`, it cannot be represented as a power of `3`.

### Output

```text
NO
```

---

## Pseudocode

```text
read k
read l

cnt = 0

while l % k == 0
    l = l / k
    cnt++

if l == 1
    print "YES"
    print cnt - 1
else
    print "NO"
```

---

## Complexity

| Complexity | Value |
|---|---|
| Time Complexity | O(logₖ l) |
| Space Complexity | O(1) |

---