#define FORM_H
#define MAX_NAME 100

#include <iostream>
#include <fstream>
#include <vector>

class form {
private:
    char* name_;
    unsigned int PostIndex_;
    bool answer_;
    double rating_;
public:
    form();
    form(char* name, unsigned int PostIndex, bool answer, double rating);
    ~form();

    void SetName(char* name);
    void SetPostIndex(unsigned int PostIndex);
    void SetAnswer(bool answer);
    void SetRating(double rating);

    char* GetName();
    unsigned int GetPostIndex();
    bool GetAnswer();
    double GetRating();
};

form* read_db(char*, form**&, unsigned int&);

int Menu();

void print_db(form**&, unsigned int&);

form* write_db(char*, form**&, unsigned int&);

unsigned int find(form**&, unsigned int&);

void sort_db(form**&, unsigned int&);

void resize(form**&, unsigned int&, unsigned int&);

void add(form**&, unsigned int&);

int del(form**&, unsigned int&);

int start_form();