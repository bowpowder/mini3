#include <iostream>
#include<string>
#include<fstream>
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
        void _get_emptyed()
        {
            delete[] heap_alocated_array;
            heap_alocated_array=new T[max_size];
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
    namespace file //each function will update a specific file
    {     
     //students list
     void student_list_f_save(std::ostream _ostream,Array<simple_daneshjo> * _students_list)
     {        
        int size=_students_list->get_size();
        std::string save_string;
       for (int i = 0; i < size; i++)
       {
        simple_daneshjo temp_daneshjo=_students_list->operator[](i);
        //_ostream<<temp_daneshjo.user_name<<'\n'<<temp_daneshjo.pass_word<<'\n'<<temp_daneshjo.shomare_daneshjoii<<'\n';
        save_string+=temp_daneshjo.user_name+'\n'+temp_daneshjo.pass_word+'\n'+std::to_string( temp_daneshjo.shomare_daneshjoii)+'\n';        
       }
       _ostream<<save_string;
     }   
     void student_list_f_reaload(std::istream _istream,bool& file_is_empty,Array<simple_daneshjo> * _students_list,int& count)
     {
        _students_list->_get_emptyed();
        std::string temp_str;
        while (std::getline(_istream >> std::ws, temp_str))
	    {
            simple_daneshjo temp_daneshjo;
            temp_daneshjo.user_name=temp_str;
            _istream>>temp_daneshjo.pass_word>>temp_daneshjo.shomare_daneshjoii;            
            _students_list->push(temp_daneshjo);
		count++;		
	    }	        
     }
     //number of student lists
      void student_list_number_save(std::ostream _ostream,int size)
      {
        _ostream<<size;
      }
      void student_list_number_reload(std::istream _istream,int &size)
      {
        _istream>>size;
      }
      //number of exams
      void exam_number_save(std::ostream _ostream,int size)
      {
        _ostream<<size;
      }
      void exam_number_reload(std::istream _istream,int &size)
      {
        _istream>>size;
      }
      //exam


      //exam resaults


      //
    };
    enum save_load_funcs
    {
        students_list_save,students_list_load,students_list_n_s,students_list_n_l,exam_save,exam_load,exam_n_s,exam_n_l
    }
}

void read_file(std::string path);
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
 class simple_daneshjo :public person
    {
    public:        
        int shomare_daneshjoii;        
    public:
        simple_daneshjo(int _sd=0,std::string _name={},std::string _pass_word={}):person(_name,_pass_word), shomare_daneshjoii(_sd)
        {

        }
        
        ~simple_daneshjo()
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
void handle_file(bp::save_load_funcs s_l_func,std::string file_name,bool read_not_write,std::string path="./",bool delete_old_file=false)
{  
path += file_name;

if (read_not_write)
{
	
	std::filebuf fb;
	fb.open(path, std::ios::app | std::ios::in);
	std::istream _istream(&fb);
	std::string temp_str;	
	int count = 0;
    //reading file
	switch (s_l_func)
    {
        //exams
    case bp::save_load_funcs::exam_save:
    
        break;
    case bp::save_load_funcs::exam_load:
    
        break;
    case bp::save_load_funcs::exam_n_s:
    
        break;
     case bp::save_load_funcs::exam_n_l:
    //student lists
        break;
    case bp::save_load_funcs::students_list_save:
    //bp::students_list_save()
        break;
    case bp::save_load_funcs::students_list_load:
    
        break;
    case bp::save_load_funcs::students_list_n_s:
    
        break; 
    case bp::save_load_funcs::students_list_n_l:
    //
        break;             
    default:
        break;
    }
    							
	if (!count)		
	{
	//	std::cout << "file was empty" << std::endl;
		//exit(1);
	}
    //close flie stream
    fb.close();	
}
else
{
    int n;
	std::cin >> n;
	std::filebuf fb;
    if (delete_old_file)
    {
     fb.open(path,std::ios::out);
    }
    else
    {
    fb.open(path,std::ios::app | std::ios::out);
    }	
    //wrting to file
	std::ostream _ostream(&fb);			
	for (int i = 0; i < n; i++)
	{
	std::string temp_str;
	std::getline(std::cin >> std::ws, temp_str);
	_ostream << temp_str << '\n';
	}
    //close flie stream
	fb.close();
    
}
}