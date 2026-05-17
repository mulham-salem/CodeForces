# Problem 116A – Tram

## Idea

We simulate the tram movement stop by stop.

At each stop:

1. Some passengers leave the tram.
2. Some passengers enter the tram.
3. Track the current number of passengers inside.
4. Keep the maximum value reached.

The maximum number of passengers at any moment is the minimum required tram capacity.

---

## Example

### Input
```text
4
0 3
2 5
4 2
4 0
```

### Simulation

| Stop | Leaving | Entering | Passengers Inside |
|------|----------|-----------|-------------------|
| 1 | 0 | 3 | 3 |
| 2 | 2 | 5 | 6 |
| 3 | 4 | 2 | 4 |
| 4 | 4 | 0 | 0 |

Maximum passengers inside the tram:

```text
6
```

So the answer is:

### Output
```text
6
```

---

## Algorithm

- Start with:
  - `currentPassengers = 0`
  - `maxCapacity = 0`

- For each stop:
  - Remove exiting passengers.
  - Add entering passengers.
  - Update the maximum capacity.

---

## Pseudocode

```text
read n

currentPassengers = 0
maxCapacity = 0

repeat n times:
    read a, b

    currentPassengers = currentPassengers - a
    currentPassengers = currentPassengers + b

    maxCapacity = max(maxCapacity, currentPassengers)

print maxCapacity
```

---

## Complexity

- Time Complexity: `O(n)`
- Space Complexity: `O(1)`

---