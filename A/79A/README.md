# Problem 79A – Bus Game

## 🧩 Problem Summary
Two players, **Ciel** and **Hanako**, play a turn-based game using coins:

- `x` coins of **100 yen**
- `y` coins of **10 yen**

They take turns removing **exactly 220 yen** from the pile.
- **Ciel goes first**
- If a player cannot make 220 yen on their turn → they **lose**

---

## ⚙️ Rules

### Possible ways to form 220 yen:
- `2 × 100 + 2 × 10`
- `1 × 100 + 12 × 10`
- `0 × 100 + 22 × 10`

### Strategy:
- **Ciel** → prefers the move with the **maximum number of 100-yen coins**
- **Hanako** → prefers the move with the **maximum number of 10-yen coins**

---

## 📥 Input

- Two integers:
  - `x` → number of 100-yen coins  
  - `y` → number of 10-yen coins

0 ≤ x, y ≤ 10^6

---

## 📤 Output

- Print:
  - `"Ciel"` → if Ciel wins  
  - `"Hanako"` → otherwise  

---

## 🧠 Key Idea

The game is a **simulation with greedy choices**:

- Each player has a **fixed priority order** of moves
- On each turn:
  - Try moves in order
  - Pick the **first valid one**
- If no move is possible → current player **loses**

---

## 🔁 Pseudocode
```
turn = Ciel

while true: 
	if turn == Ciel: 
		if can take (2,2): 
			apply move 
		else if can take (1,12): 
			apply move 
		else if can take (0,22): 
			apply move 
		else: 
			Hanako wins → break 
	else: 
		if can take (0,22): 
			apply move 
		else if can take (1,12): 
			apply move 
		else if can take (2,2): 
			apply move 
		else: 
			Ciel wins → break

switch turn
```

---

## 🔍 Examples

### Example 1

Input: 2 2

Output: Ciel

**Explanation:**
- Ciel takes `2×100 + 2×10`
- No coins left → Hanako cannot move → Ciel wins

---

### Example 2

Input: 3 22

Output: Hanako

**Explanation:**
- Ciel → takes `(2,2)` → remaining `(1,20)`
- Hanako → takes `(1,12)` → remaining `(0,8)`
- Ciel cannot make 220 → loses

---

## 🚀 Notes

- Direct simulation is efficient because each move removes **220 yen**
- Maximum number of turns is small (≤ ~10⁵)
- Order of moves is **critical** for correctness

---