# Problem 2A – Winner

## 📝 Problem Summary
In the card game **Berlogging**, each player starts with **0 points**.  
The game consists of `n` rounds. In each round, a player gains or loses points.

At the end of the game:
- If **only one player** has the maximum total score, they are the winner.
- If **multiple players** are tied with the same maximum score `m`,
  the winner is the player who **reached at least `m` points first during the game**.

It is guaranteed that at least one player has a positive score at the end.

---

## 💡 Key Idea
The problem cannot be solved by only looking at the **final scores**.

You must:
1. Compute the **final total score** for each player.
2. Find the **maximum final score**.
3. Replay the rounds in order and track scores **over time**.
4. Among players whose final score equals the maximum,  
   the winner is the **first one who reaches that score during the game**.

---

## 📊 Example 1
**Input**
```

3
mike 3
andrew 5
mike 2

```

**Final scores**
- mike → 5  
- andrew → 5  

Both are tied, but:
- andrew reached 5 points in round 2
- mike reached 5 points in round 3

✅ **Winner: andrew**

---

## 📊 Example 2
**Input**
```

3
andrew 3
andrew 2
mike 5

```

**Final scores**
- andrew → 5  
- mike → 5  

- andrew reached 5 points in round 2
- mike reached 5 points in round 3

✅ **Winner: andrew**

---

## 🧠 Why Two Score Maps Are Needed
- **Final score map**: determines who has the maximum score at the end.
- **Current score map**: tracks scores round by round to see who reaches the maximum first.

Without tracking scores over time, the tie-breaking rule cannot be applied correctly.

---

## 🧾 Pseudo-code
```

read n
rounds = empty list
totalScores = empty map

for each round:
read name, score
store (name, score) in rounds
totalScores[name] += score

maxScore = maximum value in totalScores

currentScores = empty map

for each (name, score) in rounds:
currentScores[name] += score
if currentScores[name] >= maxScore
and totalScores[name] == maxScore:
output name
stop

```

---

## ✅ Conclusion
- The winner is not only determined by the highest final score.
- When there is a tie, **the order of reaching that score matters**.
- Tracking the game progression is essential to solve the problem correctly.