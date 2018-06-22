#include "vector.h"
#include <malloc.h>
#include <string.h>

void vector_new(vector_t *vector,size_t size)
{
	vector->alloc=VECTOR_DEFAULT_ELEMS * size;
	vector->n=0;
	vector->elems=malloc(vector->alloc);
	vector->elem_sz=size;
}

void vector_destroy(vector_t *vector)
{
	free(vector->elems);
	vector->elems=NULL;
	vector->n=0;
	vector->elem_sz=0;
	vector->alloc=0;
}

void *vector_front(vector_t *vector)
{
	return vector->elems;
}

void *vector_back(vector_t *vector)
{
	if(vector->n==0){
		return vector_front(vector);
	}
	return vector_at(vector,vector->n-1);
}

void vector_pushback(vector_t *vector,void *val)
{
	size_t size=(vector->elem_sz) * (vector->n);
	if(size>=vector->alloc){
		vector->alloc*=2;
		vector->elems=realloc(vector->elems,vector->alloc);
	}
	memcpy(vector->elems+size,val,vector->elem_sz);
	vector->n++;
}

void *vector_popback(vector_t *vector)
{
	if(vector->n<1){
		return NULL;
	}
	void *ptr=vector_back(vector);
	vector->n--;
	return ptr;
}

void *vector_set(vector_t *vector,size_t pos,void *val)
{
	void *ptr=vector_at(vector,pos);
	memcpy(ptr,val,vector->elem_sz);
	return ptr;
}

void *vector_at(vector_t *vector,size_t pos)
{
	size_t size=pos * vector->elem_sz;
	char *ptr=(char*)vector->elems;
	return ptr+size;
}

void *vector_insert(vector_t *vector,size_t pos,void *val)
{
	char *ptr=vector_at(vector,pos);
	char *ptr2=vector_back(vector);
	size_t size=ptr2-ptr;
	vector_pushback(vector,ptr2);
	memmove(ptr+vector->elem_sz,ptr,size);
	vector_set(vector,pos,val);
	return ptr;
}

void vector_delete(vector_t *vector,size_t pos)
{
	char *ptr=vector_at(vector,pos+1);
	char *ptr2=vector_popback(vector);
	memmove(ptr-vector->elem_sz,ptr,ptr2-ptr);
	vector_set(vector,vector->n-1,ptr2);
}

size_t vector_find(vector_t *vector,const void *key,cmpfunc_t cmpfunc)
{
	size_t i;
	for(i=0;i<vector->n;i++){
		if(!cmpfunc((const void*)vector_at(vector,i),key)){
			return i;
		}
	}
	return -1;
}
