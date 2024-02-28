//  sec1-Meryem-Erdoğan


#include <string>
#include "Employee.h"
#include "Issue.h"
using namespace::std;

class IssueTrackingSystem {
public:
    IssueTrackingSystem();
    ~IssueTrackingSystem();
void addEmployee( const string name, const string title );
void removeEmployee( const string name );
void addIssue( const int issueId, const string description, const string
    assigneeName );
void removeIssue( const int issueId );
void changeAssignee( const string previousAssignee, const string newAssignee );
void showAllEmployees() const;
void showAllIssues() const;
void showEmployee( const string name ) const;
void showIssue( const int issueId ) const;
    void removeEmployeeFromList(const int index);
    void removeIssueFromList(const int index);

private:
    int employeeNum;
    int issueNum;
    Employee* employees;
    Issue* issues;
};
