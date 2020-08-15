#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define scanf scanf_s
int main()
{
    int a[100], amount, Max = 0, Min = 0, temp = 0;
    scanf("%d", &amount);
    if (amount < 0)
    {
        printf("Error");
        return 0;
    }
    for (int i = 0;i < amount;i++) //Input ,find max min
    {

        scanf("%d", &a[i]);
        if (a[i] >= 0) temp += a[i];
        else temp -= a[i];
        if (i == 0)
        {
            Max = a[i];
            Min = a[i];
        }
        if (a[i] >= Max) Max = a[i];
        if (a[i] <= Min) Min = a[i];

    }
    //printf("Max = %d Min = %d \n",Max,Min);
    //printf("Temp : %d\n",temp);
    if (Min < 0) Min = -Min;
    if (Max < 0) Max = 1;
    //printf("%d %d",Max,Min);
    for (int j = 0;j < Max + Min;j++)
    {
        if (j == Max - 1) //BASE
        {
            for (int i = 0;i < temp;i++)
            {
                printf("* ");
            }
        }
        for (int i = 0;i < amount;i++)
        {
            if (a[i] == 0) continue;
            if (j < Max - 1) //up
            {
                if (a[i] < 0) //space
                {
                    for (int k = 0;k < -a[i] * 2;k++)
                    {
                        //printf("-");
                        printf(" ");
                    }

                }
                if (Max - a[i] - j > 0) //space up
                {
                    for (int k = 0;k < a[i] * 2;k++)
                    {
                        //printf("-");
                        printf(" ");
                    }
                }
                else
                {
                    for (int k = 0;k < a[i] - 1 - j + (Max - a[i]);k++)
                    {
                        printf(" ");
                    }
                    for (int k = 0;k < j + 1 - (Max - a[i]);k++)
                    {
                        printf("* ");
                    }
                    for (int k = 0;k < a[i] - 1 - j + (Max - a[i]);k++)
                    {
                        printf(" ");
                    }
                }
            }
            if (j > Max - 1)
            {

                if (a[i] > 0) //space
                {
                    for (int k = 0;k < a[i] * 2;k++)
                    {
                        printf(" ");
                    }

                }
                else
                {
                    //printf("*%d*",-a[i]-j+Max-1);
                    for (int k = 0;k < j - Max + 1 && k < -a[i];k++)
                    {
                        printf(" ");
                    }
                    for (int k = 0;k < -a[i] - j + Max - 1;k++)
                    {
                        printf("* ");
                    }
                    for (int k = 0;k < j - Max + 1 && k < -a[i];k++)
                    {
                        printf(" ");
                    }
                }
            }



        }
        printf("\n");
    }
}
