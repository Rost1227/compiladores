// AST - Abstract Syntax Tree

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3){
    AST*newnode;
    newnode = (AST*) calloc(1, sizeof(AST));
    newnode->type = type;
    newnode->symbol = symbol;
    newnode->son[0] = s0;
    newnode->son[1] = s1;
    newnode->son[2] = s2;
    newnode->son[3] = s3;
    return newnode;
}

void astPrint(AST *node, int level){
    int i = 0;
    
    if (node == 0)
        return;
    
    for(i=0; i < level; ++i)
        fprintf(stderr, "  ");
    
    fprintf(stderr, "ast(");
    
    switch(node->type){
        case AST_SYMBOL:        fprintf(stderr, "AST_SYMBOL"); break;
        case AST_ADD:           fprintf(stderr, "AST_ADD"); break;
        case AST_SUB:           fprintf(stderr, "AST_SUB"); break;
        case AST_MULT:          fprintf(stderr, "AST_MULT"); break;
        case AST_DIV:           fprintf(stderr, "AST_DIV"); break;
        case AST_MENOR:         fprintf(stderr, "AST_MENOR"); break;
        case AST_MAIOR:         fprintf(stderr, "AST_MAIOR"); break;
        case AST_OU:            fprintf(stderr, "AST_OU"); break;
        case AST_E:             fprintf(stderr, "AST_E"); break;
        case AST_NEG:           fprintf(stderr, "AST_NEG"); break;
        case AST_MENOR_IGUAL:   fprintf(stderr, "AST_MENOR_IGUAL"); break;
        case AST_MAIOR_IGUAL:   fprintf(stderr, "AST_MAIOR_IGUAL"); break;
        case AST_IGUAL:         fprintf(stderr, "AST_IGUAL"); break;
        case AST_DIFERENTE:     fprintf(stderr, "AST_DIFERENTE"); break;
        case AST_VETOR:         fprintf(stderr, "AST_VETOR"); break;
        case AST_CHAMADA_FUNCAO: fprintf(stderr, "AST_CHAMADA_FUNCAO"); break;
        case AST_NOT:           fprintf(stderr, "AST_NOT"); break;
        case AST_PARAMETROS_FUNCAO:         fprintf(stderr, "AST_PARAMETROS_FUNCAO"); break;
        case AST_MAIS_PARAMETROS_FUNCAO:    fprintf(stderr, "AST_MAIS_PARAMETROS_FUNCAO"); break;

        case AST_ATTR:          fprintf(stderr, "AST_ATTR"); break;
        case AST_ATTR_VETOR:    fprintf(stderr, "AST_ATTR_VETOR"); break;
        case AST_READ:          fprintf(stderr, "AST_READ"); break;
        case AST_PRINT:         fprintf(stderr, "AST_PRINT"); break;
        case AST_RETURN:        fprintf(stderr, "AST_RETURN"); break;

        case AST_L_ELEM_PRINT:      fprintf(stderr, "AST_L_ELEM_PRINT"); break;
        case AST_MAIS_ELEM_PRINT:   fprintf(stderr, "AST_MAIS_ELEM_PRINT"); break;

        case AST_CHAR:        fprintf(stderr, "AST_CHAR"); break;
        case AST_INT:        fprintf(stderr, "AST_INT"); break;
        case AST_FLOAT:        fprintf(stderr, "AST_FLOAT"); break;
        case AST_BOOL:        fprintf(stderr, "AST_BOOL"); break;

        case AST_IF:        fprintf(stderr, "AST_IF"); break;
        case AST_IF_ELSE:   fprintf(stderr, "AST_IF_ELSE"); break;
        case AST_WHILE:     fprintf(stderr, "AST_WHILE"); break;
        case AST_LOOP:      fprintf(stderr, "AST_LOOP"); break;

        case AST_CORPO:                 fprintf(stderr, "AST_CORPO"); break;
        case AST_DECL_VARIAVEL:         fprintf(stderr, "AST_DECL_VARIAVEL"); break;
        case AST_DECL_VETOR:            fprintf(stderr, "AST_DECL_VETOR"); break;
        case AST_DECL_FUNCAO:           fprintf(stderr, "AST_DECL_FUNCAO"); break;
        case AST_PARAM_REC_FUNC:        fprintf(stderr, "AST_PARAM_REC_FUNC"); break;
        case AST_MAIS_PARAM_REC_FUNC:   fprintf(stderr, "AST_MAIS_PARAM_REC_FUNC"); break;
        case AST_INICIA_VETOR:          fprintf(stderr, "AST_INICIA_VETOR"); break;
        case AST_MAIS_VETOR:            fprintf(stderr, "AST_MAIS_VETOR"); break;
        case AST_LISTA_DECLARACOES:     fprintf(stderr, "AST_LISTA_DECLARACOES"); break;
        case AST_TAM_VETOR:             fprintf(stderr, "AST_TAM_VETOR"); break;

        case AST_LCMD: fprintf(stderr, "AST_LCMD"); break;
        case AST_PARENTESES: fprintf(stderr, "AST_PARENTESES"); break;
        default: fprintf(stderr, "AST_UNKNOWN"); break;
    }
    
    if(node->symbol != 0)
        fprintf(stderr, ",%s\n", node->symbol->text);
    else
        fprintf(stderr, ",0\n");
  
    for (i=0; i < MAX_SONS; i++)
        astPrint(node->son[i], level+1);
}
