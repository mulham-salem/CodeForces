# Problem 241A – Old Peykan

## Problem Description

There are `n` cities located on a straight line:

`c1 → c2 → ... → cn`

There are `m = n - 1` one-way roads. Road `i` connects `ci` to `ci+1` and has length `di`.

The Old Peykan:

- Travels `1` kilometer in `1` hour.
- Consumes `1` liter of fuel per hour.
- Has an unlimited fuel tank.
- Cannot run out of fuel between two cities.

Each city `ci` except the last one has a fuel supply of `si` liters.

When the car reaches or stays in a city, it can receive `si` liters of fuel. After receiving fuel, the city's supply is restored after `k` hours.

The car can wait in a city and receive fuel multiple times.

Initially, the car starts at `c1` with `s1` liters of fuel.

The goal is to reach `cn` in the minimum possible time.

---

## Key Idea

The important observation is that the fuel tank has **unlimited capacity**.

Therefore, when we are at a city with a large fuel supply, we can conceptually take multiple refills there before continuing, instead of thinking about returning to that city later.

For every city we have passed, keep:

`maxFuel = maximum s[i] seen so far`

If the current fuel is not enough to cross the next road, we calculate how much fuel is missing:

`need = d[i] - fuel`

Since every additional refill takes exactly `k` hours, we should use the largest available refill size.

The number of required refills is:

`batches = ceil(need / maxFuel)`

Each refill adds `maxFuel` liters and costs `k` hours.

---

## Algorithm

1. Start with `s[0]` liters of fuel.
2. Keep track of the largest fuel supply encountered using `maxFuel`.
3. For every road:
   - Update `maxFuel`.
   - If the current fuel is insufficient:
     - Calculate the missing fuel.
     - Calculate the number of required refills.
     - Add the corresponding waiting time.
     - Add the obtained fuel.
   - Spend `d[i]` liters to cross the road.
   - Add `d[i]` hours to the total time.
   - Upon reaching the next city, immediately receive its fuel supply.

---

## Example

### Example 1

Input:

`4 6`

`1 2 5 2`

`2 3 3 4`

The roads are:

`c1 --1--> c2 --2--> c3 --5--> c4 --2--> c5`

The minimum required time is:

`10`

Output:

`10`

---

### Example 2

Input:

`2 3`

`5 6`

`5 5`

The car needs:

- `5` hours to reach `c2`.
- It needs `6` liters for the second road but has only `5`.
- It waits `3` hours to get another fuel refill.
- Then it needs `6` more hours to reach `c3`.

Total:

`5 + 3 + 6 = 14`

Output:

`14`

---

## Complexity

- **Time:** `O(m)`
- **Space:** `O(m)`

---