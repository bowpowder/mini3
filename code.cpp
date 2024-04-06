#include <iostream>
#include<string>
namespace bp
{
    template<typename T>
    class Array
    {
    private:
        T* heap_alocated_array;
        int size;
        int max_size;
    public:
        Array(int _size):heap_alocated_array(new T[_size]),size(0),max_size(_size)
        {

        }
       

        void push(T value)
        {
            if (max_size<=size)
            {
                //resize
                T* temp=new T[max_size*2];
                max_size*=2;
                for (int i = 0; i < size; i++)
                {
                    temp[i]=heap_alocated_array[i];
                }
                delete heap_alocated_array[];
                heap_alocated_array=temp;                
            }            
            heap_alocated_array[size]=value;
            size++;                       
        }
        T* get_array()
        {
            return heap_alocated_array;
        }
        int get_size()
        {
            return size;
        }
        T& operator [](int i)
        {
        return heap_alocated_array[i];
        }        
        ~Array()
        {
            delete heap_alocated_array[];
        }
    };
   
}
class person
{
public:
    std::string user_name;
    std::string pass_word;
public:
    person(std::string _user_name,std::string _pass_word) :user_name(_user_name),pass_word(_pass_word)
    {

    }
    ~person()
    {

    }
};
bp::Array<person>* teachers=nullptr;
bp::Array<person>* students=nullptr;
int teachers_size=-1;
int students_size=-1;

void login_system();
int main()
{
    //teachers
    int _teachers_size=5;
   bp::Array<person> _teachers(_teachers_size);
   for (int i = 0; i < _teachers_size; i++)
   {
    std::string temp_name="teacher";
    temp_name+=std::to_string(i);
    std::string temp_password="pass";
    temp_password+=std::to_string(i);
    person temp_person(temp_name,temp_password);
    _teachers.push(temp_person);
   }
   //students
     int _students_size=10;
   bp::Array<person> _students(_students_size);
   for (int i = 0; i < _students_size; i++)
   {
    std::string temp_name="student";
    temp_name+=std::to_string(i);
    std::string temp_password="pass";
    temp_password+=std::to_string(i);
    person temp_person(temp_name,temp_password);
    _students.push(temp_person);
   }
   //seting up the login system
   teachers=&_teachers;
   students=&_students;
   teachers_size=_teachers_size;
   students_size=students_size;
   
    /////////login
    login_system();
    
    
    return 0;
}
void login_system()
{   
 bool log_in_again=true;
    while (log_in_again)
    {
        bool found_user_name=false;
     std::string user_name;
    std::string password;
    std::cout<<"username:";
    std::cin>>user_name;
    std::cout<<"password:";
    std::cin>>password;
    
    for (int i = 0; i <teachers_size; i++)
    {
        if (teachers->operator[](i).user_name==user_name)
        {
            found_user_name=true;
            if (teachers->operator[](i).pass_word==password)
            {
                //log in that account
                log_in_again=false;
                break;
            }
            
        }
        
    }
    
    for (int i = 0; i <students_size; i++)
    {
        if (students->operator[](i).user_name==user_name)
        {
            found_user_name=true;
            if (students->operator[](i).pass_word==password)
            {
                //log in that account
                   // creating/accessing dashbord
                //
                log_in_again=false;
                break;
            }
            
        }
        
    }

    if (found_user_name)
    {
        std::cout<<"username found but password is incorrect"<<std::endl;
    }
    else
    {
        std::cout<<"username not found"<<std::endl;
    }
    
    }
}