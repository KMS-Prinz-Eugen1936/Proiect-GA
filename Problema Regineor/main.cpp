#include <bits/stdc++.h>
using namespace std;
//RNGesus help us.
random_device rd;
mt19937 gen(rd());
int Queen_Pop;
uniform_int_distribution<int> random_mut(1, 100);
int Pop_Size;
int mutation_chance=5;
//Functions Galore
void generate_initial_population(vector<vector<int>>& Population, int Queen_Pop, int Pop_Size) {
    uniform_int_distribution<int> random_Pop(1, Queen_Pop);
    for (int i=1;i<=Pop_Size;i++)
        for (int j=1;j<=Queen_Pop;j++)
            Population[i][j] = random_Pop(gen);
}

int fitness(vector<vector<int>>Population, int Queen_Pop, int INDEX) {
    int conflict=0;
    for (int i=1;i<Queen_Pop;i++)
        for (int j=i+1;j<=Queen_Pop;j++) {
            if (Population[INDEX][i]==Population[INDEX][j])
                conflict++;
            if (abs(i-j)==abs(Population[INDEX][i]-Population[INDEX][j]))
                conflict++;
        }
return conflict;
}

void parent_selection(vector<vector<int>>& Population,int Queen_Pop,int Pop_Size,int P1[],int P2[]) {
    uniform_int_distribution<int> random_parent(1, Pop_Size);

    // Select Parent 1
    int A = random_parent(gen);
    int B = random_parent(gen);

    if (fitness(Population, Queen_Pop, A) <
        fitness(Population, Queen_Pop, B))
        for (int i = 1; i <= Queen_Pop; i++)
            P1[i] = Population[A][i];
    else
        for (int i = 1; i <= Queen_Pop; i++)
            P1[i] = Population[B][i];

    // Select Parent 2
    A = random_parent(gen);
    B = random_parent(gen);

    if (fitness(Population, Queen_Pop, A) <
        fitness(Population, Queen_Pop, B))
        for (int i = 1; i <= Queen_Pop; i++)
            P2[i] = Population[A][i];
    else
        for (int i = 1; i <= Queen_Pop; i++)
            P2[i] = Population[B][i];
}

int main() {
    cout<<"Insert number of Queens:";
    cin>>Queen_Pop;
    cout<<endl;
    cout<<"Please Insert starting Population:";
    cin>>Pop_Size;
    cout<<endl;
    vector<vector<int>> Population(Pop_Size+1, vector<int>(Queen_Pop+1, 0));
    vector<vector<int>> Next_Population(Pop_Size+1, vector<int>(Queen_Pop+1, 0));
    cout<<"Running RNG,please wait...Done";
    cout<<endl;
    generate_initial_population(Population, Queen_Pop, Pop_Size);

    return 0;
}