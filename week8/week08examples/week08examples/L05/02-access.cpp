class Base {
public:
    int m_public;
private:
    int m_private;
protected:
    int m_protected;
};

class Pub: public Base {
public:
    Pub() {
        m_public = 1;
        //m_private = 2;
        m_protected = 3;
    }
};

class Prot: protected Base {
public:
    Prot() {
        m_public = 1;
        m_protected = 3;
    }
};
 
class Priv: private Base {
public:
    Priv() {
        m_public = 1; 
        m_protected = 3; 
    }
};
 
int main() {
    Base b;
    b.m_public = 4; 
    //b.m_private = 5; 
    //b.m_protected = 6; 
 
    Prot d;
    d.m_public = 7; 
    //d.m_private = 8; 
    //d.m_protected = 9; 
}
