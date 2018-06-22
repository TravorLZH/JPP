#ifndef	__VECTOR_H_
#define	__VECTOR_H_
#include <stddef.h>

/** @defgroup vector Vector
 * Generic data structure
 *
 * @{
 */

/** Number of elements available before 1st resize */
#define	VECTOR_DEFAULT_ELEMS	16

/** Compare two elements
 *
 * @return	Integer representing the results
 *	- Negative value means a is less than b
 *	- Zero means a equals to b
 *	- Positive value means a is greater than b
 */
typedef int (*cmpfunc_t)(const void *a,const void *b);

/** Structure of vector
 * Assuming members are read-only to users
 */
typedef struct vector {
	/** Pointer to the data of vector */
	void *elems;
	/** Number of elements stored */
	size_t n;
	/** Size of each elements */
	size_t elem_sz;
	/** Allocated size of vector data
	 * Its initial value = VECTOR_DEFAULT_ELEMS * elem_sz
	 */
	size_t alloc;
} vector_t;

/** Create a vector
 * Initialize members of vector
 *
 * @param vector	Vector being created
 * @param size		Size of each vector element
 */
extern void vector_new(vector_t *vector,size_t size);

/** Destroy a vector
 *
 * @param vector	Vector being destroyed
 */
extern void vector_destroy(vector_t *vector);

/** Get the 1st element of vector
 *
 * @param vector	Vector holding the data
 *
 * @return	Pointer to the first element
 */
extern void *vector_front(vector_t *vector);

/** Get the last element of vector
 *
 * @param vector	Vector holding the data
 *
 * @return	Pointer to the last element
 */
extern void *vector_back(vector_t *vector);

/** Add value to the back of the vector
 * It doubles allocated space once overflow
 *
 * @param vector	Vector being pushed to
 * @param val		Pointer to the pushing value
 */
extern void vector_pushback(vector_t *vector,void *val);

/** Pop the last value
 *
 * @param vector	Vector holding the removing value
 *
 * @return	Popped value
 *		May be overrided by the next push
 */
extern void *vector_popback(vector_t *vector);

/** Replace the value at pos
 *
 * @param vector	Vector holding the data
 * @param pos		Where is replaced
 * @param val		Replacing value
 *
 * @return	Value at replaced space
 */
extern void *vector_set(vector_t *vector,size_t pos,void *val);

/** Get the element at pos
 *
 * @param vector	Vector holding the element
 * @param pos		Position of element
 */
extern void *vector_at(vector_t *vector,size_t pos);

/** Insert element before pos
 *
 * @param vector	Vector being inserted to
 * @param pos		Where to be inserted
 * @param val		Inserting value
 */
extern void *vector_insert(vector_t *vector,size_t pos,void *val);

/** Delete element at pos
 *
 * @param vector	Vector holding the deleting element
 * @param pos		Where to be deleted
 */
extern void vector_delete(vector_t *vector,size_t pos);

/** Search element in vector
 *
 * @param vector	Vector holding the elements
 * @param key		The element to be searched
 * @param cmpfunc	Function used to compare elements
 *
 * @return	Index of found element, negative value if not found
 */
extern size_t vector_find(vector_t *vector,const void *key,cmpfunc_t cmpfunc);

/** @} */
#endif
