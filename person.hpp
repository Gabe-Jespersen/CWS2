#ifndef PERSON_HPP
#define PERSON_HPP

class person
{
    private:
        int weight, height, age, intelligence, strength, creativity, charisma;
        bool male;

    public:
        int generateRandom();
        int generateBased(int,int,int,int,int,int,int,bool);
        int getWeight(void);
        int getHeight(void);
        int getAge(void);
        int getInt(void);
        int getStr(void);
        int getCre(void);
        int getChar(void);
        bool isMale(void);
        int setAge(int);
        int makeOlder(void);
};

#endif
