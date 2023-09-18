#include "blockchain.h"
/**
 * block_destroy-free the block
 *@block: pointer of block to free
 * Return: void
 */
void block_destroy(block_t *block)
{
	free(block);
}
