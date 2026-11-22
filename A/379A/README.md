# Problem 379A – New Year Candles

## Problem Summary

Vasily has `a` new candles. Each candle burns for **1 hour** and then becomes a **burned-out candle**. He can combine `b` burned-out candles into **1 new candle**, which can then be burned again for another hour.

The question: **What is the maximum total number of hours** the room can be lit, assuming optimal usage?

---

## Approach

- Start with `a` new candles → these give `a` hours immediately.
- Keep a counter of burned-out candles `c`.
- While `c >= b`:
  - Take `b` burned-out candles and turn them into 1 new candle.
  - Burn that new candle → +1 hour.
  - After burning, it becomes a burned-out candle again → add it back to `c`.
- Repeat until fewer than `b` burned-out candles remain.

---

## Examples

### Example 1
**Input:**
```

4 2

```

Trace:
- Start: 4 candles → 4 hours, `c = 4`
- `c = 4 ≥ 2` → make 1 candle → burn → hours = 5, `c = 3`
- `c = 3 ≥ 2` → make 1 candle → burn → hours = 6, `c = 2`
- `c = 2 ≥ 2` → make 1 candle → burn → hours = 7, `c = 1`
- `c = 1 < 2` → stop

**Output:** `7`

---

### Example 2
**Input:**
```

6 3

```

Trace:
- Start: 6 candles → 6 hours, `c = 6`
- `c = 6 ≥ 3` → make 1 candle → burn → hours = 7, `c = 4`
- `c = 4 ≥ 3` → make 1 candle → burn → hours = 8, `c = 2`
- `c = 2 < 3` → stop

**Output:** `8`

---

## Pseudocode

```

read a, b
hours = a
c = a

while c >= b:
	c = c - b         // consume b burned-out candles
	hours = hours + 1 // light the new candle for 1 hour
	c = c + 1         // the new candle becomes burned-out

print hours

```

---

## Complexity

- **Time:** O(a) in the worst case (each loop reduces `c` by `b-1 ≥ 1`)
- **Space:** O(1)

---

## Notes

- This is essentially the classic **"candles problem"** — similar to the "bottle exchange" puzzle.
- The answer can also be computed directly with the formula:


  $$
  \text{hours} = a + \left\lfloor \frac{a-1}{b-1} \right\rfloor
  $$

  (valid for `b ≥ 2`), but the simulation is simpler and clearer.
