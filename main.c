#include <stdio.h>
#include <stdlib.h>
int pobierz_dane(char *nazwa);
int main()
{

    char openpath[50]="test.txt.txt";
    printf("Podaj òcieæk© do pliku\n");
    gets(openpath);
    printf("%s\n",openpath);
    pobierz_dane(openpath);

    return 0;
}


pobierz_dane(char *nazwa)
{
    int i=0;
    char ch[500][50];
    double tablica[200][6]; /*
                            0 - POLE
                            1 - OBW‡D
                            2 - óRODEK X
                            3 - óRODEK Y
                            4 - CIEN X
                            5 - CIEN Y
                            6 - ROZPI®TOóè
                            */

    FILE *fp;
    fp=fopen(nazwa,"r");
    if(fp==NULL)
    {
        printf("Bà•d otwarcia pliku");
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
