# Problem 950A – Friends

## Requirement
You are given:

- An integer **n** — number of friends in a row
- An integer **k** — maximum distance a friend can jump to another friend  
- An array **a** of length n — heights of friends

Each friend can only jump to a friend who is **taller** than them, and the **jump distance** must be at most **k** (in positions).

Your task is to determine whether it is possible for the **first friend** to reach the **last friend** following these rules.

---

## Input
- Two integers:  
```

n k

```
- Array of integers:  
```

a1 a2 a3 ... an

```
(1 ≤ n ≤ 1000, 1 ≤ k ≤ 1000, 1 ≤ ai ≤ 1000)

---

## Output
Print:

- `"YES"` — if the first friend can reach the last friend  
- `"NO"` — otherwise

---

## Example 1
**Input**
```

5 2
1 3 2 4 5

```

**Output**
```

YES

```

**Explanation**

The first friend (height 1) can jump to 3 (within k=2 positions).  
Then to 4 or 5 following the rules.  
The last friend is reachable.

---

## Example 2
**Input**
```

3 1
3 2 1

```

**Output**
```

NO

```

**Explanation**

Each friend can only jump forward 1 position.  
Since the first friend (3) cannot jump to a taller friend, reaching the last friend is impossible.

---

## Solution Idea

- Start from the first friend.  
- At each step, check **all reachable positions** within distance k.  
- Move to any friend who is **taller**.  
- Repeat until either the last friend is reached or no further jumps are possible.

---

## Algorithm

1. Initialize `pos = 1` (first friend).  
2. While `pos < n`:
   - Find the **furthest friend** within `pos+1` to `pos+k` who is taller than current.  
   - If no such friend exists, return `"NO"`.  
   - Otherwise, jump to that friend.  
3. If `pos >= n`, return `"YES"`.

---

## Complexity
- **Time Complexity:** O(n * k)  
- **Space Complexity:** O(1)

---

## Key Insight
- Always jump to the **furthest reachable taller friend** within k steps.  
- If at any position no taller friend exists within k, the path is blocked.  
- Greedy simulation guarantees correct answer for this problem size.
