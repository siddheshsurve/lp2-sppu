#include <bits/stdc++.h>
#define MAX 20 
using namespace std;

class NQueen{
    int board[MAX][MAX];
    vector<bool>rows;       
    vector<bool>left_digonals;
    vector<bool>Right_digonals;
    int n;
    public:

    NQueen(){
        n=0;
    }

    NQueen(int i){
        n=i;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                board[j][k]=0;
            }
        }
        for(int i=0;i<n;i++){
            rows.push_back(false);
        }
        for(int i=0;i<2*n-1;i++){
            left_digonals.push_back(false);
            Right_digonals.push_back(false);
        }
        
    }

    void showBoard(){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                if(board[i][j])
                    cout << "Q ";
                else cout<<". ";
            }
        cout<<"\n";
        }
    }

    bool isSafe(int row, int col){
        int i=0,j=0;
        for (i = 0; i < col; i++){
            if (board[row][i])
                return false;
        }
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if (board[i][j])
                return false;
        }
        for (i = row, j = col; j >= 0 && i < n; i++, j--){
            if (board[i][j])
                return false;
        }
        return true;
    }

    bool solveUtil(int col){
        if(col>=n){
            return true;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,col)){
                board[i][col]=1;
                if(solveUtil(col+1)){
                    return true;
                }
                board[i][col]=0;
            }
        }
        return false;
    }

    bool solveBacktrack(){
        if(solveUtil(0)==false){
            cout<<"Solution does not exist!"<<endl;
            return false;
        }
        cout<<"Solution is: "<<endl;
        showBoard();
        return true;
    }

    bool isSafeBandB(int row ,int col) {
        if(rows[row] == true || left_digonals[row+col] == true || Right_digonals[col-row+n-1] == true) {
            return false;
        }
        return true;
    }

    bool solveBandB(int col)
    {      
       if(col>=n){
           return true;
       }
       for(int i = 0;i<n;i++)
       {
           if(isSafe(i,col) == true)
           {
               rows[i] = true;
               left_digonals[i+col] = true;
               Right_digonals[col-i+n-1] = true;
               board[i][col] = 1;   
               
               if(solveBandB(col+1) == true){
                   return true;
               }
                
               rows[i] = false;
               left_digonals[i+col] = false;
               Right_digonals[col-i+n-1] = false;
               board[i][col] = 0;    
 
           }
       }
       return false;
    }
};

int main()
{
    int n1,cho;
    cout<<"Enter size of board: ";cin>>n1;
    NQueen n(n1);
    cout<<"\n--------Menu---------\n1.Backtracking\n2.Branch and Bound\nEnter choice: ";cin>>cho;
    if(cho==1){
        n.solveBacktrack();
    }
    else if(cho==2){
        bool ans=n.solveBandB(0);
        if(ans){
            n.showBoard();
        }
        else{
            cout<<"No solution exists!"<<endl;
        }
    }
    
}

/* Output:
Enter size of board: 2

--------Menu---------
1.Backtracking
2.Branch and Bound
Enter choice: 1
Solution does not exist!

Enter size of board: 4

--------Menu---------
1.Backtracking
2.Branch and Bound
Enter choice: 1
Solution is: 
. . Q . 
Q . . . 
. . . Q 
. Q . . 


Enter size of board: 4

--------Menu---------
1.Backtracking
2.Branch and Bound
Enter choice: 2
. . Q . 
Q . . . 
. . . Q 
. Q . . 

Enter size of board: 8

--------Menu---------
1.Backtracking
2.Branch and Bound
Enter choice: 1
Solution is: 
Q . . . . . . . 
. . . . . . Q . 
. . . . Q . . . 
. . . . . . . Q 
. Q . . . . . . 
. . . Q . . . . 
. . . . . Q . . 
. . Q . . . . . 


Enter size of board: 8

--------Menu---------
1.Backtracking
2.Branch and Bound
Enter choice: 2
Q . . . . . . . 
. . . . . . Q . 
. . . . Q . . . 
. . . . . . . Q 
. Q . . . . . . 
. . . Q . . . . 
. . . . . Q . . 
. . Q . . . . . 

*/