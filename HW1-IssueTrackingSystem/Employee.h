//  sec1-Meryem-Erdoğan-


#include <string>
#include "Issue.h"
using namespace::std;


class Employee{
public:
    Employee();
    ~Employee();
    Employee(const string name, const string title);
    Employee& operator=(const Employee& right);
    Employee(Employee& copy);
    
    void addIssues(Employee* from, int num);
    void addIssue(const int issueId, const string description);
    void removeIssue(int id);
    void setName(string newName);
    void setTitle(string newTitle);
    void setNumOfIssues(int newNum);
    void removeAllIssues();
    
    string getName();
    string getTitle();
    Issue* getIssues();
    int getNumOfIssues();

private:
    string name;
    string title;
    int numOfIssues;
    Issue* issues;
};
