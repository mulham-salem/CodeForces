# Problem 62A – A Student's Dream

## 🧩 Problem Summary
You are given the number of fingers for:
- A girl: left hand `al`, right hand `ar`
- A boy: left hand `bl`, right hand `br`

They want to hold hands (one hand each) such that both are comfortable.

You can choose:
- Girl's left with Boy's right
- Girl's right with Boy's left

---

## ✅ Conditions

For a valid arrangement of:
- `g` = girl fingers
- `b` = boy fingers

### 1. Girl Condition
No two girl fingers can be adjacent:

b ≥ g - 1

### 2. Boy Condition
No three boy fingers can be consecutive:

b ≤ 2 × (g + 1)

---

## 🔄 Strategy

Check both possible pairings:
1. `(g = al, b = br)`
2. `(g = ar, b = bl)`

If **any one** satisfies both conditions → answer is `YES`, otherwise `NO`.

---

## 🧪 Examples

### Example 1

Input: 5 1 10 5

Check:
- (5, 5) → valid  
✔ `5 ≥ 4` and `5 ≤ 12`

**Output:**

YES

---

### Example 2

Input: 4 5 3 3

Check:
- (4, 3) → valid  
✔ `3 ≥ 3` and `3 ≤ 10`

**Output:**

YES

---

### Example 3

Input: 1 2 11 6

Check:
- (1, 6) → invalid (too many boys)  
- (2, 11) → invalid (too many boys)

**Output:**

NO

---

## ⚙️ Pseudocode

```
function valid(g, b): 
	return (b >= g - 1) AND (b <= 2 * (g + 1))

read al, ar read bl, br

if valid(al, br) OR valid(ar, bl): 
	print "YES" else: print "NO"
```
---

## 💡 Key Insight
- Girl fingers require separation → need enough boys
- Boy fingers must be split into gaps → limited by number of girl fingers

👉 Think of girls creating `(g + 1)` gaps, each gap can hold at most 2 boys.

---