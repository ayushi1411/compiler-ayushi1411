declblock{
	int data[5], i;
	int sum;
}

codeblock{
	for i = 1, 5 {
		data[i-1] = i*i ; 
	}

	sum = 0;
	for i = 1, 5 {
		sum = sum + data[i-1] ;
 	}
	sum = 0-sum/5;
	println "Sum value: ", sum ;
}

