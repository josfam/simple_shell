#include "shell.h"
#include <stdlib.h>

/**
 * create_mem_pool - Creates a mem pool, that stores memory locations that have
 *                   been created with malloc.
 * Description: Creates a mem pool, that stores memory locations that have
 *              been created with malloc.
 * Return: A memory pool struct.
*/
memPool *create_mem_pool()
{
	int i;
	memPool *mem_pool;

	mem_pool = (memPool *)malloc(sizeof(memPool));
	if (!mem_pool)
		return (NULL);

	/* initialize all memory locations to NULL */
	for (i = 0; i < MAX_MEMPOOL_SIZE; i++)
	{
		mem_pool->memArray[i] = NULL;
	}

	mem_pool->nextFreeIndex = 0;
	return (mem_pool);
}

/**
 * append_memory - Adds a memory location to the memory pool.
 * @pool: The memory pool where the memory location will be added.
 * @memory: The memory location that will be added.
 * Description: Adds a memory location to the memory pool.
 * Return: The next free location in the pool where
 *         a memory location can be added.
*/
int append_memory(memPool *pool, char *memory)
{
	int index;

	index = pool->nextFreeIndex;
	pool->memArray[index] = memory;
	pool->nextFreeIndex++;

	return (pool->nextFreeIndex);
}

/**
 * free_mem_pool - Frees all memory locations in the memory pool.
 * @pool: The memory pool with locations to free.
 * Description: Frees all memory locations in the memory pool.
 * Return: Nothing.
*/
void free_mem_pool(memPool *pool)
{
	char **poolPtr;

	poolPtr = pool->memArray;
	while (*poolPtr != NULL)
	{
		free(*poolPtr);
		poolPtr++;
	}
	free(pool);
}
