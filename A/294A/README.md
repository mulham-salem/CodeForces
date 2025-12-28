# Problem 294A – Shaass and Oskols

## Requirement

Shaass has `n` wires, and each wire has some birds sitting on it.

Then `m` shots are fired.  
Each shot is described by two integers:

- `x` – the wire number that was shot
- `y` – the position of the bird on that wire

When a bird is shot:

- All birds **to the left** of position `y` fly to the **previous wire** (`x - 1`)
- All birds **to the right** of position `y` fly to the **next wire** (`x + 1`)
- The bird at position `y` is removed

If a wire does not exist (first or last wire), the birds flying outside are lost.

---

**Goal:**  
After all shots, output the **number of birds on each wire**.

---

## Input

- First line: integer `n` – number of wires
- Second line: `n` integers – number of birds on each wire
- Third line: integer `m` – number of shots
- Next `m` lines: two integers `x` and `y` describing each shot

---

## Output

- Print `n` lines  
- Each line contains the number of birds remaining on wire `i`

---

## Examples

### Example

**Input**

```

5
2 4 3 2 2
3
2 2
3 1
5 2

```

**Output**

```

2
1
5
0
1

```

---

## Explanation

```

Initial wires:
[2, 4, 3, 2, 2]

Shot 1: wire 2, bird 2

* Left birds: 1 → go to wire 1
* Right birds: 2 → go to wire 3
  Result:
  [3, 0, 5, 2, 2]

Shot 2: wire 3, bird 1

* Left birds: 0 → go to wire 2
* Right birds: 4 → go to wire 4
  Result:
  [3, 0, 0, 6, 2]

Shot 3: wire 5, bird 2

* Left birds: 1 → go to wire 4
* Right birds: 0 → lost
  Result:
  [3, 0, 0, 7, 0]

```

(Final output prints each wire on a new line.)

---

## Solution Idea

1. Store the number of birds on each wire in an array.
2. For each shot:
   - Calculate birds on the left: `y - 1`
   - Calculate birds on the right: `birds[x] - y`
3. Move birds:
   - Add left birds to wire `x - 1` (if it exists)
   - Add right birds to wire `x + 1` (if it exists)
4. Set birds on wire `x` to `0`
5. After all shots, print the array.

---

## Formula

For a shot at wire `x` and position `y`:

```

left  = y - 1
right = birds[x] - y

```

---

## Implementation Notes

- Use **0-based indexing** carefully if converting from input (which is 1-based).
- This problem requires **simulation**, no complex math.
- Time complexity is `O(n + m)`.