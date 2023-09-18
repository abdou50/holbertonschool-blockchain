#include "blockchain.h"
/**
 * blockchain_destroy-destroy all
 * @blockchain: blockchain to free
 */
void blockchain_destroy(blockchain_t *blockchain)
{
	if (!blockchain)
		return;
	llist_destroy(blockchain->chain, 1, (void (*)(llist_node_t))free);
	free(blockchain);
}
