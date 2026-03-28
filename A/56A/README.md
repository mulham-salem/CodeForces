# Problem 56A – Bar

## 🧩 Problem Summary
Vasya is checking whether a bar follows the law:

> People under 18 are **not allowed** to drink alcohol.

There are `n` people. For each person, Vasya knows **only one thing**:
- either their **age** (integer),  
- or their **drink** (string).

He can **check a person** to know both their age and drink.

### 🎯 Goal
Find the **minimum number of people** Vasya must check to ensure that  
**no one under 18 is drinking alcohol**.

---

## 🍺 Alcohol List
Only the following drinks are considered alcohol:

ABSINTH, BEER, BRANDY, CHAMPAGNE, GIN, RUM, SAKE, TEQUILA, VODKA, WHISKEY, WINE

---

## 💡 Key Idea

We only need to check **suspicious people**:

| Case | Description | Action |
|------|------------|--------|
| 👶 Age < 18 | Could be drinking alcohol | ✅ Check |
| 🍺 Alcohol drink | Could be under 18 | ✅ Check |
| ✅ Age ≥ 18 | Definitely legal | ❌ Ignore |
| 🥤 Non-alcohol drink | No violation | ❌ Ignore |

---

## 📥 Example

### Input

5 18 VODKA COKE 19 17

### Step-by-step

| Person | Info   | Reason | Check? |
|--------|--------|--------|--------|
| 1 | 18 | Age ≥ 18 | ❌ |
| 2 | VODKA | Alcohol | ✅ |
| 3 | COKE | Not alcohol | ❌ |
| 4 | 19 | Age ≥ 18 | ❌ |
| 5 | 17 | Age < 18 | ✅ |

---

### Output

2

---

## 🧠 Pseudocode

```
read n initialize must_check = 0

define alcohol_list

repeat n times: read desc

if desc is a number:
    convert to integer age
    if age < 18:
        must_check++

else:
    if desc is in alcohol_list:
        must_check++

print must_check
```

---

## ⚙️ Notes

- You must distinguish between **numbers (ages)** and **strings (drinks)**.
- String comparison is **not numeric**, so convert to integer when needed.
- Use a **set or array** to store alcohol drinks for fast lookup.

---