#include<stdio.h>
#include<conio.h>
#define MAX 100
#define inputfile "dfs1.txt"

int LuuVet[MAX];
int ChuaXet[MAX];
struct QUEUE
{
	int size;
	int a[MAX];
};
typedef struct GRAPH
{
	int n;
	int a[MAX][MAX];               
}DOTHI;
void KhoiTaoQueue(QUEUE &Q)
{
	Q.size=0;
}
int DayGiaTriVaoQueue(QUEUE &Q,int x)
{
	if(Q.size+1>=100)
		return 0;
	Q.a[Q.size]=x;
	Q.size++;
	return 1;
}
int LayGiaTriRaKhoiQueue(QUEUE &Q,int &x)
{
	if(Q.size<=0)
		return 0;
	x=Q.a[0];
	for(int i=0;i<=Q.size-1;i++)
	{
			Q.a[i]=Q.a[i+1];
		Q.size--;
	}
	return 1;	
}
int KiemTraQueueRong(QUEUE Q)
{
	if(Q.size<=0)
		return 1;
	return 0;
}
//======================================================
int DocMaTranKe(const char* TenFile,DOTHI &g)
{
	FILE* f;
	f = fopen(TenFile,"rt");
	if(f==NULL)
	{
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i=0;i<g.n;i++)
		for(int j=0;j<g.n;j++)
			fscanf(f,"%d",&g.a[i][j]);
	fclose(f);
	return 1;
}
void XuatMaTranKe(DOTHI g)
{
	printf("So dinh cua do thi = %d\n",g.n);
	printf("Ma tran ke cua do thi (%s) la:\n\n",inputfile);
	for(int i=0;i<g.n;i++)
	{	for(int j=0;j<g.n;j++)
			printf("%4d",g.a[i][j]);
		printf("\n");
	}
}
//================================================================
int KiemTraMaTranKeHopLe(DOTHI g)
{
	int i;
	for(i=0;i<g.n;i++)
	{
		if(g.a[i][i]!=0)
		return 0;
	}
	return 1;
}
//================================================================
void duongdi_DQ(int S,int F)
{
	if(F!=S) duongdi_DQ( S,LuuVet [F]);
	printf("%d -> ",F);
}
void Xuatduongdi(int S,int F)
{
	int i= F; 
		printf("%d", F);
		while(i!=S)
		{
			printf("<- %d",LuuVet[i]);
			i=LuuVet[i];
		}	
}
void BFS(int v, DOTHI g)
{
	QUEUE Q;
	KhoiTaoQueue(Q);
	DayGiaTriVaoQueue(Q,v);
	while(! KiemTraQueueRong(Q))
	{
		LayGiaTriRaKhoiQueue(Q, v);
		ChuaXet[v] = 1;
		for(int u=0; u<g.n; u++)
		{
			if(g.a[v][u] !=0 && ChuaXet[u] == 0 && LuuVet[u] == -1)
			{
				DayGiaTriVaoQueue(Q,u);
				LuuVet[u] = v;
			}
		}
	}
}
//================================================================
void DuyetTheoBFS(int S, int F, DOTHI g)
{
	for(int u=0; u<g.n; u++)
	{
		LuuVet[u] = -1;
		ChuaXet[u] = 0;
	}
	BFS(S, g);
	if(ChuaXet[F] == 1)
	{
		printf("\n BFS: Duong di tu dinh %d -> %d la: \n\t", S, F);
		Xuatduongdi(S,F);
		printf("\n BFS: Duong di DQ tu dinh %d -> %d la: \n\t", S, F);
		duongdi_DQ(S,F);
		printf("\b\b\b\b.    \n");
	}
	else printf("\n Khong co duong di tu dinh %d -> %d.\n", S, F);
}
//===============================================================
int main()
{
	DOTHI g;
	if(DocMaTranKe(inputfile,g)==1)
	{
		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
		XuatMaTranKe(g);   
		getch();
		if(KiemTraMaTranKeHopLe(g)==1)
			printf("\nDo thi hop le.\n");
		else                                                            
			printf("\nDo thi khong hop le.\n");
		getch();
		DuyetTheoBFS(0,2,g);
	}
}



