#include <iostream>
#include<string>
#include<fstream>  
#include<sstream>
#include<vector>
#include <utility>
#include<chrono>
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
void load_studnt_list_n_f();
int give_num_e();
void* clear_loaded_exam();
int* get_student_mode_slin();
std::string* get_g_v_loaded_s_awnser_str();
std::vector<std::string>* get_g_v_awnsers_str_ptr();
std::string* get_g_v_loaded_eteraz_string();
std::vector<std::tuple<std::string,int>>* get_g_v_loaded_student_scores();
bool* get_exam_is_published_stu_mode();
namespace bp
{

    enum save_load_funcs
    {
     exam_resault_save,exam_resault_reload,eteraz_save,eteraz_reload,exam_load_patcipater_list,exam_add_participater, sudent_exam_awnser_load,sudent_exam_awnser_save, students_list_save, students_list_load, students_list_n_s, students_list_n_l, exam_save, exam_load, exam_n_s, exam_n_l, load_exam_name, load_exam_name_and_sl_index
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
    void handle_file(bp::save_load_funcs, std::string, bp::save_load_state, std::string, bp::delete_old_f_state, void* _ptr);
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
            if (heap_alocated_array)
            {
                operator delete[](heap_alocated_array);
            }
            heap_alocated_array = new T[max_size];
        }
        void _get_super_emptyed()
        {
            if (heap_alocated_array && this)
            {
                operator delete[](heap_alocated_array);
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
        void safe_resize(bool increase_size = false)
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

                if (heap_alocated_array)
                {
                    delete[]heap_alocated_array;
                }
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
            if (heap_alocated_array)
            {
                delete[] heap_alocated_array;
            }
        }
    };
    void set_loaded_s_l(bp::Array<int>& temp_s_list);
    class question
    {
    public:
        bool is_test = false;
        double score, time;
        std::string question_str;
        /// <summary>
        /// test stuf
        posible_test_awnsers currect_anwser;
        std::string a, b, c, d;
        /// </summary>        
        std::string string_answer;

