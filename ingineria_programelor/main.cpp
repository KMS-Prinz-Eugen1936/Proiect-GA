#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POP_SIZE 50
#define N 8
#define NR_GEN 500

double pop_mut=5.0/100.0;
int populatie[POP_SIZE][N];
int temp_gen[POP_SIZE][N];

int functia_fitness(const int v[],int n)
{
    int conf=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(abs(i-j)==abs(v[i]-v[j]))
                conf++;
            if(v[i]==v[j])
                conf++;
        }
    }
    return conf;
}

void selectia_parintilor(int *p1,int *p2)
{
    *p1=rand()%POP_SIZE;
    *p2=rand()%POP_SIZE;
}

void generete_initial_population()
{
    for(int i=0; i<POP_SIZE; i++)
    {
        for(int j=0; j<N; j++)
            populatie[i][j]=1+rand()%N;
    }
}

void recombinare(int p1,int p2,int c1[N],int c2[N])
{
    int pct_taiere=1+rand()%(N-1);
    for(int i=0; i<N; i++)
    {
        if(i<pct_taiere)
        {
            c1[i]=populatie[p1][i];
            c2[i]=populatie[p2][i];
        }
        else
        {
            c1[i]=populatie[p2][i];
            c2[i]=populatie[p1][i];
        }
    }
}

void mutatie()
{
    for(int i=0; i<POP_SIZE; i++)
    {
        for(int j=0; j<N; j++)
        {
            double r=(rand()%101)/100.0;
            if(r<pop_mut)
                temp_gen[i][j]=1+rand()%N;
        }
    }
}

void supravietuire()
{
    for(int i=0; i<POP_SIZE; i++)
    {
        for(int j=0; j<N; j++)
            populatie[i][j]=temp_gen[i][j];
    }
}

double med_fitness(int pop[POP_SIZE][N])
{
    double total=0;
    for(int i=0; i<POP_SIZE; i++)
        total+=functia_fitness(pop[i]-1,N);
    return total/POP_SIZE;
}

void sorteaza_populatie()
{
    for(int i=0; i<POP_SIZE-1; i++)
        for(int j=i+1; j<POP_SIZE; j++)
            if(functia_fitness(populatie[i]-1,N)>functia_fitness(populatie[j]-1,N))
                for(int k=0; k<N; k++)
                {
                    int aux=populatie[i][k];
                    populatie[i][k]=populatie[j][k];
                    populatie[j][k]=aux;
                }
}

int main()
{
    srand(time(NULL));
    generete_initial_population();

    for(int i=0; i<NR_GEN; i++)
    {
        printf("generatia: %d\n",i);
        printf("%f\n",med_fitness(populatie));
        for(int j=0; j<POP_SIZE/2; j++)
        {
            int p1,p2;
            selectia_parintilor(&p1,&p2);
            recombinare(p1,p2,temp_gen[2*j],temp_gen[2*j+1]);
        }
        mutatie();
        supravietuire();
        sorteaza_populatie();
    }

    printf("populatia finala:\n");
    printf("%f\n",med_fitness(populatie));
    for(int i=0; i<POP_SIZE; i++)
    {
        printf("[");
        for(int j=0; j<N; j++)
            printf("%d%s",populatie[i][j],j<N-1?", ":"");
        printf("] %d\n",functia_fitness(populatie[i]-1,N));
        printf("Media fitness: %f\n",med_fitness(populatie));
    }
    return 0;
}