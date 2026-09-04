# Problem 277A – Learning Languages

## Problem Statement

The "BerCorp" company has `n` employees and `m` official languages (numbered 1 to m). Each employee knows a list of languages (possibly empty). The company can pay for employees to learn new languages, with each language course costing 1 berdollar per employee.

We need to find the **minimum cost** so that every employee can communicate with every other employee, possibly through intermediaries who can translate.

**Key points:**
- Communication can be indirect (employee A → B → C).
- An employee can learn any number of new languages.
- If an employee knows 0 languages, they must learn at least one to be connected.

---

## Examples

### Example 1
```

Input:
5 5
1 2
2 2 3
2 3 4
2 4 5
1 5

Output:
0

```
**Explanation:** 
All employees are already connected through language chains (2–3–4–5). 
No lessons needed.

---

### Example 2
```

Input:
8 7
0
3 1 2 3
1 1
2 5 4
2 6 7
1 3
2 7 4
1 1

Output:
2

```
**Explanation:** 
Employee `1` learns language `2`, 
employee `8` learns language `4 → all` are connected.

---

### Example 3
```

Input:
2 2
1 2
0

Output:
1

```
**Explanation:** 
Employee `2` must learn language `2` (cost 1) to communicate with employee `1`.

---

## Solution Approach (Pseudo-code)

We can model this as a **graph connectivity** problem:
- Employees are nodes.
- If two employees share at least one language, they are directly connected.
- Employees who know the same language form a connected component.

**Algorithm:**
1. Read `n` (employees) and `m` (languages).
2. Initialize a DSU (Disjoint Set Union) of size `n`.
3. For each employee, read their known languages:
   - Store the employee index in a list for each language.
4. For each language, union all employees that know that language (they are connected).
5. Count the number of connected components among employees.
6. Special case: If **all employees know zero languages**, then each must learn a language → answer = `n`.
7. Otherwise, if there are `components` groups, we can connect them by teaching one language to one employee from each group → cost = `components - 1`.

**Time Complexity:** 
`O(n + m + total languages) ≤ O(100²)` → very fast.

---

## Pseudo-code

```

function solve():
read n, m
dsu = new DSU(n)
language_lists = array of size m (each stores list of employees)
all_zero = true
for i from 0 to n-1:
    read k
    if k > 0: all_zero = false
    for j from 0 to k-1:
        read lang
        lang--  // convert to 0-based
        language_lists[lang].push_back(i)

// Connect employees who know the same language
for lang from 0 to m-1:
    if language_lists[lang] is not empty:
        first = language_lists[lang][0]
        for each emp in language_lists[lang] (starting from index 1):
            dsu.unite(first, emp)

// Count connected components
components = 0
for i from 0 to n-1:
    if dsu.find(i) == i:
        components++

if all_zero:
    print n
else:
    print components - 1
```

---

**DSU Functions:**
- `find(x)`: returns the representative of the set containing `x`.
- `unite(a, b)`: merges the sets containing `a` and `b`.

---