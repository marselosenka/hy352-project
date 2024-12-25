#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

#define PROGRAM_BEGIN       int main(void) { JSON_derulo js
#define PROGRAM_END         ;cout<<name.getName()<<endl;}


#define JSON(name)          ;JSON_derulo name
#define STRING(str)         JSON_derulo(#str)          

#define NUMBER(number)      JSON_derulo(number)

#define ARRAY   

#define OBJECT              JSON_derulo
#define KEY(str)            setName(#str)          

#define TRUE
#define FALSE

enum Type{
    no_type=0,
    integer=1,
    strg=2,
    doubl=3,
    obj=4
};


class JSON_derulo {
    private:
        std::string Name;
        std::string str;
        std::string key;
        int in;
        double d;
        std::vector<JSON_derulo> array;
        std::unordered_map<std::string,JSON_derulo> obj;
        enum Type x;
    public:


        // CONSTRUCTORS 
        JSON_derulo(const string& s) {
            x = strg;
            this->str = s;
        }
        // JSON_derulo() {
        //     x = no_type;
        // }
        JSON_derulo(int n) {
            in = n;
            x = integer;
        }
        JSON_derulo(double n) {
            d = n;
            x = doubl;
        }
        JSON_derulo() {
            Name = "default";
            x = no_type;
        }
        // SET / GET



        std::string getName() {
            return this->Name;
        }
        void setName(const string& s) {
            this->Name = s;
        }
        int getIn() {
            return this->in;
        }
        void setIn(int num) {
            in = num;
        }
        double getD() {
            return this->d;
        }
        void setD(double num) {
            d = num;
        }
        std::string getString() {
            return this->str;
        }
        void setString(const string& s) {
            this->str = s;
        }
        Type getType() {
            return this->x;
        }
        void setType(Type x) {
            this->x = x;
        }
        
};
