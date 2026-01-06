# Problem 799A – Carrot Cakes

## Requirement
You are given four integers:

- **n** — number of cakes needed
- **t** — time (in minutes) to bake one batch
- **k** — number of cakes baked in one batch
- **d** — time needed to build a second oven

Initially, you have **one oven**.
You may build a **second oven**, but it becomes available only after **d minutes**.

Your task is to determine whether building the second oven allows you
to bake all **n cakes strictly faster**.

---

## Input
Four integers:
```

n t k d

```

---

## Output
Print:
- **YES** — if using a second oven makes baking faster
- **NO** — otherwise

---

## Example 1
**Input**
```

8 6 4 5

```

**Output**
```

YES

```

**Explanation**

One oven:
- Each batch bakes 4 cakes in 6 minutes
- To bake 8 cakes → 2 batches → 12 minutes

With second oven:
- Second oven is ready at minute 5
- First batch finishes at minute 6 (4 cakes)
- Second oven helps bake the next batch sooner
- Total time is less than 12 minutes

---

## Example 2
**Input**
```

8 6 4 100

```

**Output**
```

NO

```

**Explanation**

The second oven is built too late to be useful.
All cakes are already baked using one oven.

---

## Solution Idea
1. Compute the total time needed using **only one oven**.
2. Simulate the process when building a **second oven**.
3. If the total time with two ovens is **strictly less**, print `YES`.
4. Otherwise, print `NO`.

---

## Algorithm
1. Calculate time with one oven:
   - Number of batches = ceil(n / k)
   - Total time = batches × t
2. Simulate baking with two ovens:
   - Track cake production over time
   - Second oven starts working after `d` minutes
3. Compare the two times.

---

## Complexity
- **Time Complexity:** O(n / k)
- **Space Complexity:** O(1)

---

## Key Insight
If the second oven starts producing cakes before the first oven
finishes all required batches, it may reduce the total baking time.
Otherwise, it is useless.