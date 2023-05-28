#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

vector<pair<regex, string>> rules = {
    {regex("hi.*|hell.*o.*", regex_constants::icase), "Hey there! How can I assist you?"},
    {regex(".*name.*|who.*are.*you", regex_constants::icase), "My name is Chatbot."},
    {regex("how.*are.*you.*", regex_constants::icase), "I am a chatbot. I help you with problems you are facing with your mobile."},
    {regex(".*created.*|.*creator.*", regex_constants::icase), "I was created by Akash Kalme."},
    {regex(".*screen.*|.*broken.*", regex_constants::icase), "Please bring your device for inspection, we will assess the damage and repair it."},
    {regex(".*software.*issue.*|.*hang.*", regex_constants::icase), "Please try resetting or updating your device. If still not resolved then visit store."},
    {regex("exit|.*bye.*", regex_constants::icase), "Goodye!"}};

string generateResponse(string &userInput)
{
    for (const auto &rule : rules)
    {
        if (regex_search(userInput, rule.first))
            return rule.second;
    }
    return "I am sorry. I couldn't understand.";
}

int main()
{
    string userInput;
    while (true)
    {
        cout << "User: ";
        getline(cin, userInput);
        string response = generateResponse(userInput);
        cout << "Chatbot: " << response << "\n";
        if (regex_search(userInput, regex("exit|.*bye.*", regex_constants::icase)))
        {
            break;
        }
    }
    return 0;
}