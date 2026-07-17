# Problem 195A – Let's Watch Football

## Idea

The video consumes data faster than the Internet can download it (`a > b`), so starting immediately is impossible.

Suppose we wait `t` seconds before watching.

- During the waiting time, the Internet downloads `t × b` units of data.
- While watching, downloading continues at the same time.

To watch the entire video without buffering, the downloaded data must **never become less** than the amount of data already consumed.

Instead of simulating every second, we derive the minimum waiting time directly using a mathematical formula.

---

## Algorithm

1. Read `a`, `b`, and `c`.
2. Compute the minimum waiting time using integer arithmetic.
3. If the division is not exact, round the result up.
4. Output the answer.

---

## Pseudocode

```text
Read a, b, c

answer = (a × c) / b - c

If (a × c) is not divisible by b
    answer = answer + 1

Print answer
```

---

## Example

### Input

```text
4 1 1
```

### Output

```text
3
```

### Explanation

The Internet is much slower than the video playback.

Waiting **3 seconds** allows enough data to be available so the video can be watched continuously without buffering.

---

## Complexity

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---