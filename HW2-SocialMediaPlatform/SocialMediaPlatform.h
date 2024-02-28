//
//  Meryem Erdoğan Sec1 

#ifndef SocialMediaPlatform_h
#define SocialMediaPlatform_h

#include <stdio.h>
#include "ContentCreator.h"

using namespace::std;

class SocialMediaPlatform {
public:
SocialMediaPlatform();
~SocialMediaPlatform();
void addRegularUser( const int regularUserId,
                    const string name );
void removeRegularUser( const int regularUserId );
void addContentCreator( const int contentCreatorId,
                       const string name );
void removeContentCreator( const int contentCreatorId );
void addContent( const int contentCreatorId,
                const int contentId, const string
    title );
void removeContent( const int contentCreatorId,
                   const int contentId );
void followContentCreator( const int regularUserId,
                          const int contentCreatorId );
void unfollowContentCreator( const int regularUserId,
                            const int contentCreatorId);
void showFollowersOf( const int contentCreatorId ) const;
void showContentsOf( const int contentCreatorId ) const;
void showAllRegularUsers( ) const;
void showAllContentCreators( ) const;

private:
    bool isUserExist(int id);
    bool isUserExist(User u);

    
    bool isContentExist(int id);
    bool isContentExist(Content c);

    
    bool isContentCreatorExist(int id);
    bool isContentCreatorExist(ContentCreator c);

    
    LinkedList<Content> contents;
    LinkedList<ContentCreator> contentCreators;
    LinkedList<User> users;

};

#endif /* SocialMediaPlatform_hpp */
