#include <jpp.h>
#include <stdbool.h>

bool keep_comments=false;

void usage_comments(void)
{
	fprintf(stderr,"\t--keep-comments\tDon't strip comments\n");
}

int init_comments(int *i,char **argv)
{
	if(strcmp(argv[*i],"--keep-comments")){
		return 1;
	}
	printf("Let's keep comments\n");
	keep_comments=true;
	return 0;
}

void process_comments(vector_t *lines)
{
	// TODO: Strip comments
}
