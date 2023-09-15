#include "hblk_crypto.h"

/**
 * sha256- secure hash alogrithme 256
 *
 * @s: the string
 * @len: the length 
 * @digest: the buffer
 * Return: the hash algorithme
 */

uint8_t *sha256(int8_t const *s, size_t len,
		uint8_t digest[SHA256_DIGEST_LENGTH])
{
	if (!digest)
		return (NULL);

	return (SHA256((const unsigned char *)s, len, digest));
}
