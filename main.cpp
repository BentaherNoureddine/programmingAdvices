#include "dataStructure/clsMyString.h"


int main()

{


    clsMyString s1;


    std::cout<<"\n s1 = "<<s1.getValue()<<"\n";

    s1.setValue("mohamed");
    std::cout<<"\n s1 = "<<s1.getValue()<<"\n";



    s1.setValue("mohamed2");
    std::cout<<"\n s1 = "<<s1.getValue()<<"\n";

    s1.setValue("mohamed3");
    std::cout<<"\n s1 = "<<s1.getValue()<<"\n";

    std::cout<<"\n UNDO ";
    s1.undo();
    std::cout<<"\n s1 = "<<s1.getValue()<<"\n";
    s1.undo();
    std::cout<<"\n s1 = "<<s1.getValue()<<"\n";
    s1.undo();
    std::cout<<"\n s1 = "<<s1.getValue()<<"\n";


    std::cout<<"\n REDO ";
    s1.redo();
    std::cout<<"\n s1 = "<<s1.getValue()<<"\n";
    s1.redo();
    std::cout<<"\n s1 = "<<s1.getValue()<<"\n";
    s1.redo();
    std::cout<<"\n s1 = "<<s1.getValue()<<"\n";



    return 0;
}
