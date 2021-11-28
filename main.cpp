#include <string>
#include <iostream>
#include <vector>
class masina{
    std::string marca;
    std::string model;
    std::string culoare;
    int nrInmatriculare;
    std::string capacitate;
    int tarifOra;

public:
    masina(const std::string &marca, const std::string &model, const std::string &culoare, int nrInmatriculare,
           const std::string &capacitate, int tarifOra) : marca(marca), model(model), culoare(culoare),
                                                          nrInmatriculare(nrInmatriculare), capacitate(capacitate),
                                                          tarifOra(tarifOra) {}

    friend std::ostream &operator<<(std::ostream &os, const masina &masina) {
        os << "marca: " << masina.marca << " model: " << masina.model << " culoare: " << masina.culoare
           << " nrInmatriculare: " << masina.nrInmatriculare << " capacitate: " << masina.capacitate << " tarifOra: "
           << masina.tarifOra;
        return os;
    }


    void setNrInmatriculare1(int nrInmatriculare) {
        masina::nrInmatriculare = nrInmatriculare;
    }

    int getNrInmatriculare() const {
        return nrInmatriculare;
    }

    void setCuloare(const std::string &culoare) {
        masina::culoare = culoare;
    }

    masina& operator=(const masina& copie) {
        this->marca = copie.marca;
        this->model = copie.model;
        this->capacitate = copie.capacitate;
        this->nrInmatriculare = copie.nrInmatriculare;
        this->tarifOra = copie.tarifOra;
        return *this;
    }
    masina(const masina& copie)
    {
        this->marca = copie.marca;
        this->model = copie.model;
        this->capacitate = copie.capacitate;
        this->tarifOra = copie.tarifOra;
        this->nrInmatriculare = copie.nrInmatriculare;
    }



    const std::string &getModel() const {
        return model;
    }

    int getTarifOra() const {
        return tarifOra;
    }

};

class client{
    int id;
    std::string nume;
    int nrTel;
    int nrOre;
    std::string adresa;
    std::string user;
    std::string parola;
    int nr_inchirieri;
    masina masina1;
public:
    client(int id, const std::string &nume, int nrTel, int nrOre, const std::string &adresa, const std::string &user,
           const std::string &parola, int nrInchirieri, const masina &masina1) : id(id), nume(nume), nrTel(nrTel),
                                                                                 nrOre(nrOre), adresa(adresa),
                                                                                 user(user), parola(parola),
                                                                                 nr_inchirieri(nrInchirieri),
                                                                                 masina1(masina1) {}

    friend std::ostream &operator<<(std::ostream &os, const client &client) {
        os << "id: " << client.id << " nume: " << client.nume << " nrTel: " << client.nrTel << " nrOre: "
           << client.nrOre << " adresa: " << client.adresa << " user: " << client.user << " parola: " << client.parola
           << " nr_inchirieri: " << client.nr_inchirieri << " masina1: " << client.masina1;
        return os;
    }

    void setNrOre(int nrOre) {
        client::nrOre = nrOre;
    }

    int set_pret_inchiriere(){//aplic o reducere celor care au inchiriat mai mult de 2 masini si celor ce sunt la prima inchiriere
        if(nr_inchirieri>2 && nr_inchirieri<5)
            return nrOre*masina1.getTarifOra()-(nrOre*masina1.getTarifOra())/0.05;
        else
            if(nr_inchirieri>4)
                return nrOre*masina1.getTarifOra()-(nrOre*masina1.getTarifOra())/0.10;
            else
                if(nr_inchirieri==0)
                    return nrOre*masina1.getTarifOra()-(nrOre*masina1.getTarifOra())/0.03;
                else
                    return nrOre*masina1.getTarifOra();
    }

    const std::string &getUser() const {
        return user;
    }

    const std::string &getParola() const {
        return parola;
    }

    const masina &getMasina() const {
        return masina1;
    }

    void setMasina1(const masina &masina1) {
        client::masina1 = masina1;
    }
};


class aplicatie1{
    std::vector<int>status_inchirieri;//un vector care semnaleaza cu 1 daca masina este inchiriata
    std::vector<class client>clienti;
    std::vector<class masina>masini;
public:
    aplicatie1(const std::vector<int> &statusInchirieri, const std::vector<struct client> &clienti,
               const std::vector<struct masina> &masini) : status_inchirieri(statusInchirieri), clienti(clienti),
                                                           masini(masini) {}



    class client set_masina_client(class client client){
        std::cout<<"Masinile care sunt disponibile sunt:\n";
        for(int i=0;i<masini.size();i++)
            if(status_inchirieri[i]==0)
                std::cout<<masini[i].getModel()<<" "<<masini[i].getNrInmatriculare()<<"\n";
        std::cout<<"Alege numarul de inmatriculare pentru masina pe care vrei sa o inchiriezi:";
        int nr_inmatriculare;
        std::cin>>nr_inmatriculare;
        for(int i=0;i<masini.size();i++)
            if(masini[i].getNrInmatriculare()==nr_inmatriculare)
            {client.setMasina1(masini[i]);
            status_inchirieri[i]=1;
                break;
            }
        return client;
    }

    void afis_baza_de_date(){
        std::cout<<"clienti: ";
        for(const auto &client : clienti)
            std::cout<<client<<" ";
        std::cout<<"masini: ";
        for(const auto &masina : masini)
            std::cout<<masina<<" ";
    }
    void adauga_status(const int & status)
    {
        status_inchirieri.push_back(status);
    }
    void adauga_client(const class client & client ){
        clienti.push_back(client);
    }
    void adauga_masina(const class masina & masina ){
        masini.push_back(masina);
    }
    void set_status_inchiriere(){//o functie care semnalizeaza cu 1, in vectorul status_inchirieri, daca masina aleasa este deja utilizata
        for(int i=0;i<masini.size();i++) {
           for(int j=0;j<clienti.size();j++)
               if(masini[i].getNrInmatriculare()==clienti[j].getMasina().getNrInmatriculare())
                   status_inchirieri[i]=1;
               else
                   status_inchirieri[i]=0;

        }


    }

    void setMasini(const std::vector<struct masina> &masini) {
        aplicatie1::masini = masini;
    }

};
int main() {
    //std::string a;
    //std::cin>>a;
    masina masina_default{"default","default","default",0,"default",0};
    masina nr1{"bmw","Mustang","negru",1234,"5",40};
    masina nr2{"audi","Mustang","negru",1234,"5",42};
    //aplicatie1 afis_baza_de_date();
    //masina nr2=nr1;
    //client dorel{1,"Dorel",02323141241,2,"Str Mamei lui nr 25","dorel95","dorelejmek",2,nr1};
    client andrei{2,"Andrei",04124141,6,"Str tatalui nr 45","andrei12","andrei12345",4,nr1};
    //nr1.setNrInmatriculare1(12445555);
    //nr1.setCuloare("rosu");
    aplicatie1 parc_auto{{1,0},{andrei},{nr1,nr2}};
    parc_auto.afis_baza_de_date();
    std::cout<<"\n";
    client dorel{1,"Dorel",02323141241,2,"Str Mamei lui nr 25","dorel95","dorelejmek",2,masina_default};
    dorel = parc_auto.set_masina_client(dorel);
    //std::cout<<dorel;
    parc_auto.adauga_client(dorel);
    parc_auto.afis_baza_de_date();
    //client dorel{1,"Dorel",02323141241,2,"Str Mamei lui nr 25","dorel95","dorelejmek",2,parc_auto.set_masina_client(dorel)};

    return 0;
}
