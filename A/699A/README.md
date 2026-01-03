# Problem 699A – Launch of Collider

## Requirement
You are given:

- Three integers `h`, `m`, `s` — representing **hours, minutes, seconds** of a clock (24-hour format)

Your task:

- Convert this time into **angles of the clock hands**:
  1. Hour hand
  2. Minute hand
  3. Second hand  

- All angles should be measured in **degrees** relative to the **12 o’clock position**, clockwise.

---

## Input
```

h m s

```

Constraints:
- 0 ≤ h < 24  
- 0 ≤ m < 60  
- 0 ≤ s < 60

---

## Output
Three numbers:
```

hour_angle minute_angle second_angle

```

- Each angle is a floating-point number.
- Print **up to 10^-9 precision** (or high enough)

---

## Explanation
- Clock angles are calculated as follows:

### Second Hand
```

second_angle = s * 6

```
(360° / 60 seconds = 6° per second)

### Minute Hand
```

minute_angle = m * 6 + s * 0.1

```
(6° per minute + 0.1° per second contribution)

### Hour Hand
```

hour_angle = (h % 12) * 30 + m * 0.5 + s * (0.5 / 60)

```
- 30° per hour  
- 0.5° per minute  
- 0.5/60° per second

---

## Example 1

### Input
```

3 0 0

```

### Output
```

90 0 0

```

Explanation:
- Hour hand: 3 × 30 = 90°  
- Minute hand: 0  
- Second hand: 0

---

## Solution Idea
1. Convert hours to 12-hour format: `h % 12`  
2. Multiply by 30° for hours, add minute/second contributions  
3. Multiply minutes by 6°, add second contribution  
4. Multiply seconds by 6°  
5. Output three angles

---

## Important Notes
- Pay attention to floating-point precision  
- Use double/float in code  
- All hands move continuously (not just discrete steps)

---

## Complexity
- **Time Complexity:** O(1)  
- **Space Complexity:** O(1)

---

## Key Insight
Clock hands move continuously; **minute and second contributions affect hour and minute angles**.  
Use simple arithmetic formulas to calculate exact angles.
