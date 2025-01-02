#include "JSONlang.h"
#include <iostream>


JSON_derulo *temp = NULL;
JSON_derulo *temp2 = NULL;


// CONSTRUCTORS 
JSON_derulo::JSON_derulo(std::string s) {
    x = strg;
    this->str = s;
}
JSON_derulo::JSON_derulo(std::string s,int i) {
    this->key = s;
}

// Use auto for those (later).
JSON_derulo::JSON_derulo(int n) {
    in = n;
    x = integer;
}
JSON_derulo::JSON_derulo(double n) {
    d = n;
    x = doubl;
}
JSON_derulo::JSON_derulo(bool b,std::string s){
    this->bool_ = b;
    x = boolean;
}
JSON_derulo::JSON_derulo() {
    Name = "default-array";
    x = arr;
}
JSON_derulo::JSON_derulo(std::initializer_list<JSON_derulo> list) {
    for (const auto& elem : list) {
        obj.push_back(elem);
    }
    this->setType(obj_);
}
// SET / GET

std::string JSON_derulo::getName() {
    return this->Name;
}

void JSON_derulo::setName(std::string s) {
    this->Name = s;
}


void JSON_derulo::setIn(int num) {
    in = num;
}


void JSON_derulo::setD(double num) {
    d = num;
}

void JSON_derulo::setString(std::string s) {
    this->str = s;
}



void JSON_derulo::setType(Type x) {
    this->x = x;
}

void JSON_derulo::setKey(std::string s) {
    this->key = s;
}

void JSON_derulo::setObj(std::list<JSON_derulo> obj){
    this->obj = obj;
}


void JSON_derulo::setArr(std::vector<JSON_derulo> arr){
    this->array = arr;
}

void JSON_derulo::setBool(bool b){
    this->bool_ = b;
}
// Operator overloading used for Objects(Mainly).
JSON_derulo JSON_derulo::operator=(JSON_derulo right) {
    
    if(right.getType() == strg) {
        this->setString(right.getString());
        this->setType(right.getType());

    } else if(right.getType() == integer) {
        this->setIn(right.getIn());
        this->setType(right.getType());

    } else if(right.getType() == doubl) {
        this->setD(right.getD());
        this->setType(right.getType());

    } else if(right.getType() == obj_) {
        this->setObj(right.getObj());
        this->setType(right.getType());

    } else if(right.getType() == arr) {
        this->setArr(right.getArr());
        this->setType(right.getType());
    }


    return *this;
}

JSON_derulo& JSON_derulo::operator+=(JSON_derulo right) {
    if(this->getType() == strg && (right.getType() == strg) ) {
        this->setString(right.getString());
    }
    return *this;
}

JSON_derulo& JSON_derulo::operator[](JSON_derulo js) {
    if(temp != NULL) {
        this->setArr(temp->getArr());
    }
    this->array.emplace(this->array.begin(),js);
    if(temp != NULL) {
        temp = NULL;
    }
    return *this;
}

