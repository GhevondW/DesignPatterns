//
//  File.h
//  Sinton
//
//  Created by Ghevond Gevorgyan on 7/24/19.
//  Copyright © 2019 Ghevond Gevorgyan. All rights reserved.
//

#include <vector>
#include <string>

#ifndef File_h
#define File_h

namespace app {
    class File{
    public:
        static std::vector<std::string> DATA;
    };
    
    std::vector<std::string> File::DATA = {"Yerevan","800000","New York","17800000","London","25000000","Osaka","16800000"};
}



#endif /* File_h */
