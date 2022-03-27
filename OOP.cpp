#include <bits/stdc++.h>
using std::string;

class Employee {
private:
    string Company;
    int Age;
protected:
    string Name;
    
public:
    void Intro(){
        std::cout<<"Name - "<<Name<<std::endl;
        std::cout<<"Age - "<<Age<<std::endl;
        std::cout<<"Company - "<<Company<<std::endl;
    }
    // public Constructor! which will be called allways when a new variable of this datatype is declared!
    Employee(string name,string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }
    // you can have one or multiple constructors!
//ex:
    Employee(){
        Name = "Employee";
        Company = "Company";
        Age = 0;
    }


    //getters & setters!
// ENCAPSULATION!!!
    void setName(string name){
        Name = name;
    }
    void setCompany(string company){
        Company = company;
    }
    void setAge(int age){
        if(age >= 18&&age<=100) Age = age; //use of setter here! you can't use invalid age! or there is a restriction on setting / updating you age! which reduces the errors in the code!
    }
    string getName(){
        return Name;
    }
    string getCompany(){
        return Company;
    }
    int getAge(){
        return Age;
    }
    /*void Work(){ //same work() function but different uses! here!!
        std::cout<<Name<<" is Coding!!" << std::endl;
    }*/ // while using Employee pointers then always this work() will be executed! even if there are respective work() functions!!

    virtual void Work(){
        std::cout<<Name<<" is Coding!!" << std::endl;
    }
};
// Child class: Developer! of Parent: Employee!
class Developer:public Employee{// this child class is 'private' by default! i.e., cant use all variables and functions of 'Employee' publically! i.e., with the dev DataType/ variable declared!
    string FavLang;
// you can use all the functions which are private and public in the class Employee NOW!
public:
//if Employee has a user defined constructor! you have to use it here! using a colon (:)!! and initialize the rest 
//      Developer's variables! here FavLang!
    Developer(string name, string company, int age, string favLang):Employee(name, company, age){
        FavLang = favLang;
    }
    // if you wanna use the parentClasse's variables! use the setters and getters directly!
    //ex.
    void wow(){
        std::cout<<"Hello, "<<getName()<<" I suppose your favuorite Coding Language is "<<FavLang<<std::endl;
    }
    // since 'Name' is in protected! now you can use that here directly!
    void wow2(){
        std::cout<<"Hello, "<<Name<<" WOW 2 WOW "<<getCompany()<<std::endl;
    }
};
// this child class's variable can use all the (public) parent fucntions and variables "PUBLICALLY" now! and (protected ones) in the class! as it is! like in the previous example!
class Teacher: public Employee{
public:
    int XP;
    Teacher(string name,string company,int age,int xp):Employee(name, company, age){
        XP = xp;
    }
    void Work(){
        std::cout<<Name<<" is having "<< XP << std::endl;
    }
};

int main(){

    //Employee First; !!defining using default constructor
    /*First.Name = "pam";
    First.Company = "Tom";
    First.Age = 34;
    std::cout<<First.Name<<std::endl;
    std::cout<<First.Company<<std::endl;
    std::cout<<First.Age<<std::endl;*/
    Employee First ("pam","tom",35); //one way to use user defined constructor
    First.Intro();

    Employee Second = Employee("nona","Bul",25); //second way to use user defined constructor!
    /*Second.Name = "";
    Second.Company = "Bul";
    Second.Age = 25;*/
    Second.Intro();
    //Second.Name(); can't use this Publically! even if it is protected or private!!

                                      //encapsulation!
Second.setAge(15);
Second.setAge(209);
std::cout<<Second.getName()<<" is "<<Second.getAge()<<" years old!\n";// if the functions are protected! 
                                                                     // you cant use them pubically like this!

//using the second constructor!
Employee third;
third.Intro(); // hahahahaha! it works! you cna have multiple constructors!!!

//                                // LEARN ABSTRACTION!! virtual functions! etc.
// You only know a vague answer of that!


                                // Inheritence!!
// parent class: Employee! & child class: Developer!

    Developer dev("hord","uni", 90, "'R'");
dev.wow();
// you can only use those parent functions and variables in your CLASS! not here!
// dev.getName(); //doesnt work!

// using protected functions and variables in the class!
dev.wow2();

// if you want all the functions and variables of the parent function to use here! with the child DataType here 'dev2' you have to use a keyword above while creating the class!
    Teacher dev2("owo","T_T", 20, 5);
dev2.Intro();// this is public function! of parent Employee!
//std::cout<<dev2.Name;// you still cant use parent function's (private) and (protected) publically here!

                                        //polymorphism

Developer a("poly","morph",69,"Cpp");
Teacher b("morph", "poly", 45, 7);

Employee* e1 = &a;
Employee* e2 = &b;

a.Work(); //different works!
b.Work(); // defined individually!

//without Virtual function of Work()!  line 56!
e1->Work();//the parent function! will execute it's function!
e2->Work();

//change the virtual and try! NOW!! line 56!
e1->Work(); //this will first check if individual / child class is having different Work()! if there is it will execute that! else it will execute this!
e2->Work();

//thats all! in polymorphism!

    return 0;
}