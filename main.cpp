#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

///-----------APLICATIE PT ADMININSTRAREA UNUI CLUB DE FOTBAL----------

struct date
{
    int zi;
    int luna;
    int an;
};
//Acest tip de date imi va retine date din an, pt dataMeci sau dataNastere...

//Detalii generale club.
class ClubInfo
{
private:
    string numePresedinte; // presedintele clubului
    string numeClub;
    string stadionAcasa;
    string partenerPrincipal; // sponsor principal
    int nrTitluri; //nrTitluri de campioana
    int *aniTitlu;
    string anSince; //an infiintare

public:

    /// -----CONSTRUCTORI -----
    //cu toti parametrii;
    ClubInfo(string, string, string, string, int, int *, string);

    //fara parametrii
    ClubInfo();

    //2 constructori cu cate un parametru
    ClubInfo(string numeClub);
    ClubInfo(int anSince);

    //copy constructor
    ClubInfo(const ClubInfo &obj);

    /// -----GETTERS-------
    string getNumePresedinte()
    {
        return numePresedinte;
    }

    string getNumeClub()
    {
        return numeClub;
    }

    string getStadionAcasa()
    {
        return stadionAcasa;
    }

    string getPartenerPrincipal()
    {
        return partenerPrincipal;
    }

    int getNrTitluri()
    {
        return nrTitluri;
    }

    const int *getAniTitlu()
    {
        return aniTitlu;
    }

    string getAnSince()
    {
        return anSince;
    }

    /// -------SETTERS---------
    void setNumePresedinte(string numePresedinte)
    {
        this->numePresedinte = numePresedinte;
    }

    void setNumeClub(string numeClub)
    {
        this->numeClub = numeClub;
    }

    void setStadionAcasa(string stadionAcasa)
    {
        this->stadionAcasa = stadionAcasa;
    }

    void setPartenerPrincipal(string partenerPrincipal)
    {
        this->partenerPrincipal = partenerPrincipal;
    }

    void setNrTitluri(int nrTitluri)
    {
        this->nrTitluri = nrTitluri;
    }

    void setAniTitlu(int *aniTitlu);

    void setAnSince(string anSince)
    {
        this->anSince = anSince;
    }

    ///------DESTRUCTOR--------
    ~ClubInfo()
    {
        if (this->aniTitlu != NULL) delete[] this->aniTitlu;
    }

    /// ------SUPRAINCARCARI LA OPERATORI------

    //Operatorul=
    ClubInfo &operator=(const ClubInfo &obj);

    //Operatorul cin>>
    friend istream &operator>>(istream &in, ClubInfo &obj);

    //operatorul cout<<
    friend ostream &operator<<(ostream &, const ClubInfo &);

    //Operator + cu string din dreapta
    ClubInfo operator+(string s);

    //Operator + cu string din stanga
    friend ClubInfo operator+(string s, ClubInfo obj);

    //Operatorul de indexare[]
    int operator[](int index);

    //Operatorul ++ POST
    ClubInfo operator++(int);

    //Operatorul ++ PRE
    ClubInfo &operator++();

    //Operatorul +
    ClubInfo operator+(const ClubInfo &obj);

    //Operatorul -
    ClubInfo operator-(const ClubInfo &obj);

    //Operatorul cast implicit
    operator string();

    //Operatorul cast explicit
    operator string() const;

    //Operator conditional <
    bool operator<(const ClubInfo &obj);

    //Operator conditional ==
    bool operator==(const ClubInfo &obj);

    //Metoda proprie:
    int VarstaClub();

};
/// FINAL DECLARATII CLASA ClubInfo



/// Setters outside ClubInfo
void ClubInfo::setAniTitlu(int *aniTitlu)
{
    if (this->aniTitlu != nullptr)
        delete[] this->aniTitlu;
    this->aniTitlu = new int[nrTitluri];
    for (int i = 0; i < nrTitluri; i++)
        this->aniTitlu[i] = aniTitlu[i];
}

/// --- CONSTRUCTORI ClubInfo ----
//Toti parametrii
ClubInfo::ClubInfo(string numePresedinte, string numeClub, string stadionAcasa,
                   string partenerPrincipal, int nrTitluri, int *aniTitlu, string anSince)
    : numePresedinte(numePresedinte),
      numeClub(numeClub),
      stadionAcasa(stadionAcasa),
      partenerPrincipal(partenerPrincipal),
      nrTitluri(nrTitluri),
      anSince(anSince)
{
    this->aniTitlu = new int[nrTitluri];
    for (int i = 0; i < nrTitluri; i++)
        this->aniTitlu[i] = aniTitlu[i];
}

//Fara parametrii
ClubInfo::ClubInfo()
{
    numePresedinte = "empty";
    numeClub = "empty";
    stadionAcasa = "arena x";
    partenerPrincipal = "y bet";
    nrTitluri = 0;
    aniTitlu = NULL;
    anSince = "0";
}

//Cu cate un parametru
ClubInfo::ClubInfo(string numeClub)
{
    this->numeClub = numeClub;

    numePresedinte = "empty";
    stadionAcasa = "arena x";
    partenerPrincipal = "y bet";
    nrTitluri = 0;
    aniTitlu = NULL;
    anSince = "0";
}

ClubInfo::ClubInfo(int anSince)
{
    this->anSince = to_string(anSince);

    numePresedinte = "empty";
    numeClub = "empty";
    stadionAcasa = "arena x";
    partenerPrincipal = "y bet";
    nrTitluri = 0;
    aniTitlu = NULL;
}

//Copy constructor
ClubInfo::ClubInfo(const ClubInfo &obj)
{
    this->numePresedinte = obj.numePresedinte;
    this->numeClub = obj.numeClub;
    this->stadionAcasa = obj.stadionAcasa;
    this->partenerPrincipal = obj.partenerPrincipal;
    this->nrTitluri = obj.nrTitluri;
    this->aniTitlu = new int[obj.nrTitluri];
    for (int i = 0; i < obj.nrTitluri; i++)
        this->aniTitlu[i] = obj.aniTitlu[i];
    this->anSince = obj.anSince;
}

/// -- OVERLOAD OPERATORI --

//Operatorul Egal pt ClubInfo
ClubInfo &ClubInfo::operator=(const ClubInfo &obj)   // am nevoie de primul & deoarece atuncin cand fac return se creeaza un obiect copie inutil
{
    if (this != &obj)
    {
        if (this->aniTitlu != NULL)
            delete[] this->aniTitlu;//dezalocam ce e alocat dinamic si alocam iar

        this->numeClub = obj.numeClub;//suntem in interiorul clasei, deci putem accesa atributele din private
        this->numePresedinte = obj.numePresedinte;
        this->stadionAcasa = obj.stadionAcasa;
        this->partenerPrincipal = obj.partenerPrincipal;
        this->nrTitluri = obj.nrTitluri;
        this->aniTitlu = new int[obj.nrTitluri];
        for (int i = 0; i < obj.nrTitluri; i++)
            this->aniTitlu[i] = obj.aniTitlu[i];
        this->anSince = obj.anSince;
    }
    return *this; // obiectul de la adresa curenta; pointer; obiectul de la adresa this; OBIECTUL DE LA REFERINTA AIA, FARA SA MAI FAC INCA O COPIE; COPY CONSTRUCTOR

}

//OPERATORUL CIN pt ClubInfo
istream &operator>>(istream &in, ClubInfo &obj)
{
    cout << "Nume presedinte: ";
    getline(in, obj.numePresedinte);
    cout << "Nume club: ";
    getline(in, obj.numeClub);
    cout << "Stadion: ";
    getline(in, obj.stadionAcasa);
    cout << "Partener principal: ";
    getline(in, obj.partenerPrincipal);
    cout << "Nr Titluri: ";
    in >> obj.nrTitluri;

    if (obj.aniTitlu != NULL)
        delete[] obj.aniTitlu;
    obj.aniTitlu = new int[obj.nrTitluri];
    for (int i = 0; i < obj.nrTitluri; i++)
    {
        cout << "An titlu " << i + 1 << ": ";
        in >> obj.aniTitlu[i];
    }
    cout << "An infiintare: ";
    in >> obj.anSince;
    in.get();

    return in;
}

//OPERATORUL COUT pt ClubInfo
ostream &operator<<(ostream &out, const ClubInfo &obj)
{
    out << "Nume presedinte: " << obj.numePresedinte << endl;
    out << "Nume club: " << obj.numeClub << endl;
    out << "Stadion: " << obj.stadionAcasa << endl;
    out << "Partener principal: " << obj.partenerPrincipal << endl;
    out << "Numar Titluri: " << obj.nrTitluri << endl;
    for (int i = 0; i < obj.nrTitluri; i++)
        out << "An titlu " << i + 1 << ": " << obj.aniTitlu[i] << endl;
    out << "An infiintare: " << obj.anSince << endl;
    return out;
}

