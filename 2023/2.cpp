#include <iostream>
using namespace std;

int main(){
    string line;
    int sum=0;
    int R=12,G=13,B=14;
    while(true){
        getline(cin,line);
        bool possible = true;
        int index=0;
        int start_point;
        for(int i=5;i<line.length();i++){
            if(line[i] == ':'){
                start_point = i;
                break;
            }
            index = (index*10)+(int)(line[i]-'0');
        }
        //cout << "index: " << index << endl;
        // blue red green
        int r=0,g=0,b=0;
        int num=0;
        bool skip = false;
        for (int i=start_point+2;i<line.length()-2&possible;i++){
            //cout << "looking at: " << line[i] << endl;
            if (line[i] == ' '){
                i += 1;
                if (line[i] == 'r')
                    r=max(r,num);
                else if(line[i] == 'g')
                    g=max(g,num);
                else if(line[i] == 'b')
                    b=max(b,num);
                num = 0;
                while (i < line.length()-2){
                    i++;
                    if (line[i] == ',')
                        break;
                    else if (line[i] == ';'){
                        //cout << r << " " << g << " " << b << endl;
                        //r=0;g=0;b=0;
                        break;
                    }
                }
                i+=1;
                //cout << line[i] << " po sredniku, indeks " << i << endl;
            }
            int val = (int)(line[i]-'0');
            if (val >= 0 && val <= 9)
                num = num*10+val;
            //cout << num << endl;

        }
        sum += r * g * b;
        cout <<  sum << endl;
    }
}
