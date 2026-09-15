# Problem 292A – SMSC

## Problem Statement

A corporation's Short Message Service Center (SMSC) receives `n` tasks. Each task `i` arrives at time `t_i` and contains `c_i` messages to send. The SMSC can send **at most one message per second** and processes messages in a **FIFO queue**.

At each second `x`:
1. If the queue is non-empty, send **one** message from the head.
2. If a task arrives at second `x`, append all its messages to the tail (these messages **cannot** be sent at second `x`).

Determine:
- The time when the **last message** was sent.
- The **maximum queue size** at any moment.

---

## Input

- First line: integer `n` (1 ≤ n ≤ 10³) — number of tasks.
- Next `n` lines: two integers `t_i` and `c_i` (1 ≤ t_i, c_i ≤ 10⁶).
- All `t_i` are **distinct** and given in **chronological order** (`t_i < t_{i+1}`).

---

## Output

Two space-separated integers:
- The time when the last message was sent.
- The maximum queue size at any moment.

---

## Examples

### Example 1:

**Input:**
```

2
1 1
2 1

```
**Output:**
```

3 1

```

---

### Example 2:

**Input:**
```

1
1000000 10

```
**Output:**
```

1000010 10

```

---

### Example 3:

**Input:**
```

3
3 3
4 3
5 3

```
**Output:**
```

12 7

```

---

## Solution Idea

Simulate the queue with a running "finish time" — the moment the queue will become empty if no new tasks arrive.

For each task `(t, c)`:
- **Current queue size at time `t`** = `max(0, finish - t) + c`
  - `finish - t` is how many messages are still pending (if `finish > t`).
  - Add the new `c` messages.
- Update the **maximum queue size** seen so far.
- Update `finish`:
  - If the queue is already empty before `t` (`finish < t`), the new messages start at `t`.
  - Otherwise, they start after the current backlog finishes.
  - So: `finish = max(finish, t) + c`.

The final `finish` value is the time the last message is sent.

---

## Pseudocode

```

START
	READ n
	finish = 0
	maxQueue = 0
	FOR i = 1 to n DO
		READ t, c
		queue = max(0, finish - t) + c
		maxQueue = max(maxQueue, queue)
		finish = max(finish, t) + c
	END FOR
	PRINT finish, maxQueue
END

```

---

## Notes

- Use **64-bit integers** because `t_i` and `c_i` can be up to 10⁶, and with `n` up to 10³, `finish` can reach around 10⁹.
- The key trick is to avoid simulating second-by-second — instead, track only the `finish` time and update it in **O(1)** per task.
- Total complexity: **O(n)** time, **O(1)** extra space.

---