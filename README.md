# Philosophers 🧙

# Dining Philosophers Problem

This project demonstrates a synchronisation problem: the Dining Philosophers. The objective of the project is to learn about multi-threading and resource sharing in the context of parallel computing.

![Screenshot from 2023-06-15 03-05-37](https://github.com/tevaaa/Philosophers/assets/74090323/1608e57c-0fb0-4b21-8724-123ffcfba06a)

## Problem Description

The Dining Philosophers Problem involves a scenario where a number of philosophers are sitting around a circular table, each philosopher alternating between thinking, eating and sleeping The philosophers share forks placed between them. 🍽️💤 
Each philosopher needs two forks to eat, one from the left and one from the right. The challenge is to design a solution that prevents the philosopher to die by avoiding deadlock and starvation, ensuring that each philosopher can eat without being blocked by their neighbors.

## Project Details

- Language: C 🖥️

## Implementation

The project is implemented using multi-threading in C, each philosopher is represented as a separate thread. An "observer" thread is monitoring all the others. Also, each fork is a mutex.


## Usage

`git clone https://github.com/tevaaa/Philosophers.git`

`cd philo`

`make` 

`./philo <philo number> <ms for routine> <ms to eat> <ms to sleep> [stop after n times eat]` 
<philo number>: Number of philosophers
<ms for routine>: Time in milliseconds for the routine to repeat
<ms to eat>: Time in milliseconds for a philosopher to eat
<ms to sleep>: Time in milliseconds for a philosopher to sleep
[stop after n times eat] (optional): Stop the simulation after a philosopher has eaten n times

## Examples 

`./philo 100 410 200 200` - 
program musn't stop


`./philo 5 620 305 305 7` - 
program must stop after all philosophers eat 7 times (grep "is eating" | wc -l) >= 35


`./philo 3 500 200 200` - 
one philo can't eat in time

![Screenshot from 2023-06-15 03-10-16](https://github.com/tevaaa/Philosophers/assets/74090323/ca520ada-93a9-48f0-a66c-d166b6777c29)

