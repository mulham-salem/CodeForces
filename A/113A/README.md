# Problem 113A – Grammar Lessons

## Idea

Petya created a very simple language where every word belongs to:

- Adjective
- Noun
- Verb

And every word has a gender:

- Masculine
- Feminine

Each type has a specific suffix.

The task is to determine whether the given sequence of words forms **exactly one valid sentence**.

---

## Rules

A valid sentence must satisfy:

1. Every word has a valid suffix.
2. All words have the same gender.
3. Words appear in this order:

```text
[ adjectives ] [ exactly one noun ] [ verbs ]
```

Meaning:

- Zero or more adjectives
- Exactly one noun
- Zero or more verbs

---

## Valid Suffixes

| Type | Masculine | Feminine |
|---|---|---|
| Adjective | `lios` | `liala` |
| Noun | `etr` | `etra` |
| Verb | `initis` | `inites` |

---

## Example 1

### Input
```text
nataliala kataliala vetra feinites
```

### Breakdown

| Word | Type | Gender |
|---|---|---|
| nataliala | adjective | feminine |
| kataliala | adjective | feminine |
| vetra | noun | feminine |
| feinites | verb | feminine |

Correct order and same gender.

### Output
```text
YES
```

---

## Example 2

### Input
```text
etis atis animatis
```

Some words do not have valid suffixes.

### Output
```text
NO
```

---

## Pseudocode

```text
read all words

for each word:
    determine its type and gender using suffix
    if suffix is invalid:
        print NO

check that all words have same gender

count nouns
if noun count != 1:
    print NO

verify order:
    adjectives -> noun -> verbs

if everything is valid:
    print YES
else:
    print NO
```

---

## Complexity

- Time Complexity: `O(n)`
- Space Complexity: `O(n)`

---