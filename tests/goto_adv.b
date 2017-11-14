declblock{
	int i, j;
}

codeblock{
	for i=1,10 {
		println "inside outer for loop";
		for j=1,10 {
			println "inside inner for loop";
			got label;
			println "This is not printed in inner for loop";
		}
		println "This is not printed in outer for loop";
	}
	label :
	println "Congratulations";
}

