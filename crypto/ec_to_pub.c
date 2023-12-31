#include "hblk_crypto.h"
/**
 * ec_to_pub- finction
 * @key: the key
 * @pub: the public key
 *Return: the key
 */
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
	const EC_POINT *pubKey;
	const EC_GROUP *group;

	if (!key || !pub)
		return (NULL);

	pubKey = EC_KEY_get0_public_key(key);
	if (!pubKey)
	{
		fprintf(stderr, "EC_KEY_get0_public_key() is failed\n");
		return (NULL);
	}
	group = EC_KEY_get0_group(key);
	if (!group)
	{
		fprintf(stderr, "EC_KEY_get0_group() is failed\n");
		return (NULL);
	}
	if (!EC_POINT_point2oct(group, pubKey, POINT_CONVERSION_UNCOMPRESSED,
									pub, EC_PUB_LEN, NULL))
	{
		fprintf(stderr, "EC_POINT_point2oct() is failed\n");
		return (NULL);
	}
	return (pub);
}
