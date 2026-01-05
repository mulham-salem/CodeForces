# Problem 767A – Snacktower

## Problem Summary
Polycarp has n snacks, each with a unique size from 1 to n.
Snacks arrive one by one in some order.

Your task:

After each snack arrives, determine which snacks can be eaten.

Rules:
Polycarp can only eat snacks in decreasing order of size,
starting from size n down to 1.
If the next required size has not arrived yet, he must wait.

---

## Key Idea
Keep track of which snack sizes have already arrived.

Always try to eat starting from the largest available size.
When the current needed size arrives, eat it and continue eating
smaller sizes as long as they are already present.

---

## Example

Input
5
4 5 1 2 3

Explanation
Snacks arrive in this order:

Arrival 1: 4
Cannot eat yet (waiting for 5)

Arrival 2: 5
Now can eat 5 and then 4

Output
5 4

Arrival 3: 1
Cannot eat (waiting for 3)

Output
(empty)

Arrival 4: 2
Still waiting for 3

Output
(empty)

Arrival 5: 3
Now can eat 3, 2, 1

Output
3 2 1

---

## Pseudocode
read n
read array arrivals

create boolean array seen of size n
current = n

for each arriving snack x:
    mark seen[x] = true
    while current > 0 and seen[current] is true:
        print current
        current--
    print new line

---

## Final Notes
Each snack is eaten exactly once.
Time complexity is O(n).
Space complexity is O(n).
Greedy simulation problem with simple logic.