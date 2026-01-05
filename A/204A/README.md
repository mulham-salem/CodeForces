# Problem 204A – Elephant and Rozdil

## Problem Summary
An elephant wants to travel to one of n cities.
Each city has a known travel time.

Your task:

Determine the city with the minimum travel time.
If the minimum travel time appears more than once, print:
Still Rozdil
Otherwise, print the 1-based index of the city with the minimum travel time.

## Key Idea
Store all travel times.
Find the minimum travel time.
Count how many times this minimum appears.
If it appears more than once, the result is ambiguous.

## Example 1

Input
4
5 2 3 4

Explanation
Minimum travel time = 2
The value 2 appears once.
So the elephant chooses city number 2.

Output
2

## Example 2

Input
5
1 3 1 4 2

Explanation
Minimum travel time = 1
The value 1 appears twice.
More than one city has the same minimum travel time.

Output
Still Rozdil

## Pseudocode
read n
read array times

min_time = very large value
position = 0

for each city:
    if time < min_time:
        min_time = time
        position = city index

count how many times min_time appears

if count > 1:
    print Still Rozdil
else:
    print position + 1

## Final Notes
City indices are 0-based, output must be 1-based.
Time complexity is O(n).
The solution is simple and efficient.