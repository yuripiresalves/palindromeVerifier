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
    /*
        if ((palavra[i] == -96) || (palavra[i] == -58) || (palavra[i] == -125))
        {
            palavra[i] =97;
        }


        if ((palavra[i] == -126) || (palavra[i] == -120) || (palavra[i] == -118))
        {
            palavra[i] =101;;
        }


        if ((palavra[i] == -95) || (palavra[i] == -115) || (palavra[i] == -116))
        {
            palavra[i] =105;
        }
                                                                                            // Codigo para tirar os acentos

        if ((palavra[i] == -94) || (palavra[i] == -107) || (palavra[i] == -109))
        {
            palavra[i] =111;
        }


        if ((palavra[i] == -105) || (palavra[i] == -93) || (palavra[i] == -106))
        {
            palavra[i] =117;
        }
     */
    }

  }

  x = ElementoEsquerdaFilaDupla(D);
  y = ElementoDireitaFilaDupla(D);

  while(x == y)
  {
    D = RemoveEsquerdaFilaDupla(D, x);
    D = RemoveDireitaFilaDupla(D, y);

    x = ElementoEsquerdaFilaDupla(D);
    y = ElementoDireitaFilaDupla(D);
    if( FilaDuplaVazia(D) == 1 )
        break;
  }



  printf("\n%c", x);
  printf("\n%c", y);

  // for (int i = 0; i <= 5; i++)
  // {
  //   printf("%c\n", D.Elem[i]);
  // }

    printf("\n");
  for (int j = D.Esq + 1; j <= D.Dir; j++)
  {
    printf("%c\n", D.Elem[j]);
  }

  return 0;
}

