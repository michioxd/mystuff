#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10
//#define inputfile "M:/DFS1.txt"
typedef struct GRAPH{
	int n;
	int a[MAX][MAX];
}DOTHI;
int DocMaTranKe(char TenFile[100],DOTHI &g)
{
	FILE* f;
	f = fopen(TenFile,"rt");
	if(f==NULL)
	{
		printf("khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d", &g.n);
	int i,j;
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++){
			fscanf(f,"%d", &g.a[i][j]);
			
		}
	}
	fclose(f);
return 1;	
}
void XuatMaTranKe(DOTHI g)
{
	printf("So dinh cua do thi la %d",g.n);
	printf("\nMa tran ke cua do thi do la\n");
	for(int i = 0;i<g.n;i++)
	{
		printf("\n");
	    for(int j=0;j<g.n;j++)
	    {
	    	printf(" %d", g.a[i][j]);
		}
		printf("\n");
	}
}
int KiemTraMaTranKeHopLe(DOTHI g)
{
	int i;
	for(i=0;i<g.n;i++)
	{
		if(g.a[i][i] != 0)
		return 0;
	}
	return 1;
}
int LuuVet[MAX];
int ChuaXet[MAX];
void DFS(int v,DOTHI g){
	ChuaXet[v]=1;
	for(int u=0;u<g.n;u++)
		if(g.a[u][v] != 0 && ChuaXet[u] == 0){
			LuuVet[u] = v;
			DFS(u,g);
		}
}
void DuyetDFS(int S,int F,DOTHI g){
	int i;
	for(i=0;i<g.n;i++){
		LuuVet[i]=-1;
		ChuaXet[i]=0;
	}
	DFS(S,g);
	if(ChuaXet[F]==1)
	{
		printf("\n Duong di tu dinh %d -> %d la:\n\t",S,F);
		i=F;printf("%d",F);
		while(LuuVet[i]!=S){
			printf("<- %d",LuuVet[i]);
			i=LuuVet[i];
		}
		printf("<- %d",LuuVet[i]);
	}
	else printf("\n Khong co duong di tu dinh %d -> %d.\n",S,F);
}
int main(){
	DOTHI g;
	char inputfile[100];
	char ch;
	int S,F;
	do{
		printf("\n Nhap Ten File:");
		fflush(stdin); gets(inputfile);
		if(DocMaTranKe(inputfile,g)==1)
			{
				printf("\nlay thong tin thanh cong.\n\n");
				XuatMaTranKe(g);
				printf("\n Nhap dinh bat dau:"); scanf("%d",&S);
				printf("\n Nhap dinh ket thuc:"); scanf("%d",&F);
				DuyetDFS(S,F,g);
			}	
	}while(ch=='Y' || ch=='y');
	return 0;
}



