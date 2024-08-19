#include<bits/stdc++.h>
class stackf{
    public:
    int size;
    int top;
    char *p;
    stackf(int size,int top,char *p){
        this->size=size;
        this->top=top;
        this->p=p;
    }
    void pushf(char v){
        top++;
        p[top]=v;
    }
    void popf(){
        top--;
    }
    bool isemptyf(){
        if(top==-1) return true;
        else return false;
    }
    
    char topf(){
        return p[top];
    }
};

class Solution {
public:
    bool isValid(string s) {
        stackf a(sizeof(s), -1 ,new char[10001]);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') a.pushf(s[i]);
        else if(a.top==-1) return false;
        else if((s[i]==')' && a.topf()=='(') || (s[i]=='}' && a.topf()=='{') || (s[i]==']' && a.topf()=='[')) a.popf();
        else return false;
        }
        if(a.isemptyf()==true) return true;
        else return false;
    }
};
