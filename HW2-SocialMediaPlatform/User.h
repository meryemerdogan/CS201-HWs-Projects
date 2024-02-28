//
//  Meryem Erdoğan Sec1 

#ifndef User_h
#define User_h

#include <iostream>
using namespace::std;

class User{
public:
    User();
    User(int newID, string newName);
    void setName(string newName);
    void setID(int newID);
    string getName();
    int getID();
    bool operator<( const User& a);
private:
    int id;
    string name;
};
#endif /* User_hpp */
