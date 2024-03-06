#include "Librarie_2048.h"

void initializare_matrice(int ***a, int n)
{
    (*a)=(int **)calloc(n, sizeof(int *));
    for(int i=0;i<n;i++)
        (*a)[i]=(int *)calloc(n, sizeof(int));
}


void eliberare_tabela(int ***a, int n)
{
    for(int i=0;i<n;i++)
        free((*a)[i]);
    free(*a);
    *a=NULL;
}

void afisare(int **a, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
         printf(" %d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}
void copiere_matrice(int ***matrice, int **a, int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          (*matrice)[i][j]=a[i][j];
}

int comparatie_matrici(int **a, int **b, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=b[i][j])
                return 1;
        }
    }
    return 0;
}
void atribuire_numere(int ***a, int n)
{
    int x;
    int y;
    x=rand()%n;
    y=rand()%n;
    while((*a)[x][y]!=0)
    {
       x=rand()%n;
       y=rand()%n;
    }
    if(rand()%17==3)
    (*a)[x][y]=4;
    else
    (*a)[x][y]=2;
}
void insumare_numere(int ***a, int n, int *punctaj, int caz_curent)
{
    int **matrice;
    initializare_matrice(&matrice, n);
    switch(caz_curent)
    {
    case 1: //sus
        for(int j=0;j<n;j++)
        {
            int linie=0;
            for(int i=0;i<n;i++)
            {
                if(i<n-1 && (*a)[i][j]==(*a)[i+1][j] && (*a)[i][j]!=0)
                {
                    matrice[linie][j]=(*a)[i][j]*2;
                    (*punctaj)+=(*a)[i][j]*2;
                    (*a)[i+1][j]=0;
                    linie++;
                }
                else if((*a)[i][j]!=0)
                {
                    matrice[linie][j]=(*a)[i][j];
                    (*a)[i][j]=0;
                    linie++;
                }

            }
        }

        break;
    case 2: //jos
        for(int j=0;j<n;j++)
        {
            int linie=n-1;
            for(int i=n-1;i>=0;i--)
            {
                if(i>0 && (*a)[i][j]==(*a)[i-1][j] && (*a)[i][j]!=0)
                {
                    matrice[linie][j]=(*a)[i][j]*2;
                    (*punctaj)+=(*a)[i][j]*2;
                    (*a)[i-1][j]=0;
                    linie--;
                }
                else if((*a)[i][j]!=0)
                {
                    matrice[linie][j]=(*a)[i][j];
                    (*a)[i][j]=0;
                    linie--;
                }
            }
        }
            break;
    case 3: //stanga
        for(int i=0;i<n;i++)
        {
            int coloana=0;
            for(int j=0;j<n;j++)
            {
                if(j<n-1 && (*a)[i][j]!=0 && (*a)[i][j]==(*a)[i][j+1])
                {
                    matrice[i][coloana]=(*a)[i][j]*2;
                    (*punctaj)+=(*a)[i][j]*2;
                    (*a)[i][j+1]=0;
                    coloana++;
                }
                else if((*a)[i][j]!=0)
                {
                    matrice[i][coloana]=(*a)[i][j];
                    (*a)[i][j]=0;
                    coloana++;
                }
            }
        }

        break;
    case 4: //dreapta
        for(int i=0; i<n;i++)
        {
            int coloana=n-1;
            for(int j=n-1;j>=0;j--)
            {
                if(j>0 && (*a)[i][j]!=0 && (*a)[i][j]==(*a)[i][j-1])
                {
                    matrice[i][coloana]=(*a)[i][j]*2;
                    (*punctaj)+=(*a)[i][j]*2;
                    (*a)[i][j-1]=0;
                    coloana--;
                }
                else if((*a)[i][j]!=0)
                {
                    matrice[i][coloana]=(*a)[i][j];
                    (*a)[i][j]=0;
                    coloana--;
                }
            }
        }
        break;
    }
    copiere_matrice(&(*a), matrice, n);
    eliberare_tabela(&matrice, n);
}
int verificare_prima_miscare(int **a, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=0)
                return 1;
        }
    }
    return 0;
}
int translatie_matrice(int ***a, int n, int caz_curent, int *punctaj)
{
    int linie;
    int coloana;
    int **matrice;
    initializare_matrice(&matrice, n);//pentru matrice;
    //copiere_matrice(&matrice, *a, n);//matrice sa fie t(a)bela
    switch(caz_curent)
    {
    case 1: //sus
       for(int j=0;j<n;j++)
        {
            linie=0;
            for(int i=0;i<n;i++)
            {
            if((*a)[i][j]!=0)
                {
                matrice[linie][j]=(*a)[i][j];
                linie++;
                }
            }
        }
        break;
    case 2: //jos
        for(int j=n-1; j>=0;j--)
         {
             linie=n-1;
             for(int i=n-1;i>=0;i--)
             {
                 if((*a)[i][j]!=0)
                {
                matrice[linie][j]=(*a)[i][j];
                linie--;
                }
             }
         }
        break;
    case 3: //stanga
        for(int i=0;i<n;i++)
         {
             coloana=0;
             for(int j=0;j<n;j++)
             {
                 if((*a)[i][j]!=0)
                 {
                     matrice[i][coloana]=(*a)[i][j];
                     coloana++;
                 }
             }
         }
        break;
    case 4: //dreapta
        for(int i=n-1;i>=0;i--)
        {
            coloana=n-1;
            for(int j=n-1;j>=0;j--)
            {
                if((*a)[i][j]!=0)
                    {
                    matrice[i][coloana]=(*a)[i][j];
                    coloana--;
                    }
            }
        }
        break;
    }
    insumare_numere(&matrice, n, &(*punctaj), caz_curent);
    if(comparatie_matrici(matrice, *a,n)==0)
        return 0;
    copiere_matrice(&(*a), matrice, n);
    
    eliberare_tabela(&matrice, n);
    return 1;

}
int verificare_2048(int **a, int n)
{
    int **m1, **m2, **m3, **m4, p;
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n;j++)
        {
        if(a[i][j]==2048)
            return 2;
        }
    }
    //comparatie si insumare pentru imposobilitatea de miscare?
    initializare_matrice(&m1, n);
    initializare_matrice(&m2, n);
    initializare_matrice(&m3, n);
    initializare_matrice(&m4, n);
    copiere_matrice(&m1, a, n);
    copiere_matrice(&m2, a, n);
    copiere_matrice(&m3, a, n);
    copiere_matrice(&m4, a, n);
    insumare_numere(&m1, n, &p, 1);
    insumare_numere(&m2, n, &p, 2);
    insumare_numere(&m3, n, &p, 3);
    insumare_numere(&m4, n, &p, 4);
    if((!comparatie_matrici(m1, m2, n) && !comparatie_matrici(m2, m3, n) && !comparatie_matrici(m3, m4, n)))
    {
        eliberare_tabela(&m1, n);
        eliberare_tabela(&m2, n);
        eliberare_tabela(&m3, n);
        eliberare_tabela(&m4, n);
        return 0;
    }
    eliberare_tabela(&m1, n);
    eliberare_tabela(&m2, n);
    eliberare_tabela(&m3, n);
    eliberare_tabela(&m4, n);
    return 1;
}
int input(int ***a, int ***salvare, int ***previous, int *punctaj,int n)
{

    char caracter;
    int caz_curent=-1;
    copiere_matrice(&(*previous), *a, n);
    caracter=_getch();
    switch((unsigned char) caracter)
    {
    case 0xE0:
        caracter=_getch();
        switch(caracter)
        {
        case 72: //sus
            caz_curent=1;
            break;
        case 80: //jos
            caz_curent=2;
            break;
        case 75: //stanga
            caz_curent=3;
            break;
        case 77: //dreapta
            caz_curent=4;
            break;
        default:
            printf("Input gresit!?!\n");
            Sleep(2000);
        }
        break;
     case 'S':
            printf("Salvare reusita!\n");
            copiere_matrice(&(*salvare), *a, n);
            caz_curent=-1;
            Sleep(2000);
            break;
     case 'L':
            if(verificare_prima_miscare(*salvare, n))
            {
            printf("Load reusit!\n");
            copiere_matrice(&(*a), *salvare, n);
            }
            else
            printf("Nu exista o salvare precedenta!!!!");
            caz_curent=-1;
            Sleep(2000);
            break;
     case 'U':
            if(verificare_prima_miscare(*previous, n))
            {
                printf("Intoarcere reusita!");
                copiere_matrice(&(*a), *previous, n);
            }
            else
            printf("E prima miscare!");

            caz_curent=-1;
            Sleep(2000);
             break;


    default:
        printf("\n \rNu s-a introdus una buc sagetute/comenzi specificate");
    }
    if(caz_curent!=-1) //caz_curent==-1;
    {

    if(translatie_matrice(&(*a), n, caz_curent, &(*punctaj))==0)
    {
        printf("\n \rMiscare imposibila!\n");
        Sleep(2000);
    }
    else
    {
        atribuire_numere(&(*a), n);
        afisare(*a, n);
    }
    }
    return verificare_2048(*a, n);
}