//Operatorul + daca vine un string in dreapta (de ex. adaug inca un presedinte/actionar)
ClubInfo ClubInfo::operator+(string s)
{
    ClubInfo copie = *this;
    copie.numePresedinte = copie.numePresedinte + " si " + s;
    return copie;
}

// Am asigurat comutativitatea, astfel poate veni un string in stanga
ClubInfo operator+(string s, ClubInfo obj)
{
    obj.numePresedinte = obj.numePresedinte + " si " + s;
    return obj;
}

//Operatorul de indexare[] pt ClubInfo
int ClubInfo::operator[](int index)
{
    if (index >= 0 && index < this->nrTitluri)
        return this->aniTitlu[index];
    else throw runtime_error("Index invalid");
}

//Operatorul ++ pt ClubInfo
ClubInfo ClubInfo::operator++(int) //anunt post incrementarea prin int
{
    ClubInfo copie = *this; //merg la adresa this;

    this->nrTitluri++;
    int *vect = new int[this->nrTitluri];
    for (int i = 0; i < this->nrTitluri; i++)
        vect[i] = this->aniTitlu[i];
    vect[this->nrTitluri - 1] = 0;
    cout << endl << "Introduceti anul ultimului titlu castigat: ";
    cin >> vect[this->nrTitluri - 1];
    if (this->aniTitlu != NULL)
        delete[] this->aniTitlu;
    this->aniTitlu = vect;

    return copie;
}

//Incrementare ++ PRE
ClubInfo &ClubInfo::operator++()
{
    this->nrTitluri++;
    int *vect = new int[this->nrTitluri];
    for (int i = 0; i < this->nrTitluri; i++)
        vect[i] = this->aniTitlu[i];
    vect[this->nrTitluri - 1] = 0;
    cout << endl << "Introduceti anul ultimului titlu castigat: ";
    cin >> vect[this->nrTitluri - 1];
    if (this->aniTitlu != NULL)
        delete[] this->aniTitlu;
    this->aniTitlu = vect;

    return *this;

}

//Operatorul + pt ClubInfo
ClubInfo ClubInfo::operator+(const ClubInfo &obj)
{
    ClubInfo copie = *this;

    copie.numePresedinte = copie.numePresedinte + " si " + obj.numePresedinte;
    copie.numeClub = copie.numeClub + " si " + obj.numeClub;
    copie.stadionAcasa = copie.stadionAcasa + " si " + obj.stadionAcasa;
    copie.partenerPrincipal = copie.partenerPrincipal + " si " + obj.partenerPrincipal;

    int *vect = new int[copie.nrTitluri + obj.nrTitluri];
    for (int i = 0; i < copie.nrTitluri; i++)
        vect[i] = copie.aniTitlu[i];
    for (int i = 0; i < obj.nrTitluri; i++)
        vect[i + copie.nrTitluri] = obj.aniTitlu[i];

    if (copie.aniTitlu != NULL) delete[] copie.aniTitlu;
    if (obj.aniTitlu != NULL) delete[] obj.aniTitlu;

    copie.aniTitlu = vect;

    copie.nrTitluri += obj.nrTitluri;
    copie.anSince = copie.anSince + " " + obj.anSince;

    return copie;

}

//Operatorul - pt ClubInfo
ClubInfo ClubInfo::operator-(const ClubInfo &obj)
{
    ClubInfo copie = *this;
    copie.anSince = to_string(stoi(copie.anSince) - stoi(obj.anSince)); //incerc sa vad care club e mai batran
    return copie;
}

//Operatorul cast implicit pt ClubInfo
ClubInfo::operator string()
{
    string s = "";
    string t = "";
    for (int i = 0; i < this->nrTitluri; i++)
        t += to_string(this->aniTitlu[i]) + ", ";

    s = this->numePresedinte + ", " + this->numeClub + ", " + this->stadionAcasa + ", " + this->partenerPrincipal + ", "
        + to_string(this->nrTitluri) + t + ", " + anSince + " ";
    return s;
}

//Operatorul cast explicit pt ClubInfo
ClubInfo::operator string() const
{
    string s = "";
    string t = "";
    for (int i = 0; i < this->nrTitluri; i++)
        t += to_string(this->aniTitlu[i]) + ", ";

    s = this->numePresedinte + ", " + this->numeClub + ", " + this->stadionAcasa + ", " + this->partenerPrincipal + ", "
        + to_string(this->nrTitluri) + t + ", " + anSince + " ";
    return s;
}

//Operator conditional < pt ClubInfo
bool ClubInfo::operator<(const ClubInfo &obj)
{
    return this->nrTitluri < obj.nrTitluri;
}

//Operator conditional == pt ClubInfo
bool ClubInfo::operator==(const ClubInfo &obj)
{
    bool ok = 1;

    if (this->numePresedinte != obj.numePresedinte) ok = 0;
    if (this->numeClub != obj.numeClub) ok = 0;
    if (this->stadionAcasa != obj.stadionAcasa) ok = 0;
    if (this->partenerPrincipal != obj.partenerPrincipal) ok = 0;
    if (this->nrTitluri != obj.nrTitluri) ok = 0;
    if (this->nrTitluri == obj.nrTitluri)
        for (int i = 0; i < this->nrTitluri; i++)
            if (this->aniTitlu[i] != obj.aniTitlu[i]) ok = 0;
    if (this->anSince != obj.anSince) ok = 0;

    return ok;
}

//METODA PROPRIE
int ClubInfo::VarstaClub()
{
    time_t t = time(NULL); //am pus NULL ca sa obtin data curenta;
    //time_t - calendar time in seconds
    tm timeInfo = *localtime(&t);
    // tm face parte din clasa ctime si imi sparge calendar time in ani-zile-luni
    //localtime este o functie din clasa ctime care converteste calendar time-ul in tm; returneaza un pointer, de aceea folosesc * ca sa il dereferntiez

    int current_year = 1900 + timeInfo.tm_year;

    return current_year - stoi(anSince);
}


/// -----------------------
///FINAL CONTINUT pt ClubInfo
/// -----------------------


///Membru staff tehnic
class StaffMembru
{
private:
    string numeComplet; //nume + prenume
    string postStaff;
    int valoareSalariu;//pe luna, euro
    int nrBonusuri;
    int *valoareBonusuri;
    date dataNastere{};

public:
    /// -------CONSTRUCTORI-----

    //cu toti parametrii;
    StaffMembru(string, string, int, int, int *, date);

    //fara parametrii
    StaffMembru();

    //2 constructori cu cate un parametru
    StaffMembru(string numeComplet);
    StaffMembru(int valoareSalariu);

    //copy constructor
    StaffMembru(const StaffMembru &obj);

    ///----GETTERS--------
    string getNumeComplet()
    {
        return numeComplet;
    }

    string getPost()
    {
        return postStaff;
    }

    int getValoareSalariu()
    {
        return valoareSalariu;
    }

    int getNrBonusuri()
    {
        return nrBonusuri;
    }

    const int *getBonusuri()
    {
        return valoareBonusuri;
    }

    date getDataNastere()
    {
        return dataNastere;
    }

    ///-------SETTERS-------
    void setNumeComplet(string numeComplet)
    {
        this->numeComplet = numeComplet;
    }

    void setPost(string postStaff)
    {
        this->postStaff = postStaff;
    }

    void setValoareSalariu(int valoareSalariu)
    {
        this->valoareSalariu = valoareSalariu;
    }

    void setNrBonusuri(int nrBonusuri)
    {
        this->nrBonusuri = nrBonusuri;
    }

    void setBonusuri(int *valoareBonusuri);

    date setDataNastere(date dataNastere)
    {
        this->dataNastere = dataNastere;
    }

    ///-----DESTRUCTOR-----
    ~StaffMembru()
    {
        if (this->valoareBonusuri != NULL) delete[] this->valoareBonusuri;
    }

    /// SUPRAINCARCARI la OPERATORI

    //operatorul=
    StaffMembru &operator=(const StaffMembru &obj);
    //operatorul cin>>
    friend istream &operator>>(istream &in, StaffMembru &obj);
    //operatorul cout<<
    friend ostream &operator<<(ostream &, const StaffMembru &);

    //Operator + cu int din dreapta
    int operator+(int s); //cresc salariul

    //Operator + cu int din stanga
    friend int operator+(int s, StaffMembru obj); //cresc salariul

    //Operatorul de indexare[]
    int operator[](int index);

    //Operatorul ++ POST
    StaffMembru operator++(int);

    //Operatorul ++ PRE
    StaffMembru &operator++();

    //Operatorul +
    StaffMembru operator+(const StaffMembru &obj);

    //Operatorul cast implicit
    operator string();

    //Operatorul cast explicit
    operator string() const;

    //Operator conditional <
    bool operator<(const StaffMembru &obj);

    //Operator conditional ==
    bool operator==(const StaffMembru &obj);

    //Metoda proprie:
    int VarstaMembru();

