#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float pole;
    float obwod;
    float midx;
    float midy;
    float cienx;
    float cieny;
    float rozpietosc;

} dane;

int pobierz_dane(char *nazwa, dane *wynik);
int main()
{

    char openpath[50]="test.txt.txt";
    dane wynik[50];
    printf("Podaj ˜cie¾k© do pliku\n");
    gets(openpath);
    printf("%s\n",openpath);
    pobierz_dane(openpath, wynik);


    return 0;
}


pobierz_dane(char *nazwa, dane *wynik)
{
    dane record[30];
    int i=0;
    int j,licznik=0;
    char lyne [121];
    char *item;
    int k;
    int reccount = 0;

    FILE *fp;
    fp=fopen(nazwa,"r");
    if(fp==NULL)
    {
        printf("Bˆ¥d otwarcia pliku");
        return 0;
    }


    while(fgets(lyne,120,fp))
    {
        printf ("%s",lyne);

        item = strtok(lyne,"\t");
        record[reccount].pole = atof(item);

        item = strtok(NULL,"\t");
        record[reccount].obwod = atof(item);

        item = strtok(NULL,"\t");
        record[reccount].midx = atof(item);

        item = strtok(NULL,"\t");
        record[reccount].midy = atof(item);

        item = strtok(NULL,"\t");
        record[reccount].cienx = atof(item);

        item = strtok(NULL,"\t");
        record[reccount].cieny = atof(item);

        item = strtok(NULL,"\n");
        record[reccount].rozpietosc = atof(item);

        reccount++;




    }


        if (ferror(fp))
        {

            printf("Blad zapisu\n");
            return 1;
        }




    fclose(fp);

    printf("\n Tablica \n");
        for (k=0; k<reccount; k++) {
                printf("Pole  %0.2f \n",record[k].pole);
                printf("Obwod %0.2f \n",record[k].obwod);
                printf("midx %0.2f \n",record[k].midx);
                printf("midy %0.2f \n",record[k].midy);
                printf("cienx %0.2f \n",record[k].cienx);
                printf("cieny %0.2f \n",record[k].cieny);
                printf("rozpietosc %0.2f \n",record[k].rozpietosc);
                printf("\n");
                }



    return 0;

}
