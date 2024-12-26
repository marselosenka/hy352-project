#include "JSONlang.h"



std::vector<JSON_derulo> array_temp;



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
        // JSON_derulo(bool b,int x){
        //     cout<<"bitch u here?"<<endl;
        //     this->bool_ = b;
        //     x = boolean;
        // }
        JSON_derulo::JSON_derulo() {
            Name = "default-array";
            x = arr;
        }
        JSON_derulo::JSON_derulo(std::initializer_list<JSON_derulo> list) {
            for (const auto& elem : list) {
                obj.push_back(elem);
            }
        }
        // SET / GET

        std::string JSON_derulo::getName() {
            return this->Name;
        }

        void JSON_derulo::setName(std::string s) {
            this->Name = s;
        }

        int JSON_derulo::getIn() {
            return this->in;
        }

        void JSON_derulo::setIn(int num) {
            in = num;
        }

        double JSON_derulo::getD() {
            return this->d;
        }

        void JSON_derulo::setD(double num) {
            d = num;
        }

        std::string JSON_derulo::getString() {
            return this->str;
        }
        
        void JSON_derulo::setString(std::string s) {
            this->str = s;
        }

        Type JSON_derulo::getType() {
            return this->x;
        }

        void JSON_derulo::setType(Type x) {
            this->x = x;
        }

        std::string JSON_derulo::getKey() {
            return this->key;
        }

        void JSON_derulo::setKey(std::string s) {
            this->key = s;
        }

        std::list<JSON_derulo> JSON_derulo::getObj(){
            return this->obj;
        }

        void JSON_derulo::setObj(std::list<JSON_derulo> obj){
            this->obj = obj;
        }
        
        std::vector<JSON_derulo> JSON_derulo::getArr(){
            return this->array;
        }

        void JSON_derulo::setArr(std::vector<JSON_derulo> arr){
            this->array = arr;
        }

        // Operator overloading used for Objects(Mainly).
        JSON_derulo JSON_derulo::operator=(JSON_derulo right) {
            cout<<"Operator overloading!"<<endl;
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
            cout << "slay" << endl;
            this->array.push_back(js);
            if(!array_temp.empty()) {
                this->setArr(array_temp);
                this->getArr().push_back(js);
            }
            cout << (void*) this << '\n';
            return *this;
        }

        JSON_derulo& JSON_derulo::operator,(JSON_derulo js) {
            cout << "slay?" << endl;
            array_temp.push_back(js);
            return *this;
        }        