    //Metoda proprie 2:
    int SumaContract();

};
//------------
///FINAL DECLARATII StaffMembru
//-------------

//SETTERI outside StaffMembru
void StaffMembru::setBonusuri(int *valoareBonusuri)
{
    if (this->valoareBonusuri != NULL)
        delete[] this->valoareBonusuri;
    this->valoareBonusuri = new int[nrBonusuri];
    for (int i = 0; i < nrBonusuri; i++)
        this->valoareBonusuri[i] = valoareBonusuri[i];
}

///CONSTURCTORI

//Cu toti parametrii
StaffMembru::StaffMembru(string numeComplet, string postStaff, int valoareSalariu,
                         int nrBonusuri, int *valoareBonusuri, date dataNastere)
    : numeComplet(numeComplet), postStaff(postStaff), valoareSalariu(valoareSalariu),
      nrBonusuri(nrBonusuri), dataNastere(dataNastere)
{
    this->valoareBonusuri = new int[nrBonusuri];
    for (int i = 0; i < nrBonusuri; i++)
        this->valoareBonusuri[i] = valoareBonusuri[i];
}

//Fara parametrii
StaffMembru::StaffMembru()
{
    numeComplet = "empty";
    postStaff = "empty";
    valoareSalariu = 0;
    nrBonusuri = 0;
    valoareBonusuri = NULL;
    dataNastere = {0, 0, 0};
}

//Cu cate un parametru
StaffMembru::StaffMembru(string numeComplet)
{
    this->numeComplet = numeComplet;

    postStaff = "empty";
    valoareSalariu = 0;
    nrBonusuri = 0;
    valoareBonusuri = NULL;
    dataNastere = {0, 0, 0};
}

StaffMembru::StaffMembru(int valoareSalariu)
{
    this->valoareSalariu = valoareSalariu;

    numeComplet = "empty";
    postStaff = "empty";
    nrBonusuri = 0;
    valoareBonusuri = NULL;
    dataNastere = {0, 0, 0};
}

//COPY CONSTRUCTOR
StaffMembru::StaffMembru(const StaffMembru &obj)
{
    this->numeComplet = obj.numeComplet;
    this->postStaff = obj.postStaff;
    this->valoareSalariu = obj.valoareSalariu;
    this->nrBonusuri = obj.nrBonusuri;
    this->valoareBonusuri = new int[obj.nrBonusuri];
    for (int i = 0; i < obj.nrBonusuri; i++)
        this->valoareBonusuri[i] = obj.valoareBonusuri[i];
    this->dataNastere = obj.dataNastere;
}

//OPERATORUL CIN pt StaffMembru
istream &operator>>(istream &in, StaffMembru &obj)
{
    cout << "Nume complet membru staff: ";

    cin.get();
    getline(in, obj.numeComplet);
    cout << "Postul membrului: ";
    getline(in, obj.postStaff);
    cout << "Valoare salariu : ";
    in >> obj.valoareSalariu;
    cout << "Numar de bonusuri contract : ";
    in >> obj.nrBonusuri;

    if (obj.valoareBonusuri != NULL)
        delete[] obj.valoareBonusuri;
    obj.valoareBonusuri = new int[obj.nrBonusuri];
    for (int i = 0; i < obj.nrBonusuri; i++)
    {
        cout << "Valoare bonus " << i + 1 << ": ";
        in >> obj.valoareBonusuri[i];
    }

    //vom citi data nasterii in zi luna an dd-mm-yyyy
    cout << "Zi nastere: ";
    in >> obj.dataNastere.zi;
    cout << "Luna nastere: ";
    in >> obj.dataNastere.luna;
    cout << "An nastere: ";
    in >> obj.dataNastere.an;

    return in;
}

/// OPERATORI pt StaffMembru

// OPERATORUL EGAL= pt StaffMembru
StaffMembru &StaffMembru::operator=(const StaffMembru &obj)   // am nevoie de primul & deoarece atuncin cand fac & se creeaza un obiect copie inutil
{
    if (this != &obj)
    {
        if (this->valoareBonusuri != NULL)
            delete[] this->valoareBonusuri;//dezalocam ce e alocat dinamic si alocam iar

        this->numeComplet = obj.numeComplet;
        this->postStaff = obj.postStaff;
        this->valoareSalariu = obj.valoareSalariu;
        this->nrBonusuri = obj.nrBonusuri;
        this->valoareBonusuri = new int[obj.nrBonusuri];
        for (int i = 0; i < obj.nrBonusuri; i++)
            this->valoareBonusuri[i] = obj.valoareBonusuri[i];
        this->dataNastere = obj.dataNastere;
    }
    return *this; // obiectul de la adresa curenta; pointer; obiectul de la adresa this; OBIECTUL DE LA REFERINTA AIA, FARA SA MAI FAC INCA O COPIE; COPY CONSTRUCTOR
}

//OPERATORUL COUT pt StaffMembru
ostream &operator<<(ostream &out, const StaffMembru &obj)
{
    out << "Nume complet membru staff: " << obj.numeComplet << endl;
    out << "Postul membrului: " << obj.postStaff << endl;
    out << "Salariu: " << obj.valoareSalariu << endl;
    out << "Numar valoareBonusuri contract: " << obj.nrBonusuri << endl;
    for (int i = 0; i < obj.nrBonusuri; i++)
        out << "Bonus " << i + 1 << ": " << obj.valoareBonusuri[i] << endl;

    cout << "Zi nastere: ";
    out << obj.dataNastere.zi;
    cout << endl;
    cout << "Luna nastere: ";
    out << obj.dataNastere.luna;
    cout << endl;
    cout << "An nastere: ";
    out << obj.dataNastere.an;
    cout << endl;
    return out;
}

//Operatorul + daca vine un int in dreapta (cresc salariul)
int StaffMembru::operator+(int s)
{
    StaffMembru copie = *this;
    int s1 = copie.valoareSalariu + s;
    return s1;
}

// Am asigurat comutativitatea, astfel poate veni un int in stanga
int operator+(int s, StaffMembru obj)
{
    int s1 = obj.valoareSalariu + s;
    return s1;
}

//Operatorul de indexare[] pt StaffMembru // returnez valoarea bonusului ~i~
int StaffMembru::operator[](int index)
{
    if (index >= 0 && index < this->nrBonusuri)
        return this->valoareBonusuri[index];
    else throw runtime_error("Index invalid");
}

//Operatorul ++ pt StaffMembru
StaffMembru StaffMembru::operator++(int) //anunt post incrementarea prin int
{
    StaffMembru copie = *this; //merg la adresa this;

    this->nrBonusuri++; //se adauga un bonus la contract
    int *vect = new int[this->nrBonusuri];
    for (int i = 0; i < this->nrBonusuri; i++)
        vect[i] = this->valoareBonusuri[i];
    vect[this->nrBonusuri - 1] = 0;
    cout << endl << "Introduceti valoarea noului bonus: ";
    cin >> vect[this->nrBonusuri - 1];
    if (this->valoareBonusuri != NULL)
        delete[] this->valoareBonusuri;
    this->valoareBonusuri = vect;

    return copie;
}

//Pre-incrementare ++
StaffMembru &StaffMembru::operator++()
{

    this->nrBonusuri++;//se adauga un bonus la contract
    int *vect = new int[this->nrBonusuri];
    for (int i = 0; i < this->nrBonusuri; i++)
        vect[i] = this->valoareBonusuri[i];
    vect[this->nrBonusuri - 1] = 0;
    cout << endl << "Introduceti valoarea noului bonus: ";
    cin >> vect[this->nrBonusuri - 1];
    if (this->valoareBonusuri != NULL)
        delete[] this->valoareBonusuri;
    this->valoareBonusuri = vect;

    return *this;

}

//Operatorul + pt StaffMembru
StaffMembru StaffMembru::operator+(const StaffMembru &obj)
{
    StaffMembru copie = *this;

    copie.numeComplet = copie.numeComplet + " si " + obj.numeComplet;
    copie.postStaff = copie.postStaff + " si " + obj.postStaff;
    copie.valoareSalariu = copie.valoareSalariu + obj.valoareSalariu;

    int *vect = new int[copie.nrBonusuri + obj.nrBonusuri];
    for (int i = 0; i < copie.nrBonusuri; i++)
        vect[i] = copie.valoareBonusuri[i];
    for (int i = 0; i < obj.nrBonusuri; i++)
        vect[i + copie.nrBonusuri] = obj.valoareBonusuri[i];

    if (copie.valoareBonusuri != NULL) delete[] copie.valoareBonusuri;
    if (obj.valoareBonusuri != NULL) delete[] obj.valoareBonusuri;

    copie.valoareBonusuri = vect;

    copie.nrBonusuri += obj.nrBonusuri;
    copie.dataNastere = {0, 0, 0};

    return copie;

}

