# 42 Philosophers

## 📌 Project Description
42 Philosophers is a **concurrency and synchronization** project based on the classic **Dining Philosophers Problem**. This project simulates the cycle of philosophers eating and thinking using **multithreading** or **process management**.

## 🚀 Technologies Used
- **Language:** C
- **Synchronization Mechanisms:** Mutex or Semaphore
- **Threads:** `pthread`
- **Process Management:** `fork`
- **Time Management:** `usleep()` or `gettimeofday()`

## 🔧 Installation and Execution

### 1️⃣ Clone the Repository
```sh
git clone https://github.com/mertcangur/philosophers
cd philosophers
```

### 2️⃣ Compilation
```sh
make
```
or
```sh
gcc -Wall -Wextra -Werror -pthread philosophers.c -o philosophers
```

### 3️⃣ Running the Program
```sh
./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_think] [max_meals (optional)]
```

📌 **Example:** To run the program with 5 philosophers, 800ms time to die, 200ms time to eat, and 200ms time to think:
```sh
./philosophers 5 800 200 200
```

## 📜 Problem Description
- There are **N** philosophers at a table.
- Each philosopher follows a cycle of **thinking and eating**.
- Two forks are required to eat.
- Forks are **shared** and need to be managed for concurrent access.

## ⚙️ Solution Approaches
### 🛠 Using Mutexes
- Each fork is protected by a **mutex**.
- Philosophers lock **two mutexes** to eat and then release them.

### 🚥 Using Semaphores
- All forks are managed using a **semaphore array**.
- A maximum of `(N-1)` philosophers can eat at the same time.

## 🛡 Deadlock and Race Condition Prevention
- **Deadlock Prevention:** Philosophers do not pick up forks simultaneously.
- **Race Condition Prevention:** Data synchronization is ensured using mutexes or semaphores.
- **Avoiding Erratic Behavior:** `usleep()` is used to balance timing.

## 📜 Resources
- [Dining Philosophers Problem (Wikipedia)](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

---
**📌 Note:** This project is developed in accordance with the **Philosophers** project in the **common core** stage of **42 School**. If you encounter any issues during development, feel free to open an **issue** in the repository! 🚀

