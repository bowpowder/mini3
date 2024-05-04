#include <iostream>
#include<string>
#include<fstream>  
#include<sstream>
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
    simple_daneshjo(int _sd = 0, std::string _name = {}, std::string _pass_word = {}) :person(_name, _pass_word), shomare_daneshjoii(_sd)
    {

    }

    ~simple_daneshjo()
    {

    }
};
void load_e_n_f();
void save_e_n_f(bool add_one_first);
int give_num_e();
void* clear_loaded_exam();

namespace bp
{   
       
    enum save_load_funcs
    {
        students_list_save, students_list_load, students_list_n_s, students_list_n_l, exam_save, exam_load, exam_n_s, exam_n_l, load_exam_name
    };
    enum save_load_state
    {
        load, save
    };
    enum delete_old_f_state
    {
        _delete, dont_delete
    };
    enum posible_test_awnsers
    {
        a, b, c, d
    };
    void handle_file(bp::save_load_funcs , std::string , bp::save_load_state, std::string , bp::delete_old_f_state , void* _ptr);
    template<class T>
    class Array
    {
    private:
        T* heap_alocated_array;
        int size;
        int max_size;
    public:
        Array(int _size) :heap_alocated_array(new T[_size]), size(1), max_size(_size)
        {

        }
        void _get_emptyed()
        {
            delete[] heap_alocated_array;
            heap_alocated_array = new T[max_size];
        }
        void _get_super_emptyed()
        {
            if (heap_alocated_array&& this)
            {
                delete[] heap_alocated_array;
            }          
           
            heap_alocated_array = new T[1];
        }         
        void push(T value)
        {
            safe_resize();
            heap_alocated_array[size] = value;
            size++;
        }
        T* get_array()
        {
            return heap_alocated_array;
        }
        void safe_resize(bool increase_size=false)
        {
         if (increase_size)
          {
           size++;
          }            
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
    void set_loaded_s_l(bp::Array<int>& temp_s_list);
    class test_question
    {
    public:
        posible_test_awnsers currect_anwser;
        std::string a, b, c, d;
    public:
        test_question(std::string option_a = {}, std::string option_b = {}, std::string option_c = {}, std::string option_d = {}, posible_test_awnsers _currect_anwser = posible_test_awnsers::a) :a(option_a), b(option_b), c(option_c), d(option_d), currect_anwser(_currect_anwser)
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
        descriptive_question(std::string _string_anwser = {}) : string_answer(_string_anwser)
        {

        }
        ~descriptive_question()
        {

        }
    };
    class question
    {
    public:
        bool is_test = false;
        double score, time;
        std::string question_str;
        void* t_Or_d_question;

    public:
        question(bool _is_test = true, int _score = 0, int _time = 0, std::string _question_str = {}) :is_test(_is_test), score(_score), time(_time), question_str(_question_str), t_Or_d_question(nullptr)
        {
            if (is_test)
            {
                t_Or_d_question = new test_question();
            }
            else
            {
                t_Or_d_question = new descriptive_question();
            }

        }
        ~question()
        {
            if (is_test)
            {
                test_question* test_ptr = (test_question*)t_Or_d_question;
                delete test_ptr;
                test_ptr = nullptr;
            }
            else
            {
                descriptive_question* des_ptr = (descriptive_question*)t_Or_d_question;
                delete des_ptr;
                des_ptr = nullptr;
            }
            t_Or_d_question = nullptr;
        }
        void change_to_test()
        {
            is_test = true;
            delete t_Or_d_question;
            t_Or_d_question =new test_question;
        }
        void change_to_descriptive()
        {
            is_test = false;
            delete t_Or_d_question;
            t_Or_d_question = new descriptive_question;
        }
    };
    class exam
    {
    public:
        std::string exam_name;
        int total_score, total_time;
        Array<question> questions;
    public:
        exam(int _number_of_questions = 1, std::string _exam_name = {}, int _total_score = 0, int _total_time = 0)
            :questions(_number_of_questions), total_score(_total_score), total_time(_total_time), exam_name(_exam_name)
        {

        }
        ~exam()
        {

        }
        void add_question(bool is_first)
        {
            bool is_test = false;
            char input;
            std::cout << "c : cancel" << std::endl;
            std::cout << "is it test?(y/n)" << std::endl;
            std::cin >> input;
            int old_size = questions.get_size();
            if (!is_first)
            {
                questions.push(new question());
            }
            switch (input)
            {
            case 'c':
                std::cout << "canceling" << std::endl;
                return;
                break;
            case 'y':
                is_test = true;
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
                is_test = false;
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
                std::cout << "invalid command" << std::endl;
                std::cout << "canceling" << std::endl;
                return;
                break;
            }
            std::cout << "enter question_str" << std::endl;
            std::string temp_str;
            std::getline(std::cin >> std::ws, temp_str);
            std::cout << "enter max_time of answering" << std::endl;
            int temp_time, temp_score;
            std::cin >> temp_time;
            std::cout << "enter score" << std::endl;
            std::cin >> temp_score;
            std::string test_options[4];
            posible_test_awnsers currect_test_anwser;
            std::string descriptive_answer = {};
            if (is_test)
            {
                std::cout << "enter option a:" << std::endl;
                std::getline(std::cin >> std::ws, test_options[0]);
                std::cout << "enter option b:" << std::endl;
                std::getline(std::cin >> std::ws, test_options[1]);
                std::cout << "enter option c:" << std::endl;
                std::getline(std::cin >> std::ws, test_options[2]);
                std::cout << "enter option d:" << std::endl;
                std::getline(std::cin >> std::ws, test_options[3]);
                std::cout << "current answer" << std::endl;
                char char_c_a;
                std::cin >> char_c_a;
                switch (char_c_a)
                {
                case 'a':
                    std::cout << "setting currect answer to a" << std::endl;
                    currect_test_anwser = posible_test_awnsers::a;
                    break;
                case 'b':
                    std::cout << "setting currect answer to b" << std::endl;
                    currect_test_anwser = posible_test_awnsers::b;
                    break;
                case 'c':
                    std::cout << "setting currect answer to c" << std::endl;
                    currect_test_anwser = posible_test_awnsers::c;
                    break;
                case 'd':
                    std::cout << "setting currect answer to d" << std::endl;
                    currect_test_anwser = posible_test_awnsers::d;
                    break;
                default:
                    std::cout << "default currect answer is b" << std::endl;
                    std::cout << "setting currect answer to b" << std::endl;
                    currect_test_anwser = posible_test_awnsers::b;
                    break;
                }
            }
            else
            {
                std::cout << "enter currect_descriptive answer" << std::endl;
                std::getline(std::cin >> std::ws, descriptive_answer);
            }
            if (is_first)
            {
                questions[0].question_str = temp_str;
                questions[0].time = temp_time;
                questions[0].score = temp_score;
                if (is_test)
                {
                    test_question* t_ptr = (test_question*)questions[0].t_Or_d_question;
                    t_ptr->a = test_options[0];
                    t_ptr->b = test_options[1];
                    t_ptr->c = test_options[2];
                    t_ptr->d = test_options[3];
                    t_ptr->currect_anwser = currect_test_anwser;
                }
                else
                {
                    descriptive_question* d_ptr = (descriptive_question*)questions[0].t_Or_d_question;
                    d_ptr->string_answer = descriptive_answer;
                }


            }
            else
            {
                questions[old_size].question_str = temp_str;
                questions[old_size].time = temp_time;
                questions[old_size].score = temp_score;
                if (is_test)
                {
                    test_question* t_ptr = (test_question*)questions[old_size].t_Or_d_question;
                    t_ptr->a = test_options[0];
                    t_ptr->b = test_options[1];
                    t_ptr->c = test_options[2];
                    t_ptr->d = test_options[3];
                    t_ptr->currect_anwser = currect_test_anwser;
                }
                else
                {
                    descriptive_question* d_ptr = (descriptive_question*)questions[old_size].t_Or_d_question;
                    d_ptr->string_answer = descriptive_answer;
                }
            }
            std::cout << "question was added successfully" << std::endl;
            return;
        }
        void calculate_t_time()
        {
            int temp_int = 0;
            int size = number_of_questions();
            for (int i = 0; i < size; i++)
            {
                temp_int += questions[i].time;
            }
            total_time = temp_int;
        }
        int number_of_questions()
        {
            return questions.get_size();
        }

        static void save_new_exam(void* _exam)
        {
            //creating the file name
             //load exam number file
            load_e_n_f();            
            //save exam to a new exam file
            {
                std::string file_name = "exam" + std::to_string(give_num_e());
                std::string _path = "./exams/";
                handle_file(bp::save_load_funcs::exam_save, file_name, bp::save_load_state::save, _path, bp::delete_old_f_state::_delete, _exam);
            }
            //now change  and save number of exams file            
            //save exam number file            
             save_e_n_f(true);//it also adds 1 to it
        }
        static void  create_new_exam()
        {
            exam* _exam = nullptr;
            std::string exam_name;
            std::cout << "exam_name" << std::endl;
            std::getline(std::cin >> std::ws, exam_name);
            {//scoped
                std::cout << "0 : back to dashboard" << '\n';
                std::cout << "1 : add fisrt question" << '\n';
                int input;
                std::cin >> input;

                switch (input)
                {
                case 0://going back to the dashboard
                    std::cout << "going back to dashboard" << std::endl;
                    return;
                    break;
                case 1://creating an examp obj and adding first question
                    //creating an exam obj
                    _exam = new exam(1, exam_name);
                    //adding first question
                    _exam->add_question(true);
                    break;

                default:
                    std::cout << "invalid command" << std::endl;
                    std::cout << "going back to dashboard" << std::endl;
                    return;
                    break;
                }
            }
            while (true)
            {
                std::cout << "0 : save exam" << '\n';
                std::cout << "1 : add more questions" << '\n';
                int input;
                std::cin >> input;
                switch (input)
                {
                case 0://saving exam and exiting this loop
                    //save exam
                    save_new_exam(_exam);
                    //going back to dashboard
                    std::cout << "going back to dashboard" << std::endl;
                    return;
                    break;
                case 1:
                    //adding more questions          
                    _exam->add_question(false);
                    break;
                default: //saving exam and exiting this loop           
                    //save exam
                    save_new_exam(_exam);
                    //going back to dashboard
                    std::cout << "going back to dashboard" << std::endl;
                    return;
                    break;
                }
            }
        }
    };
    
    namespace file //each function will update a specific file
    {
        //students list
        void student_list_f_save(void* ptr_ostream, void* ptr__students_list)
        {
            
            std::ostream& _ostream = *((std::ostream*)ptr_ostream);
            bp::Array<int> *_student_list=(bp::Array<int> *) ptr__students_list;
            int size = _student_list->get_size();
            std::string out_string={};
            for (int i = 0; i < size; i++)
            {
                out_string+=std::to_string(_student_list->operator[](i))+='\n';                
            }
            _ostream << out_string;
        }
        void student_list_f_reaload(void* ptr_istream, void* ptr__students_list)
        {
            bp::Array<int>* temp_s_list=new bp::Array<int>(1);
            std::istream& _istream = *((std::istream*)ptr_istream);          
            std::string temp_str={};
            bool is_first_sho_da=true;
            while (std::getline(_istream >> std::ws, temp_str))
            {                
               std::stringstream ss(temp_str);
               int input;
               ss>>input;
               if (is_first_sho_da)
               {
                temp_s_list->operator[](0)=input;
                is_first_sho_da=false;
               }
               else
               {
                temp_s_list->push(input);
               }               
            }
           set_loaded_s_l(*temp_s_list);
        }
        //number of student lists
        void student_list_number_save(void* ptr_ostream, int size)
        {
            std::ostream& _ostream = *((std::ostream*)ptr_ostream);
            _ostream << size;
        }
        void student_list_number_reload(void* ptr_istream, void* ptr_size)
        {
            int& size = *((int*)ptr_size);
            std::istream& _istream = *((std::istream*)ptr_istream);
            _istream >> size;
        }
        //number of exams
        void exam_number_save(void* ptr_ostream, int size)
        {
            std::ostream& _ostream = *((std::ostream*)ptr_ostream);
            _ostream << size;
        }
        void exam_number_reload(void* ptr_istream, void* ptr_size)
        {
            int& size = *((int*)ptr_size);
            std::istream& _istream = *((std::istream*)ptr_istream);
            _istream >> size;
        }
        //exam
        void exam_save(void* ptr_ostream, void* _loaded_exam)
        {
            std::ostream& _ostream = *((std::ostream*)ptr_ostream);
            std::string out_string = {};
            exam* e_ptr = (exam*)_loaded_exam;
            out_string += ((exam*)_loaded_exam)->exam_name + '\n';
            int exam_size = e_ptr->number_of_questions();
            for (int i = 0; i < exam_size; i++)
            {
                out_string += e_ptr->questions[i].question_str += '\n';
                if (e_ptr->questions[i].is_test)
                {
                    out_string += "true";
                }
                else
                {
                    out_string += "false";
                }
                out_string += '\n';
                out_string += std::to_string(e_ptr->questions[i].time) + '\n';
                out_string += std::to_string(e_ptr->questions[i].score) + '\n';
                if (e_ptr->questions[i].is_test)//its a test
                {
                    test_question* t_q_ptr = ((test_question*)(e_ptr->questions[i].t_Or_d_question));
                    out_string += t_q_ptr->a + '\n' + t_q_ptr->b + '\n' + t_q_ptr->c + '\n' + t_q_ptr->d + '\n';
                    std::string out_char = {};
                    switch (t_q_ptr->currect_anwser)
                    {
                    case bp::posible_test_awnsers::a:
                        out_char = "a";
                        break;
                    case bp::posible_test_awnsers::b:
                        out_char = "b";
                        break;
                    case bp::posible_test_awnsers::c:
                        out_char = "c";
                        break;
                    case bp::posible_test_awnsers::d:
                        out_char = "d";
                        break;
                    default:
                        out_char = "b";
                        break;
                    }
                    out_string += out_char;
                    out_string +='\n';

                }
                else //its descriptive
                {
                    descriptive_question* d_q_ptr = ((descriptive_question*)(e_ptr->questions[i].t_Or_d_question));
                    out_string += d_q_ptr->string_answer + '\n';
                }
            }
            _ostream << out_string;
        }
        void exam_reload(void* ptr_istream, void* _loaded_exam)
        {
            std::istream& _istream = *((std::istream*)ptr_istream);
            std::string in_string = {};            
            exam* e_ptr = (exam*)(clear_loaded_exam());                        
            std::getline(_istream >> std::ws, in_string);
            e_ptr->exam_name = in_string;                     
            int i=0;
            e_ptr->questions._get_super_emptyed();
            while (std::getline(_istream >> std::ws, in_string) )
            {                
                if (i!=0)               
                {                    
                    e_ptr->questions.safe_resize();
                }                                                                       
                e_ptr->questions[i].question_str = in_string;                
                std::getline(_istream >> std::ws, in_string);
                if (in_string=="true")
                {
                    e_ptr->questions[i].is_test = true;                    
                }
                else
                {
                    e_ptr->questions[i].is_test = false;
                }
                _istream >> e_ptr->questions[i].time >> e_ptr->questions[i].score;                
                if (e_ptr->questions[i].is_test)//its a test
                {
                    e_ptr->questions[i].change_to_test();
                    test_question* t_q_ptr = ((test_question*)(e_ptr->questions[i].t_Or_d_question));
                    std::getline(_istream >> std::ws, in_string);
                    t_q_ptr->a = in_string;
                    std::getline(_istream >> std::ws, in_string);
                    t_q_ptr->b = in_string;
                    std::getline(_istream >> std::ws, in_string);
                    t_q_ptr->c = in_string;
                    std::getline(_istream >> std::ws, in_string);
                    t_q_ptr->d = in_string;
                    std::getline(_istream >> std::ws, in_string);
                    if (in_string == "a")
                    {
                        t_q_ptr->currect_anwser = bp::posible_test_awnsers::a;
                    }
                    else if (in_string == "b")
                    {
                        t_q_ptr->currect_anwser = bp::posible_test_awnsers::b;
                    }
                    else if (in_string == "c")
                    {
                        t_q_ptr->currect_anwser = bp::posible_test_awnsers::c;
                    }
                    else if (in_string == "d")
                    {
                        t_q_ptr->currect_anwser = bp::posible_test_awnsers::d;
                    }
                    else
                    {
                        t_q_ptr->currect_anwser = bp::posible_test_awnsers::b;
                    }
                }
                else //its descriptive
                {
                    e_ptr->questions[i].change_to_descriptive();
                    descriptive_question* d_q_ptr = ((descriptive_question*)(e_ptr->questions[i].t_Or_d_question));
                    std::getline(_istream >> std::ws, in_string);
                    d_q_ptr->string_answer = in_string;
                }
                i++;
            }
            
            
            


        }
        //exam resaults


        //exam name
        void exam_name_load(void* ptr_istream, void* ptr_name)
        {
            std::string& _name = *((std::string*)ptr_name);
            std::istream& _istream = *((std::istream*)ptr_istream);
            _istream >> _name;
        }
    }
    void handle_file(bp::save_load_funcs s_l_func, std::string file_name, bp::save_load_state _read_write_state, std::string path = "./", bp::delete_old_f_state _delete_old_file = bp::delete_old_f_state::dont_delete, void* _ptr = nullptr)
    {
        path += file_name;
        if (_read_write_state == bp::save_load_state::load)//read
        {
            std::filebuf fb;
            fb.open(path, std::ios::app | std::ios::in);
            std::istream _istream(&fb);
            std::string temp_str;
            int count = 0;
            //reading file
            switch (s_l_func)
            {//load funcs        
            case bp::save_load_funcs::exam_load:
                bp::file::exam_reload(&_istream, _ptr);
                break;
            case bp::save_load_funcs::exam_n_l:
                bp::file::exam_number_reload(&_istream, _ptr);
                break;
            case bp::save_load_funcs::load_exam_name:
                bp::file::exam_name_load(&_istream, _ptr);
                break;
            case bp::save_load_funcs::students_list_load:
                bp::file::student_list_f_reaload(&_istream, _ptr);
                break;
            case bp::save_load_funcs::students_list_n_l:
                bp::file::student_list_number_reload(&_istream, _ptr);
                break;;
            default:
                std::cout << "error: invalid file state" << std::endl;
                exit(1);
                break;
            }
            fb.close();
        }
        else //save
        {            
            std::filebuf fb;
            if (_delete_old_file == bp::delete_old_f_state::_delete)//delete old file
            {
                fb.open(path, std::ios::out);
            }
            else //dont delete old file
            {
                fb.open(path, std::ios::app | std::ios::out);
            }
            std::ostream _ostream(&fb);
            //wrting to file
            switch (s_l_func)
            {//save funcs
            case bp::save_load_funcs::exam_n_s:
                bp::file::exam_number_save(&_ostream, *(int*)_ptr);
                break;
            case bp::save_load_funcs::exam_save:
                bp::file::exam_save(&_ostream, _ptr);
                break;
            case bp::save_load_funcs::students_list_n_s:
                bp::file::student_list_number_save(&_ostream, *(int*)_ptr);
                break;
            case bp::save_load_funcs::students_list_save:
                bp::file::student_list_f_save(&_ostream, _ptr);
                break;
            default:
                std::cout << "error: invalid file state" << std::endl;
                exit(1);
                break;
            }
            //close flie stream
            fb.close();
        }
    }   
};
bp::Array<person>* teachers = nullptr;
bp::Array<person>* students = nullptr;
int teachers_size = -1;
int students_size = -1;
//load and save files
namespace g_V
{
    int number_of_s_lists = 0;
    int number_of_exams = 0;
    void* loaded_exam = nullptr;
    void* loaded_s_l = nullptr;
    void add_new_sho_da(bp::Array<int> &_sho_d_ha,int value,bool first_Q=false)
    {
     if (first_Q)
     {
        _sho_d_ha[0]=value;
     }
     else
     {
        _sho_d_ha.push(value);
     }
     
    }
    void creat_n_s_l()
    {
        bp::Array<int> sho_d_ha(1);
        bool keep_looping=true;
        {//scooped
            std::cout<<"add fisrt student "<<std::endl;
            int fisrt_value;
            std::cin>>fisrt_value;
            add_new_sho_da(sho_d_ha,fisrt_value,true);
        }        
        while (keep_looping)
        {
            
            std::cout<<"1: add one more student"<<std::endl;
            std::cout<<"0: save student list"<<std::endl;
            int input;
            std::cin>>input;
            int other_input;
            if (input==1)
            {
                std::cout<<"adding one more student"<<std::endl;
            //add student
            std::cin>>other_input;
            add_new_sho_da(sho_d_ha,other_input);
            }
            else
            {
                 std::cout<<"saving this student list"<<std::endl;
            //save
            //find current name for the file
               //load student lists number file
            {
                std::string file_name = "student_lists_number";
                std::string path = "./";
                void* _Ptr = &g_V::number_of_s_lists;
                handle_file(bp::save_load_funcs::students_list_n_l, file_name, bp::save_load_state::load, path, bp::delete_old_f_state::dont_delete, _Ptr);
            }
            //save student list
            {
                std::string name=std::to_string(g_V::number_of_s_lists);
                std::string file_path="./student_lists/";
                bp::handle_file(bp::save_load_funcs::students_list_save,name,bp::save_load_state::save,file_path,bp::delete_old_f_state::_delete,&sho_d_ha);
            }
            //update and save the number of student lists
            {
                g_V::number_of_s_lists++;
                std::string file_name = "student_lists_number";
                std::string path = "./";
                void* _Ptr = &g_V::number_of_s_lists;
                handle_file(bp::save_load_funcs::students_list_n_s, file_name, bp::save_load_state::save, path, bp::delete_old_f_state::dont_delete, _Ptr);
            }            
            keep_looping=false;
            }                      
        }
        
    }
    
