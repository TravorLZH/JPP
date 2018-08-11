#include <jpp.h>
#include <jpp_macro.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include <ctype.h>

const char define_prefix[]="#define";
const size_t define_prefix_len=sizeof(define_prefix)-1;

void usage_defines(void)
{
	fprintf(stderr,"\t-D <macro>\tDefine a macro\n");
}

int init_defines(int *i,char **argv)
{
	char *macro_def=NULL;
	char *macro_name=NULL;
	char *macro_val=NULL;
	char *ptr;
	if(strncmp(argv[*i],"-D",2)){
		return 1;
	}
	/* If command line is like this: `-DHELLO` */
	if(strlen(argv[*i])>2){
		macro_def=argv[*i]+2;
	}else{	/* Or it is like this: `-D HELLO' */
		(*i)++;
		if(*argv[*i]=='-'){
			MISSING_ARG();
		}
		macro_def=argv[*i];
	}
	macro_name=strtok(macro_def,"=");
	macro_val=strtok(NULL,"=");
	printf("You defined macro `%s'",macro_name);
	if(macro_val!=NULL)
		printf(" with value `%s\'",macro_val);
	add_macro(macro_name,macro_val);
	putchar('\n');
	return 0;
}

void process_defines(vector_t *lines)
{
	/* Strip defines from lines */
	size_t i,j;
	char *macro_def=NULL;
	char *macro_name=NULL;
	char *macro_val=NULL;
	bool dquote=false;	// " character
	bool quote=false;	// ' character
	size_t len=0;
	for(i=0;i<lines->n;i++){
		char *str=*(char**)vector_at(lines,i);
		if(!strncmp(define_prefix,str,define_prefix_len)){
			macro_def=str+define_prefix_len+1;
			len=strlen(macro_def);
			macro_name=strtok(macro_def," \t");
			printf("You defined macro `%s'",macro_name);
			len-=macro_name-macro_def;
			for(j=strlen(macro_name);j<len;j++){
				if(*(macro_name+j)!='\0'&&*(macro_name+j)!='\t'
						&&*(macro_name+j)!=' '){
					macro_val=macro_name+j;
					break;
				}
			}
			/* Strip the comments out */
			if(macro_val!=NULL){
				len=strlen(macro_val);
				for(j=0;j<len;j++){
					if(macro_val[j]=='\\'){
						continue;
					}
					if(macro_val[j]=='\"'&&!quote){
						dquote=dquote?false:true;
					}
					if(macro_val[j]=='\''&&!dquote){
						quote=quote?false:true;
					}
					if(macro_val[j]=='/'&&!quote&&!dquote){
						macro_val[j]='\0';
						while(isspace(macro_val[--j]));
						macro_val[j+1]='\0';
					}
				}
				printf(" with value `%s\'",macro_val);
			}
			putchar('\n');
			free(str);
			vector_delete(lines,i);
			i--;
		}
	}
}
