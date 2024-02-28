//
//  Node.h
//  ZooMap
//
//  Created by Meryem Erdoğan-22203723-Sec1
//

#ifndef Node_h
#define Node_h
using namespace std;
template < class ItemType >
class Node{
public:
    Node(){
        next = nullptr;
    }
    Node( ItemType& theItem){
        next = nullptr;
        item = &theItem;
    }

    void setID(int theID){
        ID = theID;
    }
    void setItem( ItemType& theItem){
            item = &theItem;
    }

    void setNext(Node<ItemType>* nextNodePtr){
            next = nextNodePtr;
    }

    ItemType* getItem() {
        return item;
    }
        
    int getID(){
        return ID;
    }

    Node<ItemType>* getNext(){
        return next;
    }
private:
    Node<ItemType>* next;
    ItemType* item;
    int ID;
};

template < class ItemType >
class LinkedList{
public:
    LinkedList(){
        headPtr = nullptr;
        itemNum = 0;
    }
    LinkedList(const LinkedList<ItemType>& theList){
        itemNum = theList.itemNum;
        Node <ItemType>* prev = theList.headPtr;
        
        if(prev == nullptr){
            headPtr = nullptr;
        }
        else{
            headPtr = new Node<ItemType>();
            headPtr->setItem(*(prev->getItem()));
            
            Node<ItemType>* newChainPtr = headPtr;
            prev = prev -> getNext();
            
            while (prev != nullptr) {
                ItemType nextItem = *(prev -> getItem());
                
                Node<ItemType>* newNodePtr = new Node<ItemType> (nextItem);
                newChainPtr -> setNext(newNodePtr);
                newChainPtr = newChainPtr -> getNext();
                prev = prev -> getNext();
            }
            newChainPtr -> setNext(nullptr);
        }
    }
    ~LinkedList(){
        clear();
    }
    void clear(){
        while (!isEmpty()) {
            remove(1);
        }
    }
    bool isEmpty(){
        if(itemNum == 0) {
            return true;
            
        }
        else {
            return false;
        }
    }
    int getLength() const{
        return itemNum;
    }
    
    ItemType* getEntry(int pos) const{
            Node<ItemType>* ptr = getNodeAt(pos);
            return ptr->getItem();
    }
    
    void add(ItemType& item, int id1){
            addHelp(headPtr,item, id1);
        itemNum++;
    }
    
    void addHelp(Node<ItemType>*& headPtr2, ItemType& newItem, int id2){
        if((headPtr2 == nullptr) || (newItem < *(headPtr2 -> getItem()))){
            Node<ItemType>* newPtr = new Node<ItemType>();
            newPtr -> setItem(newItem);
            newPtr-> setNext(headPtr2);
            newPtr -> setID(id2);
            headPtr2 = newPtr;
        }
        else{
            Node<ItemType>* temp = headPtr2->getNext();
            addHelp(temp,newItem,id2);
            headPtr2->setNext(temp);
        }
            
    }
    ItemType* getItemByID(int ID){
        for(int i = 1; i < getLength()+1; i++){
            if(getNodeAt(i)->getID() == ID){
                return getNodeAt(i)->getItem();
            }
        }
        ItemType* i = headPtr->getItem();
        return i;
    }
    bool isExist(int ID){
        for(int i = 1; i < getLength()+1; i++){
            if(getNodeAt(i)->getID() == ID){
                return true;
            }
        }
        return false;
    }
    bool remove(int pos){
        bool canBeRemoved = (pos >= 1) && (pos <= itemNum);
        
        if(canBeRemoved){
            Node<ItemType>* curr = nullptr;
            
            if(pos == 1){
                curr = headPtr;
                headPtr = headPtr -> getNext();
            }
            else{
                Node<ItemType>* prevPtr = getNodeAt(pos-1);
                curr = prevPtr -> getNext();
                prevPtr -> setNext(curr -> getNext());
            }
            curr -> setNext(nullptr);
            delete curr;
            
            curr = nullptr;
            itemNum--;
        }
        return canBeRemoved;
    }
    
    void removeByID(int ID){
    for(int i = 1; i<getLength()+1; i++){
        
        if(getNodeAt(i)->getID() == ID){
            remove(i);
        }
    }
}
    
private:
    Node<ItemType>* headPtr;
    int itemNum;
    Node<ItemType>* getNodeAt(int pos) const{
        Node<ItemType>* curr = headPtr;
        
        for(int i = 1; i < pos; i++){
            curr = curr->getNext();
        }
        return curr;
    }
};

#endif /* Node_h */
