#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<windows.h>

void decimal_to_binary(int d,int arr[]){
    int result,i=0;
    do{
        result=d%2;
        d/=2;
        arr[i]=result;
        i++;
    }while(d>0);
}

int lcm(int n1,int n2){
int minMultiple;
    minMultiple = (n1>n2) ? n1 : n2;
    while(1)
    {
        if( minMultiple%n1==0 && minMultiple%n2==0 )
        {
            break;
        }
        ++minMultiple;
    }
    return minMultiple;

}



int modular_exponentiation(int a,int b,int n){
 int *bb;
 int count=0,c=0,d=1,i;
 count=(int)(log(b)/log(2))+1;
 bb=(int*)malloc(sizeof(int*)*count);
 decimal_to_binary(b,bb);
 for (i=count-1;i>=0;i--){
  c=2*c;
  d=(d*d)%n;
  if (bb[i]==1){
   c=c+1;
   d=(d*a)%n;
  }
 }
 return d;
}


void cast_vote(int* voter,int* candidate)
{

  int darr[6]={0,0,0,0,0,0},i,n,c;
  for(int j=0;j<6;j++){
        begin:
        system("cls");
  printf("Welcome To The E-voting service.\n");
  printf("Please Enter your VoterID: ");
  scanf("%d",&n);
  if(darr[n-1]==1){
    printf("You have already casted your vote!! if not please check with election committee");
    printf("\nPress 1 to vote or press 0 to exit :");
    scanf("%d",&i);
    if(i==1)
     goto begin;
     else if(i==0)
        exit(1);
     else{
        printf("wrong key entered so terminating");
        exit(1);

     }
  }
  else{

  printf("\nPlease cast your vote with the number of your supported candidate!!\n");
  printf("\t (1) for CONGRESS\n");
  printf("\t (2) for BJP\n");
  printf("\t (3) for TRS\n");
  printf("Enter your choice: ");
  scanf("%d",&c);
  if(c==1 || c==2 || c==3){
   darr[n-1]=1;
  if(c==1)
    voter[n-1]=candidate[0];
  else if(c==2)
    voter[n-1]=candidate[1];
  else if(c==3)
    voter[n-1]=candidate[2];

  printf("Thank You for Voting!!! You're votes will stored untill results are declared! \n");
  printf("\n\n\n\n\n\n\n\n\n");}
  else {
    printf("Candidate with this number is not there in list");
    goto begin;}
  }

  }
}



int main()
{
  FILE *fp;
  fp=fopen("C:\\Users\\saripella vivekanand\\Desktop\\1.txt","w");
  int candidate[3];
  for(int i=2;i>=0;i--)
  {
    candidate[2-i]=pow(2,2*i);
  }
  int p=5,q=7;
  int total=6;
  int voter[6]={0,0,0,0,0,0};
  cast_vote(voter,candidate);
  system("cls");
  int n11=0,n22=0,n33=0;
  for(int i=0;i<6;i++)
    if(voter[i]==candidate[0])
        n11++;
  int n,n2,lambda;
  n=p*q;
  n2=n*n;
  lambda=lcm((p-1),(q-1));
  int i,g;
  g=141;
  int r[6]={4,17,26,12,11,32};
  int enc[6];
  for(i=0;i<6;i++)
  {
    enc[i]=(((modular_exponentiation(g,voter[i],n2))*(modular_exponentiation(r[i],n,n2)))%n2);
    fprintf(fp,"%d\n",enc[i]);
  }
  int y;
  y=((((((enc[0]*enc[1])%n2)*((enc[2]*enc[3])%n2))%n2)*((enc[4]*enc[5])%n2))%n2);
  int L1,L2,L11,L22;
  L1=modular_exponentiation(y,lambda,n2);
  L2=modular_exponentiation(g,lambda,n2);
  L11=(L1-1)/n;
  L22=(L2-1)/n;

  int dec,temp;
  for(i=1;i<n;i++)
  {
     dec=i;
     temp=((i*L22)%n);
     if(temp==L11)
        break;
  }
  if(n11>=2)
    dec=dec+n;
  int binary[100],cha;
  n=dec;
  i=0;
  while(n>0)
  {
    binary[i]=n%2;
        n=n/2;
        i++;
  }
  int v1,v2,v3;
  if(i==5)
  {
    if(binary[0]==1 && binary[1]==1)
        v3=3;
    else if(binary[0]==1 && binary[1]==0)
        v3=1;
    else if(binary[0]==0 && binary[1]==1)
        v3=2;
    else
        v3=0;

    if(binary[3]==1 && binary[2]==1)
        v2=3;
    else if(binary[3]==1 && binary[2]==0)
        v2=2;
    else if(binary[3]==0 && binary[2]==1)
        v2=1;
    else
        v2=0;

    if(binary[4]==1)
        v1=1;
    else if(binary[4]==0)
        v1=0;

  }
  if(i==6)
  {
    if(binary[0]==1 && binary[1]==1)
        v3=3;
    else if(binary[0]==1 && binary[1]==0)
        v3=1;
    else if(binary[0]==0 && binary[1]==1)
        v3=2;
    else
        v3=0;

    if(binary[3]==1 && binary[2]==1)
        v2=3;
    else if(binary[3]==1 && binary[2]==0)
        v2=2;
    else if(binary[3]==0 && binary[2]==1)
        v2=1;
    else
        v2=0;

     if(binary[5]==1 && binary[4]==1)
        v1=3;
    else if(binary[5]==1 && binary[4]==0)
        v1=2;
    else if(binary[5]==0 && binary[4]==1)
        v1=1;
    else
        v1=0;


  }
  char pass[10],password[10]="results";
  int main_exit;
  beep:
  printf("\n\n\t\tEnter the password to calculate and display results :");
    scanf("%s",pass);
  if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
            system("cls");
            system("color 0");
            printf("Total votes polled: %d\n",total);
            printf("Candidate 'congress' votes: %d\n",v1);
             printf("Candidate 'BJP' votes: %d\n",v2);
              printf("Candidate 'TRS' votes: %d\n",v3);
              if(v1==v2 && v2==v3)
                   printf("Clash occurred b/w candidate 1 and candidate 2 and candidate 3");
              else if(v1>v2 && v1>v3)
                 printf("And the winner is CANDIDATE 1 (CONGRESS)!!!");
              else if(v2>v1 && v2>v3)
                  printf("And the winner is CANDIDATE 2 (BJP)!!!");
              else if(v3>v2 && v3>v1)
                   printf("And the winner is CANDIDATE 3 (TRS)!!!");
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        goto beep;
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    exit(1);}
            else
                    {printf("\nInvalid!");

                    system("cls");
                    goto login_try;}



    }
    return 0;
}