    void show_loaded_exam(bool teacher_view = true)
    {
        if (loaded_exam)//an exam is loaded
        {
            bp::exam* e_ptr = (bp::exam*)loaded_exam;
            int exam_size = e_ptr->number_of_questions();
            std::cout << e_ptr->exam_name << std::endl;
            for (int i = 0; i < exam_size; i++)
            {
                std::cout << "question " << i << ':' << std:: endl;
                std::cout << "-----------------------------------------------" << std::endl;
                std::cout << e_ptr->questions[i].question_str << std::endl;
                std::cout << "max time :" << e_ptr->questions[i].time << std::endl;
                std::cout << "score :" << e_ptr->questions[i].score << std::endl;
                if (e_ptr->questions[i].is_test)///its test
                {
                    bp::test_question* t_ptr = (bp::test_question*)e_ptr->questions[i].t_Or_d_question;
                    std::cout << "option a:" << t_ptr->a << std::endl;
                    std::cout << "option b:" << t_ptr->b << std::endl;
                    std::cout << "option c:" << t_ptr->c << std::endl;
                    std::cout << "option d:" << t_ptr->d << std::endl;
                    if (teacher_view)
                    {
                        char c_a;
                        switch (t_ptr->currect_anwser)
                        {
                        case bp::posible_test_awnsers::a:
                            c_a = 'a';
                            break;
                        case bp::posible_test_awnsers::b:
                            c_a = 'b';
                            break;
                        case bp::posible_test_awnsers::c:
                            c_a = 'c';
                            break;
                        case bp::posible_test_awnsers::d:
                            c_a = 'd';
                            break;
                        default:
                            c_a = 'b';
                            break;
                        }
                        std::cout << "currect awnser :" << c_a << std::endl;
                    }                    
                }
                else//its descriptive
                {
                    bp::descriptive_question* d_ptr = (bp::descriptive_question*)e_ptr->questions[i].t_Or_d_question;
                    if (teacher_view)
                    {
                        std::cout << "currect awnser :" << d_ptr->string_answer << std::endl;
                    }
                }
                std::cout << "-----------------------------------------------" << std::endl;
            }             
            std::cout << std::endl << std::endl;
        }
        else // its nullptr and not loaded
        {
            std::cout << "no exam is loaded" << std::endl;
        }
       
    }
    void show_loaded_s_l()
    {
      bp::Array<int>* ptr=(bp::Array<int>*)g_V::loaded_s_l;
      int size=ptr->get_size();
      for (int i = 0; i < size; i++)
      {
        std::cout<<"student"<<i<<": "<<ptr->operator[](i)<<std::endl;
      }
        
    }
    void save_loaded_s_l()
    {
        ///
    }
    void edit_loaded_s_l()
    {
        ///
       //potantioly save that student_list back to the given file name
        //  if (/* condition */)
         // {
        save_loaded_s_l();
        //   }
    }    
     void save_loaded_exam()
    {
        ///
    }
    void edit_loaded_exam()
    {
        ///
        //potantioly save that exam back to the given file name
         //  if (/* condition */)
          // {
        save_loaded_exam();
        //   }

    }
   
