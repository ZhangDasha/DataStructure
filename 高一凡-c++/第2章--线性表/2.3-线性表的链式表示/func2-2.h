Status equal(int c1, int c2)
{
  if(c1 == c2)
    return TRUE;
  else
    return FALSE;
}

int comp(int a, int b)
{
  if(a == b)
    return 0;
  else
    return (a-b) / abs(a-b);
}

void print(int c)
{
  printf("%d ", c);
}

void print1(int &c)
{
  printf("%d ", c);
}
void print2(int c)
{
  printf("%c ", c);
}

