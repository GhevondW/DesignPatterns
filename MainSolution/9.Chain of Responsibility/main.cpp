//
//  main.cpp
//  ChainOfResposibility
//
//  Created by Ghevond Gevorgyan on 7/25/19.
//  Copyright © 2019 Ghevond Gevorgyan. All rights reserved.
//

#include "Base.h"

int main(int argc, const char * argv[]) {
    
    Employee e1("f1","l1",POSITION::P1,STATUS::A);
    Employee e2("f2","l2",POSITION::P2,STATUS::B);
    Employee e3("f3","l3",POSITION::P3,STATUS::B);
    
    System* sys = new MessageSystem(e1);
    sys->add(new MessageSystem(e2));
    sys->add(new MessageSystem(e3));
    
    Message msg("Hello World",POSITION::P1);
    
    sys->handle(msg);
    
    return 0;
}
