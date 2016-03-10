/******************************************************************************
 Course Project
 CD and DVD Collection
 CISS 243-A
 
 <description>  Pulls from the base class of Media, allows the user to create 
                a data type that keeps the nessecary info for a DVD.

 
 <author> John Carty
 <date> 7 - Oct - 2015
 <revision> NONE
 
 ******************************************************************************/

#ifndef DVD_h
#define DVD_h

#include <stdio.h>
#include <iomanip>
#include "Media.h"
#include "List.h"

class DVD : public Media {
    private:
        struct actor {
            std::string actorsName;
            std::string charactersName;
            
            actor(){
                actorsName = "";
                charactersName = "";
            }
        };
        
        List<actor> roles;
        int year;
    
    public:
        DVD();
        
        void setYear(int);
        void setRoles(std::string, std::string);
        void setLength(int);
    
        void getRoles(int);
        
        bool operator == (DVD &);
        bool operator != (DVD &);
        
        int getYear();
};

#endif /* DVD_h */
