# Problem 209A – Multicolored Marbles

## Idea

Since the colors always alternate, the answer depends only on `n`, not on whether the first marble is **Red** or **Blue**.

Use Dynamic Programming with two states:

- `a` = number of valid zebroid subsequences ending with **Red**.
- `b` = number of valid zebroid subsequences ending with **Blue**.

When processing a new marble:

- If it is **Red**:
  - Existing Red-ending subsequences remain.
  - Every Blue-ending subsequence can be extended by this Red.
  - The new Red alone forms a new subsequence.

  Therefore:

  ```text
  a = a + b + 1
  ```

- If it is **Blue**:

  ```text
  b = a + b + 1
  ```

At the end, every valid subsequence ends with either **Red** or **Blue**, so the answer is:

```text
answer = a + b
```

All operations are performed modulo `1e9 + 7`.

---

## Algorithm

1. Initialize:
   - `a = 0`
   - `b = 0`
2. Process the marbles in alternating color order.
3. Update either `a` or `b` using the transition above.
4. Print `a + b (mod MOD)`.

---

## Example

### Input

```text
3
```

Possible sequence:

```text
R B R
```

Valid zebroid subsequences:

```text
R
B
R
RB
BR
RBR
```

Answer:

```text
6
```

---

## Pseudocode

```text
a = 0
b = 0

for each marble
    if marble is Red
        a = (a + b + 1) mod MOD
    else
        b = (a + b + 1) mod MOD

print (a + b) mod MOD
```

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---