#include <stdio.h>

struct TpFilaDupla
{
  char Elem[100];
  int Esq;
  int Dir;
};

int TamMax = 100;

struct TpFilaDupla InicializaFilaDupla(struct TpFilaDupla D)
{
  D.Esq = TamMax / 2;
  D.Dir = D.Esq;

  return D;
}

int FilaDuplaVazia(struct TpFilaDupla D)
{
  if (D.Esq == D.Dir)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  struct TpFilaDupla D;
  D = InicializaFilaDupla(D);

  if (FilaDuplaVazia(D) == 1)
  {
    printf("ta vazio");
  }

  return 0;
}