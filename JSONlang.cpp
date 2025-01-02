#include "JSONlang.h"
#include <iostream>


JSON_derulo *temp = NULL;
JSON_derulo *temp2 = NULL;
JSON_derulo *k = NULL;
std::string tmp_str = "";
int glob_index = -1;

bool toERASE = false;
bool probablyAppend = false;
// CONSTRUCTORS 
JSON_derulo::JSON_derulo(std::string s) {
    x = strg;
    this->strValue = s;
}
JSON_derulo::JSON_derulo(std::string s,int i) {
    this->key = s;
}

// Use auto for those (later).
JSON_derulo::JSON_derulo(int n) {
    integerValue = n;
    x = integer;
}
JSON_derulo::JSON_derulo(double n) {
    doubleValue = n;
    x = doubl;
}
JSON_derulo::JSON_derulo(bool b,std::string s){
    this->boolValue = b;
    x = boolean;
}
JSON_derulo::JSON_derulo() {
    x = arr;
}
JSON_derulo::JSON_derulo(std::initializer_list<JSON_derulo> list) : objectValue(list) {
    this->setType(obj_);
}
// SET / GET



void JSON_derulo::setIntegerValue(int num) {
    integerValue = num;
}


void JSON_derulo::setDoubleValue(double num) {
    doubleValue = num;
}

void JSON_derulo::setStringValue(std::string s) {
    this->strValue = s;
}



void JSON_derulo::setType(Type x) {
    this->x = x;
}

void JSON_derulo::setKey(std::string s) {
    this->key = s;
}

void JSON_derulo::setObjectValue(std::list<JSON_derulo> objectValue){
    this->objectValue = objectValue;
}

void JSON_derulo::setArrayValue(std::vector<JSON_derulo> arr){
    this->arrayValue = arr;
}
void JSON_derulo::setBoolValue(bool b){
    this->boolValue = b;
}

void JSON_derulo::clear_obj(std::string key,JSON_derulo js){
    auto it = objectValue.begin();
    while(it != objectValue.end()){
        if(it->getKey() == key){
            objectValue.erase(it);
            k = NULL;
            tmp_str="";
            break;
        }
        ++it;
    }
}

 void JSON_derulo::clear_obj() {
    auto it = objectValue.begin();
    while(it != objectValue.end()){
        objectValue.erase(it);
        ++it;
    }
 }



// Operator overloading used for Objects(Mainly).
JSON_derulo JSON_derulo::operator=(JSON_derulo right) {
    
    if(right.getType() == strg) {
        this->setStringValue(right.getStringValue());
        this->setType(right.getType());

    } else if(right.getType() == integer) {
        this->setIntegerValue(right.getIntegerValue());
        this->setType(right.getType());

    } else if(right.getType() == doubl) {
        this->setDoubleValue(right.getDoubleValue());
        this->setType(right.getType());

    } else if(right.getType() == obj_) {
        this->setObjectValue(right.getObjectValue());
        this->setType(right.getType());

    } else if(right.getType() == arr) {
        this->setArrayValue(right.getArrayValue());
        this->setType(right.getType());
    }


    return *this;
}


JSON_derulo& JSON_derulo::operator[](JSON_derulo js) {
    if(temp != NULL) {
        this->setArrayValue(temp->getArrayValue());
    }
    this->arrayValue.emplace(this->arrayValue.begin(),js);
    if(temp != NULL) {
        temp = NULL;
    }
    return *this;
}