//Operatorul cast implicit pt StaffMembru
StaffMembru::operator string()
{
    string s = "";
    string t = "";
    for (int i = 0; i < this->nrBonusuri; i++)
        t += to_string(this->valoareBonusuri[i]) + ", ";

    s = this->numeComplet + ", " + this->postStaff + ", Salariu: " + to_string(this->valoareSalariu) + ", "
        + to_string(this->nrBonusuri) + " bonusuri: " + t + ", Data nastere: " + to_string(this->dataNastere.zi) + "/"
        + to_string(this->dataNastere.luna) + "/" + to_string(this->dataNastere.an);
    return s;
}

//Operatorul cast explicit pt StaffMembru
StaffMembru::operator string() const
{
    string s = "";
    string t = "";
    for (int i = 0; i < this->nrBonusuri; i++)
        t += to_string(this->valoareBonusuri[i]) + ", ";

    s = this->numeComplet + ", " + this->postStaff + ", Salariu: " + to_string(this->valoareSalariu) + ", "
        + to_string(this->nrBonusuri) + " bonusuri: " + t + ", Data nastere: " + to_string(this->dataNastere.zi) + "/"
        + to_string(this->dataNastere.luna) + "/" + to_string(this->dataNastere.an);
    return s;
}

//Operator conditional < pt StaffMembru
bool StaffMembru::operator<(const StaffMembru &obj)
{
    return this->valoareSalariu < obj.valoareSalariu;
}

//Operator conditional == pt StaffMembru
bool StaffMembru::operator==(const StaffMembru &obj)
{
    bool ok = 1;

    if (this->numeComplet != obj.numeComplet) ok = 0;
    if (this->postStaff != obj.postStaff) ok = 0;
    if (this->valoareSalariu != obj.valoareSalariu) ok = 0;
    if (this->nrBonusuri != obj.nrBonusuri) ok = 0;
    if (this->nrBonusuri == obj.nrBonusuri)
        for (int i = 0; i < this->nrBonusuri; i++)
            if (this->valoareBonusuri[i] != obj.valoareBonusuri[i]) ok = 0;
    if ((this->dataNastere.zi != obj.dataNastere.zi) || (this->dataNastere.luna != obj.dataNastere.luna)
            || (this->dataNastere.an != obj.dataNastere.an))
        ok = 0;

    return ok;
}

//METODA PROPRIE
int StaffMembru::VarstaMembru()
{
    int varsta;
    time_t t = time(NULL); //am pus NULL ca sa obtin data curenta;
    //time_t - calendar time in seconds
    tm timeInfo = *localtime(&t);
    // tm face parte din clasa ctime si imi sparge calendar time in ani-zile-luni
    //localtime este o functie din clasa ctime care converteste calendar time-ul in tm; returneaza un pointer, de aceea folosesc * ca sa il dereferntiez

    int current_year = 1900 + timeInfo.tm_year;
    int current_month = 1 + timeInfo.tm_mon; // Adăugăm 1 pentru că lunile sunt indexate de la 0
    int current_day = timeInfo.tm_mday;

    if (current_year >= dataNastere.an && current_month >= dataNastere.luna && current_day >= dataNastere.zi)
        varsta =
            current_year
            - dataNastere.an;
    else varsta = current_year - dataNastere.an - 1;

    return varsta;
}

//Metoda proprie 2:
int StaffMembru::SumaContract() //suma totala maxima din contract (in cazul in care sunt atinse toate bonusurile din contract)
{
    int s = 0;
    s = valoareSalariu * 12;
    for (int i = 0; i < nrBonusuri; i++)
        s += valoareBonusuri[i];
    return s;
}

///-------------
///FINAL CONTINUT CLASA StaffMembru
///-------------


class MeciJucat
{
private:
    string numeAdversar;
    string oraMeci;
    int nrGoluri;
    int mySpectatori;
    int *idMarcatori;// prin id ma refer la numarul de pe tricou al marcatorului;
    int nrGoluriA;// goluri ADVERSAR ; A vine de la Adversar
    int *idMarcatoriA;// goluri ADVERSAR ; A vine de la Adversar
    bool meciAcasa;
    date dataMeci{}; // zi, luna, an sunt intializate cu 0

public:
    /// ----------CONSTRUCTORI------------

    //Cu toti parametrii;
    MeciJucat(string, string, int, int, int *, int, int *, bool, date);

    //Fara parametrii
    MeciJucat();

    //2 constructori cu cate un parametru
    MeciJucat(string numeAdversar);
    MeciJucat(bool meciAcasa);

    //Copy constructor
    MeciJucat(const MeciJucat &obj);

    ///------------GETTERS---------
    string getNumeAdversar()
    {
        return numeAdversar;
    }

    string getOraMeci()
    {
        return oraMeci;
    }

    int getNrGoluri()
    {
        return nrGoluri;
    }

    const int *getIdMarcatori()
    {
        return idMarcatori;
    }
    int getNrGoluriA()
    {
        return nrGoluriA;
    }

    const int *getIdMarcatoriA()
    {
        return idMarcatoriA;
    }

    bool getMeciAcasa()
    {
        return meciAcasa;
    }

    date getDataMeci()
    {
        return dataMeci;
    }

    ///----------SETTERS----------
    void setNumeAdversar(string numeAdversar)
    {
        this->numeAdversar = numeAdversar;
    }

    void setOraMeci(string oraMeci)
    {
        this->oraMeci = oraMeci;
    }

    void setNrGoluri(int nrGoluri)
    {
        this->nrGoluri = nrGoluri;
    }

    void setIdMarcatori(int *idMarcatori);

    void setNrGoluriA(int nrGoluriA)
    {
        this->nrGoluriA = nrGoluriA;
    }

    void setIdMarcatoriA(int *idMarcatoriA);

    void setMeciAcasa(bool meciAcasa)
    {
        this->meciAcasa = meciAcasa;
    }

    void setDataMeci(date dataMeci)
    {
        this->dataMeci = dataMeci;
    }

    ///-------DESTRUCTOR---------
    ~MeciJucat();

    ///--------SUPRAINCARCARI la OPERATORI----------

    //operatorul=
    MeciJucat &operator=(const MeciJucat &obj);
    //operatorul cin>>
    friend istream &operator>>(istream &in, MeciJucat &obj);
    //operatorul cout<<
    friend ostream &operator<<(ostream &, const MeciJucat &);

    //Operator + cu int din dreapta
    MeciJucat operator+(int s); // cresc spectatorii

    //Operator + cu int din stanga
    friend MeciJucat operator+(int s, MeciJucat obj); //cresc spectatorii

    //Operatorul de indexare[]
    int operator[](int index);

    //Operatorul ++ POST
    MeciJucat operator++(int);

    //Operatorul ++ PRE
    MeciJucat &operator++();

    //Operatorul +
    MeciJucat operator+(const MeciJucat &obj);

    //Operatorul cast implicit
    operator string();

    //Operatorul cast explicit
    operator string() const;

    //Operator conditional <
    bool operator<(const MeciJucat &obj);

    //Operator conditional ==
    bool operator==(const MeciJucat &obj);

    //Metoda proprie:
    string GetScor();

};

///------
/// FINAL DECLARATII CLASA MeciJucat
///------


/// SETTERI in afara MeciJucat
void MeciJucat::setIdMarcatori(int *idMarcatori)
{
    if (this->idMarcatori != NULL)
        delete[] this->idMarcatori;
    this->idMarcatori = new int[nrGoluri];
    for (int i = 0; i < nrGoluri; i++)
        this->idMarcatori[i] = idMarcatori[i];
}

void MeciJucat::setIdMarcatoriA(int *idMarcatoriA)
{
    if (this->idMarcatoriA != NULL)
        delete[] this->idMarcatoriA;
    this->idMarcatoriA = new int[nrGoluriA];
    for (int i = 0; i < nrGoluriA; i++)
        this->idMarcatoriA[i] = idMarcatoriA[i];
}

MeciJucat::~MeciJucat()
{
    if (this->idMarcatori != NULL)
        delete[] this->idMarcatori;
    if (this->idMarcatoriA != NULL)
        delete[] this->idMarcatoriA;
}

/// CONSTURCTORI

//Toti parametrii
MeciJucat::MeciJucat(string numeAdversar, string oraMeci, int mySpectatori, int nrGoluri, int *idMarcatori,
                     int nrGoluriA, int *idMarcatoriA, bool meciAcasa, date dataMeci)
    : numeAdversar(numeAdversar),
      oraMeci(oraMeci),
      mySpectatori(mySpectatori),
      nrGoluri(nrGoluri),
      nrGoluriA(nrGoluriA),
      meciAcasa(meciAcasa),
      dataMeci(dataMeci)
{

    this->idMarcatori = new int[nrGoluri];
    for (int i = 0; i < nrGoluri; i++)
        this->idMarcatori[i] = idMarcatori[i];

    this->idMarcatoriA = new int[nrGoluriA];
    for (int i = 0; i < nrGoluriA; i++)
        this->idMarcatoriA[i] = idMarcatoriA[i];

}

