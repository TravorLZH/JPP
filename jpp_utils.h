#ifndef	JPP_UTILS_H
#define	JPP_UTILS_H
#include <stddef.h>
#include <stdio.h>
#include <vector.h>

/** @defgroup utils Utility Functions
 * Useful functions that can be plugged into your code
 *
 * @{
 */

/** Free a string array
 * It does NOT free the array itself
 *
 * @param vector	Vector of string pointers being freed
 */
extern void free_ptrs(vector_t *vector);

/** Cut string into pieces
 *
 * @param str		String being split
 * @param delim		Delimiters
 * @param vector	A place to store the pieces
 */
extern void tokenize(const char *str,char *delim,vector_t *vector);

/** Read content from a file
 *
 * @param fp	File to be read
 * @param where	Where the content to be stored
 * @param max	Don't read after it
 *		Usually the length of where
 */
extern size_t file_content(FILE *fp,char *where,size_t max);

/** @} */
#endif
