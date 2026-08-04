#include<iostream>

using namespace std;
int main(){
    string name;
    cout << "enter your color : " ;
    cin >> name;
    if(name == "green"){
        cout << "go" << endl;
    }else if(name == "red"){
        cout << "stop" << endl;
    }
    else if(name == "orange"){
        cout << "wait" << endl;
    }
    return 0;
}