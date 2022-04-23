#ifndef SCHNITTSTELLE
#define SCHNITTSTELLE

class Schnittstelle // interface
{
private:
    short pegel; // level

public:
    const static short LOW = 0;
    const static short HIGH = 1;
    const static short UNDEFINED = -1;

    Schnittstelle()
        : pegel(LOW) {};  //default level sets to LOW

    short getPegel()
    {
        return pegel;
    }
    bool setPegel(const short& pegel) //sets level, returns true if LOW or HIGH else false
    {
        this->pegel = pegel;
        return (pegel == LOW || pegel == HIGH);
    }
};

#endif
