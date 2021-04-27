#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct TpFilaDupla
{
  char Elem[100];
  int Esq;
  int Dir;
};

int TamMax = 100;
char x;
char y;

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
    // if (D.Dir == TamMax)
    // {
    //   D = DeslocaFilaDupla(D);
    // }

    D.Dir = D.Dir + 1;
    D.Elem[D.Dir] = x;
    // printf("%c\n", D.Elem[D.Dir]);

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

char ElementoEsquerdaFilaDupla(struct TpFilaDupla D)
{

  if (FilaDuplaVazia(D) == 0)
  {
    return D.Elem[D.Esq + 1];
  }
  else
  {
    printf("Fila Dupla esta vazia!\n");
  }
}

char ElementoDireitaFilaDupla(struct TpFilaDupla D)
{
  if (FilaDuplaVazia(D) == 0)
  {
    return D.Elem[D.Dir];
  }
  else
  {
    printf("Fila Dupla esta vazia!\n");
  }
}

int main()
{
  struct TpFilaDupla D;
  D = InicializaFilaDupla(D);
  char palavra[100];

  printf("Digite a palavra: ");
  fgets(palavra, 100, stdin);

  for (int i = 0; i <= strlen(palavra); i++)
  {
    if (isalpha(palavra[i]))
    {
      D = InsereDireitaFilaDupla(D, tolower(palavra[i]));
    }
  }

  do
  {
    x = ElementoEsquerdaFilaDupla(D);
    y = ElementoDireitaFilaDupla(D);

    D = RemoveEsquerdaFilaDupla(D, x);
    D = RemoveDireitaFilaDupla(D, y);

    if (FilaDuplaVazia(D) == 1)
      break;

  } while (x == y);

  if (FilaDuplaVazia(D) == 1)
  {
    printf("%s eh um palindromo!\n", &palavra);
  }
  else
  {
    printf("%s NAO eh um palindromo!\n", &palavra);
  }

  return 0;
}