//Fara parametri
MeciJucat::MeciJucat()
{
    numeAdversar = "TBD";
    oraMeci = "TBD";
    mySpectatori = 0;
    nrGoluri = 0;
    idMarcatori = NULL;
    nrGoluriA = 0;
    idMarcatoriA = NULL;
    meciAcasa = false;
    dataMeci = {0, 0, 0};
}

//Cu cate un parametru
MeciJucat::MeciJucat(string numeAdversar)
{
    this->numeAdversar = numeAdversar;

    oraMeci = "TBD";
    nrGoluri = 0;
    mySpectatori = 0;
    idMarcatori = NULL;
    nrGoluriA = 0;
    idMarcatoriA = NULL;
    meciAcasa = false;
    dataMeci = {0, 0, 0};
}

MeciJucat::MeciJucat(bool meciAcasa)
{
    this->meciAcasa = meciAcasa;

    numeAdversar = "TBD";
    oraMeci = "TBD";
    nrGoluri = 0;
    mySpectatori = 0;
    idMarcatori = NULL;
    nrGoluriA = 0;
    idMarcatoriA = NULL;
    dataMeci = {0, 0, 0};
}

//COPY CONSTRUCTOR MeciJucat
MeciJucat::MeciJucat(const MeciJucat &obj)
{
    this->numeAdversar = obj.numeAdversar;
    this->oraMeci = obj.oraMeci;
    this->mySpectatori = obj.mySpectatori;
    this->nrGoluri = obj.nrGoluri;
    this->idMarcatori = new int[obj.nrGoluri];
    for (int i = 0; i < obj.nrGoluri; i++)
        this->idMarcatori[i] = obj.idMarcatori[i];
    this->nrGoluriA = obj.nrGoluriA;
    this->idMarcatoriA = new int[obj.nrGoluriA];
    for (int i = 0; i < obj.nrGoluriA; i++)
        this->idMarcatoriA[i] = obj.idMarcatoriA[i];
    this->meciAcasa = obj.meciAcasa;
    this->dataMeci = obj.dataMeci;
}

/// OPERATORI  pt MeciJucat

//OPERATORUL CIN pt MeciJucat
istream &operator>>(istream &in, MeciJucat &obj)
{
    cout << "Nume adversar: ";
    in.get();
    getline(in, obj.numeAdversar);
    cout << "Ora meci: ";
    getline(in, obj.oraMeci);

    cout << "Nr spectatori clubul meu: ";
    in >> obj.mySpectatori;

    cout << "Numar goluri clubul meu : ";
    in >> obj.nrGoluri;

    if (obj.idMarcatori != NULL)
        delete[] obj.idMarcatori;
    obj.idMarcatori = new int[obj.nrGoluri];
    for (int i = 0; i < obj.nrGoluri; i++)
    {
        cout << "Nr tricou marcator " << i + 1 << " club" << ": ";
        in >> obj.idMarcatori[i];
    }
    cout << "Numar goluri adversar: ";
    in >> obj.nrGoluriA;

    if (obj.idMarcatoriA != NULL)
        delete[] obj.idMarcatoriA;
    obj.idMarcatoriA = new int[obj.nrGoluriA];
    for (int i = 0; i < obj.nrGoluriA; i++)
    {
        cout << "Nr tricou marcator " << i + 1 << " adversar" << ": ";
        in >> obj.idMarcatoriA[i];
    }
    cout << "Acasa: ";
    in >> obj.meciAcasa;
    cout << "Zi meci: ";
    in >> obj.dataMeci.zi;
    cout << "Luna meci: ";
    in >> obj.dataMeci.luna;
    cout << "An meci: ";
    in >> obj.dataMeci.an;

    return in;
}

//OPERATORUL COUT pt MeciJucat
ostream &operator<<(ostream &out, const MeciJucat &obj)
{
    out << "Nume adversar: " << obj.numeAdversar << endl;
    out << "Ora meci: " << obj.oraMeci << endl;
    out << "Nr spectatori clubul meu: " << obj.mySpectatori << endl;
    out << "Numar goluri clubul meu: " << obj.nrGoluri << endl;
    for (int i = 0; i < obj.nrGoluri; i++)
        out << "Nr tricou marcator " << i + 1 << " club" << ": " << obj.idMarcatori[i] << endl;
    out << "Numar goluri adversar: " << obj.nrGoluriA << endl;
    for (int i = 0; i < obj.nrGoluriA; i++)
        cout << "Nr tricou marcator " << i + 1 << " adversar" << ": " << obj.idMarcatoriA[i] << endl;
    out << "Acasa: " << obj.meciAcasa << endl;
    cout << "Zi meci: ";
    out << obj.dataMeci.zi;
    cout << endl;
    cout << "Luna meci: ";
    out << obj.dataMeci.luna;
    cout << endl;
    cout << "An meci: ";
    out << obj.dataMeci.an;
    cout << endl;
    return out;
}

//OPERATOR EGAL= pt MeciJucat
MeciJucat &MeciJucat::operator=(const MeciJucat &obj)   // am nevoie de primul & deoarece atuncin cand fac & se creeaza un obiect copie inutil
{
    if (this != &obj)
    {
        if (this->idMarcatori != NULL)
            delete[] this->idMarcatori;//dezalocam ce e alocat dinamic si alocam iar
        if (this->idMarcatoriA != NULL)
            delete[] this->idMarcatoriA;

        this->numeAdversar = obj.numeAdversar;
        this->oraMeci = obj.oraMeci;
        this->mySpectatori = obj.mySpectatori;
        this->nrGoluri = obj.nrGoluri;
        this->idMarcatori = new int[obj.nrGoluri];
        for (int i = 0; i < obj.nrGoluri; i++)
            this->idMarcatori[i] = obj.idMarcatori[i];
        this->nrGoluriA = obj.nrGoluriA;
        this->idMarcatoriA = new int[obj.nrGoluriA];
        for (int i = 0; i < obj.nrGoluriA; i++)
            this->idMarcatoriA[i] = obj.idMarcatoriA[i];
        this->meciAcasa = obj.meciAcasa;
        this->dataMeci = obj.dataMeci;
    }
    return *this; // obiectul de la adresa curenta; pointer; obiectul de la adresa this; OBIECTUL DE LA REFERINTA AIA, FARA SA MAI FAC INCA O COPIE; COPY CONSTRUCTOR
}

//Operatorul + daca vine un int in dreapta (de ex. adaug inca un presedinte/actionar)
MeciJucat MeciJucat::operator+(int s)
{
    MeciJucat copie = *this;
    copie.mySpectatori = copie.mySpectatori + s;
    return copie;
}

// Am asigurat comutativitatea, astfel poate veni un string in stanga
MeciJucat operator+(int s, MeciJucat obj)
{
    obj.mySpectatori = obj.mySpectatori + s;
    return obj;
}

//Operatorul de indexare[] pt MeciJucat
int MeciJucat::operator[](int index)
{
    if (index >= 0 && index < this->nrGoluri)
        return this->idMarcatori[index];
    else throw runtime_error("Index invalid");
} //primesc marcatorul golului i al echipei mele

//Operatorul ++ pt MeciJucat
MeciJucat MeciJucat::operator++(int) //anunt post incrementarea prin int //se adauga o mie de specatatori
{
    MeciJucat copie = *this; //merg la adresa this;

    this->mySpectatori += 1000;
    return copie;
}

//Pre-incrementare ++ pt MeciJucat
MeciJucat &MeciJucat::operator++()
{
    this->mySpectatori += 1000;

    return *this;

}

//Operatorul + pt MeciJucat
MeciJucat MeciJucat::operator+(const MeciJucat &obj)
{
    MeciJucat copie = *this;

    copie.numeAdversar = copie.numeAdversar + " si " + obj.numeAdversar;
    copie.oraMeci = copie.oraMeci + " si " + obj.oraMeci;
    copie.mySpectatori = copie.mySpectatori + obj.mySpectatori;

    int *vect = new int[copie.nrGoluri + obj.nrGoluri];
    for (int i = 0; i < copie.nrGoluri; i++)
        vect[i] = copie.idMarcatori[i];
    for (int i = 0; i < obj.nrGoluri; i++)
        vect[i + copie.nrGoluri] = obj.idMarcatori[i];

    if (copie.idMarcatori != NULL) delete[] copie.idMarcatori;
    if (obj.idMarcatori != NULL) delete[] obj.idMarcatori;

    copie.idMarcatori = vect;

    copie.nrGoluri += obj.nrGoluri;

    int *vect2 = new int[copie.nrGoluriA + obj.nrGoluriA];
    for (int i = 0; i < copie.nrGoluriA; i++)
        vect[i] = copie.idMarcatoriA[i];
    for (int i = 0; i < obj.nrGoluriA; i++)
        vect[i + copie.nrGoluriA] = obj.idMarcatoriA[i];

    if (copie.idMarcatoriA != NULL) delete[] copie.idMarcatoriA;
    if (obj.idMarcatoriA != NULL) delete[] obj.idMarcatoriA;

    copie.idMarcatoriA = vect2;

    copie.nrGoluriA += obj.nrGoluriA;
    copie.meciAcasa = 0;
    copie.dataMeci = {0, 0, 0};

    return copie;

}

