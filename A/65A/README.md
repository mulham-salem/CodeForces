# Problem 65A – Harry Potter and Three Spells

## Description
A famous alchemist taught Harry Potter three magical spells:

1. Convert a grams of sand into b grams of lead.


2. Convert c grams of lead into d grams of gold.


3. Convert e grams of gold into f grams of sand.



The goal is to determine whether it is possible to produce infinite gold starting from some finite amount of sand. Harry wants to know if he can generate unlimited gold (Ron is right), or if it's impossible due to conservation of matter (Hermione is right).

## Input
Six integers: a, b, c, d, e, f (0 ≤ a, b, c, d, e, f ≤ 1000) representing the conversion rules.

## Output
Print "Ron" if it's possible to generate infinite gold.
Print "Hermione" otherwise.


---

## Examples

### Input

```
100 200 250 150 200 250
```

### Output

```
Ron
```


### Input

```
100 50 50 200 200 100
```

### Output

```
Hermione
```

---

## Solution Idea

To solve this problem, check two main conditions:

1. Magic from nothing

If any spell can produce gold, lead, or sand from 0 units of the input material, then infinite gold is possible.



2. Profitable cycle

If all input materials exist (a, c, e > 0) and the cycle multiplies resources:

(b / a) * (d / c) * (f / e) > 1

then repeating the cycle infinitely produces unlimited gold.




If neither condition holds, producing infinite gold is impossible.


---

## Pseudocode

```
read a, b, c, d, e, f

# Case 1: produce gold from nothing
if c == 0 and d > 0:
    print "Ron"
    exit

# Case 2: produce lead from nothing then gold
if a == 0 and b > 0 and c > 0 and d > 0:
    print "Ron"
    exit

# Case 3: produce sand from nothing then gold
if e == 0 and f > 0 and a > 0 and b > 0 and c > 0 and d > 0:
    print "Ron"
    exit

# Case 4: check profitable cycle
if a > 0 and c > 0 and e > 0:
    if b * d * f > a * c * e:
        print "Ron"
        exit

# Otherwise
print "Hermione"
```

---