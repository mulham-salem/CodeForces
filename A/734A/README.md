# Problem 734A – Anton and Danik

## Requirement
You are given:

- An integer **n** — the number of games played
- A string of length **n** consisting of characters:
  - **'A'** → Anton wins the game
  - **'D'** → Danik wins the game

Your task is to determine who won **more games**:
- Print `"Anton"` if Anton won more games
- Print `"Danik"` if Danik won more games
- Print `"Friendship"` if they won the same number of games

---

## Input
- Integer **n**  
- String of length **n** with only `'A'` and `'D'`

---

## Output
- One of:
  - `"Anton"`
  - `"Danik"`
  - `"Friendship"`

---

## Examples

### Example 1
**Input**
```

7
ADAAAAA

```

**Output**
```

Anton

```

**Explanation**

Count of wins:
- Anton: 6
- Danik: 1

Anton won more games.

---

### Example 2
**Input**
```

6
DDDAAA

```

**Output**
```

Friendship

```

**Explanation**

- Anton: 3
- Danik: 3

They are tied → `"Friendship"`

---

### Example 3
**Input**
```

5
DDDDD

```

**Output**
```

Danik

```

**Explanation**

- Anton: 0
- Danik: 5

Danik won more games.

---

## Solution Idea
- Count the number of `'A'` in the string → Anton's wins
- Count the number of `'D'` → Danik's wins
- Compare the two counts:
  - Anton > Danik → `"Anton"`
  - Anton < Danik → `"Danik"`
  - Anton == Danik → `"Friendship"`

---

## Important Notes
- String only contains `'A'` and `'D'`
- Simple counting is enough; no need for complex operations

---

## Complexity
- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(1)` (if counts are tracked with two variables)

---

## Key Insight
The problem reduces to **counting letters** and comparing them.