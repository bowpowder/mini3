#include <iostream>
#include <string>

using namespace std;

class questions
{
protected:
    bool test = false;
    char type, ans;
    int a, b, c, d, score, time;
    string question, answer;

public:
    void kind()
    {
        cout << "is it a test?(y/n)\n";
        cin >> type;
        switch (type)
        {
        case 'y':
        {
            test = true;
            break;
        }
        case 'n':
        {
            test = false;
            break;
        }
        default:
        {
            cout << "please type y or n\n";
            break;
        }
        }
    }
    void set()
    {
        if (test)
        {
            cout << "write the qustion\n";
            getline(cin >> ws, question);
            cout << "write options\n";
            cin >> a >> b >> c >> d;
            cout << "choose correct answer\n";
            cin >> ans;
        }
        else if (!test)
        {
            cout << "write the qustion\n";
            getline(cin >> ws, question);
            cout << "write the answer\n";
            getline(cin >> ws, answer);
        }
        cout << "Enter the score of question\n";
        cin >> score;
        cout << "Enter the question time";
        cin >> time;
    }
};
class exam 
{
    int tscore, ttime;

public:
    exam()
    {
        cout << "Enter the exam time";
        cin >> ttime;
        cout << "Enter the exam score";
        cin >> tscore;
    }
};
int main()
{
    int n;
    cout << "Enter the number of questions";
    cin >> n;
    questions num[n];
    for (int i = 0; i < n; i++)
    {
        num[i].kind();
        num[i].set();
    };
    exam total;
    return 0;
}