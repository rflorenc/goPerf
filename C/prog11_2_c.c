#include <stdio.h>
#include <stdlib.h>

typedef struct  /* definição da data */
{
  unsigned int Dia; unsigned int Mes; unsigned int Ano;
} TDATA;

typedef struct elemento  /* definição do elemento */
{
  unsigned int NReg; char Nome[41]; TDATA Data; char Telefone[10];
} TELEM;

typedef struct index  /* definição do elemento */
{
  unsigned int NReg; unsigned int Offset; 
} TINDEX;

/* alusão aos subprogramas */
void Ordenar (TINDEX [], unsigned int);
int Pesquisar (TINDEX [], unsigned int, unsigned int, unsigned int);
void EscreverRegisto (TELEM);

int main (int argc, char *argv[])
{
  FILE *PtFich; TELEM RegFich; TINDEX *IndexTab;
  unsigned int I, NTReg, CodReg; int Status, PosTab;

  if (argc < 2)  /* o número de argumentos é suficiente? */
  {
    fprintf (stderr, "Uso: %s nome do ficheiro\n", argv[0]);
    exit (EXIT_FAILURE);
  }

  /* abertura do ficheiro */
  if ((PtFich = fopen (argv[1], "rb") ) == NULL)
  {
    fprintf (stderr, "Erro na abertura do ficheiro %s\n", argv[1]);
    exit (EXIT_FAILURE);
  }

  /* leitura da dimensão do ficheiro */
  fread (&NTReg, sizeof (unsigned int), 1, PtFich);

  /* alocação da tabela de indexação */
  if ((IndexTab = (TINDEX *) calloc (NTReg, sizeof (TINDEX))) == NULL)
  {
    fclose (PtFich); exit (EXIT_FAILURE);
  }

  /* construção da tabela de indexação */
  I = 0;
  while (fread (&RegFich, sizeof (TELEM), 1, PtFich) == 1)
  {
    /* criação do registo de indexação */
    IndexTab[I].NReg = RegFich.NReg; IndexTab[I].Offset = I;
    I++;
  }

  Ordenar (IndexTab, NTReg);  /* ordenação da tabela de indexação */

  while (1)  /* ciclo infinito */
  {
    do
    {
      /* leitura do registo pretendido */
      printf ("Codigo do registo? "); Status = scanf ("%d", &CodReg);
      scanf ("%*[^\n]"); scanf ("%*c");
    } while (!Status);

    if (!CodReg) break;

    /* pesquisa do registo pretendido na tabela de indexação */
    PosTab = Pesquisar (IndexTab, 0, NTReg-1, CodReg);

    if (PosTab != -1)
    {
      /* colocação no registo pretendido do ficheiro */
      fseek (PtFich, sizeof (unsigned int) + IndexTab[PosTab].Offset * sizeof (TELEM), SEEK_SET);

      /* leitura do registo pretendido do ficheiro */
      fread (&RegFich, sizeof (TELEM), 1, PtFich);

      /* apresentação do registo pretendido no monitor */
      EscreverRegisto (RegFich);
    }
  }

  fclose (PtFich);  /* fecho do ficheiro */

  free (IndexTab);  /* libertação da memória da tabela de indexação */

  return EXIT_SUCCESS;
}

/* definição dos subprogramas */

void Ordenar (TINDEX pseq[], unsigned int pnelem)
{
  unsigned int Indi, Indd; TINDEX Temp;

  for (Indi = 1; Indi < pnelem; Indi++)
  {
    Temp = pseq[Indi];  /* copiar o elemento a ordenar */

    /* deslocar os elementos atrás dele que lhe são maiores */
    for (Indd = Indi; Indd > 0 && pseq[Indd-1].NReg > Temp.NReg; Indd--)
      pseq[Indd] = pseq[Indd-1];

    pseq[Indd] = Temp;  /* inserir o elemento a ordenar na posição */
  }
}

int Pesquisar (TINDEX pseq[], unsigned int pinic, unsigned int pfim, unsigned int pval)
{
  unsigned int Minimo = pinic, Maximo = pfim, Medio;

  while (Minimo <= Maximo)
  {
    Medio = (Minimo + Maximo) / 2;  /* cálculo da posição média */

    if (pseq[Medio].NReg == pval) return Medio;  /* pesquisa com sucesso */

    /* Actualização dos limites do intervalo de pesquisa */
    if (pseq[Medio].NReg > pval) Maximo = Medio - 1;
    else Minimo = Medio + 1;
  }

  return -1;  /* pesquisa sem sucesso */
}

void EscreverRegisto (TELEM preg)
{

  fprintf (stdout, "\n\nNumero de Registo: %d\n", preg.NReg);
  fprintf (stdout, "Nome: %s\n", preg.Nome);
  fprintf (stdout, "Data de aniversário: %02u-%02u-%04u\n", preg.Data.Dia, preg.Data.Mes, preg.Data.Ano);
  fprintf (stdout, "Número de telefone: %s\n", preg.Telefone);
  fprintf (stdout, "\nCarregue em Enter para continuar");
  fscanf (stdin, "%*[^\n]"); fscanf (stdin, "%*c");
}
