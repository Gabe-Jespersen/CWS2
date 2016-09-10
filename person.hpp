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
        int getWeight(void) const;
        int getHeight(void) const;
        int getAge(void) const;
        int getInt(void) const;
        int getStr(void) const;
        int getCre(void) const;
        int getChar(void) const;
        bool isMale(void) const;
        int setAge(int);
        int makeOlder(void);
};

#endif
