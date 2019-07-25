//
//  Base.h
//  ChainOfResposibility
//
//  Created by Ghevond Gevorgyan on 7/25/19.
//  Copyright © 2019 Ghevond Gevorgyan. All rights reserved.
//

#include <iostream>
#include <string>

#ifndef Base_h
#define Base_h

#define _FUNCTIONS_
#define _PROPS_
#define _CTORS_

typedef enum{
    A,
    B,
} STATUS;

typedef enum{
    P1,
    P2,
    P3,
} POSITION;

class Employee{
    typedef const std::string& constStringRef;
public _CTORS_:
    Employee(constStringRef firstName,constStringRef lastName, POSITION position,const STATUS status)
    :_firstName(firstName),
    _lastName(lastName),
    _position(position),
    _status(status)
    {}
    
public _FUNCTIONS_:
    
    constStringRef get_firstName()const{
        return _firstName;
    }
    constStringRef get_lastName()const{
        return _lastName;
    }
    POSITION get_position()const{
        return _position;
    }
    STATUS get_status()const{
        return _status;
    }
    
    int get_salary() const{
        return _salary;
    }
    
    void set_position(const POSITION position){
        _position = position;
    }
    
    void set_status(const STATUS status){
        _status = status;
    }
    
    void set_salary(const int salary){
        _salary = salary;
    }
    
private _PROPS_:
    const std::string _firstName;
    const std::string _lastName;
    POSITION _position;
    STATUS _status;
    int _salary;
};

class Message{
public _CTORS_:
    Message(const std::string& text,const POSITION position)
    :_text(text),
    _position(position)
    {}
    
public _FUNCTIONS_:
    const POSITION get_position()const{
        return _position;
    }
    const std::string get_text(){
        return _text;
    }
private _PROPS_:
    const std::string _text;
    const POSITION _position;
};

class System{
    
public _CTORS_:
    System(Employee& emp)
    :_emp(emp)
    {}
    
public _FUNCTIONS_:
    
    void add(System* messageingSystem){
        if(_next){
            _next->add(messageingSystem);
        }else{
            _next = messageingSystem;
        }
    }
    
    virtual void handle(Message& msg){
        _next->handle(msg);
    }
    
private _PROPS_:
    System* _next = nullptr;
    
protected _PROPS_:
    Employee& _emp;
};

class MessageSystem: public System{
public _CTORS_:
    MessageSystem(Employee& emp)
    :System(emp)
    {}
public _FUNCTIONS_:
    void handle(Message& msg) override{
        if(msg.get_position() == _emp.get_position()){
            std::cout<<_emp.get_firstName()<<"[OK]"<<std::endl;
        }
        else{
            std::cout<<_emp.get_firstName()<<"[NO]"<<std::endl;
            System::handle(msg);
        }
        //OR
//        if(msg.get_position() == _emp.get_position()){
//            std::cout<<_emp.get_firstName()<<"[OK]"<<std::endl;
//        }
//        else{
//            std::cout<<_emp.get_firstName()<<"[NO]"<<std::endl;
//        }
//        System::handle(msg);
    }
};

#endif /* Base_h */
