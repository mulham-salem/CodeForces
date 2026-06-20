# Problem 164A – Variable, or There and Back Again

## Overview

We are given a directed graph representing program states.

Each state has one of three types:

- `0` → Ignore the variable.
- `1` → Assign a value to the variable.
- `2` → Use the variable's value.

A state is considered **interesting** if it belongs to at least one valid path that:

1. Starts at an **Assign** state.
2. Ends at a **Use** state.
3. Does not pass through any other **Assign** state after the starting one.

For every state, determine whether it can be part of such a path.

---

## Example

### Input

```text
5 4
0 1 2 0 1
1 2
2 3
2 4
4 5
```

### Graph

```text
1
|
v
2 (Assign) ---> 3 (Use)
|
v
4 -------> 5 (Assign)
```

### Valid Path

```text
2 -> 3
```

This path:

- Starts at an Assign state.
- Ends at a Use state.
- Contains no other Assign state.

States `2` and `3` belong to a valid path.

### Output

```text
0 1 1 0 0
```

---

## Key Observation

A state is interesting if:

- It can be reached from an **Assign** state without passing through another Assign.
- A **Use** state can be reached from it without passing through an Assign.

If both conditions hold, the state lies on a valid Assign → Use path.

---

## Approach

Perform two graph traversals:

### 1. Forward Reachability

Start BFS/DFS from all Assign states.

While traversing:

- Mark all reachable states.
- Never continue through another Assign state.

This identifies states reachable from a valid Assign source.

### 2. Reverse Reachability

Build the reversed graph.

Start BFS/DFS from all Use states.

While traversing:

- Mark all reachable states.
- Stop expansion when an Assign state is encountered.

This identifies states that can reach a Use state.

### 3. Final Answer

A state is interesting if it satisfies both conditions.

---

## Pseudocode

```text
read graph

forward_reachable = BFS from all Assign states
(stop when reaching another Assign)

reverse_reachable = BFS from all Use states
on reversed graph
(do not continue beyond Assign states)

for each state i:
    if forward_reachable[i] AND reverse_reachable[i]:
        answer[i] = 1
    else:
        answer[i] = 0

output answers
```

---

## Complexity Analysis

- Time Complexity: `O(N + M)`
- Space Complexity: `O(N + M)`

Where:

- `N` = number of states
- `M` = number of transitions

---