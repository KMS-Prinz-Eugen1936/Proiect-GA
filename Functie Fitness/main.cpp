#include <bits/stdc++.h>
using namespace std;

int fitness(int v[4],int n)
{
    int conflicte=0;
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++) {
            if (v[i]==v[j])
                conflicte++;
            if (abs(i-j)==abs(v[i]-v[j]))
                conflicte++;
        }
    return conflicte;
}

int main() {
int individ[4]={3,1,4,2};
    int n=4;
    cout<<fitness(individ,n);
    return 0;
}