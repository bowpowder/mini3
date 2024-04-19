#include <iostream>
#include<string>
#include<fstream>  
namespace bp
{     
    
    void create_new_exam()
    {
        exam* _exam=nullptr;
        std::string exam_name;
        std::getline(std::cin>>std::ws,exam_name);
       {//scoped
            std::cout << "0 : back to dashboard" << '\n';
            std::cout << "1 : add fisrt question" << '\n';
            int input;
            std::cin>>input;
            switch (input)
            {
            case 0://going back to the dashboard
            std::cout<<"going back to dashboard"<<std::endl;
                return;
                break;
                 case 1://creating an examp obj and adding first question
                 //creating an exam obj
             _exam=new exam(1);
                //adding first question
             _exam->add_question(true);                
                break;
            
            default:
            std::cout<<"invalid command"<<std::endl;
            std::cout<<"going back to dashboard"<<std::endl;
            return;
            break;
            }
       }            
        while (true)
        {
            std::cout << "0 : save exam" << '\n';
            std::cout << "1 : add more questions" << '\n';
            int input;
            std::cin>>input;
            switch (input)
            {
            case 0://saving exam and exiting this loop
            //save exam
            
            //going back to dashboard
            std::cout<<"going back to dashboard"<<std::endl;
                return;
                break;

                 case 1:
                 //adding more questions          
                 _exam->add_question(false);                
                break;            
            default: //saving exam and exiting this loop           
            //save exam
            

            //going back to dashboard
            std::cout<<"going back to dashboard"<<std::endl;
                return;
                break;
            }
        }
        
            
    }
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
    };

       enum posible_test_awnsers
    {
        a,b,c,d
    };
    class test_question
    {
    public:
        posible_test_awnsers currect_anwser;
        std::string a, b, c, d;
    public:
        test_question(std::string option_a={},std::string option_b={},std::string option_c={},std::string option_d={},posible_test_awnsers _currect_anwser =posible_test_awnsers::a):a(option_a),b(option_b),c(option_c),d(option_d),currect_anwser(_currect_anwser)
        {

        }
        ~test_question()
        {

        }
    }; 
    class descriptive_question 
    {
    public:
   std::string string_answer;
    public:
        descriptive_question (std::string _string_anwser={}): string_answer(_string_anwser)
        {

        }
        ~descriptive_question ()
        {

        }
    };          
    
