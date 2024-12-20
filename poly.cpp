#include<stdio.h>
#include<math.h>
struct polynomial
{
	int coeff;
	int expo;
};
typedef struct polynomial poly;
void readpolynomial(poly p[],int n);
int addpolynomial(poly p1[],poly p2[],int n1,int n2,poly p3[]);
void printpolynomial(poly p[],int n);
void evaluatepolynomial(poly p[],int n);
void readpolynomial(poly p[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter the coeffient and Exponent:");
		scanf("%d%d",&p[i].coeff,&p[i].expo);
	}
}
int addpolynomial(poly p1[],poly p2[],int n1,int n2,poly p3[])
{
	int i=0,j=0,k=0;
	while(i<n1 && j<n2)
	{
		if(p1[i].expo==p2[j].expo)
		{
			p3[k].coeff=p1[i].coeff+p2[j].coeff;
			p3[k].expo=p1[i].expo;
			i++;
			j++;
			k++;
		}
		else if(p1[i].expo>p2[j].expo)
		{
			p3[k]=p1[i];
			i++;
			k++;
		}
		else
		{
			p3[k]=p2[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		p3[k]=p1[i];
		i++;
		j++;
	}
	while(i<n2)
	{
		p3[k]=p2[j];
		j++;
		k++;
	}
}
void printpolynomial(poly p[],int n)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		printf("%d(x^%d)+",p[i].coeff,p[i].expo);
		printf("%d(x^%d)",p[n-1].coeff,p[n-1].expo);
	}
}
void evaluatepolynomial(poly p[],int n)
{
	int sum=0,i,x;
	printf("\n Enter the value of x:");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		sum=sum+p[i].coeff*pow(x,p[i].expo);
	}
	printf("\n Result=%d\n",sum);
}
int main()
{
	int n1,n2,n3;
	poly p1[10],p2[10],p3[10];
	printf("Enter the number of terms in polynomial 1:");
	scanf("%d",&n1);
	readpolynomial(p1,n1);
	printf("Enter the number of terms in polynomial 2:");
	scanf("%d",&n2);
	readpolynomial(p2,n2);
	printf("\n First polynomial:");
	printpolynomial(p1,n1);
	printf("\n Second polynomial:");
	printpolynomial(p2,n2);
	n3=addpolynomial(p1,p2,n1,n2,p3);
	printf("\n Resultant Polynomial after addition:");
	printpolynomial(p3,n3);
	evaluatepolynomial(p3,n3);
	return 0;
}
