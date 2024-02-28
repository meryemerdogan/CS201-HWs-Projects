//
//  Meryem Erdoğan Sec1 

#include "User.h"

User::User(){
    name = "";
    id = 0;
}
User::User(int newID, string newName){
    name = newName;
    id = newID;
}
void User::setName(string newName){
    name = newName;
}
void User::setID(int newID){
    id = newID;
}
string User::getName(){
    return name;
}
int User::getID(){
    return id;
}
bool User::operator<( const User& a){
    if(this->id < a.id ){
        return true;
    }else return false;
}
