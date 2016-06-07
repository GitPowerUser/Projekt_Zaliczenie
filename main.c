#include <stdio.h>
#include <stdlib.h>
int pobierz_dane(char *nazwa);
int main()
{

    char openpath[50]="test.txt.txt";
    //printf("Podaj droge do pliku\n");
    //gets(openpath);
    //printf("%s\n",openpath);
    pobierz_dane(openpath);

    return 0;
}


pobierz_dane(char *nazwa)
{
    int i=0;
    char ch[500][50];
    double tablica[200][6]; /*
                            0 - POLE
                            1 - OBWÓD
                            2 - ŒRODEK X
                            3 - ŒRODEK Y
                            4 - CIEÑ X
                            5 - CIEÑ Y
                            6 - ROZPIÊTOŒÆ
                            */

    FILE *fp;
    fp=fopen(nazwa,"r");
    if(fp==NULL)
    {
        printf("Blond otwarcia pliku");
        return 0;
    }


    while(!feof(fp))
    {
        if (fgets(ch, 500, fp) ==NULL)
        {
            if (feof(fp))
                break;
            else
            {
                puts("Blad otwarcia pliku");
                fclose (fp);
                return 0;


            }
            fp=fopen(nazwa,"r");
        }
        printf("%s",ch);
    }





        if (ferror(fp))
        {

            printf("Blad zapisu\n");
            return 1;
        }



    fclose(fp);
    return 0;

}
