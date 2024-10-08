#include <iostream>
#include <vector>
#include<string.h>
using namespace std;

void print_lcsTable(int **arr, int row, int col)
{
    for(int i=0;i<=row; i++)
    {
        for (int j=0; j<=col; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }

}

void print_direction(char **srtArr, int row, int col)
{
    for(int i=1;i<=row; i++)
    {
        for (int j=1; j<col; j++)
        {
            cout<<srtArr[i][j]<<"\t";
        }
        cout<<endl;
    }

}

void print_LCS(char **dirArr,char *str1, int i, int j)
{
    if(i==0 || j==0)
    {
        cout<<str1[i]<<" ";
        return;
    }

    if(dirArr[i][j]=='D')
    {
        print_LCS(dirArr, str1,i-1,j-1);
        cout<<str1[i]<<" ";
    }
    else if(dirArr[i][j]=='U')
        print_LCS(dirArr, str1,i-1,j);
    else
        print_LCS(dirArr, str1,i,j-1);
}



int main() {
  char S1[] = "GXTXATB";
  char S2[] = "AGGTAB";

  int m = strlen(S1);
  int n = strlen(S2);

  int **lcsTable = new int*[m+1]; // created row for lcs
  char **dirTable= new char*[m+1];

  for(int i =0; i<=m ;i++)
  {
    lcsTable[i] = new int[n+1]; // create column for each row
    lcsTable[i][0]=0;
    dirTable[i] = new char[n+1];
  }

  for(int j=0; j<=n; j++)
  {
       lcsTable[0][j]=0;
  }

  for(int i =1; i<=m ;i++)
  {
      for(int j=1; j<=n; j++)
      {
          if(S1[i]==S2[j])
          {
              lcsTable[i][j]=lcsTable[i-1][j-1]+1;
              dirTable[i][j]='D';
          }
          else if(lcsTable[i-1][j]>=lcsTable[i][j-1])
          {
              lcsTable[i][j]=lcsTable[i-1][j];
              dirTable[i][j]='U';
          }
          else
          {
             lcsTable[i][j]=lcsTable[i][j-1];
             dirTable[i][j]='L';
          }
      }
  }

  cout<<"print lcs Table: "<<endl;
  print_lcsTable(lcsTable, m,n);

  cout<<"print direction Table: "<<endl;
  print_direction(dirTable,m,n);

  cout<<"matched string: ";
  print_LCS(dirTable,S1,m,n);
}
