#pragma once



enum CATEGORY
{
    ODD_NUMBER = 1,
    START_WITH_ONE = 2,
    CONTAIN_ONLY_THREE_DIGITS = 3,
    DEFAULT = 4,
};




class CClassification
{
public:
    CATEGORY GetNumCategory(const unsigned int& num);

private:
    bool IsOdd(const unsigned int& num);
    bool IsStartWithOne(const unsigned int& num);
    bool IsContainThreeDigits(const unsigned int& num);

};

