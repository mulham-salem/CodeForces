# Problem 785A – Anton and Polyhedrons

## Problem Summary
Anton has **n polyhedrons**, each of a certain type:
- Tetrahedron → 4 faces
- Cube → 6 faces
- Octahedron → 8 faces
- Dodecahedron → 12 faces
- Icosahedron → 20 faces

Your task:

Calculate the **total number of faces** of all polyhedrons Anton has.

---

## Key Idea
- Read all polyhedron types.
- For each type, add the corresponding number of faces.
- Output the sum.

---

## Example 1

Input
3  
Icosahedron  
Cube  
Tetrahedron

Explanation
- Icosahedron → 20 faces  
- Cube → 6 faces  
- Tetrahedron → 4 faces  
Total faces = 20 + 6 + 4 = 30

Output
30

---

## Example 2

Input
5  
Tetrahedron  
Cube  
Octahedron  
Dodecahedron  
Icosahedron

Explanation
- 4 + 6 + 8 + 12 + 20 = 50

Output
50

---

## Pseudocode
read n
total_faces = 0
for i from 1 to n:
    read polyhedron_type
    if type == "Tetrahedron": total_faces += 4
    if type == "Cube": total_faces += 6
    if type == "Octahedron": total_faces += 8
    if type == "Dodecahedron": total_faces += 12
    if type == "Icosahedron": total_faces += 20
print total_faces

---

## Final Notes
- Simple mapping problem.
- Time complexity: O(n)
- Space complexity: O(1)
- Works for any valid input efficiently.
