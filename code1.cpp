#include <iostream>
#include <string>
namespace bp
{
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
   question(bool _is_test=false,int _score=0,int _time=0,std::string _question_str={}):is_test(_is_test),score(_score),time(_time),question_str(_question_str),t_Or_d_question(nullptr)
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
};
class exam 
{
    int total_score, total_time;
    int number_of_questions;
    question* questions;
public:
    exam(int _number_of_questions=1, int _total_score=0,int _total_time=0):questions(nullptr),total_score(_total_score),total_time(_total_time)
    {

    }
    ~exam()
    {
    delete[] questions;
    }
 };
};

int main()
{ 
}
