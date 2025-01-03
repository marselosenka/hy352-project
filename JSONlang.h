#ifndef JSONLANG_H
#define JSONLANG_H

#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

// Define Macros

#define PROGRAM_BEGIN       ;int main(void) { JSON_derulo dummy;
#define PROGRAM_END         ;}


#define JSON(name)          ;JSON_derulo name 
#define STRING(str)         JSON_derulo(str)          

#define NUMBER(number)      JSON_derulo(number)

#define ARRAY               JSON_derulo{}

#define OBJECT              JSON_derulo 
#define KEY(str)            JSON_derulo(#str,1) = false ? JSON_derulo("false")
#define TRUE                JSON_derulo(true,"true")
#define FALSE               JSON_derulo(false,"false")

// MANIPULATION OF OBJECTS/ARRAYS
#define SET                 ;set_flag=true;probablyAppend=true;
#define ASSIGN              =
#define ERASE               ;toERASE=true; dummy>>
#define APPEND              += 

#define HAS_KEY(json,str)   hasKey(json,str)  
#define SIZE_OF(json)       ;size_of(json)
#define PRINT               ;cout<<
#define IS_EMPTY(json)      ;is_empty_json(json)
#define TYPE_OF(json)       type_of(json)

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
extern bool toERASE;
extern bool probablyAppend;
extern bool set_flag;
/**
 * Class that will be holding the JSON data.
 * 
 */
class JSON_derulo {
private:
    std::string key;

    // VALUES
    std::string strValue;
    int integerValue;
    double doubleValue;
    bool boolValue;
    
    std::vector<JSON_derulo> arrayValue;
    std::list<JSON_derulo> objectValue;

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

    int getIntegerValue() {
        return this->integerValue;
    }
    void setIntegerValue(int num);

    double getDoubleValue() {
        return this->doubleValue;
    }
    void setDoubleValue(double num);

    std::string getStringValue() {
        return this->strValue;
    }
    void setStringValue(std::string s);

    Type getType() {
        return this->x;
    }
    void setType(Type x);

    std::string getKey() {
        return this->key;
    }
    void setKey(std::string s);

    std::list<JSON_derulo> getObjectValue(){
        return this->objectValue;
    }
    void setObjectValue(std::list<JSON_derulo> obj);

    std::vector<JSON_derulo> getArrayValue(){
        return this->arrayValue;
    }
    void setArrayValue(std::vector<JSON_derulo> arr);

    bool getBoolValue(){
        return this->boolValue;
    }
    void setBoolValue(bool b);
    void clear_arr(int i){
        arrayValue.erase(arrayValue.begin()+i);
    }
    void clear_obj(std::string key,JSON_derulo js);
    void clear_obj();
    // Operator Overloads
    JSON_derulo operator=(JSON_derulo right);
    JSON_derulo& operator[](JSON_derulo js);
    JSON_derulo& operator[](int i);
    JSON_derulo& operator[](string s);
    JSON_derulo& operator,(JSON_derulo js);
    JSON_derulo& operator()(JSON_derulo js);
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
    JSON_derulo operator==(JSON_derulo js);
    JSON_derulo operator!=(JSON_derulo js);
    JSON_derulo& operator+=(JSON_derulo js);
    void operator>>(JSON_derulo& js);
    void operator<<(JSON_derulo& js);
};


JSON_derulo size_of(JSON_derulo rulo);
JSON_derulo hasKey(JSON_derulo js, std::string key);
void erase_data(JSON_derulo& rulo);
void printJSON(JSON_derulo json, int indent = 0);
bool areJSONEqual(JSON_derulo obj1,JSON_derulo obj2);
std::ostream& operator<<(std::ostream& os,const JSON_derulo& js);
JSON_derulo is_empty_json(JSON_derulo rulo);
bool findDuplicates(JSON_derulo js,std::string key);
JSON_derulo type_of(JSON_derulo rulo);
#endif