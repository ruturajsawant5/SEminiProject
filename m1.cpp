/*  *Program for string validator
    *
    *@author ruturaj
    *@author Dnyaneshwar
    *@author rajahamad
    *@author apurv
*/
#include <iostream>
#include<string>
/* * string header file for .length() , .find() , .erase Functions
*/
#include<algorithm>
/*  for count ffunction
*/
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
    //block to count length of sequence
    for(i=0;i<T;i++){
        string test = str[i];
        int len = test.length();
        int cou=count(test.begin(),test.end(),'(');

        if(cou!=(len-cou))
        {
           cout<<name<<endl;
        }
        else{
           //Block to identify valid string sequence
        while(test.find("(())")!=-1||test.find("(()())")!=-1)
            {
                if(test.find("(())")!=-1){
                int found = test.find("(())");
                test.erase(found,found+3);
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

