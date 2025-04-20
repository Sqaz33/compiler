// 

#include <iostream>
#include <memory>

#include <FlexLexer.h>


// here we can return non-zero if lexing is not done inspite of EOF detected
int yyFlexLexer::yywrap() {
    return 1;
}

int main() {
    std::unique_ptr<FlexLexer> lexer = std::make_unique<yyFlexLexer>();
    while (lexer->yylex() != 0) {
        // do nothing for now, all is in rules
    }
}