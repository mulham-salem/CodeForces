# Problem 82A – Double Cola

## 🧾 Problem Summary
Five people are standing in a queue:

- Sheldon  
- Leonard  
- Penny  
- Rajesh  
- Howard  

They buy cola cans one by one. Each time:
1. The person at the front drinks a can.
2. Then they duplicate (become two copies).
3. Both copies go to the end of the queue.

This process continues indefinitely.

---

## 🎯 Task
Given an integer `n`, determine **who drinks the n-th can**.

---

## 💡 Key Idea
Instead of simulating the queue (which is too slow), we observe:

- People appear in **groups (rounds)**.
- In each round, every person appears multiple times.
- The repetition doubles each round:

| Round | Repetitions per Person | Total People |
|------|----------------------|-------------|
| 1    | 1                    | 5           |
| 2    | 2                    | 10          |
| 3    | 4                    | 20          |
| ...  | ...                  | ...         |

---

## 🧠 Approach
- Find which **round** the n-th cola belongs to.
- Each round has `5 × groupSize` people.
- Reduce `n` until it fits in a round.
- Determine which person based on position.

---

## 🧪 Example

### Input

n = 6

### Process
- First round → 5 people → skip → `n = 1`
- Second round → group size = 2

### Result

Sheldon

---

### Input

n = 1802

### Output

Penny

---

## 🧾 Pseudocode
```
names = ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"] 
groupSize = 1

while n > 5 * groupSize: 
	n = n - (5 * groupSize) 
	groupSize = groupSize * 2

index = (n - 1) / groupSize

print names[index]
```

---

## ⚡ Complexity
- Time: O(log n)
- Space: O(1)

---