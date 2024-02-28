//
//  Stack.h
//  ZooMap
//
//  Created by Meryem Erdoğan-22203723-Sec1
//

#ifndef Stack_h
#define Stack_h

#include "Node.h"

template<class ItemType>
class Stack{
public:

    Stack(){
        topPtr= nullptr;
    }
Stack(const Stack<ItemType>& aStack) {
        
        Node<ItemType>* origPtr = aStack.topPtr;
        
        if(origPtr==nullptr)
            topPtr = nullptr;
        else{
            //first node
            topPtr = new Node<ItemType>();
            ItemType* a = new ItemType();
            *a = *origPtr -> getItem();
            topPtr -> setItem(*a);
            
            //pointer to head node in new chain
            Node<ItemType>* newChainPtr = topPtr;
            
            origPtr = origPtr -> getNext();
            
            while (origPtr != nullptr) {
                ItemType* nextItem = origPtr -> getItem();
                
                Node<ItemType>* newNodePtr = new Node<ItemType>(*nextItem);
                newChainPtr -> setNext(newNodePtr);
                newChainPtr = newChainPtr ->getNext();
                origPtr = origPtr -> getNext();
            }
            newChainPtr -> setNext(nullptr);
        }
    }
    ~Stack(){
        while (!isEmpty()) {
            pop();
        }
    }

    bool push( ItemType& newItem){
        if(topPtr == nullptr) {
            topPtr = new Node<ItemType>();
            topPtr -> setItem(newItem);
        }
        else {
            Node<ItemType>* temp = topPtr;
            topPtr = new Node<ItemType>();
            topPtr->setItem(newItem);
            topPtr -> setNext(temp);
        }
        return true;
    }


    bool pop(){
        bool result = false;
        if(!isEmpty()){
            Node<ItemType>* nodeToDelPtr = topPtr;
            topPtr = topPtr->getNext();
            
            nodeToDelPtr -> setNext(nullptr);
            delete nodeToDelPtr;
            nodeToDelPtr = nullptr;
            
            result = true;
        }
        return result;
    }


    ItemType* peek() const{
        if(isEmpty())
            return nullptr;
        return topPtr->getItem();
    }

    bool isEmpty() const{
        return topPtr == nullptr;
    }

private:
    Node<ItemType>* topPtr;
};

#endif /* Stack_h */
