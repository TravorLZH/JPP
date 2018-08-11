#include <vector.h>
#include <string.h>
#include <stdio.h>
#include <jpp_macro.h>

vector_t macros;

static int compare_macro(const void *a,const void *b)
{
	struct jpp_macro *m1=(struct jpp_macro*)a;
	struct jpp_macro *m2=(struct jpp_macro*)b;
	return strncmp(m1->name,m2->name,sizeof(m1->name));
}

struct jpp_macro *search_macro(char *name)
{
	struct jpp_macro key;
	strncpy(key.name,name,sizeof(key.name));
	int index=vector_find(&macros,&key,compare_macro);
	if(index<0){
		return NULL;
	}
	return vector_at(&macros,index);
}

int add_macro(char *name,char *definition)
{
	struct jpp_macro macro;
	if(search_macro(name)!=NULL){
		fprintf(stderr,"error: Redeclaration of macro `%s'\n",name);
		return -1;
	}
	memset(&macro,0,sizeof(macro));
	strncpy(macro.name,name,sizeof(macro.name));
	if(definition!=NULL){
		strncpy(macro.definition,definition,sizeof(macro.definition));
	}
	vector_pushback(&macros,&macro);
	return 0;
}

int init_macro(void)
{
	vector_new(&macros,sizeof(struct jpp_macro));
	// TODO: Add built-in macros
	add_macro("JPP_AUTHOR","Travor Liu");
	add_macro("JPP_AUTHOR","Travor Liu");
	return 0;
}

int destroy_macro(void)
{
	vector_destroy(&macros);
	return 0;
}
