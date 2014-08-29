#include <stdio.h>
int CalAns(int n);
int main()
{
    char c;
    int a[11][2];
    int i,j=0, number=0,found=0,vacant=0;
    for(i=0;i<11;i++)
    {
            a[i][0]=0;
            a[i][1]=-1;
    }
    do{
     while(number<=0||number>100){
                      printf("\nPlease input a positive number smaller than 100:\n");
                      scanf("%d",&number);
     }
     printf("The integer of input is %d\n", number);
     for(i=0;i<11;i++)
     {                
                      if(a[i][0]==number){
                                          printf("Found in cache!! The output is %d,stored in position %d\n", a[i][1],i);
                                          found=1;
                                          break;
                                          }
     }
     if(found==0){
                  printf("Never mind. Let's find it in memo. First let's check if we have any available spot in cache.\n");
                  if(vacant==0)
                  {
                      for(i=0;i<11;i++){
                                        if(a[i][0]==0){
                                                       a[i][0]=number;
                                                       a[i][1]=CalAns(number);
                                                       printf("The Answer is %d, stored in position %d.\n", a[i][1],i);
                                                       if(i==10) {vacant=1;printf("Cache full, need to rewrite cache.\n");}
                                                       break;
                                        }
                      }
                  }
                  else{
                       printf("Cache is full. Rewriting cache.\n");
                       j=j%11;
                       a[j][0]=number;
                       a[j][1]=CalAns(number);
                       printf("The Answer is %d, stored in position %d.\n", a[j][1],j);
                       j++;
                      }
     }
     number=0;
     found=0;
    }while(1);
    system("pause");
}
int CalAns(int n)
{
    int sum=0;
    int i;
    for( i=1;i<=n;i++) sum+=i;
    return sum;
}
