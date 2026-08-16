# Problem 245A – System Administrator

## Problem

Polycarpus manages two servers: `a` and `b`.

He performs `ping` commands, and each command sends exactly **10 packets** to one server.

Each command gives two values:

- `x` — the number of packets that successfully reached the server.
- `y` — the number of lost packets.

Always:

`x + y = 10`

A server is considered **LIVE** if at least half of all packets sent to it were successfully received.

Otherwise, it is **DEAD**.

---

## Input

- The first line contains an integer `n` — the number of ping commands.
- Each of the next `n` lines contains three integers `t`, `x`, and `y`:
  - `t = 1` means the command was sent to server `a`.
  - `t = 2` means the command was sent to server `b`.
  - `x` is the number of successfully received packets.
  - `y` is the number of lost packets.

It is guaranteed that there is at least one ping command for each server.

---

## Output

Print the state of server `a` in the first line and the state of server `b` in the second line.

For each server, print:

- `LIVE` if at least half of its packets were received successfully.
- `DEAD` otherwise.

---

## Examples

### Example 1

**Input:**

    2
    1 5 5
    2 6 4

**Output:**

    LIVE
    LIVE

Server `a` received `5` out of `10` packets, which is exactly half.

Server `b` received `6` out of `10` packets, which is more than half.

Therefore, both servers are `LIVE`.

---

### Example 2

**Input:**

    3
    1 0 10
    2 0 10
    1 10 0

**Output:**

    LIVE
    DEAD

Server `a` received `10` out of `20` packets, which is exactly half, so it is `LIVE`.

Server `b` received `0` out of `10` packets, which is less than half, so it is `DEAD`.

---

## Approach

Since every ping sends exactly `10` packets, half of one ping is `5` packets.

For each server:

1. Count how many ping commands were sent to it.
2. Sum the number of successfully received packets.
3. The server is `LIVE` if the received packets are at least:
   `number of pings × 5`.
4. Otherwise, it is `DEAD`.

---

## Pseudocode
```
    read n

    receivedA = 0
    pingsA = 0

    receivedB = 0
    pingsB = 0

    repeat n times:
        read t, x, y

        if t == 1:
            receivedA += x
            pingsA += 1
        else:
            receivedB += x
            pingsB += 1

    if receivedA >= pingsA * 5:
        print "LIVE"
    else:
        print "DEAD"

    if receivedB >= pingsB * 5:
        print "LIVE"
    else:
        print "DEAD"
```
---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

---