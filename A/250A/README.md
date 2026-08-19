# Problem 250A – Paper Work

## Problem

Polycarpus needs to divide `n` consecutive daily reports into the minimum number of folders.

Each report contains a value `ai`:

- If `ai < 0`, the company suffered a **loss** that day.
- Otherwise, there was no loss.

A folder may contain reports from consecutive days only.

The manager gets angry if a folder contains **3 or more loss days**.

Therefore, every folder can contain at most **2 negative values**.

The goal is to find the **minimum number of folders** and output the size of each folder.

---

## Input

- The first line contains an integer `n` — the number of days.
- The second line contains `n` integers `a1, a2, ..., an`.

Constraints:

- `1 ≤ n ≤ 100`
- `|ai| ≤ 100`

---

## Output

Print:

1. The minimum number of folders `k`.
2. `k` integers `b1, b2, ..., bk`, where `bj` is the number of reports in the `j`-th folder.

The sum of all folder sizes must be exactly `n`.

Any valid optimal division is accepted.

---

## Approach

Use a **Greedy** approach.

Traverse the days from left to right while keeping:

- `currentSize` — the number of reports in the current folder.
- `negativeCount` — the number of negative values in the current folder.

For every value:

1. Add it to the current folder.
2. If it is negative, increase `negativeCount`.
3. If `negativeCount` becomes `3`, the current folder is invalid.
4. Close the previous folder and start a new folder with the current day.
5. Continue until all days are processed.

Finally, add the last folder.

The key observation is that whenever adding the current day would create a third loss, we must start a new folder from that day. This produces the minimum number of folders.

---

## Example 1

### Input

```text
11
1 2 3 -4 -5 -6 5 -5 -6 -7 6
```
One optimal division is:
```
1 2 3 -4 -5 | -6 5 -5 | -6 -7 6
```
Folder sizes:
```
5 3 3
```
Each folder contains at most two negative values.

### Output
```
3
5 3 3
```

---

## Example 2

### Input
```
5
0 -1 100 -1 0
```
There are only two negative values, so all reports can be placed in one folder:
```
0 -1 100 -1 0
```
### Output
```
1
5
```

---

## Pseudocode
```
read n
read array a

folders = empty list
currentSize = 0
negativeCount = 0

for each value x in a:

    if x < 0:
        negativeCount++

    if negativeCount > 2:
        add currentSize to folders

        currentSize = 1
        negativeCount = 1
    else:
        currentSize++

add currentSize to folders

print number of folders
print sizes of all folders
```

---

## Complexity

**Time:** `O(n)`

**Space:** `O(n)`

---