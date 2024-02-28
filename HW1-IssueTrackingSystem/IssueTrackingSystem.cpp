//  sec1-Meryem-Erdoğan



#include "IssueTrackingSystem.h"
#include "Issue.h"
#include <iostream>

IssueTrackingSystem::IssueTrackingSystem(){
    employees = nullptr;
    issues = nullptr;
    employeeNum = 0;
    issueNum = 0;
}

void IssueTrackingSystem::addEmployee( const string name, const string title ){
    
    for(int i = 0; i < employeeNum; i++){
        if(employees[i].getName() == name){
            cout << "Cannot add employee. Employee with name "<< name <<" already exists." << endl;
            return;
        }
    }
        if(employeeNum >= 0){
            Employee* temp = employees;
            employees = new Employee[employeeNum+1];
            for(int i = 0; i< employeeNum; i++){
                employees[i] = temp[i];
            }
            employees[employeeNum] = Employee(name, title);
            if(temp) delete[] temp;
        }
        cout << "Added employee " << name <<"." << endl;
        employeeNum++;
    }

void IssueTrackingSystem::removeEmployee( const string name ){
    
    bool isExist = false;
    
    for(int i = 0; i < employeeNum; i++){
        if(employees[i].getName() == name){
            isExist = true;
            
            if(employees[i].getNumOfIssues() == 0)
                removeEmployeeFromList(i);
            else{
                cout << "Cannot remove employee. " << name << " has assigned issues." << endl;
                return;
            }
        }
    }
    if(!isExist)
    {
        cout << "Cannot remove employee. There is no employee with name " << name << "." << endl;
        return;
    }
}

void IssueTrackingSystem::removeEmployeeFromList(const int index){
    Employee* temp = employees;
    
    if(employeeNum == 1){
        employees = nullptr;
    }
    else{
        employees = new Employee[employeeNum-1];
        for(int i = 0; i < employeeNum; i++ ){
            if(i < index)
                employees[i] = temp[i];
            else if(i > index)
                employees[i-1] = temp[i];
        }
        cout << "Removed employee " << temp[index].getName() << "." <<endl;
    }
    if(temp) delete[] temp;
    employeeNum--;
}

void IssueTrackingSystem::addIssue( const int issueId, const string description, const string assigneeName){
    
    bool isExist = false;
        
    for(int i = 0; i < employeeNum; i++){
        if(employees[i].getName() == assigneeName){
            isExist = true;
            break;
        }
    }
        
    if(!isExist){
        cout << "Cannot add issue. There is no employee with name " << assigneeName <<"." << endl;
        return;
    }
    
    for(int i = 0; i < issueNum; i++){
        if(issues[i].getId() == issueId){
            cout << "Cannot add issue. Issue with ID " << issueId << " already exists." << endl;
            return;
        }
    }
   
    for(int i = 0; i < employeeNum; i++){
        if(employees[i].getName() == assigneeName){
            employees[i].addIssue(issueId, description);
            break;
        }
    }
    Issue* temp = issues;
    
    if(issueNum >= 0){

        issues = new Issue[issueNum+1];
        
        for(int i = 0; i < issueNum; i++){
            issues[i] = temp[i];
        }
        issues[issueNum] = Issue(issueId, description, assigneeName);
    }
    cout << "Added issue " << issueId << "." <<endl;
    issueNum++;
    if(temp)
    delete[] temp;
}

void IssueTrackingSystem::removeIssue( const int issueId ){
    
    bool isExist = false;
    
    for(int i = 0; i < issueNum; i++){
        if(issues[i].getId() == issueId){
            isExist = true;
            cout << "Removed issue " << issueId << "." << endl;
            removeIssueFromList(i);
        }
    }
    if(!isExist){
        cout << "Cannot remove issue. There is no issue with ID " << issueId << "." << endl;
        return;
    }
}
void IssueTrackingSystem::removeIssueFromList(const int index){
    for(int i = 0; i < employeeNum; i++){
        if(employees[i].getName() == issues[index].getAssigneeName()){
            employees[i].removeIssue( issues[index].getId());
            break;
        }
    }
    Issue* temp = issues;
    if(issueNum == 1){
        issues = nullptr;
    }
    else{
        issues = new Issue[issueNum-1];
        
        for(int i = 0; i < issueNum; i++){
            if(i < index)
                issues[i] = temp[i];
            else if(i > index)
                issues[i-1] = temp[i];
        }
    }
    issueNum--;
    delete[] temp;
}

void IssueTrackingSystem::changeAssignee( const string previousAssignee, const string newAssignee ){
    int indexP = 0;
    int indexN = 0;
    bool isExistP = false;
    bool isExistN = false;
    
    for(int i = 0; i < employeeNum; i++){
        if(employees[i].getName() == previousAssignee){
            indexP = i;
            isExistP = true;
        }
        if(employees[i].getName() == newAssignee){
            indexN = i;
            isExistN = true;
        }
    }
    if(isExistP == false || isExistN == false){
        cout << "Cannot change assignee. Previous or/and new assignee does not exist." << endl;
        return;
    }
    Employee next;
    next= employees[indexP];
    employees[indexN].addIssues(&next,employees[indexP].getNumOfIssues());
    employees[indexP].removeAllIssues();
    
    for(int j = 0; j < issueNum; j++ ){
        if(issues[j].getAssigneeName() == previousAssignee){
            issues[j].setAssignee(newAssignee);
        }
    }
    cout << employees[indexP].getName()<<"'s issues are transferred to " << employees[indexN].getName() << "." << endl;
}
void IssueTrackingSystem::showAllEmployees() const{
    cout << "Employees in the system:" << endl;
    if(employeeNum == 0)
        cout << "None" << endl;
    else{
        for(int i = 0; i < employeeNum; i++){
            cout << employees[i].getName() << ", " << employees[i].getTitle()<< ", " << employees[i].getNumOfIssues()<< " issue(s)." <<endl ;
        }
    }
}
void IssueTrackingSystem::showAllIssues() const{
    cout << "Issues in the system:" << endl;
    if(issueNum == 0)
        cout << "None" << endl;
    else{
        for(int i = 0; i < employeeNum; i++){
            int num1 = employees[i].getNumOfIssues();
            for(int j = 0; j < num1; j++){
                cout << employees[i].getIssues()[j].getId() << ", " <<
                employees[i].getIssues()[j].getDescription() << ", " <<
                employees[i].getIssues()[j].getAssigneeName() << "." << endl;
            }
        }
    }
}
void IssueTrackingSystem::showEmployee( const string name ) const{
    for(int i = 0; i < employeeNum; i++){
        
        if(employees[i].getName() == name){
            
            cout << employees[i].getName() << ", " << employees[i].getTitle()<< ", " << employees[i].getNumOfIssues()<< " issue(s)." <<endl ;
            return;
        }
    }
    cout << "Cannot show employee. There is no employee with name " << name << "." << endl;
}
void IssueTrackingSystem::showIssue( const int issueId ) const{
    for(int i = 0; i < issueNum; i++){
        if(issues[i].getId() == issueId){
            cout << issues[i].getId() << ", " << issues[i].getDescription() << ", " << issues[i].getAssigneeName() << "." << endl;
            return;
        }
    }
    cout << "Cannot show issue. There is no issue with ID " << issueId << "." << endl;
}
IssueTrackingSystem::~IssueTrackingSystem(){
    if(employees) delete[] employees;
    if(issues) delete[] issues;
}
