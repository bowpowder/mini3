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
        ~Array()
        {
            delete heap_alocated_array[];
        }
    };
   
}
class person
{
protected:
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





int main()
{
    //teachers
    int teachers_size=5;
   bp::Array<person> teachers(teachers_size);
   for (int i = 0; i < teachers_size; i++)
   {
    std::string temp_name="teacher";
    temp_name+=std::to_string(i);
    std::string temp_password="pass";
    temp_password+=std::to_string(i);
    person temp_person(temp_name,temp_password);
    teachers.push(temp_person);
   }
   //students
     int students_size=10;
   bp::Array<person> students(students_size);
   for (int i = 0; i < students_size; i++)
   {
    std::string temp_name="student";
    temp_name+=std::to_string(i);
    std::string temp_password="pass";
    temp_password+=std::to_string(i);
    person temp_person(temp_name,temp_password);
    students.push(temp_person);
   }
    
    return 0;
}