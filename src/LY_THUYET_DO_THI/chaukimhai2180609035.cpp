#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10
typedef struct GRAPH{
	int n;
	int a[MAX][MAX];
}DOTHI;
typedef struct EDGE{
	int u,v,value;
}CANH;
CANH T[MAX];
int ChuaXet[MAX];
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
void timcacdinhlienthong(DOTHI g,int Nhan[],int i)
{
	for(int j=0;j<g.n;j++)
	{
		if(g.a[i][j] !=0 && Nhan[j] != Nhan[i])
		{
			Nhan[j]=Nhan[i];
			timcacdinhlienthong(g,Nhan,j);
		}
	}
}int xetlienthong(DOTHI g)
{
	 int Nhan[MAX];
	 for(int i=0;i<g.n;i++)
	 Nhan[i]=0;
	 int sothanhphanLT=0;
	 for(int i=0;i<g.n;i++)
	 {
	 	if(Nhan[i]==0)
	 	{
	 		sothanhphanLT++;
	 		Nhan[i]=sothanhphanLT;
	 		timcacdinhlienthong(g,Nhan,i);
		 }
	 }
	 printf("\nSo thanh phan lien thong la %d\n",sothanhphanLT);
	 return sothanhphanLT;
}
void Prim (DOTHI g)
{
if (xetlienthong(g) != 1) 
{
printf ("Do thi khong lien thong, do do khong thuc hien duoc thuat toan Prim tim cay khung nho nhat\n");
return;
}
int nT = 0;
for (int i = 0; i < g.n; i++) 

ChuaXet[i] = 0;
ChuaXet[?] = 1; 
while (nT < g.n - 1) 
{
	CANH CanhNhoNhat; 

	int GiaTriNhoNhat = 100; 

	for (int i = 0; i < g.n; i++) 
{
	if (ChuaXet[i] == 1)
{
	for (int j = 0; j < g.n; j++)
	if (ChuaXet[j] == 0 && g.a[i][j] != 0 &&
	GiaTriNhoNhat > g.a[i][j]) 
{
CanhNhoNhat.u = i; 
CanhNhoNhat.v = j;
CanhNhoNhat.value = g.a[i][j];
GiaTriNhoNhat = g.a[i][j]; 
}
}
}
T[nT] = CanhNhoNhat; 
nT++; 
ChuaXet[CanhNhoNhat.v] = 1;
}
int TongTrongSoCuaCayKhung = 0; 
printf ("Cay khung nho nhat cua do thi la \n");
for (int i = 0; i < nT - 1; i++)
{
printf ("(%d,%d), ", T[i].u, T[i].v);
TongTrongSoCuaCayKhung += T[i].value;
}
printf ("(%d,%d).\n", T[nT - 1].u, T[nT - 1].v);
TongTrongSoCuaCayKhung += T[nT - 1].value;
printf ("Tong gia tri cua cay khung la %d\n",TongTrongSoCuaCayKhung);
}


int main(){
	DOTHI g;
	char inputfile[100];
	char ch;
	do{
		printf("\n Nhap Ten File:");
		fflush(stdin); gets(inputfile);
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
  
  Prim(g);
}
}

	}while(ch=='Y' || ch=='y');
	return 0;
}
