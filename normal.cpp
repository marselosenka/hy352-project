#include "JSONlang.h"

int main(void) { 
    
    JSON_derulo js;

    JSON_derulo name = JSON_derulo("hello");    // HAS ONLY VALUE
    cout<<"Hello";
    JSON_derulo oop = JSON_derulo { 
         JSON_derulo("Onoma1",1) = false ? JSON_derulo("false") : JSON_derulo("Manolis"),
         JSON_derulo("Onoma2",1) = false ? JSON_derulo("false") : JSON_derulo("Giannis"),
         JSON_derulo("Onoma3",1) = false ? JSON_derulo("false") : JSON_derulo("Aleksis"),
         JSON_derulo("Onoma4",1) = false ? JSON_derulo("false") : JSON_derulo("YO")
    };

    for (auto& element : oop.getObj()) {
        std::cout<< element.getKey()<<" "<< element.getString() << std::endl;
    }





    JSON_derulo firstarray = JSON_derulo{};
    JSON_derulo secondarray = JSON_derulo{}[JSON_derulo("\"Kalispera\""),JSON_derulo("\"KALH\"")];
    cout << (void*) &secondarray << '\n';
    cout<<secondarray.getArr()[0].getString()<<endl;
    cout<<secondarray.getArr()[1].getString()<<endl;
}