JSON_derulo& JSON_derulo::operator,(JSON_derulo js) {

    if(temp == NULL) {
        temp = &js;
    }
    temp->array.push_back(js);
    return *this;
}        
JSON_derulo JSON_derulo::operator+(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        n.setIn(this->getIn() + js.getIn());
        n.setType(integer);
    }else if(this->getType() == doubl && js.getType() == doubl){
        n.setD(this->getD() + js.getD());
        n.setType(doubl);
    }else if(this->getType() == doubl && js.getType() == integer){
        n.setD(this->getD() + js.getIn());
        n.setType(doubl);
    }else if(this->getType() == integer && js.getType() == doubl){
        n.setD(this->getIn() + js.getD());
        n.setType(doubl);
    }
    else if(this->getType() == strg && js.getType() == strg){
        n.setString(this->getString() + js.getString());
        n.setType(strg);
    }else if(this->getType() == arr && js.getType() == arr){
        std::vector<JSON_derulo> tmp;
        for (JSON_derulo value : this->getArr()) {
            tmp.push_back(value);
        }
        for (JSON_derulo value : js.getArr()) {
            tmp.push_back(value);
        }
        n.setType(arr);
        n.setArr(tmp);
    }else if(this->getType() == obj_ && js.getType() == obj_){//case for duplicate keys
        std::list<JSON_derulo> tmp;
        for (JSON_derulo value : this->getObj()) {
            tmp.push_back(value);
        }
        for (JSON_derulo value : js.getObj()) {
            tmp.push_back(value);
        }
        n.setType(obj_);
        n.setObj(tmp);
    }
    return n;
}
JSON_derulo JSON_derulo::operator-(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        n.setIn(this->getIn() - js.getIn());
        n.setType(integer);
    }else if(this->getType() == doubl && js.getType() == doubl){
        n.setD(this->getD() - js.getD());
        n.setType(doubl);
    }else if(this->getType() == doubl && js.getType() == integer){
        n.setD(this->getD() - js.getIn());
        n.setType(doubl);
    }else if(this->getType() == integer && js.getType() == doubl){
        n.setD(this->getIn() - js.getD());
        n.setType(doubl);
    }
    return n;
}
JSON_derulo JSON_derulo::operator/(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        if(js.getIn() == 0){
            cout<<"Division by zero"<<endl;
            return *this;
        }
        
       n.setD(this->getIn() / js.getIn());
       n.setType(doubl);
    }else if(this->getType() == doubl && js.getType() == doubl){
        if(js.getD() == 0){
            cout<<"Division by zero"<<endl;
            return *this;
        }
        n.setD(this->getD() / js.getD());
        n.setType(doubl);
    }else if(this->getType() == doubl && js.getType() == integer){
        if(js.getIn() == 0){
            cout<<"Division by zero"<<endl;
            return *this;
        }
        n.setD(this->getD() / js.getIn());
        n.setType(doubl);
    }else if(this->getType() == integer && js.getType() == doubl){
        if(js.getD() == 0){
            cout<<"Division by zero"<<endl;
            return *this;
        }
        n.setD(this->getIn() / js.getD());
        n.setType(doubl);
    }
    return n;
}
JSON_derulo JSON_derulo::operator*(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        n.setIn(this->getIn() * js.getIn());
        n.setType(integer);
    }else if(this->getType() == doubl && js.getType() == doubl){
        n.setD(this->getD() * js.getD());
        n.setType(doubl);
    }else if(this->getType() == doubl && js.getType() == integer){
        n.setD(this->getD() * js.getIn());
        n.setType(doubl);
    }else if(this->getType() == integer && js.getType() == doubl){
        n.setD(this->getIn() * js.getD());
        n.setType(doubl);
    }
    return *this;
}
JSON_derulo JSON_derulo::operator%(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        n.setIn(this->getIn() % js.getIn());
        n.setType(integer);
    }
    return n;
}
JSON_derulo JSON_derulo::operator>(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        if(this->getIn() > js.getIn()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == doubl){
        if(this->getD() > js.getD()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == integer){
        if(this->getD() > js.getIn()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }else if(this->getType() == integer && js.getType() == doubl){
        if(this->getIn() > js.getD()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }
    return n;
}
JSON_derulo JSON_derulo::operator>=(JSON_derulo js) {

    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        if(this->getIn() >= js.getIn()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == doubl){
        if(this->getD() >= js.getD()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == integer){
        if(this->getD() >= js.getIn()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }else if(this->getType() == integer && js.getType() == doubl){
        if(this->getIn() >= js.getD()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }
    return n;
}
JSON_derulo JSON_derulo::operator<(JSON_derulo js) {

    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        if(this->getIn() < js.getIn()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == doubl){
        if(this->getD() < js.getD()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == integer){
        if(this->getD() < js.getIn()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }else if(this->getType() == integer && js.getType() == doubl){
        if(this->getIn() < js.getD()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }
    return n;
}
JSON_derulo JSON_derulo::operator<=(JSON_derulo js) {

    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        if(this->getIn() <= js.getIn()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == doubl){
        if(this->getD() <= js.getD()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == integer){
        if(this->getD() <= js.getIn()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }else if(this->getType() == integer && js.getType() == doubl){
        if(this->getIn() <= js.getD()){
            n.setBool(true);
            n.setType(boolean);
        }else{
            n.setBool(false);
            n.setType(boolean);
        }
    }
    return n;
}
JSON_derulo JSON_derulo::operator&&(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == boolean && js.getType() == boolean){
       n.setBool(this->getBool() && js.getBool());
       n.setType(boolean);
    }
    return n;
}
JSON_derulo JSON_derulo::operator||(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == boolean && js.getType() == boolean){
        n.setBool(this->getBool() || js.getBool());
        n.setType(boolean);
    }
    
    return n;
}
JSON_derulo JSON_derulo::operator==(JSON_derulo js) {
    JSON_derulo n;
    n.setBool(areJSONEqual(*this,js));
    n.setType(boolean);
    return n;
}

JSON_derulo& JSON_derulo::operator[](int i) {
    return this->array.at(i);
}

JSON_derulo& JSON_derulo::operator[](std::string s) {
    try {
        for(auto& json : obj) {
            if(json.getKey() == s) {
                return json;
            }
        }
        throw s;
    } catch(...) {
        cout<<"Key "+s+" does not exist!"<<endl;
        exit(0);
        return *this;
    }
}
void erase_data(JSON_derulo right){
    if(right.getType() == strg) {
        right.setString(nullptr);
        right.setType(no_type);

    } else if(right.getType() == integer) {
        right.setIn(0);
        right.setType(no_type);

    } else if(right.getType() == doubl) {
        right.setD(0);
        right.setType(no_type);

    } else if(right.getType() == arr) {
        right.getArr().clear();
        right.setType(no_type);

    } else if(right.getType() == obj_) {
        right.getObj().clear();
        right.setType(no_type);
    }
}
void printJSON(JSON_derulo json, int indent) {
    
    std::string indentation(indent * 2, ' ');

    switch (json.getType()) {
        case no_type:
            std::cout << "null";
            break;

        case integer:
            std::cout << json.getIn();
            if(indent == 0)cout<<"\n";
            break;

        case strg:
            std::cout << '"' << json.getString() << '"';
            if(indent == 0)cout<<"\n";
            break;

        case doubl:
            std::cout << json.getD();
            if(indent == 0)cout<<"\n";
            break;

        case boolean:
            std::cout << (json.getBool() ? "true" : "false");
            if(indent == 0)cout<<"\n";
            break;

        case arr: {
            std::cout << "[\n";
            const auto& array = json.getArr();
            for (size_t i = 0; i < array.size(); ++i) {
                std::cout << indentation << "  ";
                printJSON(array[i], indent + 1);
                if (i < array.size() - 1) {
                    std::cout << ",";
                }
                std::cout << "\n";
            }
            std::cout << indentation << "]";
            break;
        }

        case obj_: {
            std::cout << "{\n";
            auto object = json.getObj();
            auto it = object.begin();
            while (it != object.end()) {
                std::cout << indentation << "  \"" << it->getKey() << "\": ";
                printJSON(*it, indent + 1);
                ++it;
                if (it != object.end()) {
                    std::cout << ",";
                }
                std::cout << "\n";
            }
            std::cout << indentation << "}";
            if(indent == 0)cout<<"\n";
            break;
        }
    }
}
bool areJSONEqual(JSON_derulo obj1,JSON_derulo obj2) {
    
    if (obj1.getType() != obj2.getType()) {
        return false;
    }

    
    switch (obj1.getType()) {
        case no_type:
            return true;
        
        case integer:
            return obj1.getIn() == obj2.getIn();
        
        case strg:
            return obj1.getString() == obj2.getString();
        
        case doubl:
            return obj1.getD() == obj2.getD();
        
        case boolean:
            return obj1.getBool() == obj2.getBool();
        
        case arr: {
            const auto& arr1 = obj1.getArr();
            const auto& arr2 = obj2.getArr();
            if (arr1.size() != arr2.size()) {
                return false;
            }
            for (size_t i = 0; i < arr1.size(); ++i) {
                if (!areJSONEqual(arr1[i], arr2[i])) {
                    return false; 
                }
            }
            return true; 
        }
        
        case obj_: {
            auto list1 = obj1.getObj();
            auto list2 = obj2.getObj();
            if (list1.size() != list2.size()) {
                return false;
            }
            auto it1 = list1.begin();
            auto it2 = list2.begin();
            while (it1 != list1.end() && it2 != list2.end()) {
                if (it1->getKey() != it2->getKey() || !areJSONEqual(*it1, *it2)) {
                    return false;
                }
                ++it1;
                ++it2;
            }
            return true; 
        }
    }

    return false; 
}


std::ostream& operator<<(std::ostream& os,const JSON_derulo& js) {
    printJSON(js, 0);
    return os;
}

