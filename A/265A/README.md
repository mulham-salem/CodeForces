# Problem 265A – Colorful Stones (Simplified Edition)

## Requirement

You are given:
- A string `stones` representing a row of stones, where each character is a color.
- A string `instructions` representing a sequence of moves.

You start on the **first stone** (position `1`).

For each character in `instructions`:
- If it matches the color of the **current stone**, you move **one step to the right**.
- Otherwise, you stay in the same position.

Your task is to find the **final position** after all instructions are processed.

---

## Input

- String `stones` — colors of the stones
- String `instructions` — movement instructions

---

## Output

- One integer — final position (**1-based index**)

---

## Examples

### Example 1

**Input**
```

RGB
RRR

```

**Output**
```

2

```

**Explanation**
```

Start at position 1 (R)

Instruction R → matches R → move to position 2
Instruction R → does not match G → stay
Instruction R → does not match G → stay

Final position = 2

```

---

### Example 2

**Input**
```

RRGB
RGBG

```

**Output**
```

2

```

**Explanation**
```

Start at position 1 (R)

Instruction R → matches R → move to position 2
Instruction G → does not match R → stay
Instruction B → does not match R → stay
Instruction G → does not match R → stay

Final position = 2

```

---

## Solution Idea

1. Start at the **first stone**.
2. Read instructions one by one.
3. Compare the current instruction with the color of the current stone.
4. Move forward **only if they match**.
5. Stop when all instructions are processed.

---

## Important Notes

- Movement is only **to the right**.
- Indexing in the output is **1-based**.
- Extra instructions do not matter if you already reached the last stone.
- You never move backwards.

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Key Insight

You only need a pointer to the current stone.
Each instruction either moves the pointer forward or does nothing.