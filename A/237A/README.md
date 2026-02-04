# Problem 237A – Free Cash

## Problem Overview
Valera owns a 24/7 fast food cafe.  
Each customer arrives at a specific time given in **hours and minutes**.  
Serving a customer takes **less than one minute**, and customers **do not wait** if all cash desks are busy.

The goal is to determine the **minimum number of cash desks** needed so that **all customers are served**.

---

## Key Observation
Since each service takes less than one minute:
- Customers arriving at **different minutes** do not overlap.
- Customers arriving at the **same hour and minute** must be served **simultaneously**.

Therefore:
> The minimum number of cash desks required is equal to the **maximum number of customers arriving at the same time**.

---

## Approach
1. Read all arrival times.
2. Treat each arrival time as a pair `(hour, minute)`.
3. Count how many times each time pair appears.
4. Find the **maximum frequency** among all times.
5. Output this maximum value.

---

## Example 1

### Input
```

4
8 0
8 10
8 10
8 45

```

### Explanation
- (8:00) → 1 customer
- (8:10) → 2 customers
- (8:45) → 1 customer

The maximum number of customers arriving at the same time is **2**.

### Output
```

2

```

---

## Example 2

### Input
```

3
0 12
10 11
22 22

```

### Explanation
All customers arrive at different times, so only **one cash desk** is needed.

### Output
```

1

```

---

## Pseudo Code

```

read n
create empty list times

for i from 1 to n:
read h, m
add (h, m) to times

create empty map frequency

for each time in times:
frequency[time]++

maxCashes = 0

for each entry in frequency:
maxCashes = max(maxCashes, entry.value)

print maxCashes

```

---

## Complexity Analysis
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n)

---

## Conclusion
By counting how many customers arrive at the same minute and taking the maximum count, we can determine the minimum number of cash desks required to serve all customers without waiting.

---