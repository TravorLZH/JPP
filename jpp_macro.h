#ifndef	JPP_MACRO_H
#define	JPP_MACRO_H

struct jpp_macro {
	char name[256];
	char definition[256];
};

/** A list of macros the source contains */
extern vector_t macros;

extern struct jpp_macro *search_macro(char *name);

extern int add_macro(char *name,char *definition);

/** Adding some built-in macros to the list */
extern int init_macro(void);

/** Deinitialization */
extern int destroy_macro(void);

#endif
