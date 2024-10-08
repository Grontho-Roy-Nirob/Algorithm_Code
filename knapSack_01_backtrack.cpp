#include<iostream>

using namespace std;
int main()
{
    int weight[]={0,3, 4, 5,6};
    int benifit[]={0,2,3,4,1};
    int W=8, n=4;

    int B[n+1][W+1];

    for (int w = 0; w<= W; w++)
    for (int w = 0; w<= W; w++)
            B[0][w] = 0;
    for (int i = 0; i<= n; i++)
            B[i][0] = 0;

    for (int i = 1; i<= n; i++)
    {
        for (int w = 1; w<= W; w++)
        {
            if(weight[i]<=w)
            {
              if((benifit[i]+B[i-1][w-weight[i]]) > B[i-1][w])
                B[i][w]=benifit[i]+B[i-1][w-weight[i]];
              else
                B[i][w]=B[i-1][w];
            }
            else
                B[i][w] = B[i-1][w];
        }

    }

    for (int i = 0; i<= n; i++)
    {
        for (int w = 0; w<= W; w++)
        {
              cout<<  B[i][w]<<'\t' ;
        }
        cout<<endl;

    }

    cout<<"\n Maximum Profit: "<<B[n][W];

  cout<<"\n\n Backtracking"<<endl;
   int maxProfit =B[n][W];
   int i=n;
   int j=W;
  while(maxProfit>0)
  {
      if(maxProfit!=B[i-1][j])
      {
          cout<<"Weight: "<<weight[i]<<"--Profit: "<<benifit[i]<<endl;
          int remain=maxProfit-benifit[i];
          for(int k=W; k>=0; k--)
          {
              if(remain==B[i-1][k])
              {
                  maxProfit= B[i-1][k];
                  j=k;
                  i--;
                  break;
              }
          }
      }
      else
      {
          maxProfit=B[i-1][j];
          i--;
      }
   } // end of backtrack

} // end of main
