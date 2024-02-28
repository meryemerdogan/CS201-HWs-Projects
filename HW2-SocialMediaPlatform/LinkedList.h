//  Meryem Erdoğan Sec1 

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>

using namespace std;
template < class ItemType >
class Node{
public:
    Node(){
    next = nullptr;
}
    int getID(){
    return ID;
}

void setID(int newID){
    ID = newID;
}

Node(const ItemType& anItem){
    item = anItem;
    next = nullptr;
}
ItemType* getItem() {
    return &item;
}

void setItem(const ItemType& anItem){
    item = anItem;
}

void setNext(Node<ItemType>* nextNodePtr){
    next = nextNodePtr;
}

Node<ItemType>* getNext(){
    return next;
}
private:
    Node<ItemType>* next;
    ItemType item;
    int ID;
};

template < class ItemType >
class LinkedList{
public:
    LinkedList(){
        headPtr = nullptr;
        itemNum = 0;
    }
    LinkedList(const LinkedList<ItemType>& aList){
        itemNum = aList.itemNum;
        Node <ItemType>* orig = aList.headPtr;
        
        if(orig == nullptr){
            headPtr = nullptr;
        }
        else{
            headPtr = new Node<ItemType>();
            headPtr->setItem(*(orig->getItem()));
            
            Node<ItemType>* newChainPtr = headPtr;
            orig = orig -> getNext();
            
            while (orig != nullptr) {
                ItemType nextItem = *(orig -> getItem());
                
                Node<ItemType>* newNodePtr = new Node<ItemType> (nextItem);
                newChainPtr -> setNext(newNodePtr);
                newChainPtr = newChainPtr -> getNext();
                orig = orig -> getNext();
            }
            newChainPtr -> setNext(nullptr);
        }
    }
    void clear(){
        while (!isEmpty()) {
            remove(1);
        }
    }
    ~LinkedList(){
        clear();
    }
    bool isEmpty(){
        if(itemNum == 0) return true;
        else return false;
    }
    int getLength() const{
        return itemNum;
    }
    
    ItemType* getEntry(int pos) const{
            Node<ItemType>* nodePtr = getNodeAt(pos);
            return nodePtr->getItem();
    }
    
    void add(ItemType& item, int id2){
            add2(headPtr,item, id2);
        itemNum++;
    }
    
    void add2(Node<ItemType>*& headPtr2, ItemType& newItem, int id2){
        if((headPtr2 == nullptr) || (newItem < *(headPtr2 -> getItem()))){
            Node<ItemType>* newPtr = new Node<ItemType>();
            newPtr -> setItem(newItem);
            newPtr-> setNext(headPtr2);
            newPtr -> setID(id2);
            headPtr2 = newPtr;
        }
        else{
            Node<ItemType>* temp = headPtr2->getNext();
            add2(temp,newItem,id2);
            headPtr2->setNext(temp);
        }
            
    }
    ItemType* getItemByID(int id){
        for(int i = 1; i < getLength()+1; i++){
            if(getNodeAt(i)->getID() == id){
                return getNodeAt(i)->getItem();
            }
        }
        ItemType* i = headPtr->getItem();
        return i;
    }
    bool isExist(int id){
        for(int i = 1; i < getLength()+1; i++){
            if(getNodeAt(i)->getID() == id){
                return true;
            }
        }
        return false;
    }
    bool remove(int pos){
        bool ableToRemove = (pos >= 1) && (pos <= itemNum);
        if(ableToRemove){
            Node<ItemType>* curPtr = nullptr;
            if(pos == 1){
                curPtr = headPtr;
                headPtr = headPtr -> getNext();
            }
            else{
                Node<ItemType>* prevPtr = getNodeAt(pos-1);
                curPtr = prevPtr -> getNext();
                prevPtr -> setNext(curPtr -> getNext());
            }
            curPtr -> setNext(nullptr);
            delete curPtr;
            curPtr = nullptr;
            itemNum--;
        }
        return ableToRemove;
    }
    void removeByID(int id){
    for(int i = 1; i < getLength()+1; i++){
        if(getNodeAt(i)->getID() == id){
            remove(i);
        }
    }
}
    
private:
    Node<ItemType>* headPtr;
    int itemNum;
    Node<ItemType>* getNodeAt(int pos) const{
        Node<ItemType>* curPtr = headPtr;
        for(int i = 1; i < pos; i++){
            curPtr = curPtr -> getNext();
        }
        return curPtr;
    }
};
#endif /* LinkedList_hpp */
