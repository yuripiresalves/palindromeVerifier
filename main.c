#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct TpFilaDupla
{
  char Elem[200];
  int Esq;
  int Dir;
};

int TamMax = 200;
char x;
char y;
char original[200];

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

char *RemoveAcentuacao(char palavra[200])
{
  strcpy(original, palavra);
  for (int i = 0; i <= strlen(palavra); i++)
  {
    if ((palavra[i] == -95) || (palavra[i] == -96) || (palavra[i] == -93) || (palavra[i] == -94) || (palavra[i] == -125) || (palavra[i] == -126) || (palavra[i] == -127) || (palavra[i] == -128))
      palavra[i] = 97;

    if ((palavra[i] == -86) || (palavra[i] == -87) || (palavra[i] == -118) || (palavra[i] == -119) || (palavra[i] == -94))
      palavra[i] = 101;

    if ((palavra[i] == -83) || (palavra[i] == -115))
      palavra[i] = 105;

    if ((palavra[i] == -75) || (palavra[i] == -76) || (palavra[i] == -77) || (palavra[i] == -108) || (palavra[i] == -107) || (palavra[i] == -109))
      palavra[i] = 111;

    if ((palavra[i] == -170) || (palavra[i] == -102))
      palavra[i] = 117;
    if ((palavra[i] == -89))
      palavra[i] = 99;
  }
  char *resultado = palavra;
  return resultado;
}

int main()
{
  struct TpFilaDupla D;
  D = InicializaFilaDupla(D);
  char palavra[200];

  printf("Digite a palavra ou frase: ");
  fgets(palavra, 200, stdin);

  RemoveAcentuacao(palavra);

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

  char *pos;
  if ((pos = strchr(original, '\n')) != NULL)
    *pos = '\0';

  if (FilaDuplaVazia(D) == 1)
  {
    printf("\n%s eh um palindromo!", original);
  }
  else
  {
    printf("\n%s NAO eh um palindromo!\n", original);
  }
  return 0;
}