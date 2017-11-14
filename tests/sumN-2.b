declblock{
	int data, foo[2], bar;
}

codeblock{
	read data;
	bar = data + 2;
	foo[0] = bar + 1;
	println data, bar, foo[0];
}

