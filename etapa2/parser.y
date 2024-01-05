%{
    #include "y.tab.h"
    int yyerror();
%}

%token KW_CHAR
%token KW_INT
%token KW_FLOAT

%token KW_CODE

%token KW_IF
%token KW_ELSE
%token KW_WHILE
%token KW_INPUT
%token KW_PRINT
%token KW_RETURN

%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_DIF

%token TK_IDENTIFIER

%token LIT_INT
%token LIT_REAL
%token LIT_CHAR
%token LIT_STRING

%token TOKEN_ERROR

 %left '|' '^' 
 %left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF '&'
 %left '+' '-'  
 %left '*' '/'
 %left '~'


%%

programa: 
    l_globais l_codigo
    ;

l_globais: 
	global l_globais
	|
    ;

global: 
	tipo TK_IDENTIFIER '=' literal ';'


    | tipo TK_IDENTIFIER '[' LIT_INT ']' inicia_vetor ';'

    | tipo TK_IDENTIFIER '(' parametros_formais ')' ';'
    ;

tipo:
    KW_CHAR
    | KW_INT
    | KW_FLOAT
    ;

literal:
    LIT_INT
    | '-' LIT_INT
    | LIT_REAL
    | '-' LIT_REAL
    | LIT_CHAR
    ;

/* -------------------- Para o vetor --------------------*/

inicia_vetor:
    literal mais_valores
    |
    ;

mais_valores:
    literal mais_valores
    |
    ;
    
/* ----------------------------------------------------- */

/* -------------------- Para a função -------------------*/

parametros_formais:
    tipo TK_IDENTIFIER  mais_parametro
    |
    ;

mais_parametro:
    ',' tipo TK_IDENTIFIER mais_parametro
    |
    ;
/* ----------------------------------------------------- */

/* -------------------- lista codigo -------------------*/

l_codigo:
    codigo l_codigo
    |
    ;
 
codigo:
    KW_CODE TK_IDENTIFIER corpo
    ;

/* ------------------------ comandos-----------------------*/
    
corpo: 
    comando
    ;

bloco_comandos:
    '{' l_comandos '}'

l_comandos: 
    comando l_comandos
    |
    ;

comando: 
    TK_IDENTIFIER '=' expr ';'
    | TK_IDENTIFIER '[' expr ']' '=' expr ';'
    | KW_PRINT elementos_print ';'
    | KW_RETURN expr ';'
    | controle_fluxo
    | bloco_comandos
    | ';'
    ;
/* ----------------------------------------------------- */

expr:
    TK_IDENTIFIER
    | TK_IDENTIFIER '[' expr ']'
    | literal
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr '<' expr
    | expr '>' expr
    | expr '|' expr
    | expr '&' expr
    | expr OPERATOR_LE expr
    | expr OPERATOR_GE expr
    | expr OPERATOR_EQ expr
    | expr OPERATOR_DIF expr
    | '(' expr ')'
    | chamada_funcao
    | '~' expr
    | KW_INPUT '(' tipo ')'
    ;
    
/* ----------------------------------------------------- */

chamada_funcao:
	TK_IDENTIFIER '(' argumentos_enviados ')'
	;

argumentos_enviados:
    expr mais_argumentos
    |
    ;

mais_argumentos:
    ',' expr mais_argumentos
    |
    ;

/* ------------------PRINT----------------------------- */
elementos_print:
    LIT_STRING elementos_print
    | expr elementos_print
    |
    ;
/* ----------------------------------------------------- */

controle_fluxo:
    KW_IF '(' expr ')' comando
    | KW_IF '(' expr ')' comando KW_ELSE comando
    | KW_WHILE '(' expr ')' comando
    ;
%%

int yyerror(){
    fprintf(stderr, "Syntax error at line %d.\n", getLineNumber());
    exit(3);
}