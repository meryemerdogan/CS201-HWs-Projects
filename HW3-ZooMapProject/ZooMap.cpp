//
//  ZooMap.cpp
//  ZooMap
//
//  Created by Meryem Erdoğan-22203723-Sec1
//

#include <stdio.h>
#include "ZooMap.h"
#include <iostream>
#include <fstream>

ZooMap::ZooMap(const string cageFile, const string zooFile){
    cages = nullptr;
    ifstream cageF;
    cageF.open(cageFile);
    double number;
    char line[7];  int conNum = 0;      string k= "";

    nuOfCages = 0;
    while (cageF.getline(line, 7)){
        string temp(line);
        string num = temp.substr(2);
        number = stod(num);
        string a =k+temp.at(0);
        Cage c(a, number);
        Cage* tempCag = cages;
        cages = new Cage[nuOfCages+1];
        for(int i = 0; i < nuOfCages; i++){
            cages[i]=tempCag[i];
        }
        cages[nuOfCages] = c;
        nuOfCages++;
        if(tempCag)
            delete[] tempCag;
    }
    cageF.close();
    
    ifstream zooF;
    zooF.open(zooFile);
    string letter1,letter2;
    Cage *c1 = nullptr;
    Cage *c2 = nullptr;
    while (zooF.getline(line, 4)){
        letter1 = k+ line[0];
        letter2 = k+ line[2];
        for(int i = 0; i < nuOfCages; i++){
            if(cages[i].getName() == letter1) {
                c1 = &cages[i];
            }
            if(cages[i].getName() == letter2){
                c2 = &cages[i];
            }
        }
        c1->addAdjCage(*c2);
        conNum++;
    }
    zooF.close();
    isVisited = new bool[nuOfCages];
    for(int i = 0; i < nuOfCages; i++){
        isVisited[i] = false;
    }
    cout << nuOfCages <<" cages and "<<conNum<<" connections have been loaded."<<endl;
}
ZooMap::~ZooMap(){
    if(cages) delete[] cages;
    if(isVisited) delete[] isVisited;
}
void ZooMap::displayAllCages() const{
    cout << "The cages in the zoo are:" << endl;
    LinkedList<string>s;
    string** stringArr= new string*[nuOfCages];
    for(int i = 0; i < nuOfCages; i++){
        stringArr[i] = new string(cages[i].getName());
        s.add(*stringArr[i], i);
    }
    for(int i = 1; i < nuOfCages+1; i++){
        if(i==nuOfCages){
            cout <<*s.getEntry(i)<< ",";
        }else
        cout <<*s.getEntry(i)<< ", ";
    }
    for (int i = 0; i < nuOfCages; i++) {
        delete stringArr[i];
    }
    delete[] stringArr;
    cout << endl;

}
void ZooMap::displayAdjacentCages(const string cageName) const{
    cout << "The cages adjacent to " << cageName << " are:" << endl;
    cout << cageName  << " ->";
    
    for(int i = 0; i < nuOfCages; i++){
        
        if(cages[i].getName() == cageName){
            
            for(int j = 1; j < cages[i].getNuOfCages()+1; j++){
                cout << " " <<cages[i].getAdjList()->getEntry(j)->getName()<< ",";
            }
        }
    }
    cout << endl;
}
void ZooMap::displayZooMap() const{
    cout << "The whole zoo map is:" <<endl;
    LinkedList<string> names;
    string** nameS = new string*[nuOfCages];
    for(int i = 0; i < nuOfCages; i++){
        nameS[i] = new string(cages[i].getName());
        names.add(*nameS[i], i);
    }
    int index = 0;
    for(int i = 1; i < nuOfCages+1; i++){
            for(int k = 0; k < nuOfCages; k++ ){
                if(cages[k].getName() == *names.getEntry(i))
                index = k;
            }
            cout << cages[index].getName() << " ->";
            for(int j = 1; j < cages[index].getNuOfCages()+1; j++){
                if(j==cages[index].getNuOfCages())
                    cout << " "<<cages[index].getAdjList()->getEntry(j)->getName()<< ",";
                else
                cout << " "<<cages[index].getAdjList()->getEntry(j)->getName()<< ",";
            }
        cout << endl;
    }
    for (int i = 0; i < nuOfCages; i++) {
        delete nameS[i];
    }
    delete[] nameS;
    
}
void ZooMap::findSafestPath(const string startCage, const string endCage){
    Stack<Cage> mapS;
    double min = -1;
    int pathLen = 0;
    unvisitAll();
    Cage *start= nullptr; Cage *end= nullptr;
    Cage* path = nullptr;
    
    for(int i = 0; i < nuOfCages; i++ ){
        if(cages[i].getName()==startCage && start == nullptr)
             start = &cages[i];
        else if(cages[i].getName()==endCage && end == nullptr)
             end = &cages[i];
    }
    
    mapS.push(*start);
    markVisited(*start);
    
    Cage* topCage = mapS.peek();
    while ( !mapS.isEmpty()) {
        
        Cage* nextCage = topCage->getNextCage();
        while(nextCage !=nullptr && checkIfVisited(nextCage)){
            nextCage = topCage->getNextCage();
        }
        if(nextCage == nullptr){
            unvisit(*mapS.peek());
            mapS.pop();
            topCage = mapS.peek();
        }
        else {
            mapS.push(*nextCage);
            
            if(nextCage->getName() == endCage){
                double posib = calcPos(mapS);
            
                if(min == -1 || min < posib){
                    min = posib;
                    pathLen = addPath(path, mapS);
                }
                mapS.pop();
            }
            else{
                markVisited(*nextCage);
                topCage = mapS.peek();
            }
        }
        
    }
    
    if(min == -1){
        cout << "No path exists from "<< startCage<<" to "<<endCage <<"." << endl;
        return;
    }
    cout << "Safest path from "<<startCage<<" to "<<endCage<<" is:" << endl;
    for(int i = pathLen-1; -1 < i;i--){
        cout << path[i].getName();
        if(i!=0)
            cout <<" -> ";
        else
            cout << endl;
    }
    cout <<"Probability: ";
   
    cout.precision(6);
    cout << fixed <<min << endl;
    
}
void ZooMap::unvisitAll(){
    for(int i = 0; i < nuOfCages; i++ ){
        isVisited[i] = false;
        cages[i].unVisitAll();
    }
}
void ZooMap::markVisited(Cage start){
    for(int i = 0; i < nuOfCages; i++ ){
        if(cages[i].getName()==start.getName()){
            isVisited[i] = true;
        }
    }
}
void ZooMap::unvisit(Cage start){
    for(int i = 0; i < nuOfCages; i++ ){
        if(cages[i].getName()==start.getName()){
            isVisited[i] = false;
            cages[i].unVisitAll();
        }
        
    }
}
void ZooMap::findMostDangerousPath(const string startCage, const string endCage){
    Stack<Cage> mapS;
    double min = -1;
    int pathLen = 0;
    unvisitAll();
    Cage *start= nullptr; Cage *end= nullptr;
    Cage* path = nullptr;
    
    for(int i = 0; i < nuOfCages; i++ ){
        if(cages[i].getName()==startCage && start == nullptr)
             start = &cages[i];
        else if(cages[i].getName()==endCage && end == nullptr)
             end = &cages[i];
    }
    
    mapS.push(*start);
    markVisited(*start);
    
    Cage* topCage = mapS.peek();
    while ( !mapS.isEmpty()) {
        
        Cage* nextCage = topCage->getNextCage();
        while(nextCage !=nullptr && checkIfVisited(nextCage)){
            nextCage = topCage->getNextCage();
        }
        if(nextCage == nullptr){
            unvisit(*mapS.peek());
            mapS.pop();
            topCage = mapS.peek();
        }
        else {
            mapS.push(*nextCage);
            
            if(nextCage->getName() == endCage){
                double posib = calcPos(mapS);
            
                if(min == -1 || min > posib){
                    min = posib;
                    pathLen = addPath(path, mapS);
                }
                mapS.pop();
            }
            else{
                markVisited(*nextCage);
                topCage = mapS.peek();
            }
        }
        
    }
    if(min == -1){
        cout << "No path exists from "<< startCage<<" to "<<endCage <<"." << endl;
        return;
    }
    cout << "Most dangerous path from "<<startCage<<" to "<<endCage <<" is:" << endl;
    for(int i = pathLen-1; -1 < i;i--){
        cout << path[i].getName();
        if(i!=0)
            cout <<" -> ";
        else
            cout << endl;
    }
    cout <<"Probability: ";
    cout.precision(6);
    cout << fixed <<min << endl;
}
double ZooMap::calcPos(Stack<Cage> s){
    double pos = 1;
    while(!s.isEmpty()){
        pos*=s.peek()->getLivingPercent();
        s.pop();
    }
    return pos;
}
int ZooMap::addPath(Cage*& path,Stack<Cage> mapS){
    int i = 0;
    
    if(path) delete[] path;
    
    Stack<Cage> temp(mapS);
    while(!temp.isEmpty()){
        temp.pop();
        i++;
    }
    int fin = i;
    path = new Cage[i];
    i = 0;
    while(!mapS.isEmpty()){
        path[i] = *mapS.peek();
        mapS.pop();
        i++;
    }
    return fin;
}
bool ZooMap::checkIfVisited(Cage* nextCage){
    for(int i = 0; i < nuOfCages; i++ ){
        if(cages[i].getName()==nextCage->getName()){
            if(isVisited[i] == true){
                return true;
            }
        }
    }
    return false;
}
