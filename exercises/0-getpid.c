#include "exercise.h"
#include <unistd.h>

/**
 * _getpid - Returns the PID of the parent process.
 * Description: Returns the PID of the parent process.
 * Return: The PID of the parent process.
 */
pid_t _getpid(void)
{
	return (getppid());
}
