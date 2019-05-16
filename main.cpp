#include <iostream>
#include <typeinfo>
#include <string.h>
#include <string>

using namespace std;



///template<class T>
///int Expozitie<T>::nr_masini;

class Masina
{
protected:
    static int nr_masini;
    string marca;
    string culoare;
    int an_fabricatie;
public:
    Masina& operator=(const Masina& ob)
    {
        marca=ob.marca;
        culoare=ob.culoare;
        an_fabricatie=ob.an_fabricatie;
        return (*this);
    }
    Masina(){ nr_masini++; }
    Masina(string m, string c, int a)
    {
        nr_masini++;
        marca=m;
        culoare=c;
        an_fabricatie=a;
    }
    virtual ~Masina(){ nr_masini--;};
    Masina(const Masina& ob)
    {
        marca=ob.marca;
        culoare=ob.culoare;
        an_fabricatie=ob.an_fabricatie;
    }
    static int get_nr_masini(){ return nr_masini; }
    virtual void afisare(ostream& out)
    {
        out<<"Marca: "<<marca<<endl;
        out<<"Culoare: "<<culoare<<endl;
        out<<"An fabricatie: "<<an_fabricatie<<endl;
    }
    virtual void citire(istream& in)
    {
        int p=0;
        cout<<"Marca: ";
        in>>marca;
        cout<<"Culoare: ";
        in>>culoare;
        cout<<"An fabricatie: ";
        while(p==0)
        {
            p=1;
            try
            {
                in>>an_fabricatie;
                if(an_fabricatie<1900 || an_fabricatie>2019)
                    throw an_fabricatie;
            }
            catch(...)
            {
                p=0;
            }
        }
    }
    friend ostream& operator<<(ostream& out, Masina& ob);
    friend istream& operator>>(istream& in, Masina& ob);
};
int Masina::nr_masini;
class Coupe: public Masina
{
private:
    string combustibil;
public:
    Coupe& operator=(const Coupe& ob)
    {
        combustibil=ob.combustibil;
        this->Masina::operator=(ob);
        return (*this);
    }
    Coupe(){}
    Coupe(string m, string c, int a, string comb): Masina(m,c,a),combustibil(comb){}
    ~Coupe(){}
    Coupe(const Coupe& ob): Masina(ob)
    {
        combustibil=ob.combustibil;
    }
    void afisare(ostream& out)
    {
        Masina::afisare(out);
        out<<"Combustibil: "<<combustibil<<endl;
    }
    void citire(istream& in)
    {
        int p=0;
        Masina::citire(in);
        cout<<"Combustibil: ";
        while(p==0)
        {
            p=1;
            try
            {
                in>>combustibil;
                if(combustibil!="Benzina" && combustibil!="Diesel" && combustibil!="GPL" && combustibil!="Hibrid" && combustibil!="Electric")
                    if(combustibil!="benzina" && combustibil!="diesel" && combustibil!="gpl" && combustibil!="hibrid" && combustibil!="electric")
                    throw combustibil;
            }
            catch(string s)
            {
                p=0;
            }
        }
    }
};
class Coupe_4: public Masina
{
private:
    int rulaj;
public:
    Coupe_4& operator=(const Coupe_4& ob)
    {
        rulaj=ob.rulaj;
        this->Masina::operator=(ob);
        return (*this);
    }
    Coupe_4(){}
    Coupe_4(string m, string c, int a, int r): Masina(m,c,a),rulaj(r){}
    ~Coupe_4(){}
    Coupe_4(const Coupe_4& ob): Masina(ob)
    {
        rulaj=ob.rulaj;
    }
    void afisare(ostream& out)
    {
        Masina::afisare(out);
        out<<"Rulaj: "<<rulaj<<endl;
    }
    void citire(istream& in)
    {
        Masina::citire(in);
        cout<<"Rulaj: ";
        in>>rulaj;
    }

};
class Hot_Hatch: public Masina
{
private:
    int motor;
public:
    Hot_Hatch& operator=(Hot_Hatch& ob)
    {
        motor=ob.motor;
        this->Masina::operator=(ob);
        return (*this);
    }
    Hot_Hatch(){}
    Hot_Hatch(string m, string c, int a, int mot): Masina(m,c,a),motor(mot){}
    ~Hot_Hatch(){}
    Hot_Hatch(const Hot_Hatch& ob): Masina(ob)
    {
        motor=ob.motor;
    }
    void afisare(ostream& out)
    {
        Masina::afisare(out);
        out<<"Motor: "<<motor<<endl;
    }
    void citire(istream& in)
    {
        int p=0;
        Masina::citire(in);
        cout<<"Motor: ";
        while(p==0)
        {
            p=1;
            try
            {
                in>>motor;
                if(motor<600 || motor>5000)
                    throw motor;
            }
            catch(...)
            {
                p=0;
            }
        }
    }
};
class Cabrio: public Masina
{
private:
    int locuri;
public:
    Cabrio& operator=(Cabrio& ob)
    {
        locuri=ob.locuri;
        this->Masina::operator=(ob);
        return (*this);
    }
    Cabrio(){}
    Cabrio(string m, string c, int a, int l): Masina(m,c,a),locuri(l){}
    ~Cabrio(){}
    Cabrio(const Cabrio& ob): Masina(ob)
    {
        locuri=ob.locuri;
    }
    void afisare(ostream& out)
    {
        Masina::afisare(out);
        out<<"Locuri: "<<locuri<<endl;
    }
    void citire(istream& in)
    {
        int p=0;
        Masina::citire(in);
        cout<<"Locuri: ";
        while(p==0)
        {
            p=1;
            try
            {
                in>>locuri;
                if(locuri!=2 && locuri!=4)
                    throw locuri;
            }
            catch(...)
            {
                p=0;
            }
        }
    }
};
class Supersport: public Masina
{
private:
    int viteza;
    int pret;
public:
    Supersport& operator=(Supersport& ob)
    {
        viteza=ob.viteza;
        pret=ob.pret;
        this->Masina::operator=(ob);
        return (*this);
    }
    Supersport(){};
    Supersport(string m, string c, int a, int v, int p): Masina(m,c,a),viteza(v),pret(p){}
    ~Supersport(){}
    Supersport(const Supersport& ob): Masina(ob)
    {
        viteza=ob.viteza;
        pret=ob.pret;
    }
    void afisare(ostream& out)
    {
        Masina::afisare(out);
        out<<"Viteza: "<<viteza<<endl;
        out<<"Pret: "<<pret<<endl;
    }
    void citire(istream& in)
    {
        int p=0;
        Masina::citire(in);
        cout<<"Viteza: ";
        while(p==0)
        {
            p=1;
            try
            {
                in>>viteza;
                if(viteza<0 || viteza>400)
                    throw viteza;
            }
            catch(...)
            {
                p=0;
            }
        }
        cout<<"Pret: ";
        p=0;
        while(p==0)
        {
            p=1;
            try
            {
                in>>pret;
                if(pret<0)
                    throw pret;
            }
            catch(...)
            {
                p=0;
            }
        }
    }
};
class Supersport_Vanzare: public Supersport
{

};
template <class T>
class Expozitie
{
private:
    int nr_masini;
    T** masini;
public:
    Expozitie& operator=(const Expozitie& ob)
    {
        if(this!=&ob)
        {
            nr_masini=ob.nr_masini;
            for(int i=0;i<nr_masini;i++)
                masini[i]=ob.masini[i];
        }
    }
    Expozitie()
    {
        nr_masini=0;
        masini=new T*[100];
    }
    Expozitie(int i)
    {
        nr_masini=0;
        masini=new T*[i];
    }
    ~Expozitie()
    {
        for(int i=0;i<nr_masini;i++)
            delete masini[i];
        delete[] masini;
    }
    Expozitie(const Expozitie& ob)
    {
        nr_masini=ob.nr_masini;
        masini=new T*[100];
        for(int i=0;i<nr_masini;i++)
            masini[i]=ob.masini[i];
    }
    T** get_masini()
    {
        return masini;
    }
    void adaugare_masina(int i);
    void afisare_masini();
};
template<>
class Expozitie <char*>
{
private:
    int nr_stoc,nr_vandute;
    Supersport** stoc;
    Supersport** vandute;
public:
    Expozitie& operator=(const Expozitie& ob)
    {
        if(this!=&ob)
        {
            nr_stoc=ob.nr_stoc;
            nr_vandute=ob.nr_vandute;
            for(int i=0;i<nr_stoc;i++)
                stoc[i]=ob.stoc[i];
            for(int i=0;i<nr_vandute;i++)
                vandute[i]=ob.vandute[i];
                return (*this);
        }
    }
    Expozitie()
    {
        stoc=new Supersport*[100];
        vandute=new Supersport*[100];
        nr_stoc=0;
        nr_vandute=0;
    }
    Expozitie(int i, int j)
    {
        stoc=new Supersport*[i];
        vandute=new Supersport*[j];
    }
    ~Expozitie()
    {
        for(int i=0;i<nr_stoc;i++)
            delete stoc[i];
        for(int i=0;i<nr_vandute;i++)
            delete vandute[i];
        delete[] stoc;
        delete[] vandute;
    }
    void afisare_supersport()
    {
        int i;
        cout<<"In stoc:"<<endl;
        for(i=0;i<nr_stoc;i++)
        {
            cout<<i<<"."<<endl;
            cout<<*(stoc[i]);
        }
        cout<<endl<<"Vandute:"<<endl;
        for(i=0;i<nr_vandute;i++)
        {
            cout<<i<<"."<<endl;
            cout<<*(vandute[i]);
        }
    }
    int get_nr_stoc()
    {
        return nr_stoc;
    }
    void adaugare_stoc(Supersport& ob);
    Expozitie& operator-=(int i);
};
//template<>
void Expozitie<char*>::adaugare_stoc(Supersport& ob)
{
    stoc[nr_stoc]=new Supersport(ob);
    nr_stoc++;
}
Expozitie<char*>& Expozitie<char*>::operator-=(int i)
{
    vandute[nr_vandute]=new Supersport(*(stoc[i]));
    nr_vandute++;
    delete stoc[i];
    for(int j=i;j<nr_stoc-1;j++)
        stoc[j]=stoc[j+1];
    nr_stoc--;
    return (*this);
}
template<class T>
void Expozitie<T>::adaugare_masina(int i)
{
    switch(i)
    {
    case 1: masini[nr_masini]=new Coupe;
        break;
    case 2: masini[nr_masini]=new Coupe_4;
        break;
    case 3: masini[nr_masini]=new Hot_Hatch;
        break;
    case 4: masini[nr_masini]=new Cabrio;
        break;
    case 5: masini[nr_masini]=new Supersport;
        break;
    }
    cin>>*(masini[nr_masini]);
    nr_masini++;
}
template<class T>
void Expozitie<T>::afisare_masini()
{
    int i;
    for(i=0;i<nr_masini;i++)
    {
        cout<<*(masini[i]);
        cout<<endl;
    }
}
ostream& operator<<(ostream& out, Masina& ob)
{
    ob.afisare(out);
    return out;
}
istream& operator>>(istream& in, Masina& ob)
{
    ob.citire(in);
    return in;
}
int main()
{
    int nr,i,tip;
    Expozitie<Masina> masini;
    Expozitie<char*> supersporturi;
    cout<<"Cate masini doriti sa adaugati?"<<endl;
    cin>>nr;
    for(i=0;i<nr;i++)
    {
        cout<<"Masina "<<i<<" : 1.Coupe   2.Coupe cu 4 usi   3.Hot-Hatch   4.Cabrio    5.Supersport"<<endl;
        cin>>tip;
        masini.adaugare_masina(tip);
        if(tip==5)
        {
            Supersport* sup=dynamic_cast<Supersport*>(masini.get_masini()[i]);
            supersporturi.adaugare_stoc(*sup);
        }
    }
    cout<<"Toate masinile din expozitie: "<<endl;
    masini.afisare_masini();
    cout<<endl;
    cout<<"Meniu:"<<endl;
    cout<<"1.Afisare masini supersport din stoc sau vandute"<<endl;
    cout<<"2.Vanzare masina supersport"<<endl;
    cout<<"3.Exit"<<endl;
    int opt=0, ord;
    while(opt!=3)
    {
        cout<<"Alegeti"<<endl;
        cin>>opt;
        if(opt==1)
            supersporturi.afisare_supersport();
        if(opt==2)
        {
            cout<<"Alegeti numarul de ordine al masinii pe care doriti sa o vindeti"<<endl;
            int p=0;
            while(p==0)
            {
                p=1;
                try
                {
                    cin>>ord;
                    if(ord>=supersporturi.get_nr_stoc())
                        throw ord;
                }
                catch(int)
                {
                    p=0;
                }
            }
            supersporturi-=ord;
            cout<<"Masina a fost vanduta!"<<endl;
        }
    }
    return 0;
}
