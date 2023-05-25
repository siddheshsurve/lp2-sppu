#include<bits/stdc++.h>
using namespace std;

class ChatBot {
public:

    vector<pair<string, vector<string>>> rules;

    ChatBot() {
        
        rules.push_back(make_pair("hello", vector<string>{"Hello!", "Hi!", "Hey there!"}));
        rules.push_back(make_pair("howareyou", vector<string>{"I'm doing well. Thank you!", "I'm fine. How about you?"}));

    }


    void takeinp(string& input) 
    {
        string str = simplify(input);

        if (str.find("bye") != string::npos) {
            cout << "ChatBot: Goodbye! Have a nice day!" << endl;
            exit(0);
        }

        string response = answer(str);
        cout << "ChatBot: " << response << endl;
    }

    string simplify(string& input) 
    {
        string str;
        for (char c : input) 
        {
            if(isspace(c))
                continue;
            if(isdigit(c))
                continue;
            if (isalnum(c)) 
            {
                str += c;
            }
        }
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }



    string answer(string& input) 
    {
        for (auto& rule : rules) 
        {
            if (input.find(rule.first) != string::npos) 
            {
                int index = rand() % (rule.second.size() - 1) ;
                return rule.second[index];
            }
        }
        return "I'm sorry, I don't understand. Can you please rephrase?";
    }
};


int main() {
    ChatBot chatbot;
    string input;
    cout<<"\n= = = = = ChatBot = = = = =\n";
    cout << "ChatBot: Hello Siddhesh! How can I assist you?" << endl;

    while (true) 
    {
        cout << "User: ";
        getline(cin, input);
        chatbot.takeinp(input);
    }

    return 0;
}