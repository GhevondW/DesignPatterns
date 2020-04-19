//
//  MainSingleton.cpp
//  DesignPatterns
//
//  Created by Ghevond Gevorgyan on 4/17/20.
//  Copyright © 2020 Ghevond Gevorgyan. All rights reserved.
//

#if 0

#include <stdio.h>
#include <iostream>
#include "Database.h"

int main(){
    
    std::cout<<"---Singleton---"<<std::endl;
    
    std::shared_ptr<Database> db = Database::Get();
    
    db->Read();
    db->Write();
    
    std::shared_ptr<Database> db_ref = Database::Get();
    
    db_ref->Read();
    db_ref->Write();
    
    
    
    return 0;
}

#endif