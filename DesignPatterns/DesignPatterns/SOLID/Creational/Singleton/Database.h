//
//  Database.h
//  DesignPatterns
//
//  Created by Ghevond Gevorgyan on 4/17/20.
//  Copyright © 2020 Ghevond Gevorgyan. All rights reserved.
//

#ifndef Database_h
#define Database_h

#include <memory>

class Database
{
private:
    Database(){ std::cout<<"DB ctor"<<std::endl; }
public:
    
    ~Database(){ std::cout<<"DB dtor"<<std::endl; }
    
    static std::shared_ptr<Database> Get()
    {
        if(db == nullptr){
            db = std::shared_ptr<Database>(new Database());
        }
        return db;
    }
    
    void Read(){ std::cout<<"DB Read"<<std::endl; }
    void Write(){ std::cout<<"DB Write"<<std::endl; }
    
private:
    static std::shared_ptr<Database> db;
};

std::shared_ptr<Database> Database::db = nullptr;

#endif /* Database_h */
