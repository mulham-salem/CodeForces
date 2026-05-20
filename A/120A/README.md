# Problem 120A – Elevator

## Description
A VIP person enters an elevator through either the **front** or **back** door and holds one of two rails.

The position of the rails changes depending on the door:

- From the **front**:
  - Rail `1` → Left side
  - Rail `2` → Right side

- From the **back**:
  - Rail `1` → Right side
  - Rail `2` → Left side

Since the VIP always uses their strongest hand, determine whether they are:

- Left-handed (`L`)
- Right-handed (`R`)

---

## Input
The input contains:

- A string:
  - `"front"` or `"back"`
- An integer:
  - `1` or `2` representing the rail number

---

## Output
Print:

- `L` if the person is left-handed
- `R` if the person is right-handed

---

## Examples

### Input
```text
front
1
```

### Output
```text
L
```

### Explanation
Entering from the front makes rail `1` on the left side, so the person uses the left hand.

---

### Input
```text
back
1
```

### Output
```text
R
```

### Explanation
Entering from the back makes rail `1` on the right side, so the person uses the right hand.

---

## Pseudocode

```text
Read door and rail

If (door is "front" and rail is 1)
    Print 'L'

Else if (door is "back" and rail is 2)
    Print 'L'

Else
    Print 'R'
```

---

## Complexity

- Time Complexity: `O(1)`
- Memory Complexity: `O(1)`

---