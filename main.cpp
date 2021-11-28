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

    const std::string &getMarca() const {
        return marca;
    }

    const std::string &getCuloare() const {
        return culoare;
    }

    const std::string &getCapacitate() const {
        return capacitate;
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
        if(nr_inchirieri>2 && nr_inchirieri<5){
            return nrOre*masina1.getTarifOra()-(nrOre*masina1.getTarifOra())*0.05;}
        else
        if(nr_inchirieri>4)
            return nrOre*masina1.getTarifOra()-(nrOre*masina1.getTarifOra())*0.10;
        else
        if(nr_inchirieri==0)
            return nrOre*masina1.getTarifOra()-(nrOre*masina1.getTarifOra())*0.03;
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

    int getNrOre() const {
        return nrOre;
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



    class client set_masina_client(class client client){//inlocuieste masina introdusa initial cu o masina introdusa de client la tstatura
        std::cout<<"Masinile care sunt disponibile sunt:\n\n";
        for(int i=0;i<masini.size();i++)
            if(status_inchirieri[i]==0)
                std::cout<<masini[i].getMarca()<<" "<<masini[i].getModel()<<" "<<masini[i].getNrInmatriculare()<<" capacitate"<<masini[i].getCapacitate()<<" tarif/ora: "<<masini[i].getTarifOra()<<"\n";
        std::cout<<"\nAlege numarul de inmatriculare pentru masina pe care vrei sa o inchiriezi:";
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

    masina masina_default{"default","default","default",0,"default",0};
    masina nr1{"Bmw","Seria 3","negru",1234,"5",40};
    masina nr2{"Audi","A6","negru",1235,"5",42};
    masina nr3=nr1;
    nr3.setCuloare("verde");

    nr3.setNrInmatriculare1(8765);
    masina nr4=nr2;
    nr4.setNrInmatriculare1(4000);
    client andrei{2,"Andrei",04124141,6,"Str tatalui nr 45","andrei12","andrei12345",4,nr1};

    aplicatie1 parc_auto{{1,0},{andrei},{nr1,nr2}};
    parc_auto.adauga_masina({nr3});
    parc_auto.adauga_status(0);
    parc_auto.adauga_masina({nr4});
    parc_auto.adauga_status(0);
    std::cout<<"\n";

    client dorel{1,"Dorel",02323141241,2,"Str Mamei lui nr 25","dorel95","dorelejmek",2,masina_default};
    int x=1;//o vaaribila care primeste valoarea 1 si verifica daca clientul vrea sa inchirieze mai multe masini
    while(x==1){
        std::cout<<andrei.getUser()<<"\n\n";
        andrei=parc_auto.set_masina_client(andrei);
        std::cout<<"Pretul inchirerii masinii "<<andrei.getMasina().getMarca()<<" "<<andrei.getMasina().getModel()<<" "<<andrei.getMasina().getNrInmatriculare()<<" este de "<<andrei.set_pret_inchiriere()<<" pe durata de "<<andrei.getNrOre()<<" ore\n";
        std::cout<<"Apasa tasta 1 pentru as selecta inca o masina: ";
        std::cin>>x;
    }
    x=1;
    while(x==1){
        std::cout<<dorel.getUser()<<"\n\n";
        dorel = parc_auto.set_masina_client(dorel);
        std::cout<<"Pretul inchirerii masinii "<<dorel.getMasina().getMarca()<<" "<<dorel.getMasina().getModel()<<" "<<dorel.getMasina().getNrInmatriculare()<<" este de "<<dorel.set_pret_inchiriere()<<" pe durata de "<<dorel.getNrOre()<<" ore\n";
        std::cout<<"Apasa tasta 1 pentru as selecta inca o masina: ";
        std::cin>>x;
    }
    parc_auto.adauga_client(dorel);
    parc_auto.afis_baza_de_date();

    return 0;
}