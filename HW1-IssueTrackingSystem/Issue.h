//  sec1-Meryem-Erdoğan-


#ifndef Issue_hpp
#define Issue_hpp
#include <string>
using namespace::std;
#include <stdio.h>
class Issue{
public:
    Issue();
    Issue(const int issueId, const string description, const string assigneeName);
    int getId();
    string getDescription();
    string getAssigneeName();
    Issue& operator=(const Issue& right);
    Issue(Issue& copy);
    void setId(int newID);
    void setDescription(string newDescription);
    void setAssignee(string newName);
    
private:
    int id;
    string description;
    string assigneeName;
};
#endif /* Issue_hpp */
