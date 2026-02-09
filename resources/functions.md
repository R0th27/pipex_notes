# Functions

## 1. Memory related

### `malloc`

Allocates heap memory.
**Success:** pointer to memory
**Fail:** `NULL`
**errno:** ✅ yes

---

### `free`

Releases allocated heap memory.
**Success:** none
**Fail:** undefined behavior if invalid pointer
**errno:** ❌ no

---

## 2. File-descriptor related

### `access`

Checks file existence or permissions.
**Success:** `0`
**Fail:** `-1`
**errno:** ✅ yes

---

### `open`

Opens a file and returns a file descriptor.
**Success:** fd ≥ 0
**Fail:** `-1`
**errno:** ✅ yes

---

### `close`

Closes a file descriptor.
**Success:** `0`
**Fail:** `-1`
**errno:** ✅ yes

---

### `read`

Reads data from fd into buffer.
**Success:** number of bytes read (`0` = EOF)
**Fail:** `-1`
**errno:** ✅ yes

---

### `write`

Writes data from buffer to fd.
**Success:** number of bytes written
**Fail:** `-1`
**errno:** ✅ yes

---

### `pipe`

Creates a unidirectional data channel.
**Success:** `0`
**Fail:** `-1`
**errno:** ✅ yes

---

### `dup`

Duplicates an fd to the lowest available fd number.
**Success:** new fd
**Fail:** `-1`
**errno:** ✅ yes

---

### `dup2`

Duplicates an fd to a specific fd number.
**Success:** new fd
**Fail:** `-1`
**errno:** ✅ yes

---

### `unlink`

Removes a filename from the filesystem.
**Success:** `0`
**Fail:** `-1`
**errno:** ✅ yes

---

## 3. Error related

### `perror`

Prints a message followed by the current `errno` string.
**Success:** none
**Fail:** none
**errno:** ❌ no (reads it only)

---

### `strerror`

Converts an errno value to a string.
**Success:** pointer to string
**Fail:** implementation-defined
**errno:** ❌ no

---

## 4. Execution related

### `execve`

Replaces the current process with a new program.
**Success:** does **not return**
**Fail:** `-1`
**errno:** ✅ yes

---

## 5. Process related

### `fork`

Creates a new process.
**Success:**
• child → `0`
• parent → child PID
**Fail:** `-1`
**errno:** ✅ yes

---

### `wait`

Waits for any child process to exit.
**Success:** child PID
**Fail:** `-1`
**errno:** ✅ yes

---

### `waitpid`

Waits for a specific child process.
**Success:** child PID (or `0` with `WNOHANG`)
**Fail:** `-1`
**errno:** ✅ yes

---

## 6. Flow related

### `exit`

Terminates the current process with a status code.
**Success:** does not return
**Fail:** never fails
**errno:** ❌ no

---
