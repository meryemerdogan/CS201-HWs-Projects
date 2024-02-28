//
//  Cage.h
//  ZooMap
//
//  Created by Meryem Erdoğan-22203723-Sec1
//

#ifndef Cage_h
#define Cage_h
#include <iostream>
#include "Node.h"
using namespace std;
class Cage{
public:
    Cage();
    Cage(string letter, double livPer);
    ~Cage();
    void setName(string letter);
    void setLivingPercent(double livPer);
    string getName();
    double getLivingPercent();
    void addAdjCage(Cage& c);
    bool isAdjCageExist(Cage& c);
    LinkedList<Cage>* getAdjList();
    int getNuOfCages();
    bool* getisAdjVisited();
    void setAdjVisited(Cage c);
    void unVisitAll();
    Cage* getNextCage();
    bool operator<( const Cage& );
private:
    double livingPercent;
    string name;
    LinkedList<Cage>* adjList;
    int nuOfAdjCages;
    bool* isAdjVisited;
};

#endif /* Cage_h */
