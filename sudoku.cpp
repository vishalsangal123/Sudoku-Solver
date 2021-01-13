#include<bits/stdc++.h>
using namespace std;
#define n 9
void display(int a[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isValid(int a[n][n],int x,int y,int val){

    for(int i=0;i<n;i++){
        if(a[i][y]==val){
            return false;
        }
    }
    for(int j=0;j<n;j++){
        if(a[x][j]==val){
            return false;
        }
    }
    int smi=x/3*3;
    int smj=y/3*3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[smi+i][smj+j]==val){
                return false;
            }
        }
    }
    return true;
}

bool SudokuSolve(int a[n][n],int i,int j){
    if(i==n){
    return true;
    }
    int ni=0,nj=0;
        if(j==n-1){
       ni=i+1;
       nj=0;
        }
        else{
            ni=i;
            nj=j+1;
        }

if(a[i][j]!=0){
    return SudokuSolve(a,ni,nj);
}
for(int pos=1;pos<=9;pos++){
        if(isValid(a,i,j,pos)==true){
            a[i][j]=pos;
            if(SudokuSolve(a,ni,nj))
                return true;
        }
        a[i][j]=0;
    }
    return false;

}
int main(){
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    if(SudokuSolve(a,0,0)){
        cout<<"Sudoku is Valid"<<endl;
        display(a);
    }
    else{
        cout<<"Invalid Sudoku";
    }

}
