//
// Meryem Erdoğan Sec1 

#ifndef ContentCreator_h
#define ContentCreator_h

#include <stdio.h>
#include "Content.h"
#include "User.h"
#include "LinkedList.h"
class ContentCreator{
public:
    ContentCreator(int newID, string newName){
        id = newID;
        name = newName;
    }
    ContentCreator(){
        id = 0;
        name = "";
    }
        
    void addFollower(User u){
        followers.add(u, (u).getID());
    }
    string getName(){
        return name;
    }
    void addContent(Content c){
        if(c.getContentCreatorId() == id){
            contents.add(c, (c).getContentId());
        }
    }
    
    void addContent(int contentID, string title){
        Content* c = new Content(id, contentID, title);
        contents.add(*c, (*c).getContentId());
    }
    
    LinkedList<User> getAllFollowers(){
        return followers;
    }

    LinkedList<Content> getAllContents(){
        return contents;
    }
        
    bool removeFollower(int id){
        for(int i = 1; i < followers.getLength()+1; i++ ){
            if(followers.getEntry(i)->getID() == id){
                followers.remove(i);
                return true;
            }
        }
        return false;
    }

    void removeContent(int id){
        for(int i = 1; i < contents.getLength()+1; i++ ){
            if(contents.getEntry(i)->getContentId() == id){
                contents.remove(i);
                return;
            }
        }
    }

    void removeFollower(User u){
        for(int i = 1; i < followers.getLength()+1; i++ ){
            if(followers.getEntry(i)->getID() == u.getID()){
                followers.remove(i);
                return;
            }
        }
    }

    void removeContent(Content c){
        for(int i = 1; i < contents.getLength()+1; i++ ){
            if(contents.getEntry(i)->getContentId() == c.getContentId()){
                contents.remove(i);
                return;
            }
        }
    }
    void showAllFollowers(){
        if(followers.getLength() == 0) cout << "None" << endl;
        for(int i = 1; i < followers.getLength()+1; i++){
            cout << (followers.getEntry(i))->getID() << endl;
        }
    }
    void showAllContents(){
        cout << "Contents of content creator with ID " << id <<":" << endl;
        if(contents.getLength() == 0){
            cout << "None" << endl;
            return;
        }
        for(int i = 1; i < contents.getLength()+1; i++){
            cout << (contents.getEntry(i))->getContentId()<< endl;
        }
    }
    bool operator<( const ContentCreator& b){
        if(this->id > b.id ){
            return false;
        }
        return true;
    }
    int getId(){
        return id;
    }
private:
    LinkedList<User> followers;
    LinkedList<Content> contents;
    int id;
    string name;
};

#endif /* ContentCreator_hpp */
