# Problem 19A – World Football Cup

## 🏆 Overview

In this problem, we simulate a football tournament ranking system.

You are given:

- An even number `n` — the number of teams.
- The names of the `n` teams.
- The results of all matches (`n * (n - 1) / 2` games).

Your task is to determine which `n / 2` teams qualify for the knockout stage.

---

## 📋 Tournament Rules

Each match result affects team statistics as follows:

- Win → **3 points**
- Draw → **1 point**
- Loss → **0 points**

Teams are ranked by:

1. **Points** (higher first)
2. **Goal difference** = goals_scored − goals_against (higher first)
3. **Goals scored** (higher first)

It is guaranteed that these rules produce a unique ranking (no complete ties).

Finally:

- Select the top `n / 2` teams.
- Output their names in **lexicographical order**.

---

## 📥 Input Format

```

n
team_name_1
team_name_2
...
team_name_n
teamA-teamB x:y
...

```

Each match line contains:
```

name1-name2 goals1:goals2

```

---

## 📤 Output Format

Print the names of the qualified teams (top `n/2`)  
in **lexicographical order**, one per line.

---

## 🧠 Approach

### Step 1 — Store Team Data

For each team, maintain:

- `points`
- `goals_scored`
- `goals_against`

Use:
- A `map<string, Team>` for quick access by name.

---

### Step 2 — Process Matches

For each match:

- Parse team names.
- Parse goal values.
- Update:
  - goals_scored
  - goals_against
  - points

---

### Step 3 — Sort Teams

Sort all teams by:

1. Points (descending)
2. Goal difference (descending)
3. Goals scored (descending)

---

### Step 4 — Select Qualified Teams

- Take the first `n / 2` teams.
- Extract their names.
- Sort those names lexicographically.
- Print them.

---

## 🧩 Example

### Input
```

4
A
B
C
D
A-B 1:1
A-C 2:2
A-D 1:0
B-C 1:0
B-D 0:3
C-D 0:3

```

### Ranking (after processing)

| Team | Points | GD | GS |
|------|--------|----|----|
| D    | 6      | +5 | 6  |
| A    | 5      | +1 | 4  |
| B    | 3      | -1 | 2  |
| C    | 1      | -5 | 1  |

Top `2` teams: `D`, `A`  
Lexicographical order output:

```

A
D

````

---

## 💻 Pseudocode

```text
read n

create map teams

for i in 1 to n:
    read team_name
    initialize teams[team_name]

total_matches = n * (n - 1) / 2

for each match:
    read teams_part, score_part
    
    parse team1 and team2 from teams_part
    parse goals1 and goals2 from score_part
    
    update goals_scored and goals_against
    
    if goals1 > goals2:
        team1.points += 3
    else if goals1 < goals2:
        team2.points += 3
    else:
        team1.points += 1
        team2.points += 1

convert map to list

sort list by:
    points descending
    goal_difference descending
    goals_scored descending

qualified = first n/2 teams

extract their names

sort names lexicographically

print names
````

---

## ⏱ Complexity

* Processing matches: **O(n²)**
* Sorting teams: **O(n log n)**
* Overall complexity: **O(n²)** (since `n ≤ 50`, this is efficient)

---

## ✅ Key Notes

* Parsing input correctly is crucial.
* Goal difference must be computed dynamically.
* Lexicographical sorting is case-sensitive (ASCII order).
* Guaranteed unique ranking simplifies tie handling.
