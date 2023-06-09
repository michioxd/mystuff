#include <stdio.h>
#include<stdlib.h>
#define MAX 10
#define inputfile "ceuler.txt"
typedef struct GRAPH{
	int n;
	int a[MAX][MAX];
}DOTHI;
int Docfile( char tenfile[100], DOTHI &g){
	FILE* f;
	f=fopen(tenfile,"rt");
	if(f==NULL){
		printf("khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	int i,j;
	for(i=0;i<g.n;i++){
		for(j=0;j<g.n;j++){
			fscanf(f,"%d",&g.a[i][j]);
		}
			
	}
	fclose(f);
    return 1;
}
void Xuatfile(DOTHI g){
	printf("So dinh cua do thi la: %d \n", g.n);
	printf("Ma tran ke cua do thi la: \n");
	for(int i=0;i<g.n;i++){
		for(int j=0;j<g.n;j++){
			printf("%d\t", g.a[i][j]);	
		}
		printf("\n");
	}
}
struct STACK
{
	int array[100];
	int size;
};
void KHOITAOSTACK(STACK & stack)
{
	stack.size=0;
}
void DAYGIATRISTACK(STACK& stack, int value)
{
	if(stack.size +1 >=100)
		return;
	stack.array[stack.size]=value;
	stack.size++;
}

int TIMBACCUADINH(DOTHI g){
	
}
void TIMDUONGDI(int i,DOTHI & g, STACK & stack)
{
	for(int j=0; j<g.n;j++)
	{
		if(g.a[i][j]!=0)
		{
			g.a[i][j]=g.a[j][i]=0;
			TIMDUONGDI(j,g,stack);
		}
	}
	DAYGIATRISTACK(stack,i);
}
int KIEMTRACHUTRINHEULER(DOTHI g)
{
	int x=0;
	int flag=0;
	for(int i=0;i<g.n;i++)
	{
		for(int j=0;j<g.n;j++)
		{
			if(g.a[i][j]!=0){
				x=i;
				flag=1;
				break;
			}
		}
		if(flag==1)
		break;
	}
	DOTHI temp=g;
	STACK stack;
	KHOITAOSTACK(stack);
	TIMDUONGDI(x,temp,stack);
	for(int i=0;i<temp.n;i++)
	{
		for(int j=0;j<temp.n;j++)
		{
			if(temp.a[i][j] != 0)
			return 0;
		}
	}
	if(stack.array[stack.size - 1] != stack.array[0])
		return 0;
	printf("\n Chu trinh Euler:");
	for(int i= stack.size - 1;i>= 0;i--)
		printf("%5d",stack.array[i]);
	return 1;
}
int KiemTraDuongDiEuler(DOTHI g){
	int i,j;
	int x = 0;
	int flag=0;
	int bac = 0;
	for(i=0;i<g.n;i++){
		bac = 0;
		for(j=0;j<g.n;j++){
			if(g.a[i][j] != 0){
			bac++;
			}
		}
		if(bac % 2 != 0){
		x =i;
		flag=1;
		break;
		}
	}
	if(flag==0)
	return 0;
DOTHI temp = g;
STACK stack;
KHOITAOSTACK(stack);
TIMDUONGDI(x,temp,stack);
	for(i=0;i<temp.n;i++){
		for(j=0;j<temp.n;j++){
		if(temp.a[i][j] != 0)
			return 0;
	}
	}
if(stack.array[stack.size - 1] == stack.array[0])
return 0;
printf("\nDuong di Euler: ");
for(i= stack.size - 1;i>= 0;i--)
printf("%5d ",stack.array[i]);
return 1;
}
int main()
{
	DOTHI g;
	int x;
	if(Docfile(inputfile, g) == 1)
	{
		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
		Xuatfile(g);
	}
	KIEMTRACHUTRINHEULER(g);
	KiemTraDuongDiEuler(g);
	return 0;
}

