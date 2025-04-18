%option c++


%{
    using std::cout;
    using std::endl;
    // лексемы
%}

WS     [ \t\n\v]+
DIGIT  [0-9]
DIGIT1 [1-9]
OP     [\+\-\=]

%%

{WS}               /* skip blanks and tabs */
{OP}               {cout << "operator <" << yytext[0] << ">" << endl; return 1; }
{DIGIT}{DIGIT1}*   {cout << "  number <" << yytext    << ">" << endl; return 1; }
.                  {cout << " UNKNOWN <" << yytext[0] << ">" << endl; return 1; }

%%

// nothing