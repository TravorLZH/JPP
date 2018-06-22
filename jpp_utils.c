#include <jpp_utils.h>
#include <vector.h>
#include <malloc.h>
#include <string.h>

void free_ptrs(vector_t *vector)
{
	size_t i;
	for(i=0;i<vector->n;i++){
		free(*(char**)vector_at(vector,i));
	}
}

void tokenize(const char *str,char *delim,vector_t *vector)
{
	size_t len=strlen(str);
	char tmp[len+1];
	char *ptr=tmp;
	char *ptr2=NULL;
	size_t k=0;
	strcpy(tmp,str);
	ptr=strtok(tmp,delim);
	while(ptr!=NULL){
		ptr2=malloc(strlen(ptr)+1);
		strcpy(ptr2,ptr);
		vector_pushback(vector,&ptr2);
		ptr=strtok(NULL,delim);
	}
}

size_t file_content(FILE *fp,char *where,size_t max)
{
	size_t i=0;
	char c;
	while((c=fgetc(fp))!=EOF){
		if(i>=max){
			return i-1;
		}
		where[i]=c;
		i++;
	}
	where[i]='\0';
	return i;
}
