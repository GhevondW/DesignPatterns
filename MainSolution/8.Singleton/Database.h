//
//  Database.h
//  Sinton
//
//  Created by Ghevond Gevorgyan on 7/24/19.
//  Copyright © 2019 Ghevond Gevorgyan. All rights reserved.
//

#define _FUNCTIONS_
#define _PROPS_
#define _CTORS_
#define _OPERATORS_

#include "File.h"
#include <map>
#include <string>

#ifndef Database_h
#define Database_h

namespace app {
    class Database {
        
        private _CTORS_:
        Database(){
            std::vector<std::string>& fileRef = File::DATA;
            for (int i = 0; i<fileRef.size()-1; i++) {
                std::string capital = fileRef[i];
                std::string populationString = fileRef[i+1];
                int population = std::stoi(populationString);
                _capitals.insert(std::make_pair(capital, population));
            }
        }
        
        public _CTORS_:
        Database(const Database& other) = delete;
        public _OPERATORS_:
        Database& operator=(const Database& other) = delete;
        
        public _FUNCTIONS_:
        static Database& get(){
            static Database db;
            return db;
        }
        
        int get_population(const std::string& city)const{
            auto iter = _capitals.find(city);
            if(iter != _capitals.end()){
                return iter->second;
            }
            return -1;
        }
        
        private _PROPS_:
        std::map<std::string,int> _capitals;
        //static Database* db; example
    };
    
    //Database* Database::db = new Database(); example
}



#endif /* Database_h */
