# Philosophers 🧙

# Dining Philosophers Problem

This project demonstrates a synchronisation problem: the Dining Philosophers. The objective of the project is to learn about multi-threading and resource sharing in the context of parallel computing.

## Problem Description

The Dining Philosophers Problem involves a scenario where a number of philosophers are sitting around a circular table, each philosopher alternating between thinking, eating and sleeping The philosophers share forks placed between them. Each philosopher needs two forks to eat, one from the left and one from the right. The challenge is to design a solution that prevents the philosopher to die by avoiding deadlock and starvation, ensuring that each philosopher can eat without being blocked by their neighbors.

## Project Details

- Language: C

## Implementation

The project is implemented using multi-threading in C, each philosopher is represented as a separate thread. An "observer" thread is monitoring all the others. Also, each fork is a mutex.


## Usage

`git clone https://github.com/tevaaa/Philosophers.git`

`cd philo`

`make` 

`./philo <philo number> <ms for routine> <ms to eat> <ms to sleep> [stop after n times eat]` 

