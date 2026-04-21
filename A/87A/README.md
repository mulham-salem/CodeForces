# Problem 87A – Trains

## 🧠 Overview

Vasya travels by subway and chooses between two trains:
- One goes to **Dasha** every `a` minutes
- One goes to **Masha** every `b` minutes

At any moment he enters the subway:
- He takes the **first arriving train**
- If both arrive at the same time, he chooses the train with the **larger interval (less frequent one)**

We need to determine which girl Vasya visits more often.

---

## 💡 Key Idea

Instead of simulating infinite time, we analyze a single repeating cycle:

> The system repeats every **LCM(a, b)** minutes.

So we only study one full cycle.

---

## ⚙️ Approach

1. Compute:
   - `LCM(a, b)` using `gcd`
2. Count how many times each train appears in one cycle:
   - `Dasha visits = LCM / a`
   - `Masha visits = LCM / b`
3. Handle the single tie moment (when both arrive together):
   - That event happens once per cycle
   - It is assigned to the **slower train (larger interval)**
4. Compare final counts and output the result.

---

## 📌 Example

### Input

a = 3, b = 7

### Train arrivals in one cycle (LCM = 21):
- Dasha: 3, 6, 9, 12, 15, 18, 21
- Masha: 7, 14, 21

Both meet at time **21**, and it goes to the slower train.

### Result:

Dasha

---

## 📌 Another Example

### Input

a = 2, b = 3

### Cycle = 6:
- Dasha: 2, 4, 6
- Masha: 3, 6

Tie at 6 is balanced after adjustment.

### Result:

Equal

---

## 🎯 Complexity

- Time: **O(log(min(a, b)))** (for GCD)
- Space: **O(1)**

---

## 🧩 Summary

- Reduce infinite process using **LCM**
- Count occurrences per cycle
- Adjust for the single simultaneous arrival
- Compare final results

---