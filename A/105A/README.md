# Problem 105A – Transmigration

## 📌 Problem Summary

A character has several skills with experience levels.

After transmigration:

1. Every skill level is reduced by coefficient `k`.
2. Keep only skills with final level `>= 100`.
3. Add all skills of the new class:
   - If the skill already exists → keep its level.
   - Otherwise → add it with level `0`.
4. Print all final skills in lexicographical order.

---

## 🧠 Example

### Input

```text
5 4 0.75

axe 350
impaler 300
ionize 80
megafire 120
magicboost 220

heal
megafire
shield
magicboost
```

---

### Step 1 - Reduce Skill Levels

Skill	Old	New

axe	350	262
impaler	300	225
ionize	80	60
megafire	120	90
magicboost	220	165



---

### Step 2 - Remove Skills Below 100

Removed:

ionize

megafire


Remaining:

axe 262

impaler 225

magicboost 165



---

### Step 3 - Add New Class Skills

New class skills:

heal

megafire

shield

magicboost


Added:

heal → 0

megafire → 0

shield → 0


magicboost already exists, so its level stays 165.


---

#### Final Skills

axe 262
heal 0
impaler 225
magicboost 165
megafire 0
shield 0


---

## 💡 Main Idea

Use a map<string, int> to:

store skills and levels

search quickly by skill name

automatically keep skills sorted lexicographically



---

## 📝 Pseudocode
```
read n, m, k

create map skills

repeat n times:
    read name, exp

    newExp = floor(exp * k)

    if newExp >= 100:
        skills[name] = newExp

repeat m times:
    read name

    if name does not exist in skills:
        skills[name] = 0

print size of skills

for every skill in skills:
    print name and level
```
---