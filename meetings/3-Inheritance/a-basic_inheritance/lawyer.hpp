#ifndef LAWYER_CLASS
#define LAWYER_CLASS

class Lawyer{
public:
    Lawyer(string name = "", int age = 0, string firm = "", int n_cases = 0) : _name(name), _age(age),
    _firm(firm), _n_cases(n_cases){
	
	 cout << "(Lawyer class) Created a lawyer with name: " << name << ". ";
	 cout << "This lawyer is " << age << " years old" << endl;
	 cout << "(Lawyer class) He works at " << firm;
         cout << " and his/her record shows " << n_cases << " number of cases." << endl;
    }
	
    ~Lawyer(){
         cout << endl;
	 cout << "(Lawyer class) Removed lawyer " << _name << ". " << endl;
     }
     
     void has_birthday(){
	    _age++;
	    cout << "(Lawyer class) Happy birthday " << _name << "!! " << endl;
	}
     
     void introduce_yourself(){
	
	   cout << "(Lawyer class) My name is " << _name << ". ";
	   cout << "I am " << _age << " years old and I will not defend Donald Trump from his impeachment." << endl;
     }
     
private:
    string _firm;
    int _n_cases;
    int _age;
    string _name;

}; 

#endif