    std::string* exam_names = nullptr;
};
//
void bp::set_loaded_s_l(bp::Array<int>& temp_s_list)
{
   delete g_V::loaded_s_l;
   g_V::loaded_s_l=(void*)(new bp::Array<int>(temp_s_list));
}
void* clear_loaded_exam()
    {
        if (g_V::loaded_exam)
        {
           delete g_V::loaded_exam;
        }                
        g_V::loaded_exam=new bp::exam;
        return g_V::loaded_exam;
    }
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
                    enter_dashboard(true, &teachers->operator[](i));
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
void load_e_n_f()
{
    std::string file_name = "exam_numbers";
    std::string file_path = "./";
    void* _ptr = &g_V::number_of_exams;
    handle_file(bp::save_load_funcs::exam_n_l, file_name, bp::save_load_state::load, file_path, bp::delete_old_f_state::dont_delete, _ptr);
}
int give_num_e()
{
    return g_V::number_of_exams;
}
void save_e_n_f(bool add_one_first)
{
    if (add_one_first)
    {
        g_V::number_of_exams++;
    }
    std::string file_name = "exam_numbers";
    std::string file_path = "./";
    void* _ptr = &g_V::number_of_exams;
    handle_file(bp::save_load_funcs::exam_n_s, file_name, bp::save_load_state::save, file_path, bp::delete_old_f_state::_delete, _ptr);
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
            std::cout << "4 : exam resualts" << std::endl;
            std::cout << "5 : create new student list" << std::endl;
            int command;
            std::cin >> command;
            int other_input;
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
                bp::exam::create_new_exam();
                break;
            case 2:
                //exam history                
                //load exam number file
                load_e_n_f();                      
            //load that number of exam names
            {
                delete g_V::exam_names;
                g_V::exam_names = new std::string[g_V::number_of_exams];
                std::string _exam_name = {};
                void* _ptr = &_exam_name;
                for (int i = 0; i < g_V::number_of_exams; i++)
                {
                    std::string file_name = "exam";
                    file_name += std::to_string(i);
                    std::string _path = "./exams/";
                    handle_file(bp::save_load_funcs::load_exam_name, file_name, bp::save_load_state::load, _path, bp::delete_old_f_state::dont_delete, _ptr);
                    g_V::exam_names[i] = _exam_name;
                }
            }
            //show that many number of exams
            //show the exam names
            std::cout << "-1 :go back" << std::endl;
            std::cout << "exams:" << std::endl;
            for (int i = 0; i < g_V::number_of_exams; i++)
            {
                std::cout << i << " :" << g_V::exam_names[i] << std::endl;
            }
            //let the user choose what exam they want to load
            
            std::cin >> other_input;
            if (other_input == -1)
            {//stop right here and go back                  
                std::cout << "going back" << std::endl;
                break;
            }
            //load that exam
            {
                std::string file_name = "exam" + std::to_string(other_input);
                std::string file_path = "./exams/";
                delete g_V::loaded_exam;
                g_V::loaded_exam = new bp::exam(1);
                handle_file(bp::save_load_funcs::exam_load, file_name, bp::save_load_state::load, file_path, bp::delete_old_f_state::dont_delete, g_V::loaded_exam);
            }
            //show show that exam to the user
            g_V::show_loaded_exam();
            //let them edit the iner_contents of that exam
            g_V::edit_loaded_exam();   //and maybe save it             
            break;
            case 3:
                //student lists
                //load student lists number file
            {
                std::string file_name = "student_lists_number";
                std::string path = "./";
                void* _Ptr = &g_V::number_of_s_lists;
                handle_file(bp::save_load_funcs::students_list_n_l, file_name, bp::save_load_state::load, path, bp::delete_old_f_state::dont_delete, _Ptr);
            }
            //show them to the user
            std::cout << "-1 :go back" << std::endl;
            std::cout << "student lists:" << std::endl;
            for (int i = 0; i < g_V::number_of_s_lists; i++)
            {
                std::cout << i << " :" << "studentlist " << i;
            }
            //let the user choose which one they what to load            
            std::cin >> other_input;
            if (other_input == -1)
            {//stop right here and go back
                std::cout << "going back" << std::endl;
                break;
            }
            //load that specific list 
            {
                std::string file_name = std::to_string(other_input);
                std::string _path = "./student_lists/";
                void* _ptr = g_V::loaded_s_l;
                handle_file(bp::save_load_funcs::students_list_load, file_name, bp::save_load_state::load, _path, bp::delete_old_f_state::dont_delete, _ptr);
            }
            //show that list
            g_V::show_loaded_s_l();
            //let the user edit that list
            g_V::edit_loaded_s_l();
            break;
            case 5:
            g_V::creat_n_s_l();
            break;
            default:
                std::cout << "invalid command. try again" << std::endl;
                break;
            }
        }
    }
    else //its a student
    {
        ///no nonono
    }



}
