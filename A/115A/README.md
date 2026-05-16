# Problem 115A – Party

## Explanation

The company structure forms a hierarchy (tree).

Each employee has:
- Exactly one manager
- Or no manager (`-1`)

Two employees cannot be in the same group if one is a superior of the other.

So, the minimum number of groups equals:

> The maximum depth of the hierarchy.

In other words, we need to find the longest chain of managers.

---

## Example

### Input

```text
5
-1
1
2
1
-1
```

### Meaning

| Employee | Manager |
|----------|----------|
| 1 | -1 |
| 2 | 1 |
| 3 | 2 |
| 4 | 1 |
| 5 | -1 |

### Hierarchy

```text
1
├── 2
│   └── 3
└── 4

5
```

### Longest Chain

```text
3 → 2 → 1
```

Length = `3`

So the answer is:

```text
3
```

---

## Idea

For every employee:

1. Start from the employee.
2. Move upward through managers.
3. Count the depth.
4. Keep the maximum depth.

---

## Pseudocode

```text
read n

read manager array

answer = 0

for each employee:
    depth = 1
    current = employee

    while current has manager:
        depth++
        current = manager[current]

    answer = max(answer, depth)

print answer
```

---

## Complexity

- Time Complexity: `O(n²)`
- Memory Complexity: `O(n)`

---