/*#include<iostream>
#include<fstream>

using namespace std;

void vowelwords(){
    string result, word;
    ifstream first("FIRST.txt",ios::in);
    ofstream second("SEOCND.txt",ios::out);
    if(!first.is_open()){
        result = "error";
    }
    else {
        getline(first, result);
    }
    for(int i=0; i<result.size(); i++){
        char x=result.at(i);
        if(x==' '){
            if(word.at(0)=='a' || word.at(0)=='e' || word.at(0)=='i' || word.at(0)=='o' || word.at(0)=='u'){
                second<<word<<' ';
            }
            word.clear();
        }
        else {
            word = word+x;
        }
    }
}

int main(){
    vowelwords();
    return 0;
}
*/
