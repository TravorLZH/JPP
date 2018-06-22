#ifndef	JPP_H
#define	JPP_H
#include <stddef.h>
#include <stdio.h>
#include <vector.h>

#include <jpp_aux.h>

/** @defgroup jpp Java Preprocessor
 * The core part of Java Preprocessor
 *
 * @{
 */

#define	MAX_FILELEN	0x10000	// Will you write 1MB code in one file?

#define	DIE(...)	fprintf(stderr,__VA_ARGS__);exit(1)

/** For convenience in module development */
#define	MISSING_ARG()	DIE("error: Missing argument\n")

#define	ERROR_AT(file,line,...)	DIE("%s:%d: error: " __VA_ARGS__)

/* For error logging */
extern char *infile;

/** Initialize data for Preprocessing
 *
 * @param input	Where data comes from
 *
 * @return	File content cut into lines
 * @see	main
 */
extern vector_t *read_input(FILE *input);

/** Write preprocessed content to output file
 *
 * @param output	Where to be written
 * @param lines		Lines of content stored in a vector
 */
extern void write_output(FILE *output,vector_t *lines);

/** The entry function of program
 * This function parses the command line arguments and opens
 * input and output file
 *
 * @param argc	Count of command line elements
 * @param argv	Pointer to the command line elements
 *		Do not modify the content of argv
 *
 * @return	Zero on success
 * @see		init_data
 */
extern int main(int argc,char **argv);

/** @} */
#endif
