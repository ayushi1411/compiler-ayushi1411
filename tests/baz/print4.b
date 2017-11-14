declblock{
  int b;
}

codeblock{
  println "This test case uses undefined variable, so your code should throw an error";
  a = 1;
  println "This shouldn't be visible";
  println a;
}
