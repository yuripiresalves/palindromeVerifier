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
  return 0;
}

int FilaDuplaCheia(struct TpFilaDupla D)
{
  if (D.Esq == -1 && D.Dir == TamMax)
  {
    return 1;
  }
  return 0;
}

struct TpFilaDupla DeslocaFilaDupla(struct TpFilaDupla D)
{
  int desloc;
  if (D.Dir == TamMax)
  {
    desloc = (D.Esq + 1) / 2;

    for (int i = D.Esq + 1; i <= D.Dir; i++)
    {
      D.Elem[i - desloc] = D.Elem[i];
    }

    D.Esq = D.Esq - desloc;
    D.Dir = D.Dir - desloc;

    return D;
  }
  else
  {
    desloc = (TamMax - D.Dir) / 2;

    for (int i = D.Dir; i >= D.Esq + 1; i--)
    {
      D.Elem[i + desloc] = D.Elem[i];
    }

    D.Esq = D.Esq + desloc;
    D.Dir = D.Dir + desloc;

    return D;
  }
}

struct TpFilaDupla InsereDireitaFilaDupla(struct TpFilaDupla D, char x)
{
  if (FilaDuplaCheia(D) == 0)
  {
    if (D.Dir == TamMax)
    {
      D = DeslocaFilaDupla(D);
    }

    D.Dir = D.Dir + 1;
    D.Elem[D.Dir] = x;

    return D;
  }
}

struct TpFilaDupla RemoveEsquerdaFilaDupla(struct TpFilaDupla D, char x)
{
  if (FilaDuplaVazia(D) == 0)
  {
    D.Esq = D.Esq + 1;
    x = D.Elem[D.Esq];

    if (FilaDuplaVazia(D) == 1)
    {
      D = InicializaFilaDupla(D);
    }

    return D;
  }
}

struct TpFilaDupla RemoveDireitaFilaDupla(struct TpFilaDupla D, char x)
{
  if (FilaDuplaVazia(D) == 0)
  {
    x = D.Elem[D.Dir];
    D.Dir = D.Dir - 1;

    if (FilaDuplaVazia(D) == 1)
    {
      D = InicializaFilaDupla(D);
    }

    return D;
  }
}

int main()
{
  struct TpFilaDupla D;
  D = InicializaFilaDupla(D);

  if (FilaDuplaVazia(D) == 1)
  {
    printf("ta vazio\n");
  }

  if (FilaDuplaCheia(D) == 1)
  {
    printf("ta cheia");
  }

  return 0;
}