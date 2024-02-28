//  sec1-Meryem-Erdoğan-



#include "Issue.h"

Issue::Issue(){
    id = 0;
    description = "";
    assigneeName = "";
}
Issue::Issue(const int issueId, const string description1, const string assigneeName1){
    id = issueId;
    description = description1;
    assigneeName = assigneeName1;
}
int Issue::getId(){
    return id;
}
string Issue::getDescription(){
    return description;
}
string Issue::getAssigneeName(){
    return assigneeName;
}
Issue& Issue::operator=(const Issue& right){
    id = right.id;
    description = right.description;
    assigneeName = right.assigneeName;
    return *this;
}
Issue::Issue(Issue& copy){
    id = copy.id;
    description = copy.description;
    assigneeName = copy.assigneeName;
}
void Issue::setId(int newID){
    id = newID;
}
void Issue::setDescription(string newDescription){
    description = newDescription;
}
void Issue::setAssignee(string newName){
    assigneeName = newName;
}
