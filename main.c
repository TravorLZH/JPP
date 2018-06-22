#include <jpp.h>
#include <jpp_utils.h>
#include <vector.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

char *infile=NULL;	// Name of the stuff being read

/* Tell the user how to use JPP */
static void usage(char *name)
{
	fprintf(stderr,"Usage: %s [options] file\n",name);
	fprintf(stderr,"Options:\n");
	fprintf(stderr,"\t-o <file>\tOutput result to file, default to STDOUT\n");
	usage_all();
	fprintf(stderr,"\t--help\t\tDisplay this information\n");
	fprintf(stderr,"\nReport bugs to <travor_lzh@outlook.com}\n");
	exit(1);
}

/* Analyze the command line */
int main(int argc,char **argv)
{
	int i;
	char out=0;
	char in=0;
	char c;	// Temp variable for reading
	char *outfile=NULL;	// Name of the stuff being written
	FILE *input=NULL;
	FILE *output=NULL;
	if(argc==1){
		usage(argv[0]);
	}
	for(i=1;i<argc;i++){
		/* Test if the argument is a command
		 * If yes, analyze it
		 * Otherwise treat it as input file
		 */
		if(argv[i][0]=='-'){
			if(!strncmp(argv[i],"-o",2)&&!out){
				out=1;
				if(strlen(argv[i])>2){
					outfile=argv[i]+2;
					continue;
				}
				i++;
				if(i>=argc){
					MISSING_ARG();
				}
				if(argv[i][0]=='-'){
					MISSING_ARG();
				}
				/* We don't have to make a copy */
				outfile=argv[i];
				continue;
			}
			if(!strcmp(argv[i],"--help")){
				usage(argv[0]);
				continue;
			}
			if(init_all(&i,argv)!=0){
				DIE("%s: Unknown option `%s\' " \
				"type `--help\' for a list of options\n", \
				argv[0],argv[i]);
			}
		}else{
			if(!in){
				in=1;
				/* We don't have to make a copy */
				infile=argv[i];
			}else{
				DIE("error: Only allow one input file\n");
			}
		}
	}
	if(!in){
		DIE("error: No input file\n");
	}
	if(!(input=fopen(infile,"r"))){
		perror(infile);
		exit(1);
	}
	// If output file is specified, then write to it
	if(out){
		printf("Output result to %s\n",outfile);
		if(!(output=fopen(outfile,"w"))){
			perror(outfile);
			exit(1);
		}
	}else{	// Otherwise write to the screen
		output=stdout;
	}
	vector_t *lines=read_input(input);
	process_all(lines);
	write_output(output,lines);
	if(out){
		fclose(output);
		output=NULL;
	}else{
		output=NULL;
	}
	free_ptrs(lines);
	free(lines);
	return 0;
}

vector_t *read_input(FILE *input)
{
	/* Read the content from input file and split into lines */
	char *content=malloc(MAX_FILELEN);
	file_content(input,content,MAX_FILELEN);
	fclose(input);	// I don't need you anymore
	/* Create a vector of character pointers */
	vector_t *vec=malloc(sizeof(vector_t));
	vector_new(vec,sizeof(char*));
	/* Split file content into lines */
	tokenize((const char*)content,"\n",vec);
	free(content);	// Hasta la vista 1MB
	return vec;
}

void write_output(FILE *output,vector_t *lines)
{
	size_t i;
	for(i=0;i<lines->n;i++){
		fprintf(output,"%s\n",*(char**)vector_at(lines,i));
	}
}
