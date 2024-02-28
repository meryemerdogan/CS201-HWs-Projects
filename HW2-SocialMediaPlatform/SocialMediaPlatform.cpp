//
//  Meryem Erdoğan Sec1 

#include "SocialMediaPlatform.h"
SocialMediaPlatform::SocialMediaPlatform(){
    
}
SocialMediaPlatform::~SocialMediaPlatform(){
}

void SocialMediaPlatform::addRegularUser( const int regularUserId,
                    const string name ){
    User u(regularUserId, name);
    
    if(!isUserExist(u)){
        users.add(u, u.getID());
    cout << "Added regular user "<< regularUserId<<"." << endl;
    }
    else
        cout << "Cannot add regular user. There is already a regular user with ID " << regularUserId<<"." << endl;
}
    
void SocialMediaPlatform::removeRegularUser( const int regularUserId ){
    if(isUserExist(regularUserId)){
        users.removeByID(regularUserId);
        for(int i =1; i< contentCreators.getLength() + 1; i++){
            contentCreators.getEntry(i)->removeFollower(regularUserId);
        }
        cout << "Removed regular user " << regularUserId<< "." << endl;
        return;
    }
    else
        cout << "Cannot remove regular user. There is no regular user with ID "<< regularUserId<< "." << endl;
}

void SocialMediaPlatform::addContentCreator(
                   const int contentCreatorId,
                   const string name ){
    ContentCreator c(contentCreatorId, name);
    
    if(!isContentCreatorExist(c)){
        contentCreators.add(c, c.getId());
        cout << "Added content creator " << contentCreatorId << "." << endl;
    }
    else
        cout << "Cannot add content creator. There is already a content creator with ID "<< contentCreatorId<<"." << endl;
}
void SocialMediaPlatform::removeContentCreator( const int contentCreatorId ){
    if(isContentCreatorExist(contentCreatorId)){
        contentCreators.removeByID(contentCreatorId);
        cout << "Removed content creator " << contentCreatorId <<"."<<endl;
    }
    else
        cout << "Cannot remove content creator. There is no content creator with ID " << contentCreatorId <<"."<<endl;
}

void SocialMediaPlatform::addContent( const int contentCreatorId,
            const int contentId, const string title ){
    Content c (contentCreatorId, contentId, title);
    if(!isContentExist(c) && isContentCreatorExist(contentCreatorId)){
        contents.add(c, contentId);
        (*contentCreators.getItemByID(contentCreatorId)).addContent(c);
        cout << "Added content "<<contentId<<"."<< endl;
        return;
    }
    else if(isContentExist(c))
        cout << "Cannot add content. There is already a content with ID "<< contentId<<"." << endl;
    else
        cout << "Cannot add content. There is no content creator with ID "<< contentCreatorId<<"." << endl;
}
void SocialMediaPlatform::removeContent( const int contentCreatorId,
                                        const int contentId ){
    if(isContentCreatorExist(contentCreatorId) && isContentExist(contentId)){
        contents.removeByID(contentId);
        contentCreators.getItemByID(contentCreatorId)->removeContent(contentId);
        cout<<"Removed content "<< contentId<<"." << endl;
    }
    else if(!isContentCreatorExist(contentCreatorId)){
        cout << "Cannot remove content. There is no content creator with ID "<<contentCreatorId<< "."<<endl;
    }
    else
        cout << "Cannot remove content. There is no content with ID "<< contentId<<" shared by content creator with ID " << contentCreatorId<< "."<<endl;

}

