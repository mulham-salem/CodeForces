# Problem 205A – Little Elephant and Rozdil

## 📖 Problem Summary

The Little Elephant wants to leave **Rozdil** and travel to another city.

You are given the travel time from Rozdil to each city. The Elephant will choose the city with the **smallest travel time**.

- If **exactly one** city has the minimum travel time, print its index.
- If **multiple cities** share the minimum travel time, the Elephant decides not to travel and stays in Rozdil.

---

## 📥 Input

- The first line contains an integer `n` — the number of cities.
- The second line contains `n` integers, where the `i`-th integer represents the travel time to city `i`.

### Constraints

- `1 ≤ n ≤ 10^5`
- `1 ≤ travel time ≤ 10^9`

---

## 📤 Output

- Print the **1-based index** of the city with the unique minimum travel time.
- Otherwise, print:

```text
Still Rozdil
```

---

## 💡 Examples

### Example 1

**Input**
```text
2
7 4
```

**Output**
```text
2
```

**Explanation**

The smallest travel time is `4`, and it belongs only to city **2**, so the answer is `2`.

---

### Example 2

**Input**
```text
7
7 4 47 100 4 9 12
```

**Output**
```text
Still Rozdil
```

**Explanation**

The minimum travel time is `4`, but it appears for **two cities** (2 and 5), so there is no unique closest city.

---

## 🧠 Idea

Traverse the travel times once while keeping track of:

- The current minimum travel time.
- The index of the city with that minimum.
- How many times the minimum value appears.

At the end:

- If the minimum appears only once, print its city index.
- Otherwise, print `"Still Rozdil"`.

---

## 🔹 Pseudocode

```text
Read n

minTime = INF
cityIndex = -1
countMin = 0

For i = 1 to n
    Read time

    If time < minTime
        minTime = time
        cityIndex = i
        countMin = 1

    Else if time == minTime
        countMin++

If countMin == 1
    Print cityIndex
Else
    Print "Still Rozdil"
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---