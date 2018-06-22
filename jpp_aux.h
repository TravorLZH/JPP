#ifndef	JPP_AUX_H
#define	JPP_AUX_H
#include <vector.h>

/** @defgroup jpp_aux Preprocessing
 * The core function related to modules belong here
 *
 * @{
 */

/** Format of function call to print module usage */
typedef void (*usagefunc_t)(void);

/** Format of function call to initialize modules
 * The init functions below are conforming to this format
 *
 * @param index	Index of argv being interpreted
 * @param argv	`argv' from main
 *
 * @return	zero on succes, otherwise error
 * @see main
 */
typedef int (*initfunc_t)(int *index,char **argv);

/** Format of function call to let modules preprocess
 * The process functions below are conforming to this format
 *
 * @param lines	Lines of file stored in a vector
 */
typedef void (*processfunc_t)(vector_t* lines);

/** Required function for each module */
struct jpp_module {
	/** Help function */
	usagefunc_t usage;
	/** Init function */
	initfunc_t init;
	/** Preprocessing function */
	processfunc_t process;
};

/** Parse command options related to every module
 * This function is called by main
 *
 * @see initfunc_t
 * @see main
 */
extern int init_all(int *index,char **argv);

/** Parse command options related to define module
 *
 * @see initfunc_t
 */
extern int init_defines(int *index,char **argv);

/** Parse command options related to include module
 *
 * @see initfunc_t
 */
extern int init_includes(int *index,char **argv);

/** Parse command options related to comments
 *
 * @see initfunc_t
 */
extern int init_comments(int *index,char **argv);

/** Trigger preprocess every module
 * This function is called by main
 *
 * @see processfunc_t
 * @see main
 */
extern void process_all(vector_t *lines);

/** Preprocess define directive
 *
 * @see processfunc_t
 */
extern void process_defines(vector_t *lines);

/** Preprocess include directive
 *
 * @see processfunc_t
 */
extern void process_includes(vector_t *lines);

/** Strip comments
 *
 * @see processfunc_t
 */

extern void process_comments(vector_t *lines);

/** Print usage of every module
 * This function is called by main
 *
 * @see usagefunc_t
 * @see main
 */
extern void usage_all(void);

/** Print usage of define module
 *
 * @see usagefunc_t
 */
extern void usage_defines(void);

/** Print usage of include module
 *
 * @see usagefunc_t
 */
extern void usage_includes(void);

/** Print usage of comments module
 *
 * @see usagefunc_t
 */
extern void usage_comments(void);

/** @} */
#endif
