#include <iostream>

using namespace std;

string split_front(string s){
    string out = "";
    for(int i=0; i<s.length(); i++){
        if ((int)(s[i]-'0') >= 0 & (int)(s[i]-'0')<= 9)
            break;
        else
            out += s[i];
    }
    return out;
}

string split_back(string s){
    string out = "";
    for(int i=s.length()-1; i>=0; i--){
        if ((int)(s[i]-'0') >= 0 & (int)(s[i]-'0')<= 9)
            break;
        else
            out = s[i] + out;
    }
    return out;
}

int num_val(string s){
    if (s == "one") return 1;
    else if (s == "two") return 2;
    else if (s == "three") return 3;
    else if (s == "four") return 4;
    else if (s == "five") return 5;
    else if (s == "six") return 6;
    else if (s == "seven") return 7;
    else if (s == "eight") return 8;
    else if (s == "nine") return 9;
}

int main(){
    string line;
    string nums3[] = {"one","two","six"};
    string nums4[] = {"four","five","nine"};
    string nums5[] = {"three","seven","eight"};
    int a,b,sum=0;

    while(true){
        cin >> line;
        a=0;b=0;
        for(int i=0; i<line.length(); i++){
            if((int)(line[i]-'0') >= 0 & (int)(line[i]-'0')<= 9){
                a=(int)(line[i]-'0');
                break;
            }
        }
        for(int i=0; i<line.length(); i++){
            if((int)(line[line.length()-i-1]-'0') >= 0 & (int)(line[line.length()-i-1]-'0') <= 9){
                b=(int)(line[line.length()-i-1]-'0');
                break;
            }
        }

        string fr=split_front(line), bc=split_back(line);
        for (int i=0; i<fr.length()-2; i++){
            if (fr.length() - i < 3 || fr.length() < 3)
                break;
            string sub = fr.substr(i,3);
            if(sub == "one" || sub == "two" || sub == "six"){
                a = num_val(sub);
                break;
            }
            if (fr.length() - i < 4)
                continue;
            sub = fr.substr(i,4);
            if(sub == "four" || sub == "five" || sub == "nine"){
                a = num_val(sub);
                break;
            }
            if (fr.length() - i < 5)
                continue;
            sub = fr.substr(i,5);
            if(sub == "three" || sub == "seven" || sub == "eight"){
                a = num_val(sub);
                break;
            }
        }
        for (int i=0; i<bc.length()-2; i++){
            if (bc.length() - i < 3 || bc.length() < 3)
                break;
            string sub = bc.substr(i,3);
            if(sub == "one" || sub == "two" || sub == "six"){
                b = num_val(sub);
            }
            if (bc.length() - i < 4)
                continue;
            sub = bc.substr(i,4);
            if(sub == "four" || sub == "five" || sub == "nine"){
                b = num_val(sub);
            }
            if (bc.length() - i < 5)
                continue;
            sub = bc.substr(i,5);
            if(sub == "three" || sub == "seven" || sub == "eight"){
                b = num_val(sub);
            }
        }

        sum += a*10 + b;
        cout << sum << endl;
    }
}
