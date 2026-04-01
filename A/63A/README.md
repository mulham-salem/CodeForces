# Problem 63A – Sinking Ship

## 🧠 Overview
You are given a list of crew members standing in a line on a sinking ship.  
Each member has a **name** and a **status**.

Your task is to determine the correct order in which they should evacuate the ship based on priority rules.

---

## 🚨 Evacuation Rules

The crew must leave the ship in the following priority:

| Priority | Group                |
|----------|---------------------|
| 1        | Rats                |
| 2        | Women & Children    |
| 3        | Men                 |
| 4        | Captain             |

- If two people belong to the **same group**, they leave in the **same order as the input** (left to right).

---

## 📥 Input

- Integer `n` — number of crew members  
- Next `n` lines:

name status

### Example

```
6 
Jack captain
Alice woman 
Charlie man 
Teddy rat 
Bob child 
Julia woman
```

---

## 📤 Output

Print the **names only**, one per line, in the correct evacuation order.

### Example

```
Teddy 
Alice 
Bob 
Julia 
Charlie 
Jack
```

---

## 💡 Key Idea

This problem is essentially about:

- **Grouping people by priority**
- **Maintaining original order within each group**

---

## 🧩 Approach

1. Read all crew members
2. Divide them into 4 groups:
   - rats
   - women & children
   - men
   - captain
3. Print groups in priority order

---

## 📝 Pseudocode

```
read n

initialize:
    rats = empty list
    women_children = empty list
    men = empty list
    captain = ""

for i from 1 to n:
    read name, status

    if status == "rat":
        add name to rats

    else if status == "woman" or status == "child":
        add name to women_children

    else if status == "man":
        add name to men

    else if status == "captain":
        captain = name

print all names in rats
print all names in women_children
print all names in men
print captain
```

---

## ⏱ Complexity

Time: O(n)

Space: O(n)


---

## ✅ Summary

Sort by priority groups

Preserve input order within each group

Print in the correct sequence

---