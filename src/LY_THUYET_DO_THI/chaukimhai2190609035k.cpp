#include<stdio.h>
#include<stdlib.h>
#define Max 100
#define inputfile"C:/.txt"

typedef struct graph{	
	int n;
	int a[Max][Max];
}DOTHI;

int ChuaXet[Max]; 
typedef struct EDGE 
{
int u;
int v;
int value;
}CANH;

CANH T[Max]; 

int DocMaTranKe(char TenFile[100], DOTHI &g)
{
FILE* f; 
f = fopen(TenFile, "rt");
if (f == NULL)
{
printf("Khong mo duoc file\n");
return 0; 
}
fscanf(f, "%d", &g.n);

int i, j;
for (i=0; i<g.n; i++)
{
    for (j=0; j<g.n; j++)
        fscanf(f, "%d", &g.a[i][j]); 
}
fclose(f);

return 1; 
}
void XuatMaTranKe (DOTHI g)
{
printf("So dinh cua do thi la %d\n", g.n);
printf("Ma tran ke cua do thi la\n");
for (int i = 0; i < g.n; i++)
{
printf ("\t");
for (int j = 0; j < g.n; j++)
{
printf("%d ",g.a[i][j]);
}
printf("\n");
}
}
int KiemTraMaTranKeHopLe(DOTHI g)
{
int i;
for (i=0; i<g.n; i++)
{
if (g.a[i][i] != 0)
return 0;
}
return 1;
}
void sapxeptang(CANH E[100],int tongsocanh)
{
	CANH canhtam;
	for(int i=0;i<tongsocanh-1;i++)
	{
		for(int j=i+1;j<tongsocanh;j++)
		   if(E[i].value > E[j].value)
		     {
		     	canhtam=E[i];
		     	E[i]=E[j];
		     	E[j]=canhtam;
			 }
	}
}
void Kruskal(DOTHI g)
{
	CANH listEdge[Max];
	int tongsocanh=0;
	int i,j;
	for(i =0;i<g.n;i++)
	{
		for(j=i+1;j<g.n;j++)
		   if(g.a[i][j]>0)
		   {
		   	listEdge[tongsocanh].u=i;
		   	listEdge[tongsocanh].v=j;
		   	listEdge[tongsocanh].value=g.a[i][j];
		   	tongsocanh++;
		   }
	}
	sapxeptang(listEdge,tongsocanh);
	int nT=0;
	CANH T[Max];
	int Nhan[Max];
	for(i=0;i<g.n;i++)
	   Nhan[i]=i;
	int canhdangxet=0;
	while(nT<g.n && canhdangxet<tongsocanh)
	{
		if(Nhan[listEdge[canhdangxet].u] != Nhan[listEdge[canhdangxet].v])
		{
			T[nT]=listEdge[canhdangxet];
			nT++;
			int giatri=Nhan[listEdge[canhdangxet].v];
			for(j=0;j<g.n;j++)
			   if(Nhan[j]==giatri)
			     Nhan[j]=Nhan[listEdge[canhdangxet].u];
		}
		canhdangxet++;
	}
	if(nT != g.n-1)
	printf("\nDo thi khong lien thong\n");
	else
	{
		int TongTrongSo=0;
		printf("\nDo thi lien thong\n");
		printf("Cay khung nho nhat cua do thi la \n");
		for(i=0;i<nT;i++)
		{
			printf("(%d,%d), ",T[i].u,T[i].v);
			TongTrongSo+=T[i].value;
		}
		printf("\nTong gia tri cua cay khung la:%d\n",TongTrongSo);
	}
}

int main()
{
DOTHI g;

if (DocMaTranKe(inputfile, g) == 1)
{
printf("Da lay thong tin do thi tu file thanh cong.\n\n");
XuatMaTranKe(g);

if(KiemTraMaTranKeHopLe(g) == 1)
  printf("Do thi hop le.\n");
else
  printf("Do thi khong hop le.\n");
  
  Kruskal(g);
}
}
