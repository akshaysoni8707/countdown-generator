#include<stdio.h>
int calc(int i,int op1,int op2)
{
    switch(i)
    {
    case 0:
        return op1+op2;
    case 1:
        return op1-op2;
    case 2:
        return op1*op2;
    case 3:
        return op1/op2;
    }
}
void forloops(int low,int end,int loops,char name[],int inc,int a[1][4],int ans[3],int n)
{
    int i, l = low, e = end,count= 0;
    char op[4] = {'+','-','*','/'};

    while(loops>0)
    {

        if(inc == 1)
        {
            for(i = low ; i < end; i++)
            {
                if(loops == (n-1))
                {
                    ans[n-(loops+1)]=calc(i,a[0][0],a[0][1]);
                    printf("\n%d%c%d=%d",a[0][0],op[i],a[0][1],ans[n-(loops+1)]);
                }
                else if(loops!=(n-1))
                {
                    ans[n-(loops+1)]=calc(i,ans[n-(loops+2)],a[0][n-loops]);
                    printf("\n%d%c%d=%d",ans[n-(loops+2)],op[i],a[0][n-loops],ans[n-(loops+1)]);
                }

                if(loops > 2)
                {
                    forloops(l,e,loops-1,name,inc,a,ans,n);
                }
                else if(loops > 1)
                {

                    forloops(l,e,loops-1,name,1,a,ans,n);
                    printf("\n");
                }
            }
            loops = 0;
        }

    }

}
int main()
{
    char name[3] = {'k','j','i'};
    int a[1][50];
    int ans[50],n,b=0,loops;
    printf("enter how many numbers");
    scanf("%d",&n);
    for(b=0; b<n; ++b)
    {
        printf("enter no %d  :",b+1);
        scanf("%d",&a[0][b]);
    }
    loops=n-1;
    forloops(0,4,loops,name,1,a,&ans,n);

    return 0;
}
