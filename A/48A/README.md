# Problem 48A – Rock-paper-scissors

## 🧩 Problem Summary
Three players — Fyodor (F), Matroskin (M), and Sharic (S) — each choose one gesture:
- `rock`
- `paper`
- `scissors`

The goal is to determine **who wins**, or if there is **no winner**.

---

## 🪨 Rules

- rock beats scissors  
- scissors beats paper  
- paper beats rock  

---

## ⚖️ Winning Condition

A player wins **only if**:
- The other **two players chose the same gesture**
- And the player's gesture **beats that gesture**

Otherwise, the result is `"?"`

---

## ❌ No Winner Cases

Return `"?"` if:
- All three gestures are the same  
- All three gestures are different  
- Two are the same, but the third **does NOT beat them**

---

## 📥 Input
Three lines:

F M S

Each line contains one of:

rock | paper | scissors

---

## 📤 Output

Print:
- `"F"` → if Fyodor wins  
- `"M"` → if Matroskin wins  
- `"S"` → if Sharic wins  
- `"?"` → otherwise  

---

## 🔍 Examples

### Example 1

Input: rock rock rock

Output: ?

---

### Example 2

Input: paper rock rock

Output: F

---

### Example 3

Input: scissors rock rock

Output: ?

---

### Example 4

Input: scissors paper rock

Output: ?

---

## 🧠 Pseudocode

```
function beats(a, b): 
	return (a == "scissors" and b == "paper") OR 
		   (a == "paper" and b == "rock") OR 
		   (a == "rock" and b == "scissors")

read F, M, S

if (M == S AND beats(F, M)): 
	print "F" 
else if (F == S AND beats(M, F)): 
	print "M" 
else if (F == M AND beats(S, F)): 
	print "S" 
else: 
	print "?"
```
---

## 💡 Key Insight

The only way to win is:

> Two players choose the same gesture, and the third one beats them.