# Problem 167A – Wizards and Trolleybuses

## Overview

A city has `n` trolleybuses traveling from a depot to a final station located `d` meters away.

For each trolleybus:

- It starts at time `tᵢ`.
- Its maximum speed is `vᵢ`.
- It can accelerate at most `a` meters per second squared.
- It starts from rest.

A trolleybus may decelerate instantly, but it **cannot overtake** another trolleybus that started earlier. If it catches up with one, both continue together until reaching the destination.

The goal is to determine the earliest possible arrival time for every trolleybus.

---

## Key Observations

### 1. Free Travel Time

Ignoring other trolleybuses, each trolleybus tries to reach the destination as fast as possible.

There are two cases:

- The trolleybus reaches its maximum speed before the destination.
- The trolleybus never reaches its maximum speed and accelerates for the entire trip.

### 2. No Overtaking Rule

A trolleybus cannot arrive earlier than any trolleybus before it.

Therefore:

```text
arrival[i] ≥ arrival[i - 1]
```

If a trolleybus would arrive earlier, it must slow down and arrive at the same time as the previous one.

---

## Example 1

### Input

```text
3 10 10000
0 10
5 11
1000 1
```

### Explanation

- The first trolleybus reaches the station at `1000.5`.
- The second trolleybus is faster, but catches the first one and cannot pass it.
- Therefore, both arrive at the same moment.
- The third trolleybus is very slow and arrives much later.

### Output

```text
1000.5000000000
1000.5000000000
11000.0500000000
```

---

## Example 2

### Input

```text
1 2 26
28 29
```

### Output

```text
33.0990195136
```

Since there is only one trolleybus, the overtaking restriction never affects the answer.

---

## Algorithm

1. Compute the minimum travel time of each trolleybus assuming the road is empty.
2. Add its departure time to obtain its theoretical arrival time.
3. Since overtaking is forbidden, the actual arrival time cannot be smaller than the arrival time of the previous trolleybus.
4. Print the resulting arrival times.

---

## Pseudocode

```text
read n, a, d

lastArrival = 0

for each trolleybus:
    read t, v

    compute distance needed to reach maximum speed

    if destination is reached before maximum speed:
        travelTime = accelerating time only
    else:
        travelTime = acceleration time
                   + constant-speed travel time

    arrival = t + travelTime

    arrival = max(arrival, lastArrival)

    print arrival

    lastArrival = arrival
```

---

## Complexity Analysis

| Complexity | Value |
|------------|--------|
| Time | O(n) |
| Memory | O(1) |

---