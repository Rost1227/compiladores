%{
    #include "y.tab.h"
    #include "hash.c"

    int Running = 1;
    int lineNumber = 1;

    int isRunning(void){
    return Running;
    }

    int getLineNumber(void){
        return lineNumber;
    }

    void initMe(void){
        hashInit();
    }

%}
%x COMMENT

%%



"char"      return KW_CHAR;
"int"       return KW_INT;
"float"     return KW_FLOAT;

"code"		return KW_CODE;

"if"        return KW_IF;
"else"      return KW_ELSE;
"while"     return KW_WHILE;
"input"     return KW_INPUT;
"print"     return KW_PRINT;
"return"    return KW_RETURN;

[-,;()\]\[{}=+*/%<>&|~]  return yytext[0];

"<="        return OPERATOR_LE;
">="        return OPERATOR_GE;
"=="        return OPERATOR_EQ;
"!="        return OPERATOR_DIF;

[ \t]
"\n"                   ++lineNumber;

"//".*     
"///"       BEGIN(COMMENT);

[0-9]*[A-Za-z_]+[0-9A-Za-z_]*   hashInsert(yytext, TK_IDENTIFIER); return TK_IDENTIFIER;

[0-9]+                  hashInsert(yytext, LIT_INT); return LIT_INT;
'[^']'                 hashInsert(yytext, LIT_CHAR); return LIT_CHAR;
[0-9]+\.[0-9]+        	hashInsert(yytext, LIT_REAL); return LIT_REAL;

\"[^\"]*\"              hashInsert(yytext, LIT_STRING); return LIT_STRING;

.                       return TOKEN_ERROR;

<COMMENT>.
<COMMENT>"\n" ++lineNumber;
<COMMENT>"///" BEGIN(INITIAL);

%%

#include "y.tab.c"
#include "main.c"

int yywrap(){
    Running = 0;
    return 1;
}