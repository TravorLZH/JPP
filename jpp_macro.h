#ifndef	JPP_MACRO_H
#define	JPP_MACRO_H

struct jpp_macro {
	char name[256];
	char definition[256];
};



extern struct jpp_macro *search_macro(char *name);

extern void add_macro(char *name,char *definition);

extern void init_macro(void);

#endif
