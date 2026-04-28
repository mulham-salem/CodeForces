# Problem 94A – Restoring Password

## 📌 Problem Statement

A password of **8 digits** was encrypted into a **binary string of length 80**.  
Each digit is encoded using a **10-character binary string**.

You are given:
- A binary string (length = 80)
- A mapping of 10 unique binary codes → digits (0 to 9)

Your task is to restore the original password.

---

## 🧠 Idea

- Split the 80-character string into **8 chunks**
- Each chunk has size **10**
- Each chunk represents **one digit**
- Use the mapping table to decode each chunk

---

## 🧪 Example

### Input

Encoded string: 010011001010010000101101111001...

Mapping: 0 → 0100110000
1 → 0100110010
2 → 0101100000
3 → 0101100010
...

---

### Step-by-step

#### 🔹 Split:

[0100110010] [1001000010] [1101111001] ...

#### 🔹 Decode:

0100110010 → 1 1001000010 → 3 1101111001 → 7 ...

#### 🔹 Result:

137.....

---

## ⚙️ Approach

- Read the 80-bit string
- Store mapping (binary → digit)
- Iterate over string in steps of 10
- Replace each chunk using the map
- Build final password

---

## ⏱ Complexity

Time Complexity: O(80) 
Space Complexity: O(10)

---

## 💡 Key Insight

This problem is a simple:

Split + Hash Lookup

Each 10-bit pattern uniquely represents one digit, so decoding is always direct.

---