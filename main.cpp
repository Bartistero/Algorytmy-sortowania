#include <iostream>
using namespace std;
int *wczytanie(int *n);
void babelkowe(int n,int tab[]);
void wstawianie(int n,int tab[]);
void wybieranie(int n,int tab[]);
int main()
{
    int n,*tab;
    tab=wczytanie(&n);
    //babelkowe(n,tab);
    wybieranie(n,tab);
    for(int i=0;i<n;i++) cout<<tab[i]<<endl;
    return 0;
}
int *wczytanie(int *n)
{
    cout<<"ile liczb do wczytania ? "<<endl;
    cin>>*n;
    int *tab = new int[*n];
    for(int i=0;i<*n;i++)

        {
            cout<<"podaj "<<i+1<<" liczbe"<<endl;
            cin>>tab[i];
        }
    return tab;
}
void babelkowe(int n,int tab[])
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1;j++)
            if(tab[j]>tab[j+1]) swap(tab[j],tab[j+1]);
}
void wstawianie(int n,int tab[])
{
    int pom,j;
    for(int i=1;i<n;i++)
    {

        pom=tab[i];
        j=i-1;
        while(j>=0 && tab[j]>pom)
        {
            tab[j+1]=tab[j];
            j--;
        }
        tab[j+1]=pom;
    }
}
void wybieranie(int n,int tab[])
{
    int index=0;
    for(int i=n;i>0;i--)
    {
        index=i;
        for(int j=i;j>=0;j--)
        {
            if(tab[j]>tab[index])
                index=j;
        }
        swap(tab[index],tab[i]);
    }
}
