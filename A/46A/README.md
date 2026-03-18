# Problem 46A – Ball Game

## 🧠 Idea

Children stand in a circle and pass a ball.  
The ball starts with child `1`.

At each throw:
- The number of steps increases (`1, 2, 3, ...`)
- Movement is clockwise
- The circle wraps around (circular behavior)

We need to print the child who receives the ball after each throw.

---

## 🔄 Key Observation

This is a **circular movement problem**.

To simulate movement correctly, we use modulo:

current = (current + step - 1) % n + 1

This formula ensures:
- We stay inside the range `[1, n]`
- We correctly wrap around the circle

---

## ✏️ Examples

### Example 1

Input: 10

Output: 2 4 7 1 6 2 9 7 6

### Walkthrough
| Step | Move | Result |
|------|------|--------|
| 1    | +1   | 2      |
| 2    | +2   | 4      |
| 3    | +3   | 7      |
| 4    | +4   | 1      |
| 5    | +5   | 6      |
| 6    | +6   | 2      |
| 7    | +7   | 9      |
| 8    | +8   | 7      |
| 9    | +9   | 6      |

---

### Example 2

Input: 3

Output: 2 1

---

## ⚙️ Pseudocode

```
read n current = 1

for i from 1 to n-1: 
	current = (current + i - 1) % n + 1 
	print current

```

---

## ⏱ Complexity

```
- Time: `O(n)`
- Space: `O(1)`
```

---

## 📝 Notes

- The `-1` and `+1` are used to handle **1-based indexing**
- Modulo ensures circular movement
- Without proper adjustment, results may include `0`, which is invalid

---