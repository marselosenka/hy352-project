#ifndef JSONLANG_H
#define JSONLANG_H

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
using namespace std;

// Define Macros

#define PROGRAM_BEGIN       int main(void) { JSON_derulo js
#define PROGRAM_END         ;}


#define JSON(name)          ;JSON_derulo name 
#define STRING(str)         JSON_derulo(#str)          

#define NUMBER(number)      JSON_derulo(number)

#define ARRAY               JSON_derulo{}

#define OBJECT              JSON_derulo 
               

#define KEY(str)            JSON_derulo(#str,1) = false ? JSON_derulo("false")

#define TRUE                JSON_derulo(true,"true")
#define FALSE               JSON_derulo(false,"false")

#define ERASE name          erase_data(name);

// Enum to define data types
enum Type{
    no_type=0,
    integer=1,
    strg=2,
    doubl=3,
    obj_=4,
    arr=5,
    boolean=6
};

class JSON_derulo {
private:
    std::string Name;
    std::string key;

    std::string str;
    int in;
    double d;
    std::vector<JSON_derulo> array;
    std::list<JSON_derulo> obj;
    bool bool_;

    enum Type x;

public:

    // Constructors
    JSON_derulo(std::string s);
    JSON_derulo(std::string s, int i);
    JSON_derulo(int n);
    JSON_derulo(double n);
    JSON_derulo();
    JSON_derulo(std::initializer_list<JSON_derulo> list);
    JSON_derulo(bool bool_,std::string s);

    // Getters and Setters
    std::string getName();
    void setName(std::string s);

    int getIn() {
        return this->in;
    }
    void setIn(int num);

    double getD() {
        return this->d;
    }
    void setD(double num);

    std::string getString() {
        return this->str;
    }
    void setString(std::string s);

    Type getType() {
        return this->x;
    }
    void setType(Type x);

    std::string getKey() {
        return this->key;
    }
    void setKey(std::string s);

    std::list<JSON_derulo> getObj(){
        return this->obj;
    }
    void setObj(std::list<JSON_derulo> obj);

    std::vector<JSON_derulo> getArr(){
        return this->array;
    }
    void setArr(std::vector<JSON_derulo> arr);

    bool getBool(){
        return this->bool_;
    }

    void setBool(bool b);
    // Operator Overloads
    JSON_derulo operator=(JSON_derulo right);
    JSON_derulo& operator[](JSON_derulo js);
    JSON_derulo& operator,(JSON_derulo js);
    JSON_derulo operator+(JSON_derulo js);
    JSON_derulo operator-(JSON_derulo js);
    JSON_derulo operator/(JSON_derulo js);
    JSON_derulo operator*(JSON_derulo js);
    JSON_derulo operator%(JSON_derulo js);
    JSON_derulo operator>(JSON_derulo js);
    JSON_derulo operator>=(JSON_derulo js);
    JSON_derulo operator<(JSON_derulo js);
    JSON_derulo operator<=(JSON_derulo js);
    JSON_derulo operator&&(JSON_derulo js);
    JSON_derulo operator||(JSON_derulo js);
};

void erase_data(JSON_derulo rulo);
#endif