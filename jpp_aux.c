#include <jpp_aux.h>

static struct jpp_module module_table[]={
	{
		usage_defines,init_defines,process_defines
	},
	{
		usage_includes,init_includes,process_includes
	},
	{
		usage_comments,init_comments,process_comments
	}
};

const int nmodules=sizeof(module_table)/sizeof(struct jpp_module);

void usage_all(void)
{
	int i;
	for(i=0;i<nmodules;i++){
		if(module_table[i].usage){
			module_table[i].usage();
		}
	}
}

int init_all(int *index,char **argv)
{
	int i;
	int good=1;	// Make sure there are not invalid commands
	for(i=0;i<nmodules;i++){
		if(!module_table[i].init(index,argv)){
			good=0;
		}
	}
	return good;
}

void process_all(vector_t *lines)
{
	int i;
	for(i=0;i<nmodules;i++){
		if(module_table[i].process){
			module_table[i].process(lines);
		}
	}
}
