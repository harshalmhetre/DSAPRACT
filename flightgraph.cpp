
#include <iostream>
using namespace std;



int main() {
    
     int n,t;
     string city[10];
     char ch;
     cout<<"\nenter number of cities:";
     cin>>n;
     cout<<"\nenter names of cities:";
     for(int i=0;i<n;i++)
     {
         cin>>city[i];
     }
     int time1[10][10];
     
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             time1[i][j]=0;
         }
     }
     
     cout<<"\nenter paths:";
     for(int i=0;i<n;i++)
     {
         
         for(int j=0;j<n;j++)
         {
             if(i!=j && time1[j][i]==0)
             {
             cout<<"\nis there path from "<<city[i]<<" to "<<city[j]<<":";
             cin>>ch;
             if(ch=='y')
             {
                 cout<<"\nenter time required to reach "<<city[i]<<" to "<<city[j]<<":";
                 cin>>t;
                 time1[i][j]=t;
                 time1[j][i]=t;
             }
             }
         }
     }
     
     cout<<"the adjancency matrix representation is:\n";
     for(int i=0;i<n;i++)
     {
         cout<<"\t"<<city[i];
     }
     cout<<"\n";
     for(int i=0;i<n;i++)
     {
         cout<<city[i]<<"\t";
         for(int j=0;j<n;j++)
         {
             cout<<time1[i][j]<<"\t";
         }
         cout<<"\n";
     }
     
     int c=0;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(time1[i][j]==0)
             {
                c++;
             }
         }
         if(c==n)
         {
             break;
         }
     }
     if(c==n)
     {
         cout<<"graph is not connected";
     }
     else
     {
         cout<<"graph is connected";
     }
    return 0;
}
