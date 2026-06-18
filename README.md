# C-Based CLI Key-Value Database

A lightweight, in-memory Key-Value store with an interactive Command-Line Interface (CLI), written entirely in C. 

This project implements a custom Hash Table from scratch and features dual-layer disk persistence (similar to Redis's AOF and RDB mechanisms) to ensure data survives across system reboots.

## 🚀 Features

* **Custom Hash Table:** Built from scratch with manual memory management and linked-list chaining for collision resolution.
* **Interactive CLI:** A continuous loop terminal interface parsing user commands in real-time.
* **Dual-Layer Persistence:**
  * **Append-Only File (AOF):** Logs live operations (`SET`, `DEL`) to `io.txt` for real-time recovery.
  * **Binary Snapshots:** Compresses and serializes the entire memory state into `snapshot.bin` upon exit for lightning-fast loading on the next startup.
* **Memory Safe:** Strict pointer handling and comprehensive memory freeing (`freeNode`, `clearTable`) to prevent memory leaks.

## 🛠️ Tech Stack
* **Language:** C
* **Concepts:** Pointers, Manual Memory Management (`malloc`, `free`), Bitwise/Binary File I/O (`fread`, `fwrite`), Data Structures (Hash Tables, Linked Lists).

## ⚙️ Getting Started

### Prerequisites
* GCC Compiler (MinGW/MSYS2 for Windows, or standard GCC for Linux/macOS).

### Installation & Compilation

1. Clone the repository:
   ```bash
   git clone [https://github.com/ido5581/Command-Line-Interface.git](https://github.com/ido5581/Command-Line-Interface.git)
   cd Command-Line-Interface
