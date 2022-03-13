#ifndef INF112_BATALHA
#define INF112_BATALHA

class IBatalha {
public:
    virtual void batalhar() = 0;
    
};

class Batalha1x1 : public IBatalha {
public:
    virtual void batalhar();
    

};

class Batalha1x2 : public IBatalha{
public:
    virtual void batalhar();

};

class BatalhaFantasma : public IBatalha{
    public:
        virtual void batalhar();
};

#endif

