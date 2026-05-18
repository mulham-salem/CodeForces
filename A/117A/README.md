# Problem 117A – Elevator

## Idea

The elevator moves in a fixed repeating cycle:

```text
1 -> 2 -> 3 -> ... -> m -> m-1 -> ... -> 1
```

A full cycle length is:

```text
2 * (m - 1)
```

For each participant:

- `s` = starting floor
- `f` = destination floor
- `t` = starting time

We must find the earliest time the elevator reaches floor `s`
in the correct direction:

- upward if `s < f`
- downward if `s > f`

Then add the travel distance between floors.

---

## Key Observation

Each floor is visited:

- once while going up
- once while going down

So we calculate:

- the first valid arrival time of the elevator (`first`)
- how many full cycles are needed after time `t`

---

## Upward Movement

If:

```text
s < f
```

Then the participant needs the elevator while moving upward.

First upward visit to floor `s`:

```text
first = s - 1
```

### Example

```text
m = 5
s = 2
```

Elevator reaches floor `2` while going up at times:

```text
1, 9, 17, ...
```

---

## Downward Movement

If:

```text
s > f
```

Then the participant needs the elevator while moving downward.

First downward visit to floor `s`:

```text
first = (m - 1) + (m - s)
```

### Example

```text
m = 5
s = 4
```

Elevator reaches floor `4` while going down at times:

```text
5, 13, 21, ...
```

---

## Finding the Correct Elevator Time

If:

```text
t <= first
```

Then the participant can use that first arrival directly.

Otherwise:

- the first arrival was missed
- wait for the next cycle

Number of skipped cycles:

```text
k = ceil((t - first) / cycle)
```

Then:

```text
waitTime = first + k * cycle
```

---

## Final Answer

Arrival time:

```text
waitTime + abs(f - s)
```

---

## Pseudocode

```text
read n, m

cycle = 2 * (m - 1)

for each participant:

    read s, f, t

    if s == f:
        print t
        continue

    if s < f:

        first = s - 1

        if t <= first:
            waitTime = first
        else:
            k = ceil((t - first) / cycle)
            waitTime = first + k * cycle

        answer = waitTime + (f - s)

    else:

        first = (m - 1) + (m - s)

        if t <= first:
            waitTime = first
        else:
            k = ceil((t - first) / cycle)
            waitTime = first + k * cycle

        answer = waitTime + (s - f)

    print answer
```

---

## Complexity

```text
Time Complexity:  O(n)
Space Complexity: O(1)
```

---