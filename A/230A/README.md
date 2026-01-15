# Problem 230A – Dragons

## 🧠 Problem Summary
You start with an initial strength `s` and face `n` dragons.
Each dragon has:
- `x` → its strength
- `y` → bonus strength gained after defeating it

You can defeat a dragon **only if** your current strength is **strictly greater** than the dragon’s strength.
After defeating a dragon, your strength increases by its bonus.

The goal is to determine whether you can defeat **all dragons**.

---

## 📥 Input
- Two integers `s` and `n`
- `n` pairs of integers `(x, y)` representing each dragon

---

## 📤 Output
- `"YES"` if you can defeat all dragons
- `"NO"` otherwise

---

## 💡 Key Idea
The order of fighting dragons matters.

To maximize your chance of success:
- Always fight the **weakest available dragon first**.
- This is a **greedy strategy**.

Why?
Defeating weaker dragons first increases your strength, making stronger dragons easier later.

---

## 🧩 Step-by-Step Strategy
1. Read all dragons as `(strength, bonus)` pairs.
2. Sort the dragons by `strength` in **ascending order**.
3. Iterate through the sorted list:
   - If current strength `s` is not greater than the dragon’s strength → fail immediately.
   - Otherwise, defeat the dragon and add its bonus to `s`.
4. If all dragons are defeated, output `"YES"`.

---

## 📝 Pseudocode
```text
read s, n
read list of dragons (x, y)

sort dragons by x ascending

for each dragon in dragons:
    if s <= dragon.x:
        output "NO"
        exit
    s += dragon.y

output "YES"
````

---

## 📌 Example

### Input

```
s = 2, n = 2
Dragons:
(1, 2)
(3, 1)
```

### Explanation

* Fight dragon (1,2): 2 > 1 → new strength = 4
* Fight dragon (3,1): 4 > 3 → new strength = 5
* All dragons defeated → **YES**

---

### Failing Example

```
s = 2, n = 1
Dragon:
(2, 5)
```

* 2 is not greater than 2 → cannot defeat the dragon
* Output = **NO**

---

## ✅ Conclusion

* Sorting dragons by strength is essential.
* This problem is a classic **greedy algorithm**.
* Any failure during the process means the answer is `"NO"`.

---

Happy coding 🚀

---
