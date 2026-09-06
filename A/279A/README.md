# Problem 279A – Point on Spiral

## Problem Description

Valera the horse stands at the origin `(0, 0)` of an infinite spiral drawn on the Cartesian plane. This spiral passes through every integer coordinate point and is constructed as follows:

- `[(0,0), (1,0)]` — first segment
- `[(1,0), (1,1)]` — second segment
- `[(1,1), (-1,1)]` — third segment
- `[(-1,1), (-1,-1)]` — fourth segment
- `[(-1,-1), (2,-1)]` — fifth segment
- `[(2,-1), (2,2)]` — sixth segment
- And so on...

Valera wants to walk along this spiral from `(0,0)` to a given point `(x, y)`. Since turning is difficult for him (he has four legs!), we need to count **how many times he has to turn** during his journey.

---

## Understanding the Spiral Pattern

The spiral follows a clear pattern:

| Segment # | Direction | Length | Path |
|-----------|-----------|--------|------|
| 1 | Right | 1 | `(0,0) → (1,0)` |
| 2 | Up | 1 | `(1,0) → (1,1)` |
| 3 | Left | 2 | `(1,1) → (-1,1)` |
| 4 | Down | 2 | `(-1,1) → (-1,-1)` |
| 5 | Right | 3 | `(-1,-1) → (2,-1)` |
| 6 | Up | 3 | `(2,-1) → (2,2)` |
| 7 | Left | 4 | `(2,2) → (-2,2)` |
| 8 | Down | 4 | `(-2,2) → (-2,-2)` |
| ... | ... | ... | ... |

**Key observations:**
- The length repeats: `1, 1, 2, 2, 3, 3, 4, 4, ...`
- Direction cycles: **Right → Up → Left → Down → Right → ...**
- Each new segment (except the first one) requires **exactly 1 turn**
- A turn happens **between segments**, not during a segment

---

## Solution Approach

### Intuition

Instead of trying to find a mathematical formula, we can **simulate** Valera's walk step by step. Since `|x|, |y| ≤ 100`, the spiral reaches these coordinates quickly (within a few hundred steps), making simulation both simple and efficient.

### Simulation Logic

1. Start at position `(0, 0)` with `turns = 0`
2. Use a variable `length = 1` for the current segment length
3. The direction cycles: `0=Right, 1=Up, 2=Left, 3=Down`
4. For each segment:
   - If it's **not** the first segment, increment `turns` (we had to turn to start this segment)
   - Walk `length` steps in the current direction
   - After each step, check if we've reached the target `(x, y)`
   - If yes, print `turns` and exit
5. After completing a segment, change direction (cycle to next)
6. Every **two segments**, increase `length` by 1
7. Continue until we find the target point

---

## Pseudocode

```

READ x, y

IF x == 0 AND y == 0 THEN
    PRINT 0
    EXIT

currentX = 0
currentY = 0
direction = 0        // 0=Right, 1=Up, 2=Left, 3=Down
turns = 0
length = 1
isFirstSegment = true

WHILE true DO

    FOR repeat = 0 TO 1 DO     // Each length used twice

        IF NOT isFirstSegment THEN
            turns = turns + 1
        END IF

        isFirstSegment = false

        FOR step = 0 TO length - 1 DO

            IF direction == 0 THEN currentX = currentX + 1
            ELSE IF direction == 1 THEN currentY = currentY + 1
            ELSE IF direction == 2 THEN currentX = currentX - 1
            ELSE currentY = currentY - 1

            IF currentX == x AND currentY == y THEN
                PRINT turns
                EXIT
            END IF

        END FOR

        direction = (direction + 1) MOD 4

    END FOR

    length = length + 1

END WHILE

```

---

## Step-by-Step Examples

### Example 1: Input `(0, 0)`

| Step | Action | Position | Turns |
|------|--------|----------|-------|
| Start | Begin | `(0, 0)` | `0` |

We are already at the target!  
**Output:** `0`

---

### Example 2: Input `(1, 0)`

| Step | Action | Position | Turns |
|------|--------|----------|-------|
| Start | Begin | `(0, 0)` | `0` |
| Segment 1 (Right, len=1) | Step 1 | `(1, 0)` ✓ | `0` |

Target reached during the first segment.  
**Output:** `0`

---

### Example 3: Input `(0, 1)`

| Step | Action | Position | Turns |
|------|--------|----------|-------|
| Start | Begin | `(0, 0)` | `0` |
| Seg 1: Right (len=1) | Step 1 | `(1, 0)` | `0` |
| | **Turn** | | `1` |
| Seg 2: Up (len=1) | Step 1 | `(1, 1)` | `1` |
| | **Turn** | | `2` |
| Seg 3: Left (len=2) | Step 1 | `(0, 1)` ✓ | `2` |

We turn twice: once at `(1,0)` and once at `(1,1)`.  
**Output:** `2`

---

### Example 4: Input `(-1, -1)`

| Step | Action | Position | Turns |
|------|--------|----------|-------|
| Start | Begin | `(0, 0)` | `0` |
| Seg 1: Right (len=1) | Step 1 | `(1, 0)` | `0` |
| | **Turn** | | `1` |
| Seg 2: Up (len=1) | Step 1 | `(1, 1)` | `1` |
| | **Turn** | | `2` |
| Seg 3: Left (len=2) | Step 1 | `(0, 1)` | `2` |
| | Step 2 | `(-1, 1)` | `2` |
| | **Turn** | | `3` |
| Seg 4: Down (len=2) | Step 1 | `(-1, 0)` | `3` |
| | Step 2 | `(-1, -1)` ✓ | `3` |

We turn 3 times.  
**Output:** `3`

---

## Complexity Analysis

| Metric | Value |
|--------|-------|
| Time Complexity | `O(max(x, y)²)` — the spiral reaches coordinate `n` in about `4n` segments and `2n²` steps |
| Space Complexity | `O(1)` — only a few integer variables are used |
| Constraints | `x, y ≤ 100` — so simulation runs instantly |

---

## Why Simulation Works

The spiral is infinite but grows predictably. With coordinates bounded by `100`, the worst-case point `(100, 100)` is reached after only a few hundred steps. This makes simulation the simplest and most intuitive solution, avoiding complex mathematical formulas and edge-case handling.

---

## Key Takeaways

- The spiral grows with lengths repeating twice: `1, 1, 2, 2, 3, 3, ...`
- A turn occurs **between segments**, not during them
- The first segment requires **no turn** to start
- Simulation is viable due to small coordinate bounds
- Direction cycles: **Right → Up → Left → Down → Repeat**

---