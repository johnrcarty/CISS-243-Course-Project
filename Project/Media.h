/******************************************************************************
 Course Project
 CD and DVD Collection
 CISS 243-A
 
 <description>  Base class for the CD and DVD classes
 
 <author> John Carty
 <date> 7 - Oct - 2015
 <revision> NONE
 
 ******************************************************************************/

#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <iostream>

class Media {
    protected:
        std::string title;
        double length;
        
    public:
        Media();
        
        void setTitle(std::string);
        
    
        std::string getTitle();
        double getLength();
  
};


#endif /* MEDIA_H */

