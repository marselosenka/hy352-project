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
    if(this->getType() == integer && js.getType() == integer){
        this->setIn(this->getIn() + js.getIn());
    }else if(this->getType() == doubl && js.getType() == doubl){
        this->setD(this->getD() + js.getD());
    }else if(this->getType() == doubl && js.getType() == integer){
        this->setD(this->getD() + js.getIn());
    }else if(this->getType() == integer && js.getType() == doubl){
        this->setD(this->getIn() + js.getD());
        this->setType(doubl);
    }
    else if(this->getType() == strg && js.getType() == strg){
        this->setString(this->getString() + js.getString());
    }else if(this->getType() == arr && js.getType() == arr){
        std::vector<JSON_derulo> tmp;
        for (JSON_derulo value : this->getArr()) {
            tmp.push_back(value);
        }
        for (JSON_derulo value : js.getArr()) {
            tmp.push_back(value);
        }
        this->setArr(tmp);
    }else if(this->getType() == obj_ && js.getType() == obj_){
        std::list<JSON_derulo> tmp;
        for (JSON_derulo value : this->getObj()) {
            tmp.push_back(value);
        }
        for (JSON_derulo value : js.getObj()) {
            tmp.push_back(value);
        }
        this->setObj(tmp);
    }
    return *this;
}
JSON_derulo JSON_derulo::operator-(JSON_derulo js) {

    if(this->getType() == integer && js.getType() == integer){
        this->setIn(this->getIn() - js.getIn());
    }else if(this->getType() == doubl && js.getType() == doubl){
        this->setD(this->getD() - js.getD());
    }else if(this->getType() == doubl && js.getType() == integer){
        this->setD(this->getD() - js.getIn());
    }else if(this->getType() == integer && js.getType() == doubl){
        this->setD(this->getIn() - js.getD());
        this->setType(doubl);
    }
    return *this;
}
JSON_derulo JSON_derulo::operator/(JSON_derulo js) {
    if(this->getType() == integer && js.getType() == integer){
        if(js.getIn() == 0){
            cout<<"Division by zero"<<endl;
            return *this;
        }
        cout<<this->getIn() << js.getIn()<< endl;
        this->setIn(this->getIn() / js.getIn());
    }else if(this->getType() == doubl && js.getType() == doubl){
        if(js.getD() == 0){
            cout<<"Division by zero"<<endl;
            return *this;
        }
        this->setD(this->getD() / js.getD());
    }else if(this->getType() == doubl && js.getType() == integer){
        if(js.getIn() == 0){
            cout<<"Division by zero"<<endl;
            return *this;
        }
        this->setD(this->getD() + js.getIn());
    }else if(this->getType() == integer && js.getType() == doubl){
        if(js.getD() == 0){
            cout<<"Division by zero"<<endl;
            return *this;
        }
        this->setD(this->getIn() + js.getD());
        this->setType(doubl);
    }
    return *this;
}
JSON_derulo JSON_derulo::operator*(JSON_derulo js) {

    if(this->getType() == integer && js.getType() == integer){
        this->setIn(this->getIn() * js.getIn());
    }else if(this->getType() == doubl && js.getType() == doubl){
        this->setD(this->getD() * js.getD());
    }else if(this->getType() == doubl && js.getType() == integer){
        this->setD(this->getD() * js.getIn());
    }else if(this->getType() == integer && js.getType() == doubl){
        this->setD(this->getIn() * js.getD());
        this->setType(doubl);
    }
    return *this;
}
JSON_derulo JSON_derulo::operator%(JSON_derulo js) {

    if(this->getType() == integer && js.getType() == integer){
        this->setIn(this->getIn() % js.getIn());
    }
    return *this;
}
JSON_derulo JSON_derulo::operator>(JSON_derulo js) {

    if(this->getType() == integer && js.getType() == integer){
        this->setIn(this->getIn() > js.getIn());
    }else if(this->getType() == doubl && js.getType() == doubl){
        this->setD(this->getD() > js.getD());
    }else if(this->getType() == doubl && js.getType() == integer){
        this->setD(this->getD() > js.getIn());
    }else if(this->getType() == integer && js.getType() == doubl){
        this->setD(this->getIn() > js.getD());
        this->setType(doubl);
    }
    return *this;
}
JSON_derulo JSON_derulo::operator>=(JSON_derulo js) {

    if(this->getType() == integer && js.getType() == integer){
        this->setIn(this->getIn() >= js.getIn());
    }else if(this->getType() == doubl && js.getType() == doubl){
        this->setD(this->getD() >= js.getD());
    }else if(this->getType() == doubl && js.getType() == integer){
        this->setD(this->getD() >= js.getIn());
    }else if(this->getType() == integer && js.getType() == doubl){
        this->setD(this->getIn() >= js.getD());
        this->setType(doubl);
    }
    return *this;
}
JSON_derulo JSON_derulo::operator<(JSON_derulo js) {

    if(this->getType() == integer && js.getType() == integer){
        this->setIn(this->getIn() < js.getIn());
    }else if(this->getType() == doubl && js.getType() == doubl){
        this->setD(this->getD() < js.getD());
    }else if(this->getType() == doubl && js.getType() == integer){
        this->setD(this->getD() < js.getIn());
    }else if(this->getType() == integer && js.getType() == doubl){
        this->setD(this->getIn() < js.getD());
        this->setType(doubl);
    }
    return *this;
}
JSON_derulo JSON_derulo::operator<=(JSON_derulo js) {

    if(this->getType() == integer && js.getType() == integer){
        this->setIn(this->getIn() <= js.getIn());
    }else if(this->getType() == doubl && js.getType() == doubl){
        this->setD(this->getD() <= js.getD());
    }else if(this->getType() == doubl && js.getType() == integer){
        this->setD(this->getD() <= js.getIn());
    }else if(this->getType() == integer && js.getType() == doubl){
        this->setD(this->getIn() <= js.getD());
        this->setType(doubl);
    }
    return *this;
}
JSON_derulo JSON_derulo::operator&&(JSON_derulo js) {

    if(this->getType() == boolean && js.getType() == boolean){
       this->setBool(this->getBool() && js.getBool());
    }
    return *this;
}
JSON_derulo JSON_derulo::operator||(JSON_derulo js) {

    if(this->getType() == boolean && js.getType() == boolean){
        this->setBool(this->getBool() || js.getBool());
    }
    
    return *this;
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