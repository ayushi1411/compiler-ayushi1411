declblock{
	int a;
}

codeblock{
	read a;
	l :
	println a;
	a = a - 1;
	goto l if a > 0;
}

