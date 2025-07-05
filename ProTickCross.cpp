#include<bits/stdc++.h>
using namespace std;

char sum[3][3] ={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'x';
int row,colum;
int choice;
bool draw=false;
   void bord(){
    system("cls");
    cout<<"\t\t\t _________________"<<endl;
    cout<<"\t\t\t|     |     |     |"<<endl;
    cout<<"\t\t\t|  "<<sum[0][0]<<"  |  "<<sum[0][1]<<"  |  "<<sum[0][2]<<"  |"<<endl;
    cout<<"\t\t\t|_____|_____|_____|"<<endl;
    cout<<"\t\t\t|     |     |     |"<<endl;
    cout<<"\t\t\t|  "<<sum[1][0]<<"  |  "<<sum[1][1]<<"  |  "<<sum[1][2]<<"  |"<<endl;
    cout<<"\t\t\t|_____|_____|_____|"<<endl;
    cout<<"\t\t\t|     |     |     |"<<endl;
    cout<<"\t\t\t|  "<<sum[2][0]<<"  |  "<<sum[2][1]<<"  |  "<<sum[2][2]<<"  |"<<endl;
    cout<<"\t\t\t|_____|_____|_____|"<<endl;
   }
   void player(){
    if(turn == 'x')
    cout<<"\tPlayr1 [x]:";
    if(turn == 'o')
    cout<<"\tplayer2 [o]:";
    cin>>choice;
    
    switch(choice){
          case 1:row=0;colum=0;break;
          case 2:row=0;colum=1;break;
          case 3:row=0;colum=2;break;
          case 4:row=1;colum=0;break;
          case 5:row=1;colum=1;break;
          case 6:row=1;colum=2;break;
          case 7:row=2;colum=0;break;
          case 8:row=2;colum=1;break;
          case 9:row=2;colum=2;break;
          default:
          cout<<"invalide choice:";
    } 
    if(turn=='x' && sum[row][colum]!='x' && sum[row][colum]!='o'){
      sum[row][colum]='x';
      turn='o';
    }
    else if(turn=='o' && sum[row][colum]!='x' && sum[row][colum]!='o'){
        sum[row][colum]='o';
        turn='x';
    }
    else{
      cout<<"box is already fild:\nplease try again!!\n\n";
      player();
    }
     bord();
   }
   bool over(){
    for(int i=0;i<3;i++){
      if(sum[i][0]==sum[i][1] && sum[i][0]==sum[i][2]||sum[0][i]==sum[1][i] && sum[0][i]==sum[2][i])
      return false;
    
    if(sum[0][0]==sum[1][1] && sum[0][0]==sum[2][2]||sum[0][2]==sum[1][1] && sum[0][2]==sum[2][0])
      return false;
    }
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    if(sum[i][j]!='x'&& sum[i][j]!='o')
    return true;

    draw=true;
    return false;
   }
int main(){
    
    cout<<"     Welcome To My Tick Cross Game:"<<endl;
    cout<<"\tPlayer1 [x]="<<endl<<"\tPlayer2 [o]="<<endl;
    while(over()){

    bord();
    cout<<endl;
    player();
   //  bord function
    over();
    } 
    if(turn=='x' && draw==false){
      cout<<"Player2 [o] Win !! congratulation"<<endl;
    }
    else if(turn=='o' && draw==false){
      cout<<"Player1 [x] Win !! congratulation"<<endl;
    }
    else{
      cout<<"Game Draw"<<endl;
    }
}