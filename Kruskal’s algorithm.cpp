/*
    Kruskal's algorithm
    O(E lg V)
    |V| = numero de nodos
    |E| = numero de aristas
*/
#include<stdio.h>
#include<utility>
#include<algorithm>
#define a first
#define b second
using namespace std;
struct p
{
    pair<int,int> nodos;
    int w;
}G[100000];
bool cmp(p var1, p var2)
{
    return var1.w<var2.w;
}
int n,x,y,z,m;
int h[100000],c[1000000],indi=0;
pair<int,int> MSP[100000];
int find_set(int u)
{
    if(c[u]==u) return u;
    return c[u]=find_set(c[u]);
}
int main()
{
    /// dado un grafo no dirigido de n nodos con m aristas
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        G[i].nodos.a=min(x,y);
        G[i].nodos.b=max(x,y);
        G[i].w=z;
    }
    /// ordenar todas las aristas por su peso de manera no decreciente
    sort(G,G+m,cmp);


    for(int i=1; i<=n; i++) c[i]=i;

    for(int i=0; i<m; i++)
    {
        x=find_set(G[i].nodos.a);
        y=find_set(G[i].nodos.b);
        if(x!=y) /// si la arista (G[i].nodo.a,G[i].nodo.b) no forma un ciclo en nuestro MSP la agregamos
        {
            if(h[x]<h[y])
            {
                c[x]=y;
            }
            if(h[x]>h[y])
            {
                c[y]=x;
            }
            if(h[x]==h[y])
            {
                c[x]=y;
                h[y]++;
            }
            MSP[indi++]=G[i].nodos;
        }
    }
    printf("MSP:\n");
    for(int i=0; i<indi; i++) printf("%d %d\n",MSP[i].a,MSP[i].b);
    return 0;
}
