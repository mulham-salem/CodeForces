# Problem 90A – Cableway

## 🧩 Overview
A cableway sends **one cablecar every minute**, starting at time `0`.  
The colors repeat in this cycle:

Red → Green → Blue → ...

Each cablecar:
- Carries **at most 2 students**
- Takes **exactly 30 minutes** to reach the top

---

## 👥 Input
Three integers:

r g b

- `r`: number of students who only take **red**
- `g`: number of students who only take **green**
- `b`: number of students who only take **blue**
- `0 ≤ r, g, b ≤ 100`
- At least one is non-zero

---

## 🎯 Goal
Compute the **minimum time** required for all students to reach the top.

> Final Answer = **(last boarding time) + 30**

---

## ⚙️ Key Idea
- A cablecar arrives every minute
- Its color is determined by `time % 3`
- At each minute, take up to **2 students** of that color
- Continue until all students are transported
- Track the **last time a student boards**

---

## 🔁 Color Cycle

| Time (t) | Color |
|----------|------|
| 0        | Red  |
| 1        | Green|
| 2        | Blue |
| 3        | Red  |
| ...      | ...  |

---

## 📊 Example 1

### Input

1 3 2

### Simulation

| Time | Color | Taken | Remaining (r, g, b) |
|------|------|------|---------------------|
| 0    | Red   | 1    | (0, 3, 2) |
| 1    | Green | 2    | (0, 1, 2) |
| 2    | Blue  | 2    | (0, 1, 0) |
| 3    | Red   | 0    | (0, 1, 0) |
| 4    | Green | 1    | (0, 0, 0) |

Last boarding time = `4`

Final answer:

4 + 30 = 34

---

## 📊 Example 2

### Input

3 2 1

### Explanation
Students finish boarding at time `3`

Final answer:

3 + 30 = 33

---

## 🧠 Pseudocode
```
read r, g, b 
t = 0

while (r > 0 OR g > 0 OR b > 0): 
	if t % 3 == 0: 
		take up to 2 from r 
	else if t % 3 == 1: 
		take up to 2 from g 
	else: 
		take up to 2 from b

t = t + 1

last_time = t - 1 
print last_time + 30
```
---

## 🚀 Notes
- Simple simulation is enough (max ~300 steps)
- Always use `min(2, remaining students)`
- Focus only on the **last boarding time**

---