//Operatorul cast implicit pt MeciJucat
MeciJucat::operator string()   //avanpremiera meci
{
    string s = "Adversar: " + numeAdversar + " la ora: " + oraMeci + " in data de " + to_string(dataMeci.zi) + "/"
               + to_string(dataMeci.luna) + "/" + to_string(dataMeci.an);
    return s;
}

//Operatorul cast explicit pt MeciJucat
MeciJucat::operator string() const   //avanpremiera meci
{
    string s = "Adversar: " + numeAdversar + " la ora: " + oraMeci + " in data de " + to_string(dataMeci.zi) + "/"
               + to_string(dataMeci.luna) + "/" + to_string(dataMeci.an);

    return s;
}

//Operator conditional < pt MeciJucat
bool MeciJucat::operator<(const MeciJucat &obj)
{
    return this->mySpectatori < obj.mySpectatori;
}

//Operator conditional == pt MeciJucat
bool MeciJucat::operator==(const MeciJucat &obj)
{
    bool ok = 1;

    if (this->numeAdversar != obj.numeAdversar) ok = 0;
    if (this->oraMeci != obj.oraMeci) ok = 0;
    if (this->mySpectatori != obj.mySpectatori) ok = 0;
    if (this->meciAcasa != obj.meciAcasa) ok = 0;
    if (this->nrGoluri != obj.nrGoluri) ok = 0;
    if (this->nrGoluri == obj.nrGoluri)
        for (int i = 0; i < this->nrGoluri; i++)
            if (this->idMarcatori[i] != obj.idMarcatori[i]) ok = 0;

    if (this->nrGoluriA != obj.nrGoluriA) ok = 0;
    if (this->nrGoluriA == obj.nrGoluriA)
        for (int i = 0; i < this->nrGoluriA; i++)
            if (this->idMarcatoriA[i] != obj.idMarcatoriA[i]) ok = 0;
    if ((this->dataMeci.zi != obj.dataMeci.zi) || (this->dataMeci.luna != obj.dataMeci.luna)
            || (this->dataMeci.an != obj.dataMeci.an))
        ok = 0;

    return ok;

}

//METODA PROPRIE

string MeciJucat::GetScor()
{
    string s = "";
    if (meciAcasa)
        s = to_string(nrGoluri) + " - " + to_string(nrGoluriA) + " meci jucat acasa.";
    else
        s = to_string(nrGoluriA) + " - " + to_string(nrGoluri) + " meci jucat in delpasare.";
    return s;
}

///-----------------------
/// FINAL CONTINUT CLASA MeciJucat
///---------------------


///Clasa pt fiecare jucator
class JucatorClub
{
private:
    const int id;
    static int CONTORID;

    char *numeComplet;
    string postTeren;
    char nrTricou[3];
    int valoareSalariu; //pe luna, in euro
    int nrBonusuri;
    int *valoareBonusuri;
    float greutateKg; //in kg
    double inaltimeCm; // in cm
    date dataNastere{};

public:

    /// -------CONSTRUCTORI--------

    //Cu toti parametrii;
    JucatorClub(char *, string, char *, int, int, int *, float, double, date);

    //Fara parametrii
    JucatorClub();

    //2 constructori cu cate un parametru
    JucatorClub(int valoareSalariu);
    JucatorClub(char *nrTricou);

    //Copy constructor
    JucatorClub(const JucatorClub &obj);

    ///------GETTERS---------
    static int getCONTORID()
    {
        return CONTORID;
    }

    const char *getNumeComplet()
    {
        return numeComplet;
    }
    string getPostTeren()
    {
        return postTeren;
    }

    char *getNrTricou()
    {
        return nrTricou;
    }

    int getValoareSalariu()
    {
        return valoareSalariu;
    }

    int getNrBonusuri()
    {
        return nrBonusuri;
    }

    const int *getValoareBonusuri()
    {
        return valoareBonusuri;
    }

    float getGreutateKg()
    {
        return greutateKg;
    }

    double getInaltimeCm()
    {
        return inaltimeCm;
    }

    date getDataNastere()
    {
        return dataNastere;
    }

    ///----------SETTERS-----------
    void setNumeComplet(char *numeComplet);

    void setPostTeren(string postTeren)
    {
        this->postTeren = postTeren;
    }

    void setNrTricou(char *nrTricou)
    {
        strcpy(this->nrTricou, nrTricou);
    }

    void setValoareSalariu(int valoareSalariu)
    {
        this->valoareSalariu = valoareSalariu;
    }

    void setNrBonusuri(int nrBonusuri)
    {
        this->nrBonusuri = nrBonusuri;
    }

    void setValoareBonusuri(int *valoareBonusuri);

    void setGreutateKg(float greutateKg)
    {
        this->greutateKg = greutateKg;
    }
    void setInaltimeCm(double inaltimeCm)
    {
        this->inaltimeCm = inaltimeCm;
    }
    void setDataNastere(date dataNastere)
    {
        this->dataNastere = dataNastere;
    }

    ///-----DESTRUCTOR-----
    ~JucatorClub();

    /// ------SUPRAINCARCARI OPERATORI---------

    //operatorul=
    JucatorClub &operator=(const JucatorClub &obj); //JucatorClub a, b; a= b
    //operatorul cin>>
    friend istream &operator>>(istream &in, JucatorClub &obj);
    //operatorul cout<<
    friend ostream &operator<<(ostream &, const JucatorClub &);

    //Operator + cu int din dreapta
    int operator+(int s); //cresc salariul

    //Operator + cu int din stanga
    friend int operator+(int s, JucatorClub obj); //cresc salariul

    //Operatorul de indexare[]
    int operator[](int index);

    //Operatorul ++ POST
    JucatorClub operator++(int);

    //Operatorul ++ PRE
    JucatorClub &operator++();

    //Operatorul +
    JucatorClub operator+(const JucatorClub &obj);

    //Operatorul cast implicit
    operator string();

    //Operatorul cast explicit
    operator string() const;

    //Operator conditional <
    bool operator<(const JucatorClub &obj);

    //Operator conditional ==
    bool operator==(const JucatorClub &obj);

    //Metoda proprie:
    int VarstaJucator();

    //Metoda proprie 2:
    int SumaContract();
};
///----------
///FINAL CLASA JucatorClub
///----------


int JucatorClub::CONTORID = 1000; // initializez static-ul
//In C++, JucatorClub:: is the scope resolution operator.
// It's used to specify that a function or member belongs
// to the JucatorClub.

//SETTERS outside JucatorClub
void JucatorClub::setNumeComplet(char *numeComplet)
{
    if (this->numeComplet != NULL)
        delete[] this->numeComplet;
    this->numeComplet = new char[strlen(numeComplet) + 1];
    strcpy(this->numeComplet, numeComplet);
}

void JucatorClub::setValoareBonusuri(int *valoareBonusuri)
{
    if (this->valoareBonusuri != NULL)
        delete[] this->valoareBonusuri;
    this->valoareBonusuri = new int[nrBonusuri];
    for (int i = 0; i < nrBonusuri; i++)
        this->valoareBonusuri[i] = valoareBonusuri[i];
}

/// ------Constructori JucatorClub---------
JucatorClub::JucatorClub(char *numeComplet, string postTeren, char *nrTricou, int valoareSalariu,
                         int nrBonusuri, int *valoareBonusuri, float greutateKg,
                         double inaltimeCm,
                         date dataNastere) : id(CONTORID++), postTeren(postTeren), valoareSalariu(valoareSalariu),
    nrBonusuri(nrBonusuri), greutateKg(greutateKg), inaltimeCm(inaltimeCm),
    dataNastere(dataNastere)
{
    this->numeComplet = new char[strlen(numeComplet) + 1];
    strcpy(this->numeComplet, numeComplet);

    strcpy(this->nrTricou, nrTricou);

    this->valoareBonusuri = new int[nrBonusuri];
    for (int i = 0; i < nrBonusuri; i++)
        this->valoareBonusuri[i] = valoareBonusuri[i];
}

//Fara parametrii
JucatorClub::JucatorClub() : id(CONTORID++)
{
    numeComplet = new char[strlen("empty") + 1];
    strcpy(numeComplet, "empty");
    postTeren = "empty";
    strcpy(nrTricou, "XX");
    valoareSalariu = 0;
    nrBonusuri = 0;
    valoareBonusuri = NULL;
    greutateKg = 0;
    inaltimeCm = 0;
    dataNastere = {0, 0, 0};
}

//Cu un parametru
JucatorClub::JucatorClub(int valoareSalariu) : id(CONTORID++)
{
    this->valoareSalariu = valoareSalariu;

    numeComplet = new char[strlen("empty") + 1];
    strcpy(numeComplet, "empty");
    postTeren = "empty";
    strcpy(nrTricou, "XX");
    nrBonusuri = 0;
    valoareBonusuri = NULL;
    greutateKg = 0;
    inaltimeCm = 0;
    dataNastere = {0, 0, 0};
}

JucatorClub::JucatorClub(char *nrTricou) : id(CONTORID++)
{
    strcpy(this->nrTricou, nrTricou);

    numeComplet = new char[strlen("empty") + 1];
    strcpy(numeComplet, "empty");
    postTeren = "empty";
    valoareSalariu = 0;
    nrBonusuri = 0;
    valoareBonusuri = NULL;
    greutateKg = 0;
    inaltimeCm = 0;
    dataNastere = {0, 0, 0};
}

//Copy constructor
JucatorClub::JucatorClub(const JucatorClub &obj) : id(CONTORID)
{
    this->numeComplet = new char[strlen(obj.numeComplet) + 1];
    strcpy(this->numeComplet, obj.numeComplet);
    this->postTeren = obj.postTeren;
    strcpy(this->nrTricou, obj.nrTricou);
    this->valoareSalariu = obj.valoareSalariu;
    this->nrBonusuri = obj.nrBonusuri;
    this->valoareBonusuri = new int[obj.nrBonusuri];
    for (int i = 0; i < obj.nrBonusuri; i++)
        this->valoareBonusuri[i] = obj.valoareBonusuri[i];
    this->greutateKg = obj.greutateKg;
    this->inaltimeCm = obj.inaltimeCm;
    this->dataNastere = obj.dataNastere;
}

/// Destructor:
JucatorClub::~JucatorClub()
{
    if (this->valoareBonusuri != NULL) delete[] this->valoareBonusuri;
    if (this->numeComplet != NULL) delete[] this->numeComplet;
}

/// OPERATORI:

//OPERATORUL EGAL pt JucatorClub
JucatorClub &JucatorClub::operator=(const JucatorClub &obj)   // am nevoie de primul & deoarece atuncin cand fac & se creeaza un obiect copie inutil
{
    if (this != &obj)
    {
        if (this->valoareBonusuri != NULL)
            delete[] this->valoareBonusuri;//dezalocam ce e alocat dinamic si alocam iar
        if (this->numeComplet != NULL)
            delete[] this->numeComplet;

        this->numeComplet = new char[strlen(obj.numeComplet) + 1];
        strcpy(this->numeComplet, obj.numeComplet);
        this->postTeren = obj.postTeren;
        strcpy(this->nrTricou, obj.nrTricou);
        this->valoareSalariu = obj.valoareSalariu;
        this->nrBonusuri = obj.nrBonusuri;
        this->valoareBonusuri = new int[obj.nrBonusuri];
        for (int i = 0; i < obj.nrBonusuri; i++)
            this->valoareBonusuri[i] = obj.valoareBonusuri[i];
        this->greutateKg = obj.greutateKg;
        this->inaltimeCm = obj.inaltimeCm;
        this->dataNastere = obj.dataNastere;
    }

    return *this; // obiectul de la adresa curenta; pointer; obiectul de la adresa this; OBIECTUL DE LA REFERINTA AIA, FARA SA MAI FAC INCA O COPIE; COPY CONSTRUCTOR

}

//OPERATORUL CIN pt JucatorClub
istream &operator>>(istream &in, JucatorClub &obj)
{
    char nume[255];
    cout << "Nume complet fotbalist: ";
    in.get();
    in.getline(nume, 255);
    if (obj.numeComplet != NULL)
        delete[] obj.numeComplet;
    obj.numeComplet = new char[strlen(nume) + 1];
    strcpy(obj.numeComplet, nume);
    cout << "Post teren: ";
    getline(in, obj.postTeren);
    cout << "Numar tricou: ";
    in.getline(obj.nrTricou, 3);
    cout << "Valoare salariu lunar: ";
    in >> obj.valoareSalariu;
    cout << "Numarul de bonusuri din contract: ";
    in >> obj.nrBonusuri;

    if (obj.valoareBonusuri != NULL)
        delete[] obj.valoareBonusuri;
    obj.valoareBonusuri = new int[obj.nrBonusuri];
    for (int i = 0; i < obj.nrBonusuri; i++)
    {
        cout << "Bonus " << i + 1 << ": ";
        in >> obj.valoareBonusuri[i];
    }
    cout << "Greutate fotbalist (kg): ";
    in >> obj.greutateKg;
    cout << "Inaltime fotbalist (cm): ";
    in >> obj.inaltimeCm;

    cout << "Zi nastere: ";
    in >> obj.dataNastere.zi;
    cout << "Luna nastere: ";
    in >> obj.dataNastere.luna;
    cout << "An nastere: ";
    in >> obj.dataNastere.an;

    return in;
}

//OPERATORUL COUT pt JucatorClub
ostream &operator<<(ostream &out, const JucatorClub &obj)
{
    out << "Nume fotbalist: " << obj.numeComplet << endl;
    out << "Post fotbalist: " << obj.postTeren << endl;
    out << "Numar tricou: #" << obj.nrTricou << endl;
    out << "Salariu lunar: " << obj.valoareSalariu << endl;
    out << "Numar de bonusuri din contract: " << obj.nrBonusuri << endl;
    for (int i = 0; i < obj.nrBonusuri; i++)
        out << "Bonus " << i + 1 << ": " << obj.valoareBonusuri[i] << endl;
    out << "Greutate (kg): " << obj.greutateKg << endl;
    out << "Inaltime (cm): " << obj.inaltimeCm << endl;
    cout << "Zi nastere: ";
    out << obj.dataNastere.zi;
    cout << endl;
    cout << "Luna nastere: ";
    out << obj.dataNastere.luna;
    cout << endl;
    cout << "An nastere: ";
    out << obj.dataNastere.an;
    cout << endl;
    return out;
}
//Operatorul + daca vine un int
int JucatorClub::operator+(int s)
{
    JucatorClub copie = *this;
    int s1 =  copie.valoareSalariu + s;
    return s1;
}

// --S-a crescut salariul

// Am asigurat comutativitatea, astfel poate veni un int in stanga
int operator+(int s, JucatorClub obj)
{
    int s1= obj.valoareSalariu + s;
    return s1;
}



//Operatorul de indexare[] pt JucatorClub
int JucatorClub::operator[](int index)
{
    if (index >= 0 && index < this->nrBonusuri)
        return this->valoareBonusuri[index];
    else throw runtime_error("Index invalid");
}

//Operatorul ++ pt JucatorClub
JucatorClub JucatorClub::operator++(int) //anunt post incrementarea prin int
{
    JucatorClub copie = *this; //merg la adresa this;

    this->valoareSalariu += 1000;

    return copie; // fac copie ca sa fac incrementarA ++ POSTt
}//cresc salariul cu 1000 euro

JucatorClub &JucatorClub::operator++()
{
    this->valoareSalariu += 1000;

    return *this;
}//cresc salariul cu 1000 euro

//Operatorul + pt JucatorClub
JucatorClub JucatorClub::operator+(const JucatorClub &obj)
{
    JucatorClub copie = *this;

    strcpy(copie.numeComplet, strcat(copie.numeComplet, " si "));
    strcpy(copie.numeComplet, strcat(copie.numeComplet, obj.numeComplet));

    strcpy(copie.nrTricou, strcat(copie.nrTricou, " si "));
    strcpy(copie.nrTricou, strcat(copie.nrTricou, obj.nrTricou));

    copie.postTeren = copie.postTeren + " si " + obj.postTeren;
    copie.valoareSalariu = copie.valoareSalariu + obj.valoareSalariu;

    int *vect = new int[copie.nrBonusuri + obj.nrBonusuri];
    for (int i = 0; i < copie.nrBonusuri; i++)
        vect[i] = copie.valoareBonusuri[i];
    for (int i = 0; i < obj.nrBonusuri; i++)
        vect[i + copie.nrBonusuri] = obj.valoareBonusuri[i];

    if (copie.valoareBonusuri != NULL) delete[] copie.valoareBonusuri;
    if (obj.valoareBonusuri != NULL) delete[] obj.valoareBonusuri;

    copie.valoareBonusuri = vect;

    copie.nrBonusuri += obj.nrBonusuri;

    copie.greutateKg += obj.greutateKg;
    copie.inaltimeCm += obj.inaltimeCm;

    copie.dataNastere = {0, 0, 0};

    return copie;

}

