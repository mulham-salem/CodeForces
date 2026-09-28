# Problem 312A – Whose sentence is it?

A chat record contains `n` sentences. Freda always ends her sentences with `lala.`, and Rainbow always starts his sentences with `miao.`. For each sentence, determine who said it.

**Rules:**

| Condition | Result |
|-----------|--------|
| Starts with `miao.` AND does **not** end with `lala.` | `Rainbow's` |
| Ends with `lala.` AND does **not** start with `miao.` | `Freda's` |
| Starts with `miao.` AND ends with `lala.` | `OMG>.< I don't know!` |
| Neither condition satisfied | `OMG>.< I don't know!` |

---

## Examples

| Input | Output |
|-------|--------|
| `I will go to play with you lala.` | `Freda's` |
| `wow, welcome.` | `OMG>.< I don't know!` |
| `miao.lala.` | `OMG>.< I don't know!` |
| `miao.` | `Rainbow's` |
| `miao .` | `OMG>.< I don't know!` |

---

## Pseudocode

```

READ n
IGNORE rest of line

FOR i = 1 TO n:
	READ line s
	starts = (s begins with "miao.")
	ends   = (s length >= 5) AND (last 5 chars of s == "lala.")

	IF starts AND NOT ends:
		PRINT "Rainbow's"
	ELSE IF ends AND NOT starts:
		PRINT "Freda's"
	ELSE:
		PRINT "OMG>.< I don't know!"
END FOR

```

---

| Complexity | Value |
|------------|-------|
| Time | `O(n · L)` |
| Space | `O(L)` |

Where `L` is the sentence length (≤ 100) and `n` is the number of sentences (≤ 10).

---