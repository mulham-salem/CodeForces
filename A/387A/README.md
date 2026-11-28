# Problem 387A – George and Sleep

## Explanation

George woke up at time `s` (current time) and he slept for a duration `t`. We need to find the time `p` when he went to bed.

Since George could have gone to bed **the previous day**, we must handle cases where subtracting the sleep duration from the current time gives a negative result. In that case, we add 24 hours (1440 minutes) to wrap around.

### Steps:
1. Parse both times from `"hh:mm"` format into hours and minutes.
2. Convert both times to total minutes since midnight.
3. Subtract sleep duration from current time: `result = current - sleep`.
4. If `result < 0`, add `1440` (minutes in a full day) to wrap to the previous day.
5. Convert `result` back to `"hh:mm"` format, ensuring two-digit padding.

### Key Insight:
Working in **minutes** simplifies arithmetic and avoids separate hour/minute borrowing logic.

---

## Examples

### Example 1
```

Input:
05:50
05:44

Calculation:
current = 560 + 50 = 350
sleep   = 560 + 44 = 344
result  = 350 - 344 = 6 minutes

Output:
00:06

```

---

### Example 2 (went to bed yesterday)
```

Input:
00:00
01:00

Calculation:
current = 0
sleep   = 60
result  = 0 - 60 = -60
-60 + 1440 = 1380 minutes

1380 / 60 = 23 hours, 1380 % 60 = 0 minutes

Output:
23:00

```

---

### Example 3 (zero sleep)
```

Input:
00:01
00:00

Calculation:
current = 1
sleep   = 0
result  = 1

Output:
00:01

```

---

## Pseudocode

```

READ string s        // current time "hh:mm"
READ string t        // sleep duration "hh:mm"

currentHours   = INTEGER(s[0..1])
currentMinutes = INTEGER(s[3..4])
sleepHours     = INTEGER(t[0..1])
sleepMinutes   = INTEGER(t[3..4])

currentTime = currentHours * 60 + currentMinutes
sleepTime   = sleepHours   * 60 + sleepMinutes

result = currentTime - sleepTime

IF result < 0 THEN
	result = result + 1440        // wrap to previous day
END IF

hours   = result / 60
minutes = result % 60

PRINT hours formatted as 2 digits + ":" + minutes formatted as 2 digits

```

---

## Complexity
- **Time:** O(1) — constant number of operations.
- **Space:** O(1) — only a few integer variables.

---

## Notes
- Always output with **two-digit padding** (e.g., `00:06`, not `0:06`).
- The modulo-by-1440 trick handles the "yesterday" case elegantly.
- No need for separate hour/minute borrow logic — minutes arithmetic does it all.