class question
{
public:
    bool is_test = false;        
    double score, time;
   std:: string question_str;
   void* t_Or_d_question;

public:
   question(bool _is_test=true,int _score=0,int _time=0,std::string _question_str={}):is_test(_is_test),score(_score),time(_time),question_str(_question_str),t_Or_d_question(nullptr)
   {
     if (is_test)
     {
      t_Or_d_question=new test_question();
     }
     else
     {
      t_Or_d_question=new descriptive_question();
     }

   } 
   ~question()
   {
    if (is_test)
    {
       test_question* test_ptr=(test_question*)t_Or_d_question;
       delete test_ptr;
       test_ptr=nullptr;               
    }
    else
    {
        descriptive_question* des_ptr=(descriptive_question*)t_Or_d_question;
        delete des_ptr;
        des_ptr=nullptr;
    }
    t_Or_d_question=nullptr;
   }  
   void change_to_test()
   {
      delete t_Or_d_question;
       t_Or_d_question=(test_question*)t_Or_d_question;
   }
   void change_to_descriptive()
   {
    delete t_Or_d_question;
    t_Or_d_question=(descriptive_question*)t_Or_d_question;
   }
};
class exam 
{
    public:
    int total_score, total_time;    
    Array<question> questions;
public:
    exam(int _number_of_questions=1, int _total_score=0,int _total_time=0):questions(_number_of_questions),total_score(_total_score),total_time(_total_time)
    {

    }
    ~exam()
    {    

    }
    void add_question(bool is_first)
    {
        bool is_test=false;
        char input;
        std::cout<<"c : cancel"<<std::endl;
        std::cout<<"is it test?(y/n)"<<std::endl;  
        std::cin>>input;
        int old_size=questions.get_size();
        if (!is_first)
        {
            questions.push(new question());
        }
        
        switch (input)
        {
        case 'c':
            std::cout<<"canceling"<<std::endl;
           return;
            break;
             case 'y':    
             is_test=true;       
           if (is_first)
           {
            questions[0].change_to_test();
           } 
           else
           {
            questions[old_size].change_to_test();
           }          
            break;
             case 'n':
             is_test=false;
           if (is_first)
           {
            questions[0].change_to_descriptive();
           }
           else
           {
            questions[old_size].change_to_descriptive();
           }
            break;
        
        default:
         std::cout<<"invalid command"<<std::endl;
         std::cout<<"canceling"<<std::endl;
           return;            
            break;
        }
        std::cout<<"enter question_str"<<std::endl;
        std::string temp_str;
        std::getline(std::cin>>std::ws,temp_str);
        std::cout<<"enter max_time of answering"<<std::endl;
        int temp_time,temp_score;
        std::cin>>temp_time;
        std::cout<<"enter score"<<std::endl;
        std::cin>>temp_score;
        std::string test_options[4];
        posible_test_awnsers currect_test_anwser;
        std::string descriptive_answer={};               
        if (is_test)
        {
           std::cout<<"enter option a:"<<std::endl;
           std::getline(std::cin>>std::ws,test_options[0]);
           std::cout<<"enter option b:"<<std::endl;
           std::getline(std::cin>>std::ws,test_options[1]);
           std::cout<<"enter option c:"<<std::endl;
           std::getline(std::cin>>std::ws,test_options[2]);
           std::cout<<"enter option d:"<<std::endl;
           std::getline(std::cin>>std::ws,test_options[3]);
           std::cout<<"current answer"<<std::endl;
           char char_c_a;
           std::cin>>char_c_a;
           switch (char_c_a)
           {
            case 'a':
            std::cout<<"setting currect answer to a"<<std::endl;
            currect_test_anwser=posible_test_awnsers::a;
            break;
            case 'b':
            std::cout<<"setting currect answer to b"<<std::endl;
            currect_test_anwser=posible_test_awnsers::b;
            break;
            case 'c':
            std::cout<<"setting currect answer to c"<<std::endl;
            currect_test_anwser=posible_test_awnsers::c;
            break;
            case 'd':
            std::cout<<"setting currect answer to d"<<std::endl;
            currect_test_anwser=posible_test_awnsers::d;
            break;           
           default:
            std::cout<<"default currect answer is b"<<std::endl;
            std::cout<<"setting currect answer to b"<<std::endl;
            currect_test_anwser=posible_test_awnsers::b;
            break;
           }
        }
        else
        {
        std::cout<<"enter currect_descriptive answer"<<std::endl;
        std::getline(std::cin>>std::ws,descriptive_answer);
        }      
        if (is_first)
        {
            questions[0].question_str=temp_str;
            questions[0].time=temp_time;
            questions[0].score=temp_score;
            if (is_test)
            {
               test_question* t_ptr=(test_question*) questions[0].t_Or_d_question;
               t_ptr->a=test_options[0];
               t_ptr->b=test_options[1];
               t_ptr->c=test_options[2];
               t_ptr->d=test_options[3];
               t_ptr->currect_anwser=currect_test_anwser;
            }
            else
            {
             descriptive_question* d_ptr=(descriptive_question*) questions[0].t_Or_d_question;
             d_ptr->string_answer=descriptive_answer;
            }
            
            
        }
        else
        {
            questions[old_size].question_str=temp_str;
            questions[old_size].time=temp_time;
            questions[old_size].score=temp_score;
            if (is_test)
            {
               test_question* t_ptr=(test_question*) questions[old_size].t_Or_d_question;
               t_ptr->a=test_options[0];
               t_ptr->b=test_options[1];
               t_ptr->c=test_options[2];
               t_ptr->d=test_options[3];
               t_ptr->currect_anwser=currect_test_anwser;
            }
            else
            {
             descriptive_question* d_ptr=(descriptive_question*) questions[old_size].t_Or_d_question;
             d_ptr->string_answer=descriptive_answer;
            }
        }
       std::cout<<"question was added successfully"<<std::endl;        
       return;
    }
    void calculate_t_time()
    {
        int temp_int=0;
        int size=number_of_questions();
        for (int i = 0; i < size; i++)
        {
           temp_int+=questions[i].time;
        }
        total_time=temp_int;        
    }
    int number_of_questions()
    {
        return questions.get_size();
    }
 };
}

//void read_file(std::string path);
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
                bp::create_new_exam();
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