# Problem 10A – Power Consumption Calculation

## 🧩 Problem Summary

Tom is interested in the power consumption of his laptop.  
The laptop operates in **three modes**:

| Mode          | Power Consumption (per minute) |
|---------------|--------------------------------|
| Normal        | P1                             |
| Screensaver   | P2                             |
| Sleep         | P3                             |

### Mode Transitions

- While Tom is working, the laptop stays in **Normal mode**.
- After **T1 minutes** of inactivity → switches to **Screensaver mode**.
- After an additional **T2 minutes** → switches to **Sleep mode**.
- If Tom interacts with the laptop at any time, it immediately returns to **Normal mode**.

Tom works during `n` time intervals:

```

[l1, r1], [l2, r2], ..., [ln, rn]

```

During each interval, he continuously uses the laptop.

Your task is to compute the **total power consumption** during the entire period  
from `l1` to `rn`.

---

## 💡 Key Observations

There are two types of time segments:

1. **Working intervals**
   - Laptop always in **Normal mode**
   - Energy = `(r - l) × P1`

2. **Gaps between intervals**
   - Laptop transitions through modes depending on gap length
   - Each gap must be divided carefully into:
     - Normal time
     - Screensaver time
     - Sleep time

---

## 🧠 Handling a Gap

Let:

```

gap = next_l - previous_r

```

We simulate the transition in order:

1. **Normal phase**
```

normalTime = min(gap, T1)

```

2. **Screensaver phase**
```

remaining = gap - normalTime
screenTime = min(remaining, T2)

```

3. **Sleep phase**
```

sleepTime = remaining - screenTime

```

Energy is accumulated accordingly.

---

## 📌 Example 1

### Input
```

1 3 2 1 5 10
0 10

```

### Explanation

Only one working interval:

```

Duration = 10 minutes
Energy = 10 × 3 = 30

```

### Output
```

30

```

---

## 📌 Example 2

### Input
```

2 8 4 2 5 10
20 30
50 100

```

### Step 1 — Working Intervals

- 20 → 30 → 10 × 8 = 80
- 50 → 100 → 50 × 8 = 400

Total working energy:
```

480

```

### Step 2 — Gap

```

Gap = 50 - 30 = 20 minutes

```

- First 5 minutes → Normal → 5 × 8 = 40
- Next 10 minutes → Screensaver → 10 × 4 = 40
- Remaining 5 minutes → Sleep → 5 × 2 = 10

Gap energy:
```

90

```

### Final Answer
```

480 + 90 = 570

```

---

## 🧮 Algorithm (Pseudocode)

```

read n, P1, P2, P3, T1, T2

read all intervals into array intervals

ans = 0

for i from 0 to n-1:

```
# Working time
working_time = intervals[i].r - intervals[i].l
ans += working_time * P1

if i > 0:
    gap = intervals[i].l - intervals[i-1].r

    # Normal phase
    normalTime = min(gap, T1)
    ans += normalTime * P1
    gap -= normalTime

    # Screensaver phase
    screenTime = min(gap, T2)
    ans += screenTime * P2
    gap -= screenTime

    # Sleep phase
    ans += gap * P3
```

print ans

```

---

## ⏱ Time Complexity

```

O(n)

```

We iterate through the intervals once.

---

## 🎯 Core Idea

For each gap, distribute the time across the three modes  
without exceeding:

- The remaining gap time
- The maximum duration allowed for each mode

This ensures accurate simulation of state transitions.