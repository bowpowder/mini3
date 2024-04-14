#include <iostream>
#include<string>
namespace bp
{
    template<class T>
    class Array
    {
    private:
        T* heap_alocated_array;
        int size;
        int max_size;
    public:
        Array(int _size) :heap_alocated_array(new T[_size]), size(0), max_size(_size)
        {

        }


        void push(T value)
        {
            if (max_size <= size)
            {
                //resize
                T* temp = new T[max_size * 2];
                max_size *= 2;
                for (int i = 0; i < size; i++)
                {
                    temp[i] = heap_alocated_array[i];
                }
                delete[] heap_alocated_array;
                heap_alocated_array = temp;
            }
            heap_alocated_array[size] = value;
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
            delete[] heap_alocated_array;
        }
    };

}
class person
{
public:
    std::string user_name;
    std::string pass_word;
public:
    person(std::string _user_name = {}, std::string _pass_word = {}) :user_name(_user_name), pass_word(_pass_word)
    {

    }
    ~person()
    {

    }

};
bp::Array<person>* teachers = nullptr;
bp::Array<person>* students = nullptr;
int teachers_size = -1;
int students_size = -1;

void login_system();
void enter_dashboard(bool is_teacher, person* _persone);
int main()
{
    //teachers
    int _teachers_size = 5;
    bp::Array<person> _teachers(_teachers_size);
    for (int i = 0; i < _teachers_size; i++)
    {
        std::string temp_name = "teacher";
        temp_name += std::to_string(i);
        std::string temp_password = "pass";
        temp_password += std::to_string(i);
        person temp_person(temp_name, temp_password);
        _teachers.push(temp_person);
    }
    //students
    int _students_size = 10;
    bp::Array<person> _students(_students_size);
    for (int i = 0; i < _students_size; i++)
    {
        std::string temp_name = "student";
        temp_name += std::to_string(i);
        std::string temp_password = "pass";
        temp_password += std::to_string(i);
        person temp_person(temp_name, temp_password);
        _students.push(temp_person);
    }  
    //seting up the login system
    teachers = &_teachers;
    students = &_students;
    teachers_size = _teachers_size;
    students_size = students_size;

    /////////login
    login_system();


    return 0;
}
void login_system()
{

    while (true)
    {
        bool pass_was_correct = false;
        bool found_user_name = false;
        std::string user_name;
        std::string password;
        std::cout << "-1:exit application" << std::endl;
        std::cout << "username:";
        std::cin >> user_name;
        if (user_name == "-1")//the exit conditon
        {
            exit(0);
        }
        std::cout << "password:";
        std::cin >> password;

        for (int i = 0; i < teachers_size; i++)
        {
            person temp_teacher = teachers->operator[](i);
            if (temp_teacher.user_name == user_name)
            {
                found_user_name = true;
                if (temp_teacher.pass_word == password)
                {                    
                    pass_was_correct = true;
                    //log in that account                
                    break;
                }

            }

        }

        for (int i = 0; i < students_size; i++)
        {
            person temp_student = students->operator[](i);
            if (temp_student.user_name == user_name)
            {
                found_user_name = true;
                if (temp_student.pass_word == password)
                {

                    pass_was_correct = true;
                    //log in that account

                       // creating/accessing dashbord
                    //                
                    break;
                }

            }

        }

        if (found_user_name)
        {
            if (!pass_was_correct)
            {
                std::cout << "username found but password is incorrect" << std::endl;
            }
        }
        else
        {
            std::cout << "username not found" << std::endl;
        }

    }
}
void enter_dashboard(bool is_teacher, person* _persone)
{
    if (is_teacher)
    {
        bool keep_loop_going = true;
        while (keep_loop_going)
        {
            std::cout << "-1 : log out and exit application" << '\n';
            std::cout << "0 : log out" << '\n';
            std::cout << "1 : creat a new exam" << '\n';
            std::cout << "2 : exam history" << '\n';
            std::cout << "3 : student lists" << '\n';
            std::cout << "2 : exam resualts" << std::endl;
            int command;
            std::cin >> command;
            switch (command)
            {
            case -1:
                //log out and exit application
                //log out

                //exit application
                exit(0);
                break;
            case 0:
                //log out

                //return to loging system
                return;
                break;
            case 1:
                //creat a new exam

                break;
            case 2:
                //exam history

                break;
            case 3:
                //student lists

                break;
            default:
                std::cout << "invalid command. try again" << std::endl;
                break;
            }
        }
    }
    else //its a student
    {

    }



}