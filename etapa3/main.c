int main(int argc, char ** argv){
    
    initMe();
    int tok;

    if(argc < 2){
        fprintf(stderr, "Call: etapa2 fileName\n");
        exit(1);
    }
    
    yyin = fopen(argv[1], "r");

    if(yyin == 0){
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        exit(2);
    }

	yyparse();
	hashPrint();

	fprintf(stderr, "Compilation successful!\n");
	exit(0);
} 