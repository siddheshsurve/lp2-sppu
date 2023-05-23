#include <bits/stdc++.h>
using namespace std;
string toLowercase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

class Harish
{
private:
    map<string, string> rules;

public:
    Harish()
    {
        rules["hi"] = "Hello!";
        rules["how are you"] = "I'm doing well, thank you!";
        rules["what's your name"] = "My name is Chatbot.";
        rules["bye"] = "Goodbye!";
    }

    string respond(string message)
    {
        message = toLowercase(message);

        for (const auto &rule : rules)
        {
            if (message.find(rule.first) != string ::npos)
            {
                return rule.second;
            }
        }

        return "I'm sorry, I don't understand.";
    }
};

int main()
{
    Harish chatbot;

    cout << "Chatbot: Hello! How can I assist you?" << endl;

    while (true)
    {
        string userMessage;
        cout << "User: ";
        getline(cin, userMessage);

        string response = chatbot.respond(userMessage);
        cout << "Chatbot: " << response << endl;

        if (toLowercase(userMessage) == "bye")
        {
            break;
        }
    }

    return 0;
}