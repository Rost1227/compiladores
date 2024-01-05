// AST - Abstract Syntax Tree

#include "hash.h"

#ifndef AST_HEADER
#define AST_HEADER

#define MAX_SONS 4

#define AST_SYMBOL 1
#define AST_ADD 2
#define AST_SUB 3
#define AST_MULT 4
#define AST_DIV 5
#define AST_MENOR 6
#define AST_MAIOR 7
#define AST_OU 8
#define AST_E 9
#define AST_NEG 10
#define AST_MENOR_IGUAL 11
#define AST_MAIOR_IGUAL 12
#define AST_IGUAL 13
#define AST_DIFERENTE 14
#define AST_VETOR 15
#define AST_CHAMADA_FUNCAO 16
#define AST_NOT 17
#define AST_PARAMETROS_FUNCAO 18
#define AST_MAIS_PARAMETROS_FUNCAO 19

#define AST_ATTR 20
#define AST_ATTR_VETOR 21
#define AST_READ 22
#define AST_PRINT 23
#define AST_RETURN 24
#define AST_L_ELEM_PRINT 25
#define AST_MAIS_ELEM_PRINT 26

#define AST_CHAR 27
#define AST_INT 28
#define AST_FLOAT 29
#define AST_BOOL 30

#define AST_IF 31
#define AST_IF_ELSE 32
#define AST_WHILE 33
#define AST_LOOP 34

#define AST_CORPO 35

#define AST_DECL_VARIAVEL 36
#define AST_DECL_VETOR 37
#define AST_DECL_FUNCAO 38
#define AST_PARAM_REC_FUNC 39
#define AST_MAIS_PARAM_REC_FUNC 40
#define AST_INICIA_VETOR 41
#define AST_MAIS_VETOR 42
#define AST_LISTA_DECLARACOES 43
#define AST_TAM_VETOR 44

#define AST_LCMD 45

#define AST_PARENTESES 46

typedef struct astnode{
    int type;
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3);
void astPrint(AST *node, int level);



#endif