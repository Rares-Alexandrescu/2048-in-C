#include "Librarie_2048.h"

int main()
{
    srand(time(NULL));
    //informatii despre joc si cateva chestii implementate in viitor...
    printf("---------------------2048----------------------\n");
    printf("Comenzi : (S)alvare, (U)ndo, (L)oad si sagetile pentru a manipula matricea! \n");
    printf("Vrei sa incepi un nou joc?\n");
    int **matrice, **salvare, **previous, n, punctaj_max=0;
    char litera;
    while(scanf("%c", &litera) && (litera=='y' || litera=='Y'))
    {
        int punctaj=0;
        getchar();
        int OK=1;
        printf("\n\rCat de mare vrei sa fie matricea?");
        scanf("%d", &n);
        initializare_matrice(&matrice, n);
        initializare_matrice(&salvare, n);//pentru save
        initializare_matrice(&previous, n);//pentru undo
        atribuire_numere(&matrice, n);
        afisare(matrice, n);
        while(OK==1)
        {
            OK=input(&matrice,&salvare, &previous,&punctaj, n);
            system("cls");
            //afisare(matrice, n);
            afisare(matrice, n);
        }
        if(punctaj_max<punctaj)
            punctaj_max=punctaj;
        printf("\n \rScor curent : %d \n \rScor maxim : %d \n", punctaj, punctaj_max);
        if(OK==0)
        {
            printf("Nicio mutare posibila\n");
        }
        else if(OK==2)
        {
            printf("Felicitari!\n");
        }
        printf("Vrei sa incepi un nou joc?\n");
        eliberare_tabela(&matrice, n);
        eliberare_tabela(&salvare, n);
        eliberare_tabela(&previous, n);
        while(getchar()!='\n');
    }
    return 0;
}

