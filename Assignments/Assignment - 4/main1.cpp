#include<iostream>
#include<fstream>

using namespace std;

void words(){
    int l=0, upper=0, lower=0, spaces=0;
    string result;
    ifstream story("STORY.txt",ios::in);

    while(getline(story, result)){
        for(int i=0; i<result.length(); i++){
            if(result[i]>='A' && result[i]<='Z'){
                upper++;
            }
            else if(result[i]>='a' && result[i]<='z'){
                lower++;
            }
            else if(result[i]==' '){
                spaces++;
            }
        }
        if(result.at(0)=='T'){
            cout<<result<<"\n";
        }
        l++;
    }
    cout<<"Number of lines: "<<l<<endl;
    cout<<"Number of spaces: "<<spaces<<endl;
    cout<<"Number of uppercase letters: "<<upper<<endl;
    cout<<"Number of lowercase letters: "<<lower;
    }

int main(){
    words();
    return 0;
}
