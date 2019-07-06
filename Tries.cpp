#include<bits/stdc++.h>
using namespace std;
typedef long long int lln;
#define hashmap unordered_map<char,node*>
class node
{
    public:
    char data;
    hashmap h;
    bool isterminal;
    node(char d)
    {
        data=d;
        isterminal=false;
    }
};

class Trie
{
    node *root;
    public:
    Trie()
    {
        root=new node('\0');
    }
    //Insertion
    void insertword(char *word)
    {
        node *temp=root;
        for(int i=0;word[i]!='\0';i++)
        {
            char ch=word[i];
            if(temp->h.count(ch)==0)
            {
                node *child=new node(ch);
                temp->h[ch]=child;
                temp=child;
            }
            else
            {
                temp=temp->h[ch];
            }
        }
        temp->isterminal=true;
    }
    //Lookup
    bool lookup(char *word)
    {
        node *temp=root;
        for(int i=0;word[i]!='\0';i++)
        {
            char ch=word[i];
            if(temp->h.count(ch)==1)
                temp=temp->h[ch];
            else
                return false;
        }
        return temp->isterminal;
    }
};
int main()
{
    Trie t;
    char word[10][100]={"apple","ape","coder","new","news","piyush tyagi","india","indian"};

    for(int i=0;i<8;i++)
        t.insertword(word[i]);

    char searchword[100];
    cin.getline(searchword,100);

    if(t.lookup(searchword))
        cout<<"Found\n";
    else
        cout<<"Not Found\n";

    return 0;
}
