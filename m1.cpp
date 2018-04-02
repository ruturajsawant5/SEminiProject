#include <iostream>
#include<graphics.h>
#include<string>
#include<cstdio>

using namespace std;
int count(string);
int main()
{
    initwindow(720,500,"images");
    readimagefile("r.jpg",0,0,720,500);
    getch();
    closegraph();

    char name[20];
    cout<<"***************************************************\n*              Welcome to GAME                    *\n***************************************************\n";

    cout<<"Enter your Name : ";
    cin>>name;

    int choice;
    do{
    cout<<name<<" enter number of strings you want to enter : ";
    int T;
    cin>>T;
    cout<<endl;
    int i;
    string str[10000];
    cout<<"Enter Strings"<<endl;
    for(i=0;i<T;i++){
        cout<<"Enter String no "<<i+1<<":";
        cin>>str[i];
    }

    cout<<"\nResults"<<endl;
    //block to count length of sequence
    for(i=0;i<T;i++){
        string test = str[i];
      //  int len = test.length();
        int cou=count(test);

        if(cou==0)
        {
             cout<<"String "<<str[i]<<" is invalid So "<<name<<" Won\n";
        }
        else{
           //Block to identify valid string sequence
        while(test.find("(())")!=-1||test.find("(()())")!=-1)
            {
                if(test.find("(())")!=-1){
                int found = test.find("(())");
                test.erase(test.begin()+found,test.begin()+found+4);
                }
                if(test.find("(()())")!=-1){
                int found1 = test.find("(()())");
                test.erase(test.begin()+found1,test.begin()+found1+6);

                }
            }
           //block decides winner
        if(test.empty()){
            cout<<"String "<<str[i]<<" is Valid So ATM Won\n";
        }
        else{
            cout<<"String "<<str[i]<<" is invalid So "<<name<<" Won\n";
        }
    }
    }
    cout<<"\nPress 1 to continue playing and 0 to exit :";
    cin>>choice;
    cout<<endl;
    }while(choice==1&&choice!=0);
    return 0;
}
//end of main

int count(string test)
{
    int  count_=0;
    int length_ = test.length();
    for(int i=0;i<length_;i++)
    {
        if(test[i]=='(')
        count_++;
    }
    if(count_==length_-count_)
    {
        return 1;
    }
    else
    {
    return 0;
    }
}
