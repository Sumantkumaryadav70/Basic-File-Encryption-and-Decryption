#include<bits/stdc++.h>
using namespace std;


string fun(string text,int shift,bool encrypt){
    if(!encrypt) shift = -shift;
    string res;
    for(char c :text){
        if(isalpha(c)){
            char base = isupper(c) ? 'A':'a';
            res += char((c-base+shift +26*100)% 26+base);
        }else{
            res+=c;
        }
    }
    return res;
}

int main(){
    cout<<"1. Encrypt :"<<endl;
    cout<<"2. Decrypt :"<<endl;
    cout<<"your choice :"<<endl;
    
    int choice,shift;
    string infile,outfile,line;
    cin>>choice;
    cout<<"input file :";
    cin>>infile;
    cout<<"output file :";
    cin>>outfile;
    cout<<"shift(1-25) :";
    cin>>shift;

    ifstream fin(infile);
    if(!fin){
        cout<<"not open :";
        cout<<infile;
        return 1;
    }
    ofstream fout(outfile);
    if(!fout){
        cout<<"not write :";
        cout<<outfile;
        return 1;
    }

    bool encrypt = (choice==1);
    while(getline(fin,line)){
        fout<< fun(line,shift,encrypt)<<endl;
    }

    cout<<(encrypt ? "Encrypt :": "Decrype :")<<"to"<<outfile<<endl;
}