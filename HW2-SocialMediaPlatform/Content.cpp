//  Created by Meryem Erdoğan Sec1 
//

#include <stdio.h>
#include "Content.h"

Content::Content(int newContentCreatorId,
                 int newContentId,
                 string newTitle){
    contentCreatorId = newContentCreatorId;
    contentId = newContentId;
    title = newTitle;
}
Content::Content(){
    contentCreatorId = 0;
    contentId = 0;
    title = "";
}
int Content::getContentCreatorId(){
    return contentCreatorId;
}
int Content::getContentId(){
    return contentId;
}
string Content::getTitle(){
    return title;
}

void Content::setContentCreatorId(int newContentCreatorId){
    contentCreatorId = newContentCreatorId;
}

void Content::setContentId(int newContentId){
    contentId = newContentId;
}
void Content::setTitle(string newTitle){
    title = newTitle;
}
bool Content::operator<( const Content& b){
    if(this->contentId > b.contentId ){
        return false;
    }
    else return true;
}
