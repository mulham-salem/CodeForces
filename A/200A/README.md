# Problem 200A – Cinema

## 📌 Problem Statement

A cinema has `n` rows, and each row contains `m` seats.

There are `k` people in a queue. Each person has a preferred seat `(x, y)`.

When a person reaches the ticket office:

- If the preferred seat is empty, they take it.
- Otherwise, they choose another empty seat according to these rules:

1. Minimize the Manhattan distance:

$$
|x_1 - x_2| + |y_1 - y_2|
$$

2. If multiple seats have the same distance:
   - Choose the seat with the smallest row number.
   - If rows are equal, choose the seat with the smallest column number.

The goal is to determine the final seat assigned to every person.

---

## 📥 Input

The first line contains:
```
n m k
```
Where:

| Variable | Meaning |
|----------|---------|
| `n` | Number of rows |
| `m` | Number of seats in each row |
| `k` | Number of people |

The next `k` lines contain:
```
x y
```
The preferred seat coordinates of each person in queue order.

---

## 📤 Output

Print `k` lines.

Each line contains:
```
row column
```
representing the seat assigned to that person.

---

# 💡 Examples

## Example 1

### Input

```text
3 4 6
1 1
1 1
1 1
1 2
1 3
1 3
```
### Explanation

The first person gets (1,1) because it is available.

The next people want already occupied seats, so they choose the nearest available seats according to the rules.

### Output
```text
1 1
1 2
2 1
1 3
1 4
2 3
```

---

## Example 2

### Input
```text
4 3 12
2 2
2 2
2 2
2 2
2 2
2 2
2 2
2 2
2 2
2 2
2 2
2 2
```
### Explanation

All people want the same seat (2,2).

The first person takes it, and the others are assigned the closest available seats while respecting the tie-breaking rules.

### Output
```text
2 2
1 2
2 1
2 3
3 2
1 1
1 3
3 1
3 3
4 2
4 1
4 3
```

---

# 🧠 Solution Idea

Checking every seat for every person is too slow.

The solution uses Disjoint Set Union (DSU) to quickly find the closest available seats.

For every seat, we store four links:

| Link | Purpose |
|----------|---------|
| `left` | Closest free seat on the left |
| `right` | Closest free seat on the right |
| `up` | Closest free seat above |
| `down` | Closest free seat below |
	

When a seat is occupied, these links are updated so future searches can skip occupied seats.


---

# 🔍 Searching Process

For a person who wants (x, y):

**Case 1**: Seat is available

Take it directly.


**Case 2**: Seat is occupied

Search rows around x:

`d = 0 → row x`

`d = 1 → rows x-1 and x+1`

`d = 2 → rows x-2 and x+2`

...

For each checked row:

Find the closest free seat to the left of y.

Find the closest free seat to the right of y.


Then choose the best candidate:

1. Minimum Manhattan distance.


2. Minimum row number.


3. Minimum column number.

---

# 📝 Pseudocode
```text
Initialize DSU:

For every seat:

    left  = its column
    right = its column
    up    = its row
    down  = its row


Function FIND:

    If current node points to itself:

        return current position

    Otherwise:

        Find the parent recursively
        Compress the path
        Return the result



Function MARK(row, column):

    Mark seat as occupied

    Update:

        left  = nearest free seat on the left
        right = nearest free seat on the right
        up    = nearest free seat above
        down  = nearest free seat below



For each person:

    Read preferred seat (x, y)

    If (x, y) is empty:

        MARK(x, y)
        Print it


    Else:

        bestSeat = none

        For increasing distance d:

            Check row x-d

                Check nearest free seat left
                Check nearest free seat right


            Check row x+d

                Check nearest free seat left
                Check nearest free seat right


            Update bestSeat


        MARK(bestSeat)

        Print bestSeat
```

---

# ⏱ Complexity Analysis

**Time Complexity**

The DSU operations are almost O(1) because of path compression.

The solution avoids scanning all seats and only checks necessary candidates.

`O(k * number_of_checked_rows)`

**Space Complexity**

`O(n × m)`


---

# 🔑 Key Concepts

**Greedy selection**

**Manhattan distance**

**Disjoint Set Union (DSU)**

**Path Compression**

**Efficient simulation**

---