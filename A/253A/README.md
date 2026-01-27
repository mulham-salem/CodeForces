# Problem 253A – Boys and Girls

## 🧩 Problem Overview

There are `n` boys and `m` girls in a class. They should stand in a line so that **boys and girls alternate as much as possible**.  

Formally:
- Let positions be indexed from 1 to n+m.
- Maximize the number of indices `i` (1 ≤ i < n+m) where children at positions `i` and `i+1` are of different genders.

Your task is to print **one possible optimal arrangement**.

---

## 📥 Input

Two integers:
- `n` — number of boys
- `m` — number of girls

Constraints:
- 1 ≤ n, m ≤ 100

---

## 📤 Output

A line of `n + m` characters:
- `B` for boy
- `G` for girl  

The arrangement must have exactly `n` Bs and `m` Gs, and maximize alternations.  
If multiple optimal solutions exist, print any.

---

## 💡 Key Insight

- Always start with the **gender that has more children**.  
- Place the **other gender in every second position** to maximize alternation.  
- After placing the smaller group, append any remaining children of the larger group at the end.

This ensures the **maximum number of alternating pairs**.

---

## ✏️ Examples

### Example 1

**Input:**
```

3 3

```

**Possible Output:**
```

BGBGBG

```
Other valid output:
```

GBGBGB

```

### Example 2

**Input:**
```

4 2

```

**Possible Output:**
```

BGBGBB

```
Other valid output:
```

BBGBGB

```

---

## 🧠 Pseudo-code

```

read n, m

if n >= m:
first_gender = 'B'
second_gender = 'G'
else:
first_gender = 'G'
second_gender = 'B'

while n > 0 and m > 0:
print(first_gender)
print(second_gender)
decrement corresponding counts

# print remaining children of the larger group

while n > 0:
print('B')
n--
while m > 0:
print('G')
m--

```

---

## ⏱ Complexity

- **Time Complexity:** O(n + m)  
- **Space Complexity:** O(n + m) (if storing the string)  

---

## ✅ Notes

- The solution is greedy and works for all inputs in the given range.
- The key is to **alternate children as long as both genders remain**, then append leftovers.