//
// Created by pbochkarev on 29.03.2023.
//
class Text{

private:
    char str[256];
public:
    Text(char*);
    Text(){

    }
    Text(const Text&);
    Text& operator=(const Text&);
    Text& operator+(const Text&);
    Text& operator==(const Text&);
    int length();
    void input();
    void output();

};