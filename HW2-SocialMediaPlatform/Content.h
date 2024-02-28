//
//  Meryem Erdoğan Sec1 

#ifndef Content_h
#define Content_h

#include <stdio.h>
#include <iostream>
using namespace std;

class Content{
private:
    int contentCreatorId;
    int contentId;
    string title;
public:
    Content(int contentCreatorId,
            int contentId,
            string title);
    Content();
    int getContentCreatorId();
    int getContentId();
    string getTitle();
    
    void setContentCreatorId(int contentCreatorId);
    void setContentId(int contentId);
    void setTitle(string title);
    bool operator<( const Content& );
};
#endif /* Content_hpp */
