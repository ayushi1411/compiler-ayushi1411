declblock{
  int i, j, a[10];
}

codeblock{
  println "This should print 2 6 14. Hello 15 1 ";
  j = 10;
  for i = 1, 10 {
    i = i + i;
    println i;
  }
  println "Hello", i, i/j;
}

