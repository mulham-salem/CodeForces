# Problem 8A – Train and Peter

## 📌 Problem Summary

This problem is from Codeforces.

Peter was traveling by train and observed the sequence of flag colors at railway stations.  
He woke up twice during the journey and recorded:

- `A1` — the sequence seen during the first wake period  
- `A2` — the sequence seen during the second wake period  

You are given:

- `S` — the full sequence of station flags from **A → B**
- `A1`
- `A2`

The train from **B → A** passes the same stations in reverse order.

Your task is to determine whether Peter could have seen these sequences:

- only in forward direction  
- only in backward direction  
- in both directions  
- or in neither direction  

---

## 🔎 Key Observations

- `A1` must appear before `A2`
- `A2` must appear **after the end of `A1`**
- Overlapping is not allowed
- The train never stops or revisits a station
- We must check both:
  - `S`
  - `reverse(S)`

---

## ✅ What We Need To Check

For a given direction:

1. Find `A1` inside `S`
2. Starting from the index **after `A1` ends**, search for `A2`
3. If both are found → valid direction

Repeat the same logic for the reversed string.

---

## 📘 Example 1

Input:
```

S  = atob
A1 = a
A2 = b

```

Forward:
```

a t o b
^     ^
A1    A2

```
Valid ✔

Backward (`bota`):
Sequence does not match ✖

Output:
```

forward

```

---

## 📘 Example 2

Input:
```

S  = aaacaaa
A1 = aca
A2 = aa

```

Both forward and backward directions satisfy the condition.

Output:
```

both

```

---

## 🧠 Algorithm Idea

We create a helper function:

```

function check(S, A1, A2):
pos1 = find A1 in S
if pos1 not found:
return false

```
pos2 = find A2 starting from pos1 + length(A1)
if pos2 not found:
    return false

return true
```

```

Then:

```

isForward  = check(S, A1, A2)
isBackward = check(reverse(S), A1, A2)

if isForward and isBackward:
print "both"
else if isForward:
print "forward"
else if isBackward:
print "backward"
else:
print "fantasy"

```

---

## ⏱ Complexity

- Searching uses string find
- Each check runs in linear time
- Overall complexity: **O(n)**

---

## 🎯 Final Output Options

- `forward`
- `backward`
- `both`
- `fantasy`