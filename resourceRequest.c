#include<stdio.h>
#define max 50
int bankers()
{
   int n,m;
   printf("\nenter no of procesess");
   scanf("%d",&n);
   printf("\nenter no of resourcess");
   scanf("%d",&m);
   int pro[n];
   int allow[n][m];
   int maxAllow[n][m];
   int available[m];
   int need[n][m];
   int seque[n];
   int set[n];

      int pid;
    int arr[m];


  printf("\nenter available resources");
  for(int i=0;i<m;i++){
     scanf("%d",&available[i]);
  }

  printf("\nenter allowcation matrix");
   for(int i=0;i<n;i++){
    set[i]=0;
    for(int j=0;j<m;j++){
         scanf("%d",&allow[i][j]);
    }
   }


  printf("\nenter max allowcation matrix");
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
         scanf("%d",&maxAllow[i][j]);
         need[i][j]=(maxAllow[i][j])-(allow[i][j]);
    }
   }

  int count=0;
  int i,j,trace;
  i=j=trace=0; 

//here run time request is accept is fetch
 
printf("\nenter  process  no as 0,1,2,3...: which are requesting run time resources");
    scanf("%d",&pid);

    printf("\nenter resource request");
    for(int i=0;i<m;i++)
    {
        printf("\nenter resource");
        scanf("%d",&arr[i]);
        if(arr[i]<=need[pid][i] && arr[i]<=available[i]){
           continue;
        }
        else{
            printf("\npermision not granted enter another resource value");
            i--;
            continue;
        }
    }


//calculate current need, allocation and available 
  for(int j=0;j<m;j++){
          allow[pid][j]+=arr[j];
          need[pid][j]=(maxAllow[pid][j])-(allow[pid][j]);
          available[j]-=arr[j];
    }
   


    while(count<n){
        trace=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(need[i][j]<=available[j])
                  continue;
                else
                  break;
            }
            if(j==m && set[i]!=1){
               seque[count++]=i;
               set[i]=1; //keep track if already visit(approve request) or not 
               //update available
               trace=1;
               for(int k=0;k<m;k++)
                 available[k]+=allow[i][k];
            }
        }

        //this case when system in a deadlock state
        if(trace==0){
          printf("\nsystem is in a deadlock state");
          return 0;
          break;
        }

    }

    printf("\nthe safe sequence is\n"); 
    for(int i=0;i<n;i++){
      printf("%dP->",seque[i]);
    }  
}



void main(){
   int ch;
 bankers();

}