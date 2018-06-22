#ifndef	HASHSET_H
#define	HASHSET_H
#include "vector.h"

/** @defgroup hashset Hashset
 * Generic data structure imitating std::hash_set
 *
 * @{
 */

/** Get the hash code */
typedef int (*hashfunc_t)(const void *addr,int nbuckets);

/** Data structure of hash set */
typedef struct hashset {
	hashfunc_t hash;
	cmpfunc_t cmpfunc;
} hashset_t;

extern void hashset_new(hashset_t *hs,size_t elem_sz

/** @} */
#endif
