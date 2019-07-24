//
//  main.cpp
//  Sinton
//
//  Created by Ghevond Gevorgyan on 7/24/19.
//  Copyright © 2019 Ghevond Gevorgyan. All rights reserved.
//

#include <iostream>
#include "Database.h"

int main(int argc, const char * argv[]) {
    
    std::string city = "yerevan";
    
    app::Database& db = app::Database::get();
    
    int population = db.get_population(city);
    
    std::cout<<population<<std::endl;
    
    return 0;
}
