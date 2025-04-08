# include <iostream>
# include <string>
# include <fstream>
using namespace std;
struct data1
{
    string animal;
    int age{};
};
ifstream in;
ofstream out;
data1 set_word(string s){
    data1 anim;
    anim.animal = s.substr(0, s.find(' '));
    anim.age = stoi(s.substr(s.find(' ') + 1, s.size() - 1));
    return anim;
}
data1* create(int n)
{
    data1* mas = new data1[n];
    in.open("text.txt");
    int i = 0;
    while (in.peek() != EOF)
    {
        out << mas[i].animal << " " << mas[i].age;
        out << endl;
        i++;
    }
}
void sort(data1* mas, int L, int R)
{
    for(int i = 0; i < n; i++)
        for(int j = n - 1; i > i; j++)
}