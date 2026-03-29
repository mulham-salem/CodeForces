# Problem 57A – Square Earth

## 🧩 Problem Summary
Meg models the Earth as a **square of side `n`**.  
You are given two points that lie **on the boundary of the square**.

Your task is to find the **shortest distance between these two points**, moving **only along the edges (perimeter)** of the square.

---

## 🎯 Key Idea
Instead of working on a square, imagine the perimeter as a **linear circular path** of length:

perimeter = 4 × n

Each point on the boundary can be converted into a **single position** along this perimeter.

Then the shortest distance between two points is:

min(|p1 - p2|, perimeter - |p1 - p2|)

---

## 🔄 Mapping Points to the Perimeter

Depending on which side the point lies on:

| Side          | Condition   | Position Formula     |
|---------------|------------|----------------------|
| Bottom        | y = 0      | p = x                |
| Right         | x = n      | p = n + y            |
| Top           | y = n      | p = 3n - x           |
| Left          | x = 0      | p = 4n - y           |

---

## 🧪 Examples

### Example 1

Input: 2 0 0 1 0

Both points are on the **bottom edge**, so we move directly:

Distance = 1

---

### Example 2

Input: 2 0 1 2 1

Points are on opposite sides (left and right).  
Two possible paths (top or bottom), both give:

Distance = 4

---

### Example 3

Input: 100 0 0 100 100

Points are opposite corners.  
Shortest path along edges:

Distance = 200

---

## 🧠 Pseudocode

```
function getPosition(n, x, y): 
	if y == 0: return x 
	else if x == n: return n + y 
	else if y == n: return 3n - x 
	else: return 4n - y

read n, x1, y1, x2, y2

p1 = getPosition(n, x1, y1) 
p2 = getPosition(n, x2, y2)

d = abs(p1 - p2) 
perimeter = 4 * n

answer = min(d, perimeter - d)

print answer
```

---

## ✅ Conclusion
- Convert 2D boundary points into 1D positions on the perimeter  
- Compute both possible distances  
- Return the minimum

---