# Problem 141A – Amusing Joke

## 🧩 Problem Summary
You are given three strings:

- `guest` – the guest's name  
- `host` – the host's name  
- `pile` – a pile of letters on the table  

Your task is to determine whether the third string (`pile`) is made **exactly** from all the letters of the first two strings (`guest` and `host`) combined.

---

## 📌 Rules
- All letters are **uppercase English letters**
- The **order of letters does not matter**
- The **count of each letter must match exactly**
- No extra letters and no missing letters are allowed

---

## ✅ Output
- Print `"YES"` if the pile can be formed from the guest's and host's names
- Print `"NO"` otherwise

---

## ✨ Examples

### Example 1
**Input**
```

guest = "ABC"
host  = "DEF"
pile  = "FEDCBA"

```

**Explanation**  
The pile contains exactly the same letters as `guest + host`.

**Output**
```

YES

```

---

### Example 2
**Input**
```

guest = "ANN"
host  = "BOB"
pile  = "ANANBB"

```

**Explanation**  
The pile is missing the letter `O` and has an extra `A`.

**Output**
```

NO

```

---

### Example 3
**Input**
```

guest = "A"
host  = "B"
pile  = "AB"

```

**Explanation**  
All letters are present with the correct counts.

**Output**
```

YES

```

---

## 🎯 Key Idea
The problem checks whether the third string is simply a **rearrangement** of all characters from the first two strings combined.

---