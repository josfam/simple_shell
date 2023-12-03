#include "exercise.h"

/**
 * getpid - Returns the PID of the parent process.
 * Description: Returns the PID of the parent process.
 * Return: The PID of the parent process.
 */
pid_t getpid(void)
{
	return (getppid());
}
