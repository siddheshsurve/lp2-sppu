#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the name of the Employee" << endl;
    string name, domain, gender;
    int n1, n2, n3, n4, n5, n6, n7, n8;
    cin >> name;
    cout << "In which domain " << name << " is working (web/testing/design)" << endl;
    cin >> domain;
    cout << "What is the gender of " << name << " (M/F)" << endl;
    cin >> gender;
    cout << "Lets evaluate the performance of " << name << " " << endl;
    cout << endl;
    cout << "What is the number of tasks successfully completed by " << name << " out of 10" << endl;
    cin >> n1;
    cout << "What is the average hours " << name << " has worked each week " << endl;
    cin >> n2;
    cout << "What is the salary of " << name << " per year " << endl;
    cin >> n3;
    cout << "What is the previous rating of " << name << " out of 5 " << endl;
    cin >> n4;
    cout << "How many presentation does " << name << " given last year" << endl;
    cin >> n5;
    cout << "What is the age of the employee" << endl;
    cin >> n6;
    cout << "What is the experience of " << name << " " << endl;
    cin >> n7;
    cout << "How many leave " << name << " has taken last year" << endl;
    cin >> n8;
    int rat = 0;

    if (n5 >= 10)
    {
        rat++;
    }
    if (n8 <= 20)
    {
        rat++;
    }
    if (n1 > 8)
    {
        rat += 2;
    }
    if (n2 > 49)
    {
        rat++;
    }
    cout << "The evaluation of " << name << endl;
    cout << "This year rating is " << rat << endl;

    if (gender == "M")
    {
        if (domain == "web")
        {
            if (n2 >= 37 and n1 >= 7)
            {
                if (n3 <= 800000)
                {
                    cout << "Acccording to the performance of " << name << " the salaray should be incremented by 100000" << endl;
                }

                else
                {
                    cout << "Acccording to the performance of " << name << " the salaray should remain same" << endl;
                }
            }
            else
            {
                if (n3 >= 1500000)
                {
                    cout << "Acccording to the performance of " << name << " the salaray should be decremented by 100000" << endl;
                }
                else
                {
                    cout << "Acccording to the performance of " << name << " the salaray should remain same" << endl;
                }
            }
        }
        else if (domain == "testing")
        {
            if (n2 >= 40 and n1 > 8)
            {
                if (n3 <= 500000)
                {
                    cout << "Acccording to the performance of " << name << " the salaray should be incremented by 100000" << endl;
                }

                else
                {
                    cout << "Acccording to the performance of " << name << " the salaray should remain same" << endl;
                }
            }
            else
            {
                if (n3 >= 1000000)
                {
                    cout << "Acccording to the performance of " << name << " the salaray should be decremented by 100000" << endl;
                }
                else
                {
                    cout << "Acccording to the performance of " << name << " the salaray should remain same" << endl;
                }
            }
        }
        else if (domain == "design")
        {
            if (n2 >= 37 and n1 > 6)
            {
                if (n3 <= 1000000)
                {
                    cout << "Acccording to the performance of " << name << " the salaray should be incremented by 100000" << endl;
                }

                else
                {
                    cout << "Acccording to the performance of " << name << " the salaray should remain same" << endl;
                }
            }
            else
            {
                if (n3 > 1800000)
                {
                    cout << "Acccording to the performance of " << name << " the salaray should be decremented by 100000" << endl;
                }
                else
                {
                    cout << "Acccording to the performance of " << name << " the salaray should remain same" << endl;
                }
            }
        }
        if (rat > n4)
        {
            cout << "The rating of " << name << " has increased. He has performed well this year" << endl;
        }
        else if (rat < n4 and n6 < 25)
        {
            cout << "The employee has underperformed but can be trained for effective performance" << endl;
        }
        else if (rat < n4 and n6 > 25)
        {
            cout << "The employee has underperformed and proved to be unproductive for the company" << endl;
        }
        else
        {
            cout << "The performance of the employee is maintained" << endl;
        }
        if (n7 > 8 and n4 == 5)
        {
            cout << name << " should get a promotion in the company" << endl;
        }
    }
    if (gender == "F")
    {
        if (domain == " web")
        {
            if (n2 >= 30 and n1 > 7)
            {
                if (n3 <= 800000)
                {
                    cout << "Acccording to the performance of " << name << " the salaray should be incremented by 100000" << endl;
                }
                else if (n3 >= 1500000)
                {
                    cout << "Acccording to the performance of " << name << " the salaray should be decremented by 100000" << endl;
                }
                else
                {
                    cout << "Acccording to the performance of " << name << " the salaray should remain same" << endl;
                }
            }
        }
        else if (domain == " testing")
        {
            if (n2 >= 35 and n1 > 8)
            {
                if (n3 <= 500000)
                {
                    cout << "Acccording to the performance of " << name << " the salaray should be incremented by 100000" << endl;
                }
                else if (n3 >= 1000000)
                {
                    cout << "Acccording to the performance of " << name << " the salaray should be decremented by 100000" << endl;
                }
                else
                {
                    cout << "Acccording to the performance of " << name << " the salaray should remain same" << endl;
                }
            }
        }
        else if (domain == " design")
        {
            if (n2 >= 32 and n1 > 6)
            {
                if (n3 <= 1000000)
                {
                    cout << "Acccording to the performance of " << name << " the salaray should be incremented by 100000" << endl;
                }
                else if (n3 > 1800000)
                {
                    cout << "Acccording to the performance of " << name << " the salaray should be decremented by 100000" << endl;
                }
                else
                {
                    cout << "Acccording to the performance of " << name << " the salaray should remain same" << endl;
                }
            }
        }
        if (rat > n4)
        {
            cout << "The rating of " << name << " has increased. He has performed well this year" << endl;
        }
        else if (rat < n4 and n6 < 25)
        {
            cout << "The employee has underperformed but can be trained for effective performance" << endl;
        }
        else if (rat < n4 and n6 > 25)
        {
            cout << "The employee has underperformed and proved to be unproductive for the company" << endl;
        }
        else
        {
            cout << "The performance of the employee is maintained" << endl;
        }
        if (n7 > 8 and n4 == 5)
        {
            cout << name << " should get a promotion in the company" << endl;
        }
    }
}