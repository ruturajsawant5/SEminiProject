#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

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

    for(i=0;i<T;i++){
        string test = str[i];
        int len = test.length();
        int cou=count(test.begin(),test.end(),'(');

        if(cou!=(len-cou))
        {
           cout<<name<<endl;
        }
        else{
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