    public:
        question(bool _is_test = true, int _score = 0, int _time = 0, std::string _question_str = {}) :is_test(_is_test), score(_score), time(_time), question_str(_question_str)
        {
        }
        ~question()
        {
        }
        void change_to_test()
        {
            is_test = true;
        }
        void change_to_descriptive()
        {
            is_test = false;
        }
    };
    class exam
    {
    public:
        bool is_PUBLISHED;
        int exam_index;
        std::string exam_name;
        int total_score, total_time;
        std::vector<question> questions;
    public:
        exam(int _number_of_questions = 1, std::string _exam_name = {}, int _total_score = 0, int _total_time = 0, int _exam_index = -1, bool _published = false)
            :questions(_number_of_questions), total_score(_total_score), total_time(_total_time), exam_name(_exam_name), exam_index(_exam_index), is_PUBLISHED(_published)
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
            question* temp_q = nullptr;
            if (!is_first)
            {
                temp_q = new question();
                //questions.push(*q);
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
                    temp_q->change_to_test();
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
                    temp_q->change_to_descriptive();
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
                    questions[0].a = test_options[0];
                    questions[0].b = test_options[1];
                    questions[0].c = test_options[2];
                    questions[0].d = test_options[3];
                    questions[0].currect_anwser = currect_test_anwser;
                }
                else
                {
                    questions[0].string_answer = descriptive_answer;
                }


            }
            else
            {
                temp_q->question_str = temp_str;
                temp_q->time = temp_time;
                temp_q->score = temp_score;
                if (is_test)
                {
                    temp_q->a = test_options[0];
                    temp_q->b = test_options[1];
                    temp_q->c = test_options[2];
                    temp_q->d = test_options[3];
                    temp_q->currect_anwser = currect_test_anwser;
                }
                else
                {
                    temp_q->string_answer = descriptive_answer;
                }
                questions.push_back(*temp_q);
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
        void calculate_t_score()
        {
            int temp_int = 0;
            int size = number_of_questions();
            for (int i = 0; i < size; i++)
            {
                temp_int += questions[i].score;
            }
            total_score = temp_int;
        }
        int number_of_questions()
        {
            return questions.size();
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
                    //setting student list exam
                    std::cout << "enter associated student list index" << std::endl;
                    std::cin >> _exam->exam_index;
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
            bp::Array<int>* _student_list = (bp::Array<int> *) ptr__students_list;
            int size = _student_list->get_size();
            std::string out_string = {};
            for (int i = 0; i < size; i++)
            {
                out_string += std::to_string(_student_list->operator[](i)) += '\n';
            }
            _ostream << out_string;
        }
        void student_list_f_reaload(void* ptr_istream)
        {
            bp::Array<int>* temp_s_list = new bp::Array<int>(1);
            std::istream& _istream = *((std::istream*)ptr_istream);
            std::string temp_str = {};
            bool is_first_sho_da = true;
            while (std::getline(_istream >> std::ws, temp_str))
            {
                std::stringstream ss(temp_str);
                int input;
                ss >> input;
                if (is_first_sho_da)
                {
                    temp_s_list->operator[](0) = input;
                    is_first_sho_da = false;
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
        void sudent_exam_awnser_load(void* ptr_istream)
        {
          std::string* _g_v_loaded_s_awnser_str=get_g_v_loaded_s_awnser_str();
          std::istream& _istream = *((std::istream*)ptr_istream);
          *_g_v_loaded_s_awnser_str="";
          std::string temp_str;
          while (std::getline(_istream>>std::ws,temp_str))
          {
            *_g_v_loaded_s_awnser_str+=temp_str+'\n';
          }          
        }
        void exam_add_participater(void* ptr_ostream,std::string* shomare_daneshjoii)
        {
            std::ostream& _ostream = *((std::ostream*)ptr_ostream);
            std::string out_string{*shomare_daneshjoii+'\n'};
            _ostream<<out_string;
        }
        void exam_load_patcipater_list(void* ptr_istream,std::vector<std::string>* string_vector_ptr)
        {
            std::istream& _istream = *((std::istream*)ptr_istream);
            string_vector_ptr->clear();
            std::string temp_string;
            while (std::getline(_istream>>std::ws,temp_string))
            {
                string_vector_ptr->push_back(temp_string);
            }
            
        }
        void sudent_exam_awnser_save(void* ptr_ostream, void* _loaded_exam)
        {
            std::vector<std::string>* awnsers_str_ptr=get_g_v_awnsers_str_ptr();
            std::ostream& _ostream = *((std::ostream*)ptr_ostream);
            std::string out_string = {};
            exam* e_ptr = (exam*)_loaded_exam;
            out_string += ((exam*)_loaded_exam)->exam_name + '\n';               
            int exam_size = e_ptr->number_of_questions();
            for (int i = 0; i < exam_size; i++)
            {
                out_string += '\n';
                out_string += e_ptr->questions[i].question_str += '\n';                
                                
                out_string += std::to_string(e_ptr->questions[i].score) + '\n';
                if (e_ptr->questions[i].is_test)//its a test
                {
                    std::string out_char = {};
                    out_string+="currect awnser:";
                    switch (e_ptr->questions[i].currect_anwser)
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
                    out_string += '\n';

                }
                else //its descriptive
                {
                    out_string += e_ptr->questions[i].string_answer + '\n';
                }
                ///adding the awnsers
                out_string+="student awnser: "+(*awnsers_str_ptr)[i]+'\n';
            }
            _ostream << out_string;
        }        
        void exam_save(void* ptr_ostream, void* _loaded_exam)
        {
            std::ostream& _ostream = *((std::ostream*)ptr_ostream);
            std::string out_string = {};
            exam* e_ptr = (exam*)_loaded_exam;
            out_string += ((exam*)_loaded_exam)->exam_name + '\n';
            //adding exam student list index
            out_string += std::to_string(e_ptr->exam_index) + '\n';
            //adding published text
            std::string pu_str{};

            if (e_ptr->is_PUBLISHED)
            {
                pu_str = "true";
            }
            else
            {
                pu_str = "false";
            }
            out_string += pu_str + '\n';
            // 
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

                    out_string += e_ptr->questions[i].a + '\n' + e_ptr->questions[i].b + '\n' + e_ptr->questions[i].c + '\n' + e_ptr->questions[i].d + '\n';
                    std::string out_char = {};
                    switch (e_ptr->questions[i].currect_anwser)
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
                    out_string += '\n';

                }
                else //its descriptive
                {
                    out_string += e_ptr->questions[i].string_answer + '\n';
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
            //getting exam student list index
            _istream >> e_ptr->exam_index;
            //adding published bool

            std::getline(_istream >> std::ws, in_string);
            if (in_string == "true")
            {
                e_ptr->is_PUBLISHED = true;
            }
            else
            {
                e_ptr->is_PUBLISHED = false;
            }
            //                 
            int i = 0;
            e_ptr->questions.clear();
            while (std::getline(_istream >> std::ws, in_string))
            {
                question* temp_q = &e_ptr->questions[0];
                //  if (i != 0)
               //   {
                temp_q = new question();
                // e_ptr->questions.push_back(*(new question()));
         //    }
                temp_q->question_str = in_string;
                std::getline(_istream >> std::ws, in_string);
                if (in_string == "true")
                {
                    temp_q->is_test = true;
                }
                else
                {
                    temp_q->is_test = false;
                }
                _istream >> temp_q->time >> temp_q->score;
                if (temp_q->is_test)//its a test
                {
                    temp_q->change_to_test();
                    std::getline(_istream >> std::ws, in_string);
                    temp_q->a = in_string;
                    std::getline(_istream >> std::ws, in_string);
                    temp_q->b = in_string;
                    std::getline(_istream >> std::ws, in_string);
                    temp_q->c = in_string;
                    std::getline(_istream >> std::ws, in_string);
                    temp_q->d = in_string;
                    std::getline(_istream >> std::ws, in_string);
                    if (in_string == "a")
                    {
                        temp_q->currect_anwser = bp::posible_test_awnsers::a;
                    }
                    else if (in_string == "b")
                    {
                        temp_q->currect_anwser = bp::posible_test_awnsers::b;
                    }
                    else if (in_string == "c")
                    {
                        temp_q->currect_anwser = bp::posible_test_awnsers::c;
                    }
                    else if (in_string == "d")
                    {
                        temp_q->currect_anwser = bp::posible_test_awnsers::d;
                    }
                    else
                    {
                        temp_q->currect_anwser = bp::posible_test_awnsers::b;
                    }
                }
                else //its descriptive
                {
                    temp_q->change_to_descriptive();
                    std::getline(_istream >> std::ws, in_string);
                    temp_q->string_answer = in_string;
                }
                // if (i!=0)
               //  {
                e_ptr->questions.push_back(*(temp_q));
                //   }

                i++;
            }





        }
        //exam resaults
        void exam_resault_reload(std::istream* _istream_ptr, bool* _g_v_loaded_stu_score_exists)
        {
            std::vector<std::tuple<std::string, int>>* _g_v_loaded_student_scores=get_g_v_loaded_student_scores();   
            *_g_v_loaded_stu_score_exists = true;
            std::string in_string{};
            //start check
            std::getline(*_istream_ptr >> std::ws, in_string);
            if (in_string == "start")
            {
                _g_v_loaded_student_scores->clear();
                while (std::getline(*_istream_ptr >> std::ws, in_string))
                {
                    std::stringstream ss(in_string);
                    std::string temp_student_id;                    
                    int temp_student_score;
                    ss >> temp_student_id >> temp_student_score ;
                    _g_v_loaded_student_scores->push_back(std::make_tuple(temp_student_id, temp_student_score));
                    
                }
            }
            else
            {
                *_g_v_loaded_stu_score_exists = false;
                return;
            }
        }
        void exam_resault_save(std::ostream* _ostream_ptr )
        {
            std::vector<std::tuple<std::string, int>>* _g_v_loaded_student_scores=get_g_v_loaded_student_scores();            
            std::string out_string{"start\n"};//start check           
            
            int number = _g_v_loaded_student_scores->size();
            for (int i = 0; i < number; i++)
            {
                out_string += std::get<0>((*_g_v_loaded_student_scores)[i])+ ' ';
                out_string += std::to_string(std::get<1>((*_g_v_loaded_student_scores)[i])) + '\n';                
            }
            *_ostream_ptr << out_string;
        }
        //eteraz
        void eteraz_reload(std::istream* _istream_ptr, std::string* _g_v_loaded_eteraz, bool* _g_v_is_eteraz_loaded)
        {
            *_g_v_is_eteraz_loaded = true;
            std::string start_check;
            std::getline(*_istream_ptr >> std::ws, start_check);
            if (start_check != "start")
            {
                *_g_v_is_eteraz_loaded = false;
                return;
            }
            std::string input_str{};
            std::string temp_str{};
            while (std::getline(*_istream_ptr >> std::ws, temp_str))
            {
                input_str += temp_str + '\n';;
            }
            *_g_v_loaded_eteraz = input_str;
        }
        void eteraz_save(std::ostream* _ostream_ptr, std::string* _g_v_loaded_eteraz)
        {
            std::string out_str{};
            //adding start check str
            out_str += "start\n";
            out_str += *_g_v_loaded_eteraz;
            *_ostream_ptr << out_str;
        }
        void eteraz_codes_reload(std::istream* _istream_ptr, std::vector<int>* _g_v_loaded_eT_N_V, bool* _G_V_loaded_et_bool)
        {
            *_G_V_loaded_et_bool = true;
            std::string start_check;
            std::getline(*_istream_ptr >> std::ws, start_check);
            if (start_check != "start")
            {
                *_G_V_loaded_et_bool = false;
                return;
            }
            int number;
            *_istream_ptr >> number;
            //empty the loaded vector
            _g_v_loaded_eT_N_V->clear();
            if (number > 0)
            {
                int temp_int;
                for (int i = 0; i < number; i++)
                {
                    *_istream_ptr >> temp_int;
                    _g_v_loaded_eT_N_V->push_back(temp_int);
                }

            }
            else
            {
                *_G_V_loaded_et_bool = false;
                return;
            }
        }
        void eteraz_codes_save(std::ostream* _ostream_ptr, std::vector<int>* _g_v_loaded_eT_N_V)
        {
            std::string out_string{};
            //add start check srting
            out_string += "start" + '\n';
            int number = _g_v_loaded_eT_N_V->size();
            out_string += std::to_string(number) + '\n';
            for (int i = 0; i < number; i++)
            {
                *_ostream_ptr << (*_g_v_loaded_eT_N_V)[i] << '\n';
            }

        }
        //exam name
        void exam_name_load(void* ptr_istream, void* ptr_name, int* student_list_index = nullptr, bool studnet_mode = false)
        {
            std::string& _name = *((std::string*)ptr_name);
            std::istream& _istream = *((std::istream*)ptr_istream);
            _istream >> _name;
            if (studnet_mode)
            {
                _istream >> *student_list_index;
                //adding published bool
            std::string temp_in_string;
            std::getline(_istream >> std::ws, temp_in_string);            
            if (temp_in_string == "true")
            {
                (*get_exam_is_published_stu_mode())=true;
            }
            else
            {
                (*get_exam_is_published_stu_mode())=false;
            }
            //        
            }
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
            case bp::save_load_funcs::load_exam_name_and_sl_index:
                bp::file::exam_name_load(&_istream, _ptr, get_student_mode_slin(),true);
                break;
            case bp::save_load_funcs::students_list_load:
                bp::file::student_list_f_reaload(&_istream);
                break;
            case bp::save_load_funcs::students_list_n_l:
                bp::file::student_list_number_reload(&_istream, _ptr);
                break;
            case bp::save_load_funcs::sudent_exam_awnser_load:
                bp::file::sudent_exam_awnser_load(&_istream);
                break;
                case bp::save_load_funcs::exam_load_patcipater_list:
                bp::file::exam_load_patcipater_list(&_istream,(std::vector<std::string>*)_ptr);
                break;
                case bp::save_load_funcs::eteraz_reload:
                bp::file::eteraz_reload(&_istream,get_g_v_loaded_eteraz_string(),(bool*)_ptr);
                break;
                case bp::save_load_funcs::exam_resault_reload:
                bp::file::exam_resault_reload(&_istream,(bool*)_ptr);
                break;                
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
            case bp::save_load_funcs::sudent_exam_awnser_save:
                bp::file::sudent_exam_awnser_save(&_ostream,_ptr);
                break;
            case bp::save_load_funcs::exam_add_participater:
                bp::file::exam_add_participater(&_ostream,(std::string*)_ptr);
                break;
            case bp::save_load_funcs::eteraz_save:
                bp::file::eteraz_save(&_ostream,(std::string*)_ptr);
                break;
            case bp::save_load_funcs::exam_resault_save:
                bp::file::exam_resault_save(&_ostream);
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
bp::Array<simple_daneshjo>* students = nullptr;
int teachers_size = -1;
int students_size = -1;
//load and save files
namespace g_V
{
    bool exam_is_published_stu_mode=false;
    std::vector<std::tuple<std::string, int>> g_v_loaded_student_scores;
    std::string g_v_loaded_eteraz_string;
    std::vector<std::string> awnsers_str_ptr;
    std::string g_v_loaded_s_awnser_str;
    int student_mode_stu_l_index = 0;
    int loaded_exam_index = -1;
    int number_of_s_lists = 0;
    int number_of_exams = 0;
    void* loaded_exam = nullptr;
    bp::Array<int>* loaded_s_l = nullptr;
    void add_new_sho_da(bp::Array<int>& _sho_d_ha, int value, bool first_Q = false)
    {
        if (first_Q)
        {
            _sho_d_ha[0] = value;
        }
        else
        {
            _sho_d_ha.push(value);
        }

    }
    void creat_n_s_l()
    {
        bp::Array<int> sho_d_ha(1);
        bool keep_looping = true;
        {//scooped
            std::cout << "add fisrt student " << std::endl;
            int fisrt_value;
            std::cin >> fisrt_value;
            add_new_sho_da(sho_d_ha, fisrt_value, true);
        }
        while (keep_looping)
        {

            std::cout << "1: add one more student" << std::endl;
            std::cout << "0: save student list" << std::endl;
            int input;
            std::cin >> input;
            int other_input;
            if (input == 1)
            {
                std::cout << "adding one more student" << std::endl;
                //add student
                std::cin >> other_input;
                add_new_sho_da(sho_d_ha, other_input);
            }
            else
            {
                std::cout << "saving this student list" << std::endl;
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
                    std::string name = std::to_string(g_V::number_of_s_lists);
                    std::string file_path = "./student_lists/";
                    bp::handle_file(bp::save_load_funcs::students_list_save, name, bp::save_load_state::save, file_path, bp::delete_old_f_state::_delete, &sho_d_ha);
                }
                //update and save the number of student lists
                {
                    g_V::number_of_s_lists++;
                    std::string file_name = "student_lists_number";
                    std::string path = "./";
                    void* _Ptr = &g_V::number_of_s_lists;
                    handle_file(bp::save_load_funcs::students_list_n_s, file_name, bp::save_load_state::save, path, bp::delete_old_f_state::_delete, _Ptr);
                }
                keep_looping = false;
            }
        }

    }
 
    void edit_loaded_exam();
    void show_loaded_exam(bool teacher_view = true,std::string shomre_daneshjoii={})
    {
        if (loaded_exam)//an exam is loaded
        {
            bp::exam* e_ptr = (bp::exam*)loaded_exam;
            int exam_size = e_ptr->number_of_questions();
            std::cout << e_ptr->exam_name << std::endl;
            std::cout << "student list:" << e_ptr->exam_index << std::endl;
            for (int i = 0; i < exam_size; i++)
            {
                std::cout << "question " << i << ':' << std::endl;
                std::cout << "-----------------------------------------------" << std::endl;
                std::cout << e_ptr->questions[i].question_str << std::endl;
                std::cout << "max time :" << e_ptr->questions[i].time << std::endl;
                std::cout << "score :" << e_ptr->questions[i].score << std::endl;
                if (e_ptr->questions[i].is_test)///its test
                {

                    std::cout << "option a:" << e_ptr->questions[i].a << std::endl;
                    std::cout << "option b:" << e_ptr->questions[i].b << std::endl;
                    std::cout << "option c:" << e_ptr->questions[i].c << std::endl;
                    std::cout << "option d:" << e_ptr->questions[i].d << std::endl;
                    if (teacher_view)
                    {
                        char c_a;
                        switch (e_ptr->questions[i].currect_anwser)
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
                    if (teacher_view)
                    {
                        std::cout << "currect awnser :" << e_ptr->questions[i].string_answer << std::endl;
                    }
                }
                std::cout << "-----------------------------------------------" << std::endl;
            }
            e_ptr->calculate_t_score();
            e_ptr->calculate_t_time();
            std::cout<<"exam time:"<<e_ptr->total_time<<std::endl;
            std::cout<<"exam score:"<<e_ptr->total_score<<std::endl;
            std::cout << std::endl << std::endl;
            if (teacher_view)
            {
                edit_loaded_exam();
            }
            else
            {
                
                
                //awnser the questions
                std::vector<std::string> awnser_vector(exam_size);
                for (int i = 0; i < exam_size; i++)
                {
                    awnser_vector[i]={};
                }          
                //staring the timer
                const auto start{ std::chrono::steady_clock::now() };          
                while (true)
                {
                    std::cout<<"-1:submit exam"<<'\n';
                    std::cout<<"awnser questions with this tempelete"<<'\n';
                    std::cout<<"question_number awnser+enter_key"<<'\n';
                    std::cout<<"if its a test question right the currect test option insted of awnser text"<<std::endl;

                    int input;
                    std::cin>>input;
                    if (input==-1)
                    {
                       //exit the loop
                       break;
                    }
                    if (input<exam_size)
                    {
                       
                       std::string string_awnser{};
                       std::getline(std::cin>>std::ws,string_awnser);
                        awnser_vector[input]=string_awnser;
                        std::cout<<"-----------------------\n"<<std::endl<<"set question "<<input<<"'s awser to "<<string_awnser<<std::endl<<"-----------------------\n";
                    }
                    else
                    {
                        std::cout<<"-----------------------\n"<<std::endl<<"invalid question number"<<std::endl<<"-----------------------\n"<<std::endl;
                    }                 
                                      
                }
                const auto end{ std::chrono::steady_clock::now() };
                const std::chrono::duration<double> elapsed_seconds{ end - start };
                if (elapsed_seconds.count()<((e_ptr->total_time*60)+10))
                {
                    (*get_g_v_awnsers_str_ptr())=awnser_vector;
                }
                else
                {
                    for (int i = 0; i < exam_size; i++)
                    {
                    awnser_vector[i]={};
                    } 
                    (*get_g_v_awnsers_str_ptr())=awnser_vector;
                }
                //now handle file
                {
                    std::string file_name="exam"+std::to_string(g_V::loaded_exam_index)+"student"+shomre_daneshjoii;
                    std::string path="./exam_student_awnsers/";
                    bp::handle_file(bp::save_load_funcs::sudent_exam_awnser_save,file_name,bp::save_load_state::save,path,bp::_delete,e_ptr);
                }
                //add student to participated students
                {
                std::string file_name="exam"+std::to_string(g_V::loaded_exam_index)+"participaters";
                std::string path="./exam_participaters/";
                bp::handle_file(bp::save_load_funcs::exam_add_participater,file_name,bp::save_load_state::save,path,bp::delete_old_f_state::dont_delete,&shomre_daneshjoii);
                }
            }
        }
        else // its nullptr and not loaded
        {
            std::cout << "no exam is loaded" << std::endl;
        }

    }
    void show_loaded_s_l()
    {
        bp::Array<int>* ptr = (bp::Array<int>*)g_V::loaded_s_l;
        int size = ptr->get_size();
        for (int i = 0; i < size; i++)
        {
            std::cout << "student" << i << ": " << ptr->operator[](i) << std::endl;
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
        std::string file_name = "exam" + std::to_string(g_V::loaded_exam_index);
        std::string _path = "./exams/";
        handle_file(bp::save_load_funcs::exam_save, file_name, bp::save_load_state::save, _path, bp::delete_old_f_state::_delete, g_V::loaded_exam);
    }
    void edit_loaded_exam()
    {
        bool changed = false;
        std::cout << "do you like to add changes to this exam?(y/n)" << std::endl;
        char input;
        std::cin >> input;
        switch (input)
        {
        case 'y':
            break;
        case 'n':
            return;
            break;
        default:
            std::cout << "invalid command" << std::endl;
            return;
            break;
        }
        while (true)
        {
            if (changed)
            {
                std::cout << "0:save and go back to dashboard" << std::endl;
            }
            else
            {
                std::cout << "0:go back to dashboard" << std::endl;
            }
            std::cout << "1:change change publicity" << std::endl;
            std::cout << "2:change student list index" << std::endl;
            int input;
            std::cin >> input;
            char char_input;
            int other_int_input;
            switch (input)
            {
            case 0:
                if (changed)
                {
                    std::cout << "saving changes" << std::endl;
                    save_loaded_exam();
                }
                std::cout << "going back to dashborad" << std::endl;
                return;
                break;
            case 1:
                std::cout << "change publicity to(t/f):";
                std::cin >> char_input;
                if (char_input == 't')
                {

                    if (((bp::exam*)g_V::loaded_exam)->is_PUBLISHED != true)
                    {
                        changed = true;
                        ((bp::exam*)g_V::loaded_exam)->is_PUBLISHED = true;
                    }
                }
                else
                {
                    if (((bp::exam*)g_V::loaded_exam)->is_PUBLISHED != false)
                    {
                        changed = true;
                        ((bp::exam*)g_V::loaded_exam)->is_PUBLISHED = false;
                    }

                }
                break;
            case 2:
                std::cout << "enter new student list index:";
                std::cin >> other_int_input;
                if (((bp::exam*)g_V::loaded_exam)->exam_index != other_int_input)
                {
                    changed = true;
                    ((bp::exam*)g_V::loaded_exam)->exam_index = other_int_input;
                }
                break;
            default:
                std::cout << "invalid command" << std::endl;
                if (changed)
                {
                    std::cout << "saving changes" << std::endl;
                    save_loaded_exam();
                }
                std::cout << "going back to dashborad" << std::endl;
                return;
                break;
            }
        }

    }

    std::string* exam_names = nullptr;
};
//
int* get_student_mode_slin()
{
    return &g_V::student_mode_stu_l_index;
}
bool* get_exam_is_published_stu_mode()
{
    return &g_V::exam_is_published_stu_mode;
}
std::string* get_g_v_loaded_s_awnser_str()
{
    return &g_V::g_v_loaded_s_awnser_str;
}
std::string* get_g_v_loaded_eteraz_string()
{
    return &g_V::g_v_loaded_eteraz_string;
}
std::vector<std::string>* get_g_v_awnsers_str_ptr()
{
    return &g_V::awnsers_str_ptr;
}
std::vector<std::tuple<std::string,int>>* get_g_v_loaded_student_scores()
{
    return &g_V::g_v_loaded_student_scores;
}

void bp::set_loaded_s_l(bp::Array<int>& temp_s_list)
{
    if ((bp::Array<int>*)g_V::loaded_s_l)
    {
        delete (bp::Array<int>*)g_V::loaded_s_l;
    }
    g_V::loaded_s_l = new bp::Array<int>(temp_s_list);
}
void* clear_loaded_exam()
{
    if ((bp::exam*)g_V::loaded_exam)
    {
        delete (bp::exam*)g_V::loaded_exam;
    }
    g_V::loaded_exam = new bp::exam;
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
    bp::Array<simple_daneshjo> _students(_students_size);
    for (int i = 0; i < _students_size; i++)
    {
        std::string temp_name = "student";
        temp_name += std::to_string(i);
        std::string temp_password = "pass";
        temp_password += std::to_string(i);
        simple_daneshjo temp_person(i, temp_name, temp_password);
        _students.push(temp_person);
    }
    //seting up the login system
    teachers = &_teachers;
    students = &_students;
    teachers_size = _teachers_size;
    students_size = _students_size;

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
                    enter_dashboard(false, &students->operator[](i));
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
void load_studnt_list_n_f()
{
    std::string file_name = "student_lists_number";
    std::string file_path = "./";
    void* _ptr = &g_V::number_of_s_lists;
    handle_file(bp::save_load_funcs::students_list_n_l, file_name, bp::save_load_state::load, file_path, bp::delete_old_f_state::dont_delete, _ptr);
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
    std::vector<std::string> partisipaters_list;
    if (is_teacher)
    {
        bool keep_loop_going = true;
        
        int size;        
        bool eteraz_existed;
        bool found_student_in_score_lists;
        while (keep_loop_going)
        {
            std::cout << "-1 : log out and exit application" << '\n';
            std::cout << "0 : log out" << '\n';
            std::cout << "1 : creat a new exam" << '\n';
            std::cout << "2 : exam history" << '\n';
            std::cout << "3 : student lists" << '\n';
           //std::cout << "4 : exam resualts" << std::endl;
            std::cout << "4 : create new student list" << std::endl;
            std::cout << "5 : see student awnsers"<<std::endl;
            std::cout << "6 : see student ranks"<<std::endl;
            int command;
            std::cin >> command;
            int other_input;   
            int other_other_int_input;   
            bool student_score_file_exists=false;  
            std::tuple<std::string,int> temp_sort_tuple;    
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
                    if (g_V::exam_names)
                    {
                        delete[]g_V::exam_names;
                    }
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
                if (!(other_input<g_V::number_of_exams))
                {
                    std::cout<<"invalid index going back"<<std::endl;
                    break;
                }
                //load that exam
                {
                    g_V::loaded_exam_index = other_input;
                    std::string file_name = "exam" + std::to_string(other_input);
                    std::string file_path = "./exams/";
                    if (((bp::exam*)g_V::loaded_exam))
                    {
                        delete ((bp::exam*)g_V::loaded_exam);
                    }
                    g_V::loaded_exam = new bp::exam(1);
                    handle_file(bp::save_load_funcs::exam_load, file_name, bp::save_load_state::load, file_path, bp::delete_old_f_state::dont_delete, g_V::loaded_exam);
                }
                //show show that exam to the user
                g_V::show_loaded_exam();
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
                std::cout << i << " :" << "studentlist " << i<<std::endl;
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
            case 4:
                g_V::creat_n_s_l();
                break;
            case 5:
             //exam history                
                //load exam number file
                load_e_n_f();
                //load that number of exam names
                {
                    if (g_V::exam_names)
                    {
                        delete[]g_V::exam_names;
                    }
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
                if (other_input<g_V::number_of_exams)
                {
                    {
                        std::string file_name="exam"+std::to_string(other_input)+"participaters";
                        std::string file_path="./exam_participaters/";
                        partisipaters_list.clear();
                        bp::handle_file(bp::exam_load_patcipater_list,file_name,bp::save_load_state::load,file_path,bp::delete_old_f_state::dont_delete,&partisipaters_list);
                    }
                    size=partisipaters_list.size();
                    if (!size)
                    {
                        std::cout<<"found no avalable options"<<std::endl<<"going back"<<std::endl;
                        break;
                    }                    
                    std::cout<<"choose one"<<std::endl;
                    for (int i = 0; i < size; i++)
                    {
                        std::cout<<i<<":shomaredaneshjoi:"<<partisipaters_list[i]<<std::endl;
                    }
                    std::cin>>other_input;
                    if (other_input<size)
                    {
                        {
                            std::string file_name="exam"+std::to_string(other_input)+"student"+partisipaters_list[other_input];
                            std::string file_path="./exam_student_awnsers/";
                            bp::handle_file(bp::save_load_funcs::sudent_exam_awnser_load,file_name,bp::save_load_state::load,file_path,bp::delete_old_f_state::dont_delete);                            
                        }
                        std::cout<<"------------------------\n"<<*get_g_v_loaded_s_awnser_str()<<"------------------------\n"<<std::endl;
                        //check if "eterazz"
                        {
                            std::string file_name="exam"+std::to_string(other_input)+"student"+partisipaters_list[other_input]+"eteraz";
                            std::string file_path="./exam_eterazha/";
                            bp::handle_file(bp::save_load_funcs::eteraz_reload,file_name,bp::save_load_state::load,file_path,bp::delete_old_f_state::dont_delete,&eteraz_existed);
                        }
                        if (eteraz_existed)
                        {
                           std::cout<<"eteraz:"<<std::endl;
                           std::cout<<"------------------------\n"<<*get_g_v_loaded_eteraz_string()<<"------------------------\n"<<std::endl;
                        }
                        else
                        {
                           std::cout<<"hasent found a \"eteraz\" file"<<std::endl;
                        }
                        std::cout<<"score?(-1:going back):";
                        std::cin>>other_other_int_input;
                        if (other_other_int_input==-1)
                        {
                            std::cout<<"going back"<<std::endl;
                            break;
                        }
                        else
                        {
                            //load student score list file
                            //get_g_v_loaded_student_scores
                            {
                                std::string file_name="exam"+std::to_string(other_input)+"scores";
                                std::string file_path="./exam_student_scores/";
                                bp::handle_file(bp::save_load_funcs::exam_resault_reload,file_name,bp::save_load_state::load,file_path,bp::delete_old_f_state::dont_delete,&student_score_file_exists);
                            }
                            if (student_score_file_exists)
                            {
                                //search for student
                                size=get_g_v_loaded_student_scores()->size();
                                found_student_in_score_lists=false;
                                for (int i = 0; i < size; i++)
                                {
                                    if (partisipaters_list[other_input]==std::get<0>((*get_g_v_loaded_student_scores())[i]))
                                    {
                                        found_student_in_score_lists=true;
                                        (*get_g_v_loaded_student_scores())[i]=std::make_tuple(partisipaters_list[other_input],other_other_int_input);                                        
                                        break;
                                    }                                    
                                }
                                if (!found_student_in_score_lists)///add that manually
                                {
                                    get_g_v_loaded_student_scores()->push_back(std::make_tuple(partisipaters_list[other_input],other_other_int_input));
                                }                               
                                
                            }
                            else//it dosent exist its new
                            {
                            get_g_v_loaded_student_scores()->clear();
                            get_g_v_loaded_student_scores()->push_back(std::make_tuple(partisipaters_list[other_input],other_other_int_input));
                            }
                            //now save it to the file
                            {
                                std::string file_name="exam"+std::to_string(other_input)+"scores";
                                std::string file_path="./exam_student_scores/";
                                bp::handle_file(bp::save_load_funcs::exam_resault_save,file_name,bp::save_load_state::save,file_path,bp::delete_old_f_state::_delete);
                            }
                            std::cout<<"set score to "<<other_other_int_input<<'\n'<<"going back"<<std::endl;
                        }
                            
                    }                    
                    else
                    {
                        std::cout<<"invalid index going back"<<std::endl;
                    }
                }
                else
                {
                    std::cout<<"invalid index going back"<<std::endl;
                    break;
                }
                
            break;
            case 6:
              //exam history                
                //load exam number file
                load_e_n_f();
                //load that number of exam names
                {
                    if (g_V::exam_names)
                    {
                        delete[]g_V::exam_names;
                    }
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
                //load that exam student score file
                if (other_input<g_V::number_of_exams)
                {
                    //cehck for files existtence
                    {
                        std::string file_name="exam"+std::to_string(other_input)+"scores";
                        std::string file_path="./exam_student_scores/";
                        bp::handle_file(bp::save_load_funcs::exam_resault_reload,file_name,bp::save_load_state::load,file_path,bp::delete_old_f_state::dont_delete,&student_score_file_exists);
                    }
                    if (student_score_file_exists)
                    {
                       //sort the list
                       size=get_g_v_loaded_student_scores()->size();
                       for (int i = 0; i < size; i++)
                       {
                        for (int j = i+1; j < size; j++)
                        {
                            if (std::get<1>((*get_g_v_loaded_student_scores())[i])>std::get<1>((*get_g_v_loaded_student_scores())[j]))
                            {
                                temp_sort_tuple=(*get_g_v_loaded_student_scores())[i];
                                (*get_g_v_loaded_student_scores())[i]=(*get_g_v_loaded_student_scores())[j];
                                (*get_g_v_loaded_student_scores())[j]=temp_sort_tuple;
                            }
                            
                        }                        
                       }
                       //show the list
                       std::cout<<"------------------------"<<std::endl;
                       for (int i = 0; i < size; i++)
                       {
                        std::cout<<"student"<<std::get<0>((*get_g_v_loaded_student_scores())[i])<<": "<<std::to_string(std::get<1>((*get_g_v_loaded_student_scores())[i]))<<std::endl;
                       }                       
                    }
                    else
                    {
                        std::cout<<"this exam dosent have a student_score file\n"<<"going back"<<std::endl;
                    }
                    
                }
                else
                {
                    std::cout<<"invalid index going back"<<std::endl;
                    break;
                }
                std::cout<<"------------------------\n"<<"going back"<<std::endl;
            break;
            default:
                std::cout << "invalid command. try again" << std::endl;
                break;
            }
        }
    }
    else //its a student
    {
        bool keep_loop_going = true;
        while (keep_loop_going)
        {
            std::cout << "-1 : log out and exit application" << '\n';
            std::cout << "0 : log out" << '\n';
            std::cout << "1 : participate in an exam" << '\n';
            std::cout << "2 : exam history" << '\n';
            std::cout << "3 : sabte eteraz" << '\n';
            std::cout << "4 : expierd exams" <<std::endl;
            int command;
            std::cin >> command;
            int other_input;
            std::vector<int> _student_mode_exam_vector;
            std::vector<int> _stu_l_vector;
            int stundet_id = ((simple_daneshjo*)_persone)->shomare_daneshjoii;
            bool found_currect_number = false;
            int size;
            std::string file_name;
            std::string _path = "./student_lists/";
            std::string _exam_name = {};
            //shomare daneshjoii
            std::string _shomare_danseshjoii{std::to_string(((simple_daneshjo*)_persone)->shomare_daneshjoii)};
            std::vector<int> history_index_vector;
            int int_st_input;
            int size_of_indexes;
            bool eteraz_exists=false;
            std::string eteraz_save_string;
            int size_size;
            bool is_in_participaters=false;
            int expired_exams_count=0;
            bool allready_done_that_exam=false;
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
                //participate in an exam
                //load all studnet list and see which on this student is in
                //create a vector of maching student lists

                //load exam number file
                load_studnt_list_n_f();
                //load that many studnet lists
                for (int i = 0; i < g_V::number_of_s_lists; i++)
                {
                    file_name = std::to_string(i);                   

                    handle_file(bp::save_load_funcs::students_list_load, file_name, bp::save_load_state::load, _path, bp::delete_old_f_state::dont_delete);
                    size = g_V::loaded_s_l->get_size();
                    for (int j = 0; j < size; j++)
                    {
                        if ((*(g_V::loaded_s_l))[j] == stundet_id)
                        {
                            _stu_l_vector.push_back(i);
                            break;
                        }

                    }
                }
                //load exam number file
                load_e_n_f();
                //load that number of exam names
                {
                    if (g_V::exam_names)
                    {
                        delete[]g_V::exam_names;
                    }
                    g_V::exam_names = new std::string[g_V::number_of_exams];

                    void* _ptr = &_exam_name;
                    for (int i = 0; i < g_V::number_of_exams; i++)
                    {
                        file_name = "exam";
                        file_name += std::to_string(i);
                        std::string _path = "./exams/";
                        handle_file(bp::save_load_funcs::load_exam_name_and_sl_index, file_name, bp::save_load_state::load, _path, bp::delete_old_f_state::dont_delete, _ptr);
                        g_V::exam_names[i] = _exam_name;
                        size = _stu_l_vector.size();
                        int loaded_exam_studnet_list = *get_student_mode_slin();
                        for (int j = 0; j < size; j++)
                        {
                            //now we check if allready havent done that
                            if ((loaded_exam_studnet_list == _stu_l_vector[j]) &&(*get_exam_is_published_stu_mode()))
                            {
                                
                                std::string file_name{"exam"+std::to_string(i)+"participaters"};                        
                                std::string _path = "./exam_participaters/";
                                std::vector<std::string> participater_list;
                                handle_file(bp::save_load_funcs::exam_load_patcipater_list, file_name, bp::save_load_state::load, _path, bp::delete_old_f_state::dont_delete,&participater_list);
                                int size=participater_list.size();
                                allready_done_that_exam=false;
                                for (int j = 0; j < size; j++)
                                {
                                  if (_shomare_danseshjoii==participater_list[j])
                                    {
                                        allready_done_that_exam=true;
                                        break;
                                    }                            
                                }  
                                if (!allready_done_that_exam)
                                {
                                    _student_mode_exam_vector.push_back(i);
                                     break;
                                }                                  
                                break;
                            }

                        }

                    }
                }



                //show that many number of exams
                //show the exam names
                size = _student_mode_exam_vector.size();
                if (!size)
                {
                    std::cout << "dident find any unpurticipated exam" << std::endl;
                    std::cout << "going back" << std::endl;
                    break;
                }
                std::cout << "-1 :go back" << std::endl;
                std::cout << "exams:" << std::endl;
                
                
                for (int i = 0; i < size; i++)
                {
                    std::cout << i << " :" << _student_mode_exam_vector[i] << std::endl;
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

                    for (int i = 0; i < size; i++)
                    {
                        if (other_input == _student_mode_exam_vector[i])
                        {
                            found_currect_number = true;
                            g_V::loaded_exam_index = other_input;
                            std::string file_name = "exam" + std::to_string(other_input);
                            std::string file_path = "./exams/";
                            if (((bp::exam*)g_V::loaded_exam))
                            {
                                delete ((bp::exam*)g_V::loaded_exam);
                            }
                            g_V::loaded_exam = new bp::exam(1);
                            handle_file(bp::save_load_funcs::exam_load, file_name, bp::save_load_state::load, file_path, bp::delete_old_f_state::dont_delete, g_V::loaded_exam);
                            //show show that exam to the user
                            g_V::show_loaded_exam(false,std::to_string(((simple_daneshjo*)_persone)->shomare_daneshjoii));
                            break;
                        }
                    }
                }
                if (!found_currect_number)
                {
                    std::cout << "going back" << std::endl;
                }
                break;
                case 2:
                //exam history
                //load exam number file
                load_e_n_f();
                //load that number of exam_patricipater_list files and add them if necessary                     
                    history_index_vector.clear();
                 for (int i = 0; i < g_V::number_of_exams; i++)
                    {
                        std::string file_name{"exam"+std::to_string(i)+"participaters"};                        
                        std::string _path = "./exam_participaters/";
                        std::vector<std::string> participater_list;
                        handle_file(bp::save_load_funcs::exam_load_patcipater_list, file_name, bp::save_load_state::load, _path, bp::delete_old_f_state::dont_delete,&participater_list);
                        int size=participater_list.size();
                        for (int j = 0; j < size; j++)
                        {
                            if (_shomare_danseshjoii==participater_list[j])
                            {
                                history_index_vector.push_back(i);
                                break;
                            }
                            
                        }                                                
                    }
                    //show exam_history avalible indexes                    
                     size_of_indexes=history_index_vector.size();
                     if (!size_of_indexes)
                     {
                        std::cout<<"no available exam found for your request"<<std::endl;
                        break;
                     }
                     
                    for (int i = 0; i < size_of_indexes; i++)
                    {
                        std::cout<<i<<':'<<"esam"<<history_index_vector[i]<<std::endl;
                    }
                    //now let them choose which they want to show on the screen
                    
                    std::cin>>int_st_input;
                    if (int_st_input<size_of_indexes)
                    {
                        //now handle file
                        {
                            file_name="exam"+std::to_string(history_index_vector[int_st_input])+"student"+_shomare_danseshjoii;
                            _path="./exam_student_awnsers/";
                            bp::handle_file(bp::save_load_funcs::sudent_exam_awnser_load,file_name,bp::load,_path,bp::delete_old_f_state::dont_delete);
                            std::cout<<"-------------------------"<<std::endl<<(*get_g_v_loaded_s_awnser_str())<<"-------------------------"<<std::endl;
                            std::cout<<"going back"<<std::endl;
                        }
                    }
                    else
                    {
                        std::cout<<"invalid index going back"<<std::endl;
                    }
                    
                break;
                case 3:
                //exam eteraz
                 //load exam number file
                load_e_n_f();
                //load that number of exam_patricipater_list files and add them if necessary                     
                    history_index_vector.clear();
                 for (int i = 0; i < g_V::number_of_exams; i++)
                    {
                        std::string file_name{"exam"+std::to_string(i)+"participaters"};                        
                        std::string _path = "./exam_participaters/";
                        std::vector<std::string> participater_list;
                        handle_file(bp::save_load_funcs::exam_load_patcipater_list, file_name, bp::save_load_state::load, _path, bp::delete_old_f_state::dont_delete,&participater_list);
                        int size=participater_list.size();
                       
                        for (int j = 0; j < size; j++)
                        {
                            if (_shomare_danseshjoii==participater_list[j])
                            {
                                //now we haveto check if we havent done that yet
                                {
                                    std::string file_name{"exam"+std::to_string(i)+"student"+_shomare_danseshjoii+"eteraz"};                        
                                    std::string _path = "./exam_eterazha/";
                                    bp::handle_file(bp::save_load_funcs::eteraz_reload,file_name,bp::save_load_state::load,_path,bp::delete_old_f_state::dont_delete,&eteraz_exists);
                                    if (!eteraz_exists)
                                    {
                                        history_index_vector.push_back(i);
                                    }                                    
                                }
                                
                                break;
                            }
                            
                        } 
                    }
                        //show exam_history avalible indexes                    
                     size_of_indexes=history_index_vector.size();
                      if (!size_of_indexes)
                        {
                        std::cout<<"no available exam found for your request"<<std::endl;
                        break;
                         }
                    for (int i = 0; i < size_of_indexes; i++)
                    {
                        std::cout<<i<<':'<<"esam"<<history_index_vector[i]<<"eteraz"<<std::endl;
                    }
                    //now let them choose which they want to show on the screen                    
                    std::cin>>int_st_input;
                    if (int_st_input<size_of_indexes)
                    {
                        std::cout<<"enter what you want to save +enterkey:"<<std::endl;
                        std::getline(std::cin>>std::ws,eteraz_save_string);
                        //now handle file
                        {
                            std::string file_name{"exam"+std::to_string(history_index_vector[int_st_input])+"student"+_shomare_danseshjoii+"eteraz"};                        
                            std::string _path = "./exam_eterazha/";
                            bp::handle_file(bp::save_load_funcs::eteraz_save,file_name,bp::save_load_state::save,_path,bp::delete_old_f_state::_delete,&eteraz_save_string);                                                     
                        }
                        std::cout<<'\n'<<"------------------------"<<'\n'<<eteraz_save_string<<'\n'<<"------------------------"<<'\n'<<"going back"<<std::endl;
                    }
                    else
                    {
                        std::cout<<"invalid index going back"<<std::endl;
                    }
                    break;
                case 4:
                std::cout<<"-------------------------------"<<std::endl;
                 //load exam number file
                load_e_n_f();
                //load that number of exam names
                {
                    if (g_V::exam_names)
                    {
                        delete[]g_V::exam_names;
                    }
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
                std::cout << "expired exams:" << std::endl;
                expired_exams_count=0;
                for (int i = 0; i < g_V::number_of_exams; i++)
                {
                    //now cwe see if its expired or not
                    //load that exam
                    {
                        g_V::loaded_exam_index = i;
                        std::string file_name = "exam" + std::to_string(i);
                        std::string file_path = "./exams/";
                        if (((bp::exam*)g_V::loaded_exam))
                        {
                            delete ((bp::exam*)g_V::loaded_exam);
                        }
                        g_V::loaded_exam = new bp::exam(1);
                        handle_file(bp::save_load_funcs::exam_load, file_name, bp::save_load_state::load, file_path, bp::delete_old_f_state::dont_delete, g_V::loaded_exam);
                    }
                   if(!(((bp::exam*)g_V::loaded_exam)->is_PUBLISHED))
                   {
                    //more ifs
                    {
                        std::string file_name="exam"+std::to_string(i)+"participaters";
                        std::string file_path="./exam_participaters/";
                        partisipaters_list.clear();
                        bp::handle_file(bp::exam_load_patcipater_list,file_name,bp::save_load_state::load,file_path,bp::delete_old_f_state::dont_delete,&partisipaters_list);
                    }
                    is_in_participaters=false;
                    for (int i = 0; i < partisipaters_list.size(); i++)
                    {
                        if (partisipaters_list[i]==_shomare_danseshjoii)
                        {
                            is_in_participaters=true;
                            break;
                        }
                        
                    }
                    if (!is_in_participaters)
                    {
                        expired_exams_count++;
                        std::cout << i << " :" << g_V::exam_names[i] << std::endl;
                    }                    
                   }
                    
                }
                if (!expired_exams_count)
                {
                   std::cout<<"there wasent any expired exam here"<<std::endl;
                }
                std::cout<<"-------------------------------"<<std::endl;
                break;
            default:
                std::cout << "invalid command. try again" << std::endl;
                break;
            }
        }
    }



}
