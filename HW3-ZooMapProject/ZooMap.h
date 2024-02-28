//
//  ZooMap.h
//  ZooMap
//
//  Created by Meryem Erdoğan-22203723-Sec1
//

#ifndef ZooMap_h
#define ZooMap_h

#include "Cage.h"
#include "Stack.h"

using namespace std;
class ZooMap {
public:
    ZooMap(const string cageFile, const string zooFile);
    ~ZooMap();
    void displayAllCages() const;
    void displayAdjacentCages(const string cageName) const;
    void displayZooMap() const;
    void findSafestPath(const string startCage, const string endCage);
    void findMostDangerousPath(const string startCage, const string endCage);
    
    Cage* getNext(Cage* topCage, Stack<Cage>* mapS);
    void unvisitAll();
    void markVisited(Cage start);
    void unvisit(Cage start);
    double calcPos(Stack<Cage> s);
    int addPath(Cage*& path,Stack<Cage> mapS);
    bool checkIfVisited(Cage* nextCage);
private:
    Cage* cages;
    int nuOfCages;
    bool* isVisited;
};

#endif /* ZooMap_h */
