#include <stdio.h>
#include <math.h>

int ScurityCode(int SecuPin, int name);

int main()
{

    int SecuPin, name;
    ScurityCode(SecuPin, name);
    return 0;
}

int ScurityCode(int SecuPin, int name)
{
    int Choose;

    printf("please choose a way to set your security code :\n");
    printf("1 : PinMaker : yow will choose 3 integer and we will make your security pin.\n");
    printf("2 : Set your security code.\n");
    printf("3 : choose 3 for finishing the process of making security code.\n");

    do
    {
        scanf("%d", &Choose);
        if(Choose > 3 || Choose <= 0)
        {
            printf("Pleas choose from numbers that you have permission!\n\n");
        }
    }while(Choose > 3 || Choose <= 0);

    if(Choose == 1)
    {
        int ReDo;
        int SecuPin;
        int ForUpdater;
        int Scan[3];
        char cast[8];
        do
        {
        printf("Please set your security pin : \n");
        printf("First choose 3 integer from 1 to 5 : \n");
        printf("%c\t\t\t", 0xba);
        scanf("%d", &Scan[0]);
        printf("%c\t\t\t", 0xba);
        scanf("%d", &Scan[1]);
        printf("%c\t\t\t", 0xba);
        scanf("%d", &Scan[2]);

        for(ForUpdater = 1; ForUpdater <= Scan[2]; ForUpdater++)
        {
            SecuPin = Scan[0] + Scan[1];
            Scan[0] = Scan[1];
            Scan[1] = SecuPin;
            SecuPin = pow(SecuPin, 5);
        }

        sprintf(cast, "%d", SecuPin);

        printf("%c",0xc9);
        int Chart1 = 40;
        int CharUpd1;
        for(CharUpd1 = 0; CharUpd1 < Chart1; CharUpd1++)
        {
            printf("%c", 0xcd);
        }
        printf("%c\n", 0xbb);
        printf("%c", 0xba);
        printf("                                        %c\n", 0xba);
        printf("%c         Your PIN code : %s                    \n",0xba, cast);
        printf("%c", 0xba);
        printf("                                        %c\n", 0xba);

        printf("%c",0xc8);
        int Chart2 = 40;
        int CharUpd2;
        for(CharUpd2 = 0; CharUpd2 < Chart2; CharUpd2++)
        {
            printf("%c", 0xcd);
        }
        printf("%c\n", 0xbc);
        if(SecuPin < 0)
        {
            printf("Pleas choose from numbers that you have permission!\n\n");
        }
        }while(SecuPin < 0);
    }

    else if(Choose == 2)
    {
        printf("Please enter your security code:\n");

        char name[15];
        scanf("%15s", name); //Becuse name is a array, we don't need &.

        printf("\nYour security code is: %s\n", name);

        int N = sizeof(name)/sizeof(name[0]);
        printf("Maximum security code length: %d\n", N);

        int M = 0;
        int i;
        for(i = 0; i < N; i++)
        {
            if(name[i] == '\0') break;
            M++;
        }
        printf("Length of your security code is: %d\n", M);
    }
}


