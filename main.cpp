#include <string>
#include <iostream>
#include <vector>
class masina{
    std::string marca;
    std::string model;
    std::string culoare;
    std::string nrNmatriculare;
    std::string capacitate;
    std::string tarifOra;
    std::string tarifZi;
    int nr=1;
public:
    masina(const std::string &culoare, const std::string &nrNmatriculare, const std::string &capacitate,
           const std::string &marca, const std::string &model, const std::string &tarifOra, const std::string &tarifZi
    ) : culoare(culoare), nrNmatriculare(nrNmatriculare), capacitate(capacitate), marca(marca),
        model(model), tarifOra(tarifOra), tarifZi(tarifZi) {}

    friend std::ostream &operator<<(std::ostream &os, const masina &masina) {
        os << "\nmarca: " << masina.marca << " model: " << masina.model << " culoare: " << masina.culoare
           << " nrNmatriculare: " << masina.nrNmatriculare << " capacitate: " << masina.capacitate << " tarifOra: "
           << masina.tarifOra << " tarifZi: " << masina.tarifZi << " nr: " << masina.nr;
        return os;
    }


    void schimba(std::string a){
        if(nrNmatriculare.compare(a)==0){
            nr=0;}
    }

    int getNr() const {
        return nr;
    }
    masina (const masina& copie):
            marca(copie.marca), model(copie.model), culoare(copie.culoare),nrNmatriculare(copie.nrNmatriculare),nr(copie.nr),tarifZi(copie.tarifZi),capacitate(copie.capacitate),tarifOra(copie.tarifOra){}

};
class cautare{
    std::string nume;
    std::vector<masina>masini;
public:
    cautare(const std::string &nume, const std::vector<masina> &masini) : nume(nume), masini(masini) {}

    void adauga(const masina&masina){
        masini.push_back(masina);
    }
    std::string a;
    void search(){
        std::string a;std::cout<<"\nIntroduce-ti numarul de enmatriculare al masinii alese:";std::cin>>a;
        for(int i=0;i<masini.size();i++)
            masini[i].schimba(a);
    }
    void afis_nr(int i){
        std::cout<<masini[i].getNr();
    }
};
class client{
    std::string id;
    std::string nume;
    std::string nrTel;
    std::string adresa;
public:
    client(const std::string &id, const std::string &nume, const std::string &nrTel, const std::string &adresa) : id(
            id), nume(nume), nrTel(nrTel), adresa(adresa) {}

    friend std::ostream &operator<<(std::ostream &os, const client &client) {
        os << "\nid: " << client.id << " nume: " << client.nume << " nrTel: " << client.nrTel << " adresa: "
           << client.adresa;
        return os;
    }
    client (const client& copie):
            nume(copie.nume), nrTel(copie.nrTel), id(copie.id),adresa(copie.adresa){}


};

class cont {
    std::string user;
    std::string parola;
public:
    cont(const std::string &user, const std::string &parola) : user(user), parola(parola) {}

    const std::string &getUser() const {
        return user;
    }

    friend std::ostream &operator<<(std::ostream &os, const cont &cont) {
        os << "Utilizator: " << cont.user << " Parola: " << cont.parola;
        return os;
    }

    void dif() {
        std::cout<<"\nAcest nume utilizator este folosit: ";std::cin>>user;

    }

};
class verif{
    std::string nume;
    std::vector<cont>conturi;
public:
    verif(const std::string &nume, const std::vector<cont> &conturi) : nume(nume), conturi(conturi) {}

    void adauga(const cont&cont){
        conturi.push_back(cont);
    }
    void cautare(int &x){
        int n;
        x=0;
        for(int i=0;i<conturi.size()-1;i++){
            n=conturi.size();
            if (n > 1) {
                if(conturi[n-1].getUser().compare(conturi[i].getUser())==0){
                    conturi[n-1].dif();
                    x=1;
                }

            }
        }

    }
    std::string afis_user(int i){
        return conturi[i].getUser();
    }
};


int main() {
    cont dorel{"nucu","maca"};
    cont andrei{"nucu","vaca"};
    std::cout<<dorel;
    verif pac{"parc auto",{dorel,andrei}};
    int x=1;
    while(x!=0)
        pac.cautare(x);
    std::cout<<pac.afis_user(1);
    masina nr1{"negru","PH27POC","7","Ford","Mustang","50","1000"};
    std::cout<<"\n"<<nr1;
    client c1{"501234","Andrei","023455566","mareseanu nr1"};
    std::cout<<c1;
    cautare car{"t1",{nr1}};
    car.search();
    car.afis_nr(0);
    if(nr1.getNr()==1)
        std::cout<<"\nNu exista nicio masina cu acest numar";
    return 0;
}//
// Created by Steff on 11/15/2021.
//