void SocialMediaPlatform::followContentCreator( const int regularUserId,
                                               const int contentCreatorId ){
    for(int i= 1; i < users.getLength()+1; i++){
        if( users.getEntry(i)->getID() == regularUserId){
            for(int pos = 1; pos < contentCreators.getLength()+1; pos++){
                if(contentCreators.getEntry(pos)->getId() == contentCreatorId){
                    contentCreators.getEntry(pos)->addFollower((*users.getEntry(i)));
                    cout<< "Regular user with ID " << regularUserId<<" followed content creator with ID "<< contentCreatorId << "." << endl;
                    return;
                }
            }
        }
    }
    cout << "Cannot follow. Regular user and/or content creator ID does not exist." << endl;
}
void SocialMediaPlatform::unfollowContentCreator( const int regularUserId,
                                                 const int contentCreatorId){
    for(int i= 1; i < users.getLength()+1; i++){
        if( users.getEntry(i)->getID() == regularUserId){
            for(int pos = 1; pos < contentCreators.getLength()+1; pos++){
                if(contentCreators.getEntry(pos)->getId() == contentCreatorId){
                    bool a = contentCreators.getItemByID(contentCreatorId)->removeFollower(regularUserId);
                    if(!a){
                        cout << "Cannot unfollow. The user is not following the content creator." << endl;
                        return;
                    }
                    cout <<"Regular user with ID "<< regularUserId<<" unfollowed content creator with ID "<< contentCreatorId <<"." <<endl;
                    return;
                }
            }
        }
    }
    cout << "Cannot unfollow. Regular user and/or content creator ID does not exist." << endl;
}

void SocialMediaPlatform::showFollowersOf( const int contentCreatorId ) const{
    for(int i = 1; i < contentCreators.getLength()+1; i++){
        if(contentCreators.getEntry(i)->getId() == contentCreatorId){
            cout << "Regular users following content creator with ID " << contentCreatorId <<":" <<endl;
            contentCreators.getEntry(i)->showAllFollowers();
            return;
        }
    }
    cout << "Cannot show. There is no content creator with ID "<< contentCreatorId<<"." << endl;
}
void SocialMediaPlatform::showContentsOf( const int contentCreatorId ) const{
    for(int i = 1; i < contentCreators.getLength()+1; i++){
        if(contentCreators.getEntry(i)->getId() == contentCreatorId){
            contentCreators.getEntry(i)->showAllContents();
            return;
        }
    }
    cout << "Cannot show. There is no content creator with ID " << contentCreatorId <<"."<<endl;
    return;
}
void SocialMediaPlatform::showAllRegularUsers( ) const{
    cout << "Regular users in the social media platform:" << endl;
    if(users.getLength() == 0)
        cout << "None" << endl;
    for(int i= 1; i < users.getLength()+1; i++){
        cout << users.getEntry(i)->getID()<< ", " << users.getEntry(i)->getName() << endl;
    }
}
void SocialMediaPlatform::showAllContentCreators( ) const{
    cout << "Content creators in the social media platform:" << endl;
    if(contentCreators.getLength() == 0)
        cout << "None" << endl;
    for(int i = 1; i < contentCreators.getLength()+1; i++ ){
        
        cout<< contentCreators.getEntry(i)->getId() << ", " << contentCreators.getEntry(i)->getName()<< ", " <<
                contentCreators.getEntry(i)->getAllFollowers().getLength() <<
                " follower(s), " <<
                contentCreators.getEntry(i)->getAllContents().getLength()<<
                " content(s)" << endl;
    }
}
bool  SocialMediaPlatform::isUserExist(int id){
    for(int i = 1; i < users.getLength()+1; i++){
        if(users.getEntry(i)->getID() == id)
            return true;    }
    return false;
}
bool  SocialMediaPlatform::isUserExist(User u){
    for(int i = 1; i < users.getLength()+1; i++){
        if(users.getEntry(i)->getID() == u.getID())
            return true;
    }
    return false;
}


bool  SocialMediaPlatform::isContentExist(int id){
    for(int i = 1; i < contents.getLength()+1; i++){
        if(contents.getEntry(i)->getContentId() == id)
            return true;    }
    return false;
}
bool  SocialMediaPlatform::isContentExist(Content c){
    for(int i = 1; i < contents.getLength()+1; i++){
        if(contents.getEntry(i)->getContentId() == c.getContentId())
            return true;    }
    return false;
}


bool  SocialMediaPlatform::isContentCreatorExist(int id){
    for(int i = 1; i < contentCreators.getLength()+1; i++){
        if(contentCreators.getEntry(i)->getId() == id)
            return true;
    }
    return false;
}
bool  SocialMediaPlatform::isContentCreatorExist(ContentCreator c){
    for(int i = 1; i < contentCreators.getLength()+1; i++){
        if(contentCreators.getEntry(i)->getId() == c.getId())
            return true;
    }
    return false;
}
