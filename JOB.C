#include<stdio.h>
int i,k,j,t,c=0,n,profit=0,temp,p[20],d[20],job[20],flag,dead[20];
void swap(int w[],int a,int b)
{
    temp = w[a];
    w[a] = w[b];
    w[b] = temp;
}
int final(int job[],int dead[],int c)
{
  for(i=0;i<c;i++)
  {
    for(j=0;j<c-i-1;j++)
    {
      if(dead[j]>dead[j+1])
      {
	 swap(job,j,j+1);
	 swap(dead,j,j+1);
      }
    }
  }
  return c;
}
void process(int p[],int d[])
{
  clrscr();
  printf("\njobs arranged in max profit order ,are --\n");
  for(i=0;i<n;i++)
 {
   printf("job%d --- profit = %d,,,deadline = %d\n",i,p[i],d[i]);
 }
 k=0;
 for(i=0;i<n;i++)
 {
   flag=0;
   if(k!=0)
   {
       for(t=0;t<k;t++)
       {
	  if(dead[t]==d[i])
	  flag++;
       }
   }
   if(flag==0)
   {
       job[k] = i;
       dead[k] = d[i];
       k++;c++;
       profit = profit + p[i];
   }
 }
}
void sort(int p[],int d[])
{
  for(i=0;i<n;i++)
  {
   for(j=0;j<n-i-1;j++)
   {
      if(p[j]<p[j+1])
      {
	 swap(p,j,j+1);
	 swap(d,j,j+1);
      }
   }
  }
}
int main()
{
 clrscr();
 printf("total no. of jobs\n");
 scanf("%d",&n);
 printf("enter profits of jobs\n");
 for(i=0;i<n;i++)
 scanf("%d",&p[i]);
 printf("enter deadlines of jobs\n");
 for(i=0;i<n;i++)
 scanf("%d",&d[i]);
			sort(p,d);
			process(p,d);
			final(job,dead,c);
 printf("\njob execution order\n\n");

 for(i=0;i<c;i++)
 {
  printf("%d\t",job[i]);
 }
 printf("\nyour total profit is %d",profit);
 getch();
 return 0;
 }