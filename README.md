# Philo

The **Philo** project simulates the classic dining philosophers problem. The goal is to manage synchronization and resource sharing among multiple threads representing philosophers.

## Description

In this simulation, philosophers sit around a table with a fork placed between each pair of adjacent philosophers. Each philosopher alternates between thinking and eating. To eat, a philosopher must acquire both forks to their left and right. The challenge is to ensure that all philosophers can eat without causing deadlock or starvation.

## Key Features

- **Fork Handling**: Simulates the allocation and deallocation of forks between philosophers.
- **Synchronization**: Uses synchronization mechanisms to prevent deadlock and ensure that each philosopher can eat when needed.
- **Concurrency**: Implements multithreading to simulate the concurrent actions of multiple philosophers.

## Parameters

- **Number of Philosophers**: Specify the number of philosophers participating in the simulation.
- **Time to Die**: Maximum time a philosopher can go without eating before they die.
- **Time to Eat**: Time required for a philosopher to eat.
- **Time to Sleep**: Time a philosopher will sleep after eating.
- **Number of Meals**: The number of times each philosopher should eat before the simulation ends.

## Example Usage

To start the simulation, use the following command:

```bash
./philo 5 800 200 200 10
```
## Simulation Example

This command will start a simulation with:

- **5 philosophers**
- A maximum time to die of **800 milliseconds**
- A time to eat of **200 milliseconds**
- A time to sleep of **200 milliseconds**
- Each philosopher is expected to eat **10 times**

## Key Features

- **Deadlock Prevention**: Implements strategies to avoid situations where philosophers wait indefinitely for resources.
- **Starvation Prevention**: Ensures that every philosopher gets a chance to eat, avoiding situations where some philosophers might never get to eat.
- **Resource Management**: Manages the allocation of forks to avoid conflicts and ensure fair access.

## Implementation Details

- **Parsing**: The program parses command-line arguments to configure the simulation parameters.
- **Fork Management**: Handles the allocation of forks and manages access to avoid conflicts.
- **Thread Management**: Uses threads to simulate the concurrent actions of philosophers.
- **Synchronization**: Employs mutexes and condition variables to coordinate access to shared resources.

## Notes

- **Memory Management**: Ensure proper allocation and deallocation of memory to prevent leaks.
- **Error Handling**: Gracefully handle errors such as invalid arguments or thread creation issues.
- **Edge Cases**: Consider edge cases such as insufficient forks or very short simulation times.

## Additional Features (Optional)

- **Visualization**: Implement a graphical or textual representation of the simulation.
- **Logging**: Add logging to track the state of each philosopher and the allocation of forks.

## Testing

Test your simulation with various configurations to ensure it handles different scenarios correctly:

- **Basic Configuration**: Start with a small number of philosophers and simple parameters.
- **Complex Configuration**: Test with a larger number of philosophers and varied timing parameters.
- **Stress Testing**: Test the simulation with extreme values to ensure stability and correctness.
