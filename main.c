#include<stdio.h>
void forloops(int low,int end,int loops,char name[],int inc,int a[1][4],int ans[3],int n)
{
    int i, l = low, e = end,count= 0;
    while(loops>0)
    {

        if(inc == 1)
        {
            for(i = low ; i < end; i++)
            {
                if(loops == (n-1))
                {
                    if(i==0)
                    {
                        ans[n-(loops+1)]=a[0][0]+a[0][1];
                        printf("\n%d+%d=%d",a[0][0],a[0][1],ans[n-(loops+1)]);
                    }
                    if(i==1)
                    {
                        ans[n-(loops+1)]=a[0][0]-a[0][1];
                        printf("\n%d-%d=%d",a[0][0],a[0][1],ans[n-(loops+1)]);
                    }
                    if(i==2)
                    {
                        ans[n-(loops+1)]=a[0][0]*a[0][1];
                        printf("\n%d*%d=%d",a[0][0],a[0][1],ans[n-(loops+1)]);
                    }
                    if(i==3)
                    {
                        ans[n-(loops+1)]=a[0][0]/a[0][1];
                        printf("\n%d/%d=%d",a[0][0],a[0][1],ans[n-(loops+1)]);
                    }

                }
                else if(loops!=(n-1))
                {

                    if(i==0)
                    {
                        printf("\n%d+%d=",ans[n-(loops+2)],a[0][n-loops]);
                        ans[n-(loops+1)]=ans[n-(loops+2)]+a[0][n-loops];
                        printf("%d",ans[n-(loops+1)]);
                    }
                    if(i==1)
                    {
                        printf("\n%d-%d=",ans[n-(loops+2)],a[0][n-loops]);
                        ans[n-(loops+1)]=ans[n-(loops+2)]-a[0][n-loops];
                        printf("%d",ans[n-(loops+1)]);
                    }
                    if(i==2)
                    {
                        printf("\n%d*%d=",ans[n-(loops+2)],a[0][n-loops]);
                        ans[n-(loops+1)]=ans[n-(loops+2)]*a[0][n-loops];
                        printf("%d",ans[n-(loops+1)]);
                    }
                    if(i==3)
                    {
                        printf("\n%d/%d=",ans[n-(loops+2)],a[0][n-loops]);
                        ans[n-(loops+1)]=ans[n-(loops+2)]/a[0][n-loops];
                        printf("%d",ans[n-(loops+1)]);
                    }
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
