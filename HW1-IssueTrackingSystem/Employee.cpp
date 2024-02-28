//  sec1-Meryem-Erdoğan-
//

#include "Employee.h"
#include <string>
using namespace::std;

Employee::Employee(){
    name = "";
    title = "";
    numOfIssues = 0;
    issues = nullptr;
}

Employee::Employee(const string name1, const string title1){
    name = name1;
    title = title1;
    numOfIssues = 0;
    issues = nullptr;
}
Employee::~Employee(){
    if(issues) delete [] issues;
}

Employee::Employee(Employee& copy){
    if(&copy != this){
        if(numOfIssues != copy.numOfIssues){
            if(numOfIssues > 0){
               if(issues) delete[] issues;
            }
            numOfIssues = copy.numOfIssues;
            if(numOfIssues > 0){
                issues = new Issue[numOfIssues];
            }
            else {
                issues = nullptr;
            }
        }
        for(int i = 0; i< numOfIssues; i++){
            issues[i] = copy.issues[i];
        }
        name = copy.name;
        title = copy.title;
    }
}
    
Employee& Employee::operator=(const Employee& right){
    if(&right != this){
        if(numOfIssues != right.numOfIssues){
            if(numOfIssues > 0){
                delete[] issues;
            }
            numOfIssues = right.numOfIssues;
            if(numOfIssues > 0){
                issues = new Issue[numOfIssues];
            }
            else {
                issues = nullptr;
            }
        }
        for(int i = 0; i< numOfIssues; i++){
            issues[i] = right.issues[i];
        }
        name = right.name;
        title = right.title;
        numOfIssues = right.numOfIssues;
    }
    return *this;
}
void Employee::addIssue(const int issueId, const string description){
    Issue* temp = issues;
    issues = new Issue[numOfIssues+1];
    
    for(int i = 0; i < numOfIssues; i++){
        issues[i] = temp[i];
    }
    issues[numOfIssues] = Issue(issueId, description, name);
    if(temp) delete [] temp;
    numOfIssues++;
}
void Employee::addIssues(Employee* from, int num){
    
    Issue* fromIssues = (*from).getIssues();
    
    Issue* temp = issues;
    issues = new Issue[num + numOfIssues];
    
    for(int i = 0; i < numOfIssues; i++){
        issues[i] = temp[i];
    }
    for(int i = numOfIssues; i < num+numOfIssues; i++){
        fromIssues[numOfIssues-i].setAssignee(name);
        issues[i] = fromIssues[numOfIssues-i];
    }
    if(temp) delete[] temp;
    numOfIssues+=num;
}

void Employee::removeAllIssues(){
    numOfIssues = 0;
    if(issues) delete[] issues;
    issues = nullptr;
}
void Employee::removeIssue(int id){
    for(int i = 0; i < numOfIssues; i++){
        if(issues[i].getId() == id){
            
            Issue* temp = issues;
            
            if(numOfIssues == 1){
                issues = nullptr;
            }
            else{
                issues = new Issue[numOfIssues-1];
                
                for(int j = 0; j < numOfIssues; j++){
                    if(j < i)
                        issues[j] = temp[j];
                    else if(j > i)
                        issues[j-1] = temp[j];
                }
            }
            delete[] temp;
            numOfIssues--;
        }
    }
}
string Employee::getName(){
    return name;
}
string Employee::getTitle(){
    return title;
}
Issue* Employee::getIssues(){
    return issues;
}
int Employee::getNumOfIssues(){
    return numOfIssues;
}
void Employee::setName(string newName){
    name = newName;
}
void Employee::setTitle(string newTitle){
    title = newTitle;
}
void Employee::setNumOfIssues(int newNum){
    numOfIssues = newNum;
}
