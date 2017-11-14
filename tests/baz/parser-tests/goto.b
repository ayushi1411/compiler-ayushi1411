declblock{
int a;
}

codeblock{
  heaven: goto hell if 1 == 1;
  hell: goto heaven if 1 < x[2+y[2]];
  goto hell;
  goto heaven;
}

