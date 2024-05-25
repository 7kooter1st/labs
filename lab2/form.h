#include <iostream>
#include <fstream>
#include <vector>


class form {
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