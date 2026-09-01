#include <iostream>

using namespace std;

class Movie{
    public:
        string like;
        string title;
        string genre;
        string releasedYear;

    Movie(string aTitle, string aGenre, string aReleasedYear, string aLike){
        title = aTitle;
        genre = aGenre;
        releasedYear = aReleasedYear;
        like = aLike;
    }
    

    void display(){
        cout << "like" << like << endl;
        cout << "title" << title << endl;
        cout << "genre" << genre << endl;
        cout << "released year" << releasedYear << endl;
    }

};

int main(){
    Movie *m[1000];
    int object;
    cout << "enter how many objects created  :" ;
    cin >> object;
    for(int i=0; i<object; i++){
        string title, genre, releasedYear, like;
        cout << endl;
        cout << "enter data for object " << i+1 << endl;
        cout << "enter title :";
        cin >> title;
        cout << "enter genre :";
        cin >> genre;
        cout << "enter released year :";
        cin >> releasedYear;
        cout << "enter like :";
        cin >> like;
        m[i] = new Movie(title, genre, releasedYear, like);
        cout << "data entered successfully" << endl;
    }
    cout << endl << endl ;
    cout << "============================================================================================" << endl;
    cout << "displaying all objects data" << endl;  
    for(int i=0; i<object; i++){
        cout << "data for object " << i+1 << " is :"<< endl;
        m[i]->display();
        cout << endl;
    }
    return 0;



}