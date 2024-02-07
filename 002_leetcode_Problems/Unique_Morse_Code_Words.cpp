#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

unordered_map<char, string> mcode = {{'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."}, {'g', "--."},
                                    {'h', "...."}, {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."},
                                    {'o', "---"}, {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, {'u', "..-"},
                                    {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"}, {'z', "--.."}};

int uniqueMorseRepresentations(vector<string>& words) {
    stack<string> s;
    int count = 0;
    for (auto str : words)
    {
        string temp;
        for (int i = 0; i < str.size(); i++)
        {
            temp.append(mcode[str[i]]);
        }
        cout<<temp<<endl;
        if (s.empty())
        {
            s.push(temp);
            continue;
        }

        string s_top = s.top();
        if (s_top == temp)
        {
            // s.pop();
            // count++;
            s.push(temp);
        }
        else{
            count++;
            // s.push(temp);
        }
    }
    return count ? count : 1;
}

int main(void)
{
    vector<string> v = {"cbrl","cdfl","wvtj","wvkm","anuyt"};
    cout<<uniqueMorseRepresentations(v)<<endl;
    return 0;
}