# Problem 110A – Nearly Lucky Number

## Problem Description
You are given a number `n`.  
A number is called **nearly lucky** if the **count of lucky digits** in it is itself a **lucky number**.

### Lucky Digits
Lucky digits are:
- `4`
- `7`

### Lucky Number
A number is **lucky** if it consists **only of digits 4 and 7**  
(order does not matter).

---

## What is Required?
1. Count how many times the digits **4** and **7** appear in the given number.
2. Store this count in a variable.
3. Check whether this count is a **lucky number**.
4. Print:
   - `YES` if it is nearly lucky
   - `NO` otherwise

---

## Examples

### Example 1
**Input**
```

4477

```
**Explanation**
- Count of `4` and `7` = 4
- `4` is a lucky number  
**Output**
```

YES

```

---

### Example 2
**Input**
```

444777

```
**Explanation**
- Count of `4` and `7` = 6
- `6` is **not** a lucky number  
**Output**
```

NO

```

---

### Example 3
**Input**
```

44774477

```
**Explanation**
- Count of `4` and `7` = 8
- `8` is **not** a lucky number  
**Output**
```

NO

```

---

### Example 4
**Input**
```

44447777

```
**Explanation**
- Count of `4` and `7` = 8 → Not lucky  
**Output**
```

NO

```

---

## Key Idea
> It is **not enough** that the count equals `4` or `7`.  
> The count itself must be composed **only** of digits `4` and `7`.

---

## Summary
- Count digits `4` and `7`
- Check the digits of the count
- If all digits are `4` or `7` → `YES`
- Otherwise → `NO`
