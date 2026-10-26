# EX NO 7 – Banker's Algorithm for Deadlock Avoidance

## Aim
To implement and study the Banker's Algorithm for the Deadlock Avoidance problem.

## Domain / Use Case
Train track deadlock demonstration.

## Files
| File | Description |
|------|-------------|
| `ex7_partA_deadlock.c` | Part A – deadlock demonstration |
| `ex7_partB_deadlock_avoidance.c` | Part B – deadlock avoidance by lock ordering |
| `ex7_partC_bankers_algorithm.c` | Part C – Banker's Algorithm safety check |
| `ex7_partA_output.png`, `ex7_partB_output.png`, `ex7_partC_output.png` | Program outputs |

## Part A – Deadlock
Train A locks Track-0 then wants Track-1; Train B locks Track-1 then wants Track-0. Each waits for the track the other holds, so the program hangs (stop it with `Ctrl+C`).

```bash
gcc ex7_partA_deadlock.c -o deadlock -pthread
./deadlock
```
![Part A output](ex7_partA_output.png)

## Part B – Deadlock Avoidance
Both trains lock the tracks in the same order (T0 then T1), so circular wait cannot occur and both cross safely.

```bash
gcc ex7_partB_deadlock_avoidance.c -o avoidance -pthread
./avoidance
```
![Part B output](ex7_partB_output.png)

## Part C – Banker's Algorithm
Reads the number of processes and resources, the Available vector and the Allocation and Need matrices. A process whose Need ≤ Available can finish and releases its Allocation. If every process can finish the state is `SAFE`, otherwise `DEADLOCK`.

```bash
gcc ex7_partC_bankers_algorithm.c -o bankers
./bankers
```
![Part C output](ex7_partC_output.png)

## Definitions
- **Deadlock** – two or more processes are permanently blocked, each waiting for a resource held by another.
- **Four necessary conditions** – mutual exclusion, hold and wait, no preemption, circular wait.
- **Deadlock prevention** – make sure at least one of the four conditions never holds.
- **Deadlock avoidance** – allocate resources only if the system stays in a safe state (Banker's Algorithm).
- **Deadlock detection / recovery** – detect a deadlock after it occurs, then recover by terminating processes, preempting resources or rolling back.

## Result
Successfully implemented the concepts of Banker's Algorithm.
