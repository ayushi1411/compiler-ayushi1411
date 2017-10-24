b: lex.yy.c parser.tab.c ASTDefinitions.h Interpreter.cpp
	g++ -std=c++11 -g lex.yy.c parser.tab.c -o b

lex.yy.c: parser.tab.c scanner.l
	flex scanner.l

parser.tab.c: parser.y
	bison -d --debug --verbose parser.y

clean: 
	rm -f lex.yy.c parser.tab.c parser.tab.h b


ASTDefinitions.h :
	g++ -std=c++11 -g lex.yy.c parser.tab.c  -o b