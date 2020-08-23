//
//  main.cpp
//  35this啥的
//
//  Created by codew on 8/22/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Person {
    
public:
    // 使用this 区分形参的区分
    Person(string name, int age){
        
        printf("%s\n", __func__);
        this->name = name;
        this->age = age;
    }
    
    // 2. 返回对象本身的引用
    
    Person PersonPlusPerson(Person& person){
        
        printf("%s\n", __func__);
        
        string newname = this->name + person.name;
        int newAge = this->age + person.age;
        
        Person newperson(newname, newAge);
        
        return newperson;
    }
    
    void showPerson(){
        
        cout << "name: " << name << " Age:" << age << endl;
    }
    
public:
    string name;
    int age;
};


Person PersonPlusPerson(Person& p1, Person& p2){
    
    printf("%s\n", __func__);
    string newName = p1.name + p2.name;
    
    int newAge = p1.age + p2.age;
    
    Person newperson(newName, newAge);
    
    return newperson;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    Person person("tom", 100);
    person.showPerson();
    
    cout << "--------------" <<endl;
    
    Person person1("John", 20);
    Person person2("kitil", 20);
    
    // 1. 全局函数实现两个对象相加
    Person person3 = PersonPlusPerson(person1, person2);
    
    person1.showPerson();
    person2.showPerson();
    person3.showPerson();
    
    // 2. 成员函数实现两个对象相加
    
    Person person4 = person1.PersonPlusPerson(person2);
    person4.showPerson();
    
    
    return 0;
}
