//
//  Cage.cpp
//  ZooMap
//
//  Created by Meryem Erdoğan-22203723-Sec1
//

#include "Cage.h"

Cage::Cage(){
    name = "";
    livingPercent = 0;
    adjList = nullptr;
    nuOfAdjCages = 0;
    isAdjVisited = nullptr;
}
    Cage::Cage(string letter, double livPer){
        nuOfAdjCages = 0;
        name = letter;
        livingPercent = livPer;
        adjList = nullptr;
        isAdjVisited = nullptr;
    }

void Cage::setName(string letter){
    name = letter;
}

void Cage::setLivingPercent(double livPer){
    livingPercent = livPer;
}

string Cage::getName(){
    return name;
}

double Cage::getLivingPercent(){
    return livingPercent;
}

void Cage::addAdjCage(Cage& c){
    if(adjList==nullptr)
        adjList = new LinkedList<Cage>();
    if(isAdjCageExist(c))
        return;
    
    adjList->add(c, c.getNuOfCages());
    
    if(nuOfAdjCages >= 0){
        bool* temp = isAdjVisited;
        isAdjVisited = new bool[nuOfAdjCages+1];
        for(int i = 0; i < nuOfAdjCages; i++){
            isAdjVisited[i] = temp[i];
        }
        isAdjVisited[nuOfAdjCages] = false;
        if(temp) delete[] temp;
    }
    nuOfAdjCages++;
}

bool Cage::isAdjCageExist(Cage& c){
    for(int i = 0; i < nuOfAdjCages; i++ ){
        if(adjList->getEntry(i+1)->getName() == c.getName()){
            return true;
        }
    }
    return false;
}

Cage::~Cage(){
    
}
int Cage::getNuOfCages(){
    return nuOfAdjCages;
}

LinkedList<Cage>* Cage::getAdjList(){
    return adjList;
}
bool*  Cage::getisAdjVisited(){
    return isAdjVisited;
}
void  Cage::setAdjVisited(Cage c){
    for(int i = 0; i < nuOfAdjCages; i++){
        if(c.getName()==adjList->getEntry(i+1)->getName())
            isAdjVisited[i] = true;
    }
    
}
void Cage::unVisitAll(){
    for(int i = 0; i < nuOfAdjCages; i++){
        isAdjVisited[i] = false;
    }
}
Cage* Cage::getNextCage(){
    if(adjList == nullptr){
        return nullptr;
    }
    for(int i = 0; i < nuOfAdjCages; i++){
        if(isAdjVisited[i] == false){
            isAdjVisited[i] = true;
            return adjList->getEntry(i+1);
        }
    }
    return nullptr;
}
bool Cage::operator<( const Cage& b){
    if(this->name < b.name ){
        return true;
    }
    return false;
}