//Operatorul cast implicit pt JucatorClub
JucatorClub::operator string()
{
    string s = "";
    string t = "";
    string strNrTricou(this->nrTricou);
    string strNumeComplet(this->numeComplet);
    for (int i = 0; i < this->nrBonusuri; i++)
        t += to_string(this->valoareBonusuri[i]) + ", ";

    s = strNumeComplet + ", " + this->postTeren + " ,Nr.tricou: " + strNrTricou + ", Salariu: "
        + to_string(this->valoareSalariu) + ", "
        + to_string(this->nrBonusuri) + " bonusuri: " + t + ", Data nastere: " + to_string(this->dataNastere.zi) + "/"
        + to_string(this->dataNastere.luna) + "/" + to_string(this->dataNastere.an) + " ,Greutate(kg): "
        + to_string(this->greutateKg)
        + " ,Inaltime(cm)" + to_string(this->inaltimeCm);
    return s;
}

//Operatorul cast explicit pt JucatorClub
JucatorClub::operator string() const
{
    string s = "";
    string t = "";
    string strNrTricou(this->nrTricou);
    string strNumeComplet(this->numeComplet);
    for (int i = 0; i < this->nrBonusuri; i++)
        t += to_string(this->valoareBonusuri[i]) + ", ";

    s = strNumeComplet + ", " + this->postTeren + " ,Nr.tricou: " + strNrTricou + ", Salariu: "
        + to_string(this->valoareSalariu) + ", "
        + to_string(this->nrBonusuri) + " bonusuri: " + t + ", Data nastere: " + to_string(this->dataNastere.zi) + "/"
        + to_string(this->dataNastere.luna) + "/" + to_string(this->dataNastere.an) + " ,Greutate(kg): "
        + to_string(this->greutateKg)
        + " ,Inaltime(cm)" + to_string(this->inaltimeCm);
    return s;
}

//Operator conditional < pt JucatorClub
bool JucatorClub::operator<(const JucatorClub &obj)
{
    return this->valoareSalariu < obj.valoareSalariu;
}

//Operator conditional == pt JucatorClub
bool JucatorClub::operator==(const JucatorClub &obj)
{
    bool ok = 1;

    if (this->numeComplet != obj.numeComplet) ok = 0;
    if (this->postTeren != obj.postTeren) ok = 0;
    if (strcmp(this->nrTricou, obj.nrTricou) != 0) ok = 0;
    if (this->greutateKg != obj.greutateKg) ok = 0;
    if (this->inaltimeCm != obj.inaltimeCm) ok = 0;
    if (this->valoareSalariu != obj.valoareSalariu) ok = 0;
    if (this->nrBonusuri != obj.nrBonusuri) ok = 0;
    if (this->nrBonusuri == obj.nrBonusuri)
        for (int i = 0; i < this->nrBonusuri; i++)
            if (this->valoareBonusuri[i] != obj.valoareBonusuri[i]) ok = 0;
    if ((this->dataNastere.zi != obj.dataNastere.zi) || (this->dataNastere.luna != obj.dataNastere.luna)
            || (this->dataNastere.an != obj.dataNastere.an))
        ok = 0;

    return ok;
}

//METODA PROPRIE

int JucatorClub::VarstaJucator()
{
    int varsta;
    time_t t = time(NULL); //am pus NULL ca sa obtin data curenta;
    //time_t - calendar time in seconds
    tm timeInfo = *localtime(&t);
    // tm face parte din clasa ctime si imi sparge calendar time in ani-zile-luni
    //localtime este o functie din clasa ctime care converteste calendar time-ul in tm; returneaza un pointer, de aceea folosesc * ca sa il dereferntiez

    int current_year = 1900 + timeInfo.tm_year;
    int current_month = 1 + timeInfo.tm_mon; // Adăugăm 1 pentru că lunile sunt indexate de la 0
    int current_day = timeInfo.tm_mday;

    if (current_year >= dataNastere.an && current_month >= dataNastere.luna && current_day >= dataNastere.zi)
        varsta =current_year - dataNastere.an;
    else varsta = current_year - dataNastere.an - 1;

    return varsta;
}

int JucatorClub::SumaContract() //suma totala maxima din contract (in cazul in care sunt atinse toate bonusurile din contract)
{
    int s = 0;
    s = valoareSalariu * 12;
    for (int i = 0; i < nrBonusuri; i++)
        s += valoareBonusuri[i];
    return s;
}

///--------------------------
/// FINAL CONTINUT JucatorClub
///--------------------------


///AM SUPRAINCARAT OPERATORUL PLUS PT CLASELE JucatorClub si StaffMembru, astfel incat
///pot aduna salariile angajatilor din club si pot calcula bugetul lunar de salarii
int operator+(JucatorClub& jucator,  StaffMembru& staff)
{
    return jucator.getValoareSalariu() + staff.getValoareSalariu();
}
int operator+(StaffMembru& staff, JucatorClub& jucator)
{
    return staff.getValoareSalariu() + jucator.getValoareSalariu();
}
int operator+(JucatorClub& jucator,  JucatorClub& jucator2)
{
    return jucator.getValoareSalariu() + jucator2.getValoareSalariu();
}
int operator+(StaffMembru& staff,  StaffMembru& staff2)
{
    return staff.getValoareSalariu() + staff2.getValoareSalariu();
}

//transform stringurile in majuscule
string toUpper(string str)
{
    string upper;
    for (char c : str)
    {
        upper += toupper(c);
    }
    return upper;
}
///----INCEPE MENIUL INTERACTIV----

int main()
{

    vector <JucatorClub> jucatori;
    vector <StaffMembru> stafftehnic;
    vector <MeciJucat> meciuri;
    ClubInfo club;
    int k = 1;

    cout << "Bine ai venit! \nIncepe administrarea clubului tau de fotbal.\nMai intai incepe prin introducerea informatiilor principale despre club:\n\n";
    cin >> club;
    cout<<"\nAi introdus urmatoarele date despre club:\n\n" << club;

    while(k==1)
    {
        cout<<"\n CLUBUL TAU: " <<club.getNumeClub()<<"\n";
        cout<<"\n 1 Adauga jucator: \n ";
        cout<<"\n 2 Afiseaza jucatori: \n ";

        cout<<"\n 3 Adauga membru in staff: \n ";
        cout<<"\n 4 Afiseaza staff: \n ";

        cout<<"\n 5 Adauga meci: \n ";
        cout<<"\n 6 Afiseaza meciuri: \n ";

        cout<<"\n 7 Elimina jucator: \n ";
        cout<<"\n 8 Elimina membru staff: \n ";

        cout<<"\n 9 Exit \n ";

        int comanda;
        cin>>comanda;

        switch(comanda)
        {
        case 1:
        {
            JucatorClub j;
            cin>>j;
            jucatori.push_back(j);
            break; //adaug jucator
        }
        case 2:
        {
            for(int i=0; i<jucatori.size(); i++)
                cout << endl<<jucatori[i] <<endl;
            break; //afisez jucatorii
        }
        case 3:
        {
            StaffMembru s;
            cin>>s;
            stafftehnic.push_back(s);
            break; //adaug membru in staff
        }
        case 4:
        {
            for(int i=0; i<stafftehnic.size(); i++)
                cout << endl<<stafftehnic[i] <<endl;
            break; //afisez stafful
        }
        case 5:
        {
            MeciJucat m;
            cin>>m;
            meciuri.push_back(m);
            break; //adaug meci jucat
        }
        case 6:
        {
            for(int i=0; i<meciuri.size(); i++)
                cout << endl <<meciuri[i] <<endl;
            break; //afisez rezultate
        }
        case 7:
        {
            int i1 = -1;
            string j2;
            cout << "Jucatorul eliminat (nume complet): \n";
            cin.get();
            getline(cin, j2); //primesc numele jucatorului care trebuie eliminat
            for(int i=0; i<jucatori.size(); i++)
            {
                string h(jucatori[i].getNumeComplet());
                if (toUpper(j2)==toUpper(h))
                {
                    i1 = i; //caut indexul in array
                    break;
                }
            }

            if(i1>=0)jucatori.erase(jucatori.begin() + i1); //sterg jucatorul de la indexul care corespunde numelui

            for(int i=0; i<jucatori.size(); i++)
                cout << endl <<jucatori[i] <<endl;
            break; //afisez jucatorii
        }
        case 8:
        {
            int i1 = -1;
            string j2;
            cout << "Membrul eliminat (nume complet): \n";
            cin.get();
            getline(cin, j2);
            for(int i=0; i<stafftehnic.size(); i++)
            {
                if (toUpper(j2)==toUpper(stafftehnic[i].getNumeComplet()))
                {
                    i1 = i;
                    break;
                }
            }

            if(i1>=0)stafftehnic.erase(stafftehnic.begin() + i1);

            for(int i=0; i<stafftehnic.size(); i++)
                cout << endl <<stafftehnic[i] <<endl;
            break; //analog ca la cazul 7
        }
        case 9:
        default:
        {
            k=0;
            break; // se introduce 9 sau orice altceva am terminat programul
        }
        }
    }

    return 0;
}


