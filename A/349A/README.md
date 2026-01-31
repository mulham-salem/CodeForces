# Problem 349A – Cinema Line

## Problem Summary

There are `n` people standing in a line to buy cinema tickets.  
Each ticket costs **25 rubles**.

Each person has **exactly one bill**, which can be:
- `25`
- `50`
- `100`

The clerk:
- Starts with **no money**
- Sells tickets **in order**
- Must give the **correct change** immediately

The task is to determine whether the clerk can successfully sell a ticket to **every person** in the line.

---

## Key Observations

- A person paying with `25` needs **no change**
- A person paying with `50` needs **25 change**
- A person paying with `100` needs **75 change**
- The clerk **cannot break bills**
- Change can only be given using money collected from **previous customers**

---

## Strategy

Instead of tracking total money, we track:
- The number of `25` ruble bills
- The number of `50` ruble bills

Why?
Because the **type of bills matters**, not just the sum.

---

## Rules While Processing the Line

### If the person pays with `25`
- No change needed
- Store one `25` bill

### If the person pays with `50`
- Must give **one `25` bill**
- If no `25` is available → fail

### If the person pays with `100`
- Must give **75 change**
- Prefer giving:
  1. One `50` + one `25`
  2. Otherwise, three `25`
- If neither is possible → fail

---

## Example Walkthroughs

### Example 1
```

Input: 25 25 50 50

```
Process:
- Collect two `25`
- Use one `25` for each `50`

Result: ✅ YES

---

### Example 2
```

Input: 25 100

```
Process:
- Collect one `25`
- Cannot give `75` change for `100`

Result: ❌ NO

---

### Example 3
```

Input: 25 25 25 100

```
Process:
- Collect three `25`
- Use all three as change

Result: ✅ YES

---

## Pseudo Code

```

read n
initialize count25 = 0
initialize count50 = 0

for each person in line:
read bill

```
if bill == 25:
    count25++

else if bill == 50:
    if count25 >= 1:
        count25--
        count50++
    else:
        print NO
        exit

else if bill == 100:
    if count50 >= 1 and count25 >= 1:
        count50--
        count25--
    else if count25 >= 3:
        count25 -= 3
    else:
        print NO
        exit
```

print YES

```

---

## Final Notes

- Always process people **in order**
- Never assume you can split a bill
- Correct change must come from **previous transactions only**

This greedy approach guarantees correctness and runs in **O(n)** time.

---