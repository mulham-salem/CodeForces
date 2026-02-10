# Problem 5A – Chat Server's Outgoing Traffic

## 📝 Problem Summary
Polycarp implemented a chat server that processes a sequence of commands.  
Each command is one of the following:

- **Add** a user to the chat
- **Remove** a user from the chat
- **Send** a message from a user to all users currently in the chat (including the sender)

Your task is to calculate the **total outgoing traffic** produced by the server.

---

## 📜 Command Types

### 1️⃣ Add Command
```

+name

```
- Adds a user to the chat
- Produces **no traffic**

---

### 2️⃣ Remove Command
```

-name

```
- Removes a user from the chat
- Produces **no traffic**

---

### 3️⃣ Send Command
```

sender_name:message_text

```
- Sends a message to **all current users**
- The server sends `L` bytes to **each user**, where `L` is the length of the message
- The sender also receives the message

---

## 📦 Traffic Calculation
For each **Send** command:

```

traffic += (length of message) × (number of users currently in chat)

````

- Message length counts **letters, digits, and spaces**
- The message may be **empty** (length = 0)

---

## 📌 Important Notes
- Add and Remove commands do not generate traffic
- All commands are valid
- Names are **case-sensitive**
- Input size is small, but the number of commands is **unknown**
- Commands should be processed until **end of input (EOF)**

---

## 📊 Examples

| Command | Users in Chat | Message Length | Traffic Added |
|-------|---------------|----------------|---------------|
| `Mike:hello` | 1 | 5 | 5 |
| `Kate:hi` | 2 | 2 | 4 |

---

## 🧠 Pseudocode

```text
initialize traffic = 0
initialize current_users_count = 0

while there is a new input line:
    read the line

    if line starts with '+':
        current_users_count++

    else if line starts with '-':
        current_users_count--

    else:
        extract message part after ':'
        message_length = length of message
        traffic += message_length × current_users_count

print traffic
````

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(N), where N is the number of commands
* **Space Complexity:** O(1)