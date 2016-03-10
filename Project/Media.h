/******************************************************************************
 Course Project
 CD and DVD Collection
 CISS 243-A
 
 <description>  Provides a menu for the user to select if they want to work
 with cds or dvds. The program will then keep a list of the
 users cd and dvd collection and allow them to add, remove,
 update, or outout the contents.
 
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