JSON_derulo& JSON_derulo::operator,(JSON_derulo js) {
    if(probablyAppend) {
        if(temp2==NULL) {
            temp2 = &js;
        }
    } else {
        temp2 = NULL;
    }
    if(temp == NULL) {
        temp = &js;
    }
    temp->arrayValue.push_back(js);
    return *this;
}        
JSON_derulo JSON_derulo::operator+(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        n.setIntegerValue(this->getIntegerValue() + js.getIntegerValue());
        n.setType(integer);
    }else if(this->getType() == doubl && js.getType() == doubl){
        n.setDoubleValue(this->getDoubleValue() + js.getDoubleValue());
        n.setType(doubl);
    }else if(this->getType() == doubl && js.getType() == integer){
        n.setDoubleValue(this->getDoubleValue() + js.getIntegerValue());
        n.setType(doubl);
    }else if(this->getType() == integer && js.getType() == doubl){
        n.setDoubleValue(this->getIntegerValue() + js.getDoubleValue());
        n.setType(doubl);
    }
    else if(this->getType() == strg && js.getType() == strg){
        n.setStringValue(this->getStringValue() + js.getStringValue());
        n.setType(strg);
    }else if(this->getType() == arr && js.getType() == arr){
    
        std::vector<JSON_derulo> tmp;
        tmp = this->arrayValue;
        for (JSON_derulo value : js.getArrayValue()) {
            tmp.push_back(value);
        }
        n.setType(arr);
        n.setArrayValue(tmp);
    }else if(this->getType() == obj_ && js.getType() == obj_){//case for duplicate keys
        std::list<JSON_derulo> tmp;
        tmp = this->getObjectValue();
        for (JSON_derulo value : js.getObjectValue()) {
            if(findDuplicates(*this,value.getKey())) {
                tmp.push_back(value);
            }
        }
        n.setType(obj_);
        n.setObjectValue(tmp);
    } else {        // APPEND
        if(this->getType() == arr) { 
            
            cout<<"operator+"<<endl;
            if(temp2 != NULL) {
                cout<<"HEYY"<<endl;
            }
            if(temp2 != NULL) {
                temp2 = NULL;
            }
            
           cout<<"UHH"<<endl;
        }
    }
    return n;
}
JSON_derulo JSON_derulo::operator-(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        n.setIntegerValue(this->getIntegerValue() - js.getIntegerValue());
        n.setType(integer);
    }else if(this->getType() == doubl && js.getType() == doubl){
        n.setDoubleValue(this->getDoubleValue() - js.getDoubleValue());
        n.setType(doubl);
    }else if(this->getType() == doubl && js.getType() == integer){
        n.setDoubleValue(this->getDoubleValue() - js.getIntegerValue());
        n.setType(doubl);
    }else if(this->getType() == integer && js.getType() == doubl){
        n.setDoubleValue(this->getIntegerValue() - js.getDoubleValue());
        n.setType(doubl);
    }
    return n;
}
JSON_derulo JSON_derulo::operator/(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        if(js.getIntegerValue() == 0){
            cout<<"Division by zero"<<endl;
            return *this;
        }
        
       n.setDoubleValue(this->getIntegerValue() / js.getIntegerValue());
       n.setType(doubl);
    }else if(this->getType() == doubl && js.getType() == doubl){
        if(js.getDoubleValue() == 0){
            cout<<"Division by zero"<<endl;
            return *this;
        }
        n.setDoubleValue(this->getDoubleValue() / js.getDoubleValue());
        n.setType(doubl);
    }else if(this->getType() == doubl && js.getType() == integer){
        if(js.getIntegerValue() == 0){
            cout<<"Division by zero"<<endl;
            return *this;
        }
        n.setDoubleValue(this->getDoubleValue() / js.getIntegerValue());
        n.setType(doubl);
    }else if(this->getType() == integer && js.getType() == doubl){
        if(js.getDoubleValue() == 0){
            cout<<"Division by zero"<<endl;
            return *this;
        }
        n.setDoubleValue(this->getIntegerValue() / js.getDoubleValue());
        n.setType(doubl);
    }
    return n;
}
JSON_derulo JSON_derulo::operator*(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        n.setIntegerValue(this->getIntegerValue() * js.getIntegerValue());
        n.setType(integer);
    }else if(this->getType() == doubl && js.getType() == doubl){
        n.setDoubleValue(this->getDoubleValue() * js.getDoubleValue());
        n.setType(doubl);
    }else if(this->getType() == doubl && js.getType() == integer){
        n.setDoubleValue(this->getDoubleValue() * js.getIntegerValue());
        n.setType(doubl);
    }else if(this->getType() == integer && js.getType() == doubl){
        n.setDoubleValue(this->getIntegerValue() * js.getDoubleValue());
        n.setType(doubl);
    }
    return *this;
}
JSON_derulo JSON_derulo::operator%(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        n.setIntegerValue(this->getIntegerValue() % js.getIntegerValue());
        n.setType(integer);
    }
    return n;
}
JSON_derulo JSON_derulo::operator>(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        if(this->getIntegerValue() > js.getIntegerValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == doubl){
        if(this->getDoubleValue() > js.getDoubleValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == integer){
        if(this->getDoubleValue() > js.getIntegerValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }else if(this->getType() == integer && js.getType() == doubl){
        if(this->getIntegerValue() > js.getDoubleValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }
    return n;
}
JSON_derulo JSON_derulo::operator>=(JSON_derulo js) {

    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        if(this->getIntegerValue() >= js.getIntegerValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == doubl){
        if(this->getDoubleValue() >= js.getDoubleValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == integer){
        if(this->getDoubleValue() >= js.getIntegerValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }else if(this->getType() == integer && js.getType() == doubl){
        if(this->getIntegerValue() >= js.getDoubleValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }
    return n;
}
JSON_derulo JSON_derulo::operator<(JSON_derulo js) {

    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        if(this->getIntegerValue() < js.getIntegerValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == doubl){
        if(this->getDoubleValue() < js.getDoubleValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == integer){
        if(this->getDoubleValue() < js.getIntegerValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }else if(this->getType() == integer && js.getType() == doubl){
        if(this->getIntegerValue() < js.getDoubleValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }
    return n;
}
JSON_derulo JSON_derulo::operator<=(JSON_derulo js) {

    JSON_derulo n;
    if(this->getType() == integer && js.getType() == integer){
        if(this->getIntegerValue() <= js.getIntegerValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == doubl){
        if(this->getDoubleValue() <= js.getDoubleValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }else if(this->getType() == doubl && js.getType() == integer){
        if(this->getDoubleValue() <= js.getIntegerValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }else if(this->getType() == integer && js.getType() == doubl){
        if(this->getIntegerValue() <= js.getDoubleValue()){
            n.setBoolValue(true);
            n.setType(boolean);
        }else{
            n.setBoolValue(false);
            n.setType(boolean);
        }
    }
    return n;
}
JSON_derulo JSON_derulo::operator&&(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == boolean && js.getType() == boolean){
       n.setBoolValue(this->getBoolValue() && js.getBoolValue());
       n.setType(boolean);
    }
    return n;
}
JSON_derulo JSON_derulo::operator||(JSON_derulo js) {
    JSON_derulo n;
    if(this->getType() == boolean && js.getType() == boolean){
        n.setBoolValue(this->getBoolValue() || js.getBoolValue());
        n.setType(boolean);
    }
    
    return n;
}
JSON_derulo JSON_derulo::operator==(JSON_derulo js) {
    JSON_derulo n;
    n.setBoolValue(areJSONEqual(*this,js));
    n.setType(boolean);
    return n;
}

JSON_derulo& JSON_derulo::operator[](int i) {
    if(toERASE == true) {
        k = this;
        glob_index = i;
        tmp_str = "";
    } 
    return this->arrayValue.at(i);
}
// CHANGE
JSON_derulo& JSON_derulo::operator[](std::string s) {
    if(toERASE == true) {
        k = this;
        tmp_str = s;
        glob_index = -1;
    }
    try {
        for(auto& json : objectValue) {
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

JSON_derulo& JSON_derulo::operator()(JSON_derulo js) {
    cout<<"heyy queen pls";
    if(temp2 != NULL) {
        this->setArrayValue(temp2->getArrayValue());
    }
    this->arrayValue.emplace(this->arrayValue.begin(),js);
    if(temp2 != NULL) {
        temp2 = NULL;
    }
    return *this;
}

JSON_derulo JSON_derulo::operator+=(JSON_derulo js) {
        
        std::vector<JSON_derulo> tmp;
        tmp = this->arrayValue;
        if(temp2 != NULL) {
            this->setArrayValue(temp2->getArrayValue());
        }
        for (JSON_derulo value : tmp) {
            this->arrayValue.push_back(value);
        }
        this->arrayValue.emplace(this->arrayValue.begin(),js);
        if(temp2 != NULL) {
            temp2 = NULL;
        }
        return *this;
}

void erase_data(JSON_derulo& right){
    if(right.getType() == strg) {
        right.setStringValue(nullptr);
        right.setType(no_type);

    } else if(right.getType() == integer) {
        right.setIntegerValue(0);
        right.setType(no_type);

    } else if(right.getType() == doubl) {
        right.setDoubleValue(0);
        right.setType(no_type);

    } else if(right.getType() == arr) {

    } 
}
void printJSON(JSON_derulo json, int indent) {
    
    std::string indentation(indent * 2, ' ');

    switch (json.getType()) {
        case no_type:
            std::cout << "null";
            break;

        case integer:
            std::cout << json.getIntegerValue();
            if(indent == 0)cout<<endl;
            break;

        case strg:
            std::cout<<"\""<< json.getStringValue()<<"\"";
            if(indent == 0)cout<<endl;
            break;

        case doubl:
            std::cout << json.getDoubleValue();
            if(indent == 0)cout<<endl;
            break;

        case boolean:
            std::cout << (json.getBoolValue() ? "true" : "false");
            if(indent == 0)cout<<endl;
            break;

        case arr: {
            std::cout << "[\n";
            const auto& array = json.getArrayValue();
            for (size_t i = 0; i < array.size(); ++i) {
                std::cout << indentation << "  ";
                printJSON(array[i], indent + 1);
                if (i < array.size() - 1) {
                    std::cout << ",";
                }
                std::cout << "\n";
            }
            std::cout << indentation << "]";
            if(indent == 0)cout<<endl;
            break;
        }

        case obj_: {
            std::cout << "{\n";
            auto object = json.getObjectValue();
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
            if(indent == 0)cout<<endl;
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
            return obj1.getIntegerValue() == obj2.getIntegerValue();
        
        case strg:
            return obj1.getStringValue() == obj2.getStringValue();
        
        case doubl:
            return obj1.getDoubleValue() == obj2.getDoubleValue();
        
        case boolean:
            return obj1.getBoolValue() == obj2.getBoolValue();
        
        case arr: {
            const auto& arr1 = obj1.getArrayValue();
            const auto& arr2 = obj2.getArrayValue();
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
            auto list1 = obj1.getObjectValue();
            auto list2 = obj2.getObjectValue();
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

JSON_derulo hasKey(JSON_derulo js, std::string key){
    JSON_derulo ret_value;
    ret_value.setType(boolean);
    ret_value.setBoolValue(false);
    if(js.getType() == obj_){
        auto list = js.getObjectValue();
        auto it = list.begin();
        while(it != list.end()){
            if(it->getKey() == key){
                ret_value.setBoolValue(true);
                break;
            }
            ++it;
        }
    }
    return ret_value;
}

std::ostream& operator<<(std::ostream& os,const JSON_derulo& js) {
    printJSON(js, 0);
    return os;
}

JSON_derulo size_of(JSON_derulo rulo){
    JSON_derulo ret_value;
    ret_value.setType(integer);
    if(rulo.getType() == arr){
        ret_value.setIntegerValue(rulo.getArrayValue().size());
    }else if(rulo.getType() == obj_){
        ret_value.setIntegerValue(rulo.getObjectValue().size());
    }else{
        ret_value.setIntegerValue(1);
    }
    return ret_value;
}

void JSON_derulo::operator>>(JSON_derulo& js) {
    if(toERASE==true) {
        if(tmp_str != "") {
            k->clear_obj(tmp_str,js);
            tmp_str = "";
        } else if(glob_index != -1){
            k->clear_arr(glob_index);
            glob_index = -1;
        } else {
            js.clear_obj();
        }
    } else {
        cout<<"Not erasing!"<<endl;
    }
}

JSON_derulo is_empty_json(JSON_derulo rulo){
    JSON_derulo ret_value;
    ret_value.setType(boolean);
    ret_value.setBoolValue(false);
    if(rulo.getType() == arr){
        if(rulo.getArrayValue().size() == 0){ret_value.setBoolValue(true);}
    }else if(rulo.getType() == obj_){
        if(rulo.getObjectValue().size() == 0){ret_value.setBoolValue(true);}
    }
    return ret_value;
}

bool findDuplicates(JSON_derulo js,std::string key) {
    for(JSON_derulo j : js.getObjectValue()) {
        if(j.getKey() == key) {
            return false;
        }
    }
    return true;
}
void foo() {
    return;
}
