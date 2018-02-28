#include <iostream>
#include<string>
using namespace std;
int count(string);
int main()
{
    char name[20];
    cout<<"Enter your Name : ";
    cin>>name;
    cout<<name<<" Enter number of strings you want to enter : ";
    int T;
    cin>>T;
    int i;
    string str[10000];
    cout<<"Enter Strings one by one :"<<endl;
    for(i=0;i<T;i++)
        cin>>str[i];
    //block to count length of sequence
    for(i=0;i<T;i++){
        string test = str[i];
      //  int len = test.length();
        int cou=count(test);

        if(cou==0)
        {
           cout<<name<<endl;
        }
        else{
           //Block to identify valid string sequence
        while(test.find("(())")!=-1||test.find("(()())")!=-1)
            {
                if(test.find("(())")!=-1){
                int found = test.find("(())");
                test.erase(found,found+4);
                }
                if(test.find("(()())")!=-1){
                int found1 = test.find("(()())");
                test.erase(found1,found1+6);
                }
            }
           //block decides winner
        if(test.empty()){
            cout<<"ATM\n";
        }
        else{
            cout<<name<<endl;
        }
    }
    }
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
