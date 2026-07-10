# Problem 187A – Permutations

## Idea

We are given two permutations of numbers `1` to `n`.

In one move, we can only remove the **last element** of the current permutation and insert it anywhere.

Instead of simulating these operations, observe that the **relative order of all elements except the moved one never changes**.

To compare both permutations easily:

1. Store the position of every value in the target permutation.
2. Replace each element of the first permutation with its position in the target permutation.
3. Scan this sequence from left to right.
4. As long as the positions are strictly increasing, the order is still valid.
5. The first decrease means the remaining suffix must be moved.
6. The answer is the size of that suffix.

---

## Example

### Input

```text
A = [1, 5, 2, 3, 4]
B = [1, 2, 3, 4, 5]
```

Positions in `B`:

```text
1 → 1
2 → 2
3 → 3
4 → 4
5 → 5
```

Transform `A` into position values:

```text
[1, 5, 2, 3, 4]
```

The sequence stops being increasing at:

```text
1 5 2 3 4
  ↑
```

So the last **3** elements must be moved.

Output:

```text
3
```

---

## Algorithm (Pseudo Code)

```text
Read n
Read permutation A
Read permutation B

Store the position of each value in B

For each adjacent pair in A:
    If position(A[i]) > position(A[i+1]):
        Output n - i
        Stop

Output 0
```

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`
```

---