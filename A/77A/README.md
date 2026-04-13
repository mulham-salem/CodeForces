# Problem 77A – Heroes

## 🧩 Overview
You are given **7 heroes** that must be split into **3 teams**, each assigned to defeat a different boss:

- Mephisto → gives `a` experience  
- Diablo → gives `b` experience  
- Baal → gives `c` experience  

Each hero in a team of size `y` receives:

floor(x / y)

Where `x` is the boss experience.

---

## 🎯 Objective

You must divide the heroes into **3 non-empty teams** such that:

### 1. Minimize Experience Difference (Primary)
Minimize:

(max experience among heroes) - (min experience among heroes)

---

### 2. Maximize Total Liking (Secondary)

Among all optimal splits (from step 1), maximize:

- The number of ordered pairs `(p, q)` such that:
  - `p` and `q` are in the same team
  - `p` likes `q`

> ⚠️ Note:
> - Likes are **directed**
> - Mutual liking counts as **2**

---

## 📥 Input

- Integer `n` — number of "likes"
- Next `n` lines:

p likes q

- Last line:

a b c

---

## 📤 Output

min_difference max_total_liking

---

## 🧠 Key Idea

Since there are only **7 heroes**, we can:

- Try all possible ways to assign each hero to one of 3 teams
- Total combinations: `3^7 = 2187`

---

## ⚙️ Approach

1. Assign each hero to team `0`, `1`, or `2`
2. For each valid assignment:
   - Ensure all teams are non-empty
   - Compute experience per team
   - Compute difference
   - Compute total liking inside teams
3. Track the best result:
   - Minimize difference
   - Maximize liking

---

## 🧾 Pseudocode

```
best_diff = INF
best_like = 0

function solve(i):
    if i == 7:
        if any team is empty:
            return

        compute team sizes

        exp[0] = a / size[0]
        exp[1] = b / size[1]
        exp[2] = c / size[2]

        diff = max(exp) - min(exp)

        like = count_likes()

        if diff < best_diff:
            best_diff = diff
            best_like = like
        else if diff == best_diff:
            best_like = max(best_like, like)

        return

    for t in {0,1,2}:
        assign hero i to team t
        solve(i + 1)


---

❤️ Counting Likes

function count_likes():
    total = 0

    for each team:
        for each pair (i, j) in team:
            if i != j and i likes j:
                total++

    return total
```

---

📌 Example 1

Input
```
3
Troll likes Dracul
Dracul likes Anka
Snowy likes Hexadecimal
210 200 180
```
Output
```
30 3
```

---

📌 Example 2

Input
```
2
Anka likes Chapay
Chapay likes Anka
10000 50 50
```
Output
```
1950 2
```

---

🚀 Complexity

Total states: 3^7 = 2187

Efficient for brute-force

---

🧠 Summary

Try all team assignments

Minimize experience gap first

Maximize liking second

---