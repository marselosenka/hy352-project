#include "JSONlang.h"

int main(void) { 
    
    JSON_derulo js;

    JSON_derulo name = JSON_derulo("hello");    // HAS ONLY VALUE
    cout<<"Hello";
    JSON_derulo oop = JSON_derulo { 
         JSON_derulo("Onoma1",1) = false ? JSON_derulo("false") : JSON_derulo("Manolis"),
         JSON_derulo("Onoma2",1) = false ? JSON_derulo("false") : JSON_derulo("Giannis"),
         JSON_derulo("Onoma3",1) = false ? JSON_derulo("false") : JSON_derulo("Aleksis"),
         JSON_derulo("Onoma4",1) = false ? JSON_derulo("false") : JSON_derulo("Makis")
    };
    JSON_derulo oop2 = JSON_derulo { 
         JSON_derulo("Onoma5",1) = false ? JSON_derulo("false") : JSON_derulo("Manolis2"),
         JSON_derulo("Onoma6",1) = false ? JSON_derulo("false") : JSON_derulo("Giannis2"),
         JSON_derulo("Onoma7",1) = false ? JSON_derulo("false") : JSON_derulo("Aleksis2"),
         JSON_derulo("Onoma8",1) = false ? JSON_derulo("false") : JSON_derulo("Makis2")
    };
    JSON_derulo oop3 = oop + oop2;
    for (auto& element : oop3.getObj()) {
        std::cout<< element.getKey()<<" "<< element.getString() << std::endl;
    }

    // JSON_derulo help = JSON_derulo(false,"false") && JSON_derulo(false,"true");
    // cout<<help.getType()<<endl<<help.getBool()<<endl;
    JSON_derulo hihi = JSON_derulo(2.5) - JSON_derulo(2);
    cout<<hihi.getD()<<endl;
    JSON_derulo firstarray = JSON_derulo{}[JSON_derulo("\"Kalispera\""),JSON_derulo("\"KALH\""),JSON_derulo("\"Kalimera\""),JSON_derulo("\"Gamw\"")];
    JSON_derulo secondarray = JSON_derulo{}[JSON_derulo("\"2\""),JSON_derulo("\"3\""),JSON_derulo("\"4\""),JSON_derulo("\"5\"")];
    //cout << (void*) &secondarray << '\n';
    // cout<<secondarray.getArr()[0].getString()<<endl;
    // cout<<secondarray.getArr()[1].getString()<<endl;
    // cout<<secondarray.getArr()[2].getString()<<endl;
    // cout<<secondarray.getArr()[3].getString()<<endl;

    // JSON_derulo rulo = firstarray+secondarray;
    // //cout<<rulo.getString()<<endl;
    // cout<<rulo.getArr()[0].getString()<<endl;
    // cout<<rulo.getArr()[1].getString()<<endl;
    // cout<<rulo.getArr()[2].getString()<<endl;
    // cout<<rulo.getArr()[3].getString()<<endl;
    // cout<<rulo.getArr()[4].getString()<<endl; 
    // cout<<rulo.getArr()[5].getString()<<endl;
    // cout<<rulo.getArr()[6].getString()<<endl;
    // cout<<rulo.getArr()[7].getString()<<endl;
}