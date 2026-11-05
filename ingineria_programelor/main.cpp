#include <stdio.h>
#include <stdlib.h>

int functia_fitness(const int v[], int n)
{
    int conf=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(abs(i-j)==abs(v[i]-v[j]))
            {
                conf++;
            }

            if (v[i]==v[j])
            {
                conf++;
            }
        }
    }
    return conf;
}

int main()
{
    int n=4;
    int individ[]={2, 4, 1, 3};
    printf("Fitness: %d\n", functia_fitness(individ - 1, n));
    return 0;
}