#include <iostream>
#include<string>
class person
{
private:
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
    std::cout<<"hello wrold"<<std::endl;
    return 0;
}