b: lex.yy.c y.tab.c
	gcc -g lex.yy.c y.tab.c -o b

lex.yy.c: y.tab.c scanner.l
	flex scanner.l

y.tab.c: parser.y
	yacc -d parser.y

clean: 
	rm -f lex.yy.c y.tab.c y.tab.h b
