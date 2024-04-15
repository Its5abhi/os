#include<stdio.h>
#include<stdlib.h>
int allocation[20][20],max[20][20],available[20],need[20][20],safe[10],s=0;
int finish[10],work[10],cnt=0,flag=0,temp=0;
int p,i,r,j,ch,ind,req[10];

void check()
{
   temp=0;
   s=0;
   for(i=0;i<p;i++)
    for(j=0;j<r;j++)
    need[i][j]=max[i][j]-allocation[i][j];
    
    printf("\n Need Table is:\n");
     for(i=0;i<p;i++)
      {
         for(j=0;j<r;j++) 
             printf("%d\t",need[i][j]);
              printf("\n");
       }
     for(i=0;i<p;i++)
     finish[i]=0;
     for(i=0;i<r;i++)
      work[i]=available[i];
      
      while(temp<2)
      {
         for(i=0;i<p;i++)
         {
             for(j=0;j<r;j++) 
             {
                   if(finish[i]==0 && need[i][j]<=work[j])
                      flag=1;
                  else
                  {
                        flag=0;
                           break;
                  }
              }
              if(flag==1)
              {
                   for(j=0;j<r;j++) 
                   work[j]=work[j]+allocation[i][j];
                    finish[i]=1;
                     safe[s++]=i;  
              }
          }
          temp++;
      }
      flag=0;
       for(i=0;i<p;i++)
       {
          if(finish[i]==0)
          {
               flag=1;
                  break;
          }
       }
       if(flag==1)
       {
           printf("\n system is in Deadlock state");
       }
       else
       {
           printf("\n system is in Safe state");
           printf("\n safe sequence is:");
             for(i=0;i<p;i++)
                printf("p%d\t",safe[i]);
       }
}
int main()
{
   system("clear");
   printf("\n~~~~~~~~~BANKER'S ALGORITHM~~~~~~~~~~~~~");
   printf("\n\nEnter the no of resources and processes:");
   scanf("%d%d",&r,&p);
   printf("\n Enter The Allocation Table:\n");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
         scanf("%d",&allocation[i][j]);
         
    printf("\n Enter The Max Table:\n");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
         scanf("%d",&max[i][j]);
         
    printf("\n Enter The  Vector Available:");
          for(i=0;i<r;i++)
          scanf("%d",&available[i]);
          check();
          
      printf("\n do you want to add new request:(0/1)");
      scanf("%d",&ch);
      if(ch==0)
      exit(1);
      
      printf("\n Enter the proces no:");
      scanf("%d",&ind);
        printf("\n Enter the request :");
            for(i=0;i<r;i++)
             scanf("%d",&req[i]);
        flag=0;
        
   for(i=0;i<r;i++)
    if(req[i]<=need[ind][i])
     flag=1;
    else
    flag=0;
   if(flag==0)
   {
       printf("\n Request can not be satisfied");
       exit(1);
   }     
        
  for(i=0;i<r;i++)
    if(req[i]<=available[i])
     flag=1;
    else
    flag=0;
   if(flag==0)
   {
       printf("\n Request can not be satisfied");
       exit(1);
   }
  for(i=0;i<r;i++)
  {
     allocation[ind][i]=allocation[ind][i]+req[i];
     
     available[i]=available[i]-req[i];
   } 
  check();
  return 0;
   
}

/*~~~~~~~~~BANKER'S ALGORITHM~~~~~~~~~~~~~

Enter the no of resources and processes:3
5

 Enter The Allocation Table:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

 Enter The Max Table:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

 Enter The  Vector Available:3 3 2

 Need Table is:
7	4	3	
1	2	2	
6	0	0	
0	1	1	
4	3	1	

 system is in Safe state
 safe sequence is:p1	p3	p4	p0	p2	
 do you want to add new request:(0/1)1

 Enter the proces no:4

 Enter the request :1 1 0

 Need Table is:
7	4	3	
1	2	2	
6	0	0	
0	1	1	
3	2	1	

 system is in Safe state
 safe sequence is:p1	p3	p4	p0	p2	bcs@bcs-OptiPlex-3020:~$ ^C
*/














