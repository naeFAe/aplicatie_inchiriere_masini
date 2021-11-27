#include <string>
#include <iostream>
#include <vector>
class masina{
    std::string marca;
    std::string model;
    std::string culoare;
    std::string nrInmatriculare;
    std::string capacitate;
    int tarifOra;
    int garantie;
public:
    masina(const std::string &marca, const std::string &model, const std::string &culoare,
           const std::string &nrInmatriculare, const std::string &capacitate, int tarifOra, int garantie) : marca(
            marca), model(model), culoare(culoare), nrInmatriculare(nrInmatriculare), capacitate(capacitate), tarifOra(
            tarifOra), garantie(garantie) {}

    friend std::ostream &operator<<(std::ostream &os, const masina &masina) {
        os << "marca: " << masina.marca << " model: " << masina.model << " culoare: " << masina.culoare
           << " nrInmatriculare: " << masina.nrInmatriculare << " capacitate: " << masina.capacitate << " tarifOra: "
           << masina.tarifOra << " garantie: " << masina.garantie;
        return os;
    }

    int pret_inchiriere(const int nrOre,const int tarifOra){
        return nrOre*tarifOra;
    }
    const std::string &getNrInmatriculare() const {
        return nrInmatriculare;
    }

    void setNrInmatriculare(const std::string &nrInmatriculare) {
        masina::nrInmatriculare = nrInmatriculare;
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
    abonament(const masina& copie)
    {
        this->marca = copie.marca;
        this->model = copie.model;
        this->capacitate = copie.capacitate;
        this->tarifOra = copie.tarifOra;
        this->nrInmatriculare = copie.nrInmatriculare;
    }

    int getGarantie() const {
        return garantie;
    }

    const std::string &getModel() const {
        return model;
    }

    int getTarifOra() const {
        return tarifOra;
    }

};
/*class aplicatie{
    std::string nume;
    std::vector<masina>masini;
    std::string masina_aleasa;
public:
    aplicatie(const std::string &nume, const std::vector<masina> &masini) : nume(nume), masini(masini) {}

    void adauga(const masina&masina){
        masini.push_back(masina);
    }

    const std::string &getMasinaAleasa() const {
        return masina_aleasa;
    }

    void search(){
        std::cout<<"\nIntrodu numarul de Inmatriculare al masinii alese:";std::cin>>masina_aleasa;
        for(int i=0;i<masini.size();i++)
            masini[i].schimba(masina_aleasa);
    }
    void afis_nr(int i){
        std::cout<<masini[i].getNr();
    }
};*/
class client{
    int id;
    std::string nume;
    int nrTel;
    int nrOre;
    int pret_inchiriere;
    std::string adresa;
    std::string user;
    std::string parola;
    int nr_inchirieri;
    masina masina;
public:
    client(int id, const std::string &nume, int nrTel, const std::string &adresa, const std::string &user,
           const std::string &parola, int aniExperienta, int pretGarantie) : id(id), nume(nume), nrTel(nrTel),
                                                                             adresa(adresa), user(user), parola(parola),
                                                                             ani_experienta(aniExperienta),
                                                                             pret_garantie(pretGarantie) {}

    friend std::ostream &operator<<(std::ostream &os, const client &client) {
        os << "id: " << client.id << " nume: " << client.nume << " nrTel: " << client.nrTel << " adresa: "
           << client.adresa << " user: " << client.user << " parola: " << client.parola << " ani_experienta: "
           << client.ani_experienta << " pret_garantie: " << client.pret_garantie;
        return os;
    }

    void setNrOre(int nrOre) {
        client::nrOre = nrOre;
    }

    void set_pret_inchiriere(){
        if(nr_inchirieri>2 && nr_inchirieri<5)
            pret_inchiriere=nrOre*masina.getTarifOra()-(nrOre*masina.getTarifOra())/0.05
        else
            if(nr_inchirieri>4)
                pret_inchiriere=nrOre*masina.getTarifOra()-(nrOre*masina.getTarifOra())/0.10;
            else
                if(nr_inchirieri==0)
                    pret_inchiriere=nrOre*masina.getTarifOra()-(nrOre*masina.getTarifOra())/0.03;
                else
                    pret_inchiriere=nrOre*masina.getTarifOra();
    }

    const std::string &getUser() const {
        return user;
    }

    const std::string &getParola() const {
        return parola;
    }

    const masina &getMasina() const {
        return masina;
    }
};


/*class sesiune{
    std::string nume;
    std::vector<cont>conturi;
public:
    sesiune(const std::string &nume, const std::vector<cont> &conturi) : nume(nume), conturi(conturi) {}

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
};*/
/*class sesiune{
    std::vector<int>status_inchirieri;//un vector care semnaleaza cu 1 daca masina este inchiriata
    std::vector<class client>clienti;
    std::vector<class masina>masini;
public:
    sesiune(const std::vector<int> &statusInchirieri, const std::vector<struct client> &clienti,
            const std::vector<struct masina> &masini) : status_inchirieri(statusInchirieri), clienti(clienti),
                                                        masini(masini) {}
    int decizie(){
        int nr;//numarul mentionat in linia de mai jos
        std::cout<<"Apasa tasta 1 pentru a te loga/tasta 2 pentru a crea cont: ";
        std::cin>>nr;
        return nr;
    }

    bool logare(int nr){
        std::string user_i;//i vine de la introdus
        std::string parola_i;
        for(int i=0;i<3;i++){//utilizatorul poate introduce gresit de 3 ori contul pana ii va reaparea optiunea de a se loga sau a crea cont
            std::cout<<"Introdu usernaname";std::cin>>user_i;
            std::cout<<"Introdu parola";std::cin>>parola_i;
            for(int i=0;i<clienti.size();i++)
                if(clienti[i].getUser().compare(user_i)==0 && clienti[i].getParola().compare(parola_i)==0){//caut contul
                    return 1;
                }
            std::cout<<"Ai introdus contul gresit de prea multe ori";
            return 0;

        }

    }*/

    /*class client register_client(int nr){
        std::string user_i;//i vine de la introdus
        std::string parola_i;
        int id;
        std::string nume;
        int nrTel;
        std::string adresa;
        while(nr==2){
            std::cout<<"Introdu usernaname";std::cin>>user_i;
            std::cout<<"Introdu parola";std::cin>>parola_i;
            int a=clienti.size();
            for(int i=0;i<clienti.size();i++)
                if(clienti[i].getUser().compare(user_i)==0) {//verific daca username-ul este deja utilizat
                    nr=0;break;
                }
            if(nr==2){//varianta in care nr nu isi schimba valoarea in urma verifcarii si cazul in care username-ul selectat nu este utilizat
                nr=0;
                std::cout<<"Introdu cnp";std::cin>>id;
                std::cout<<"Introdu nume";std::cin>>nume;
                std::cout<<"Introdu numar de telefon";std::cin>>nrTel;
                std::cout<<"Introdu adresa";std::cin>>adresa;
                class client client ={id,nume,nrTel,adresa,user_i,parola_i};
                return client;
            }
            else{//varianta in care nr devine 0 si utilizatorului ii este cerut sa reintroduca datele
                nr=2;std::cout<<"Username-ul este deja utilizat introduce-ti alt username";}
        }
    }

    void adauga_client(const class client & client ){
        clienti.push_back(client);
    }
};*/




class aplicatie1{
    std::vector<int>status_inchirieri;//un vector care semnaleaza cu 1 daca masina este inchiriata
    std::vector<class client>clienti;
    std::vector<class masina>masini;
public:
    aplicatie1(const std::vector<struct client> &clienti, const std::vector<struct masina> &masini) : clienti(clienti),
                                                                                                      masini(masini) {}

    class client set_masina_client(class client client){
        std::cout<<"Masinile care sunt disponibile sunt:\n"
        for(int i=0;i<masini.size();i++)
            if(status_inchirieri[i]==0)
                std::cout<<masini[i].getModel()<<" "<<masini[i].getNrInmatriculare()<<"\n";
        std::cout<<"Alege numarul de inmatriculare pentru masina pe care vrei sa o inchiriezi:"
        int nr_inmatriculare;
        std::cin>>nr_inmatriculare;
        for(int i=0;i<masini.size();i++)
            if(masini[i].getNrInmatriculare()==nr_inmatriculare)
            {client.getMasina()=masini[i];
            status_inchirieri[i]=1;
                break;
            }
        return client;
    }

    void afis_baza_de_date() {
        std::cout << "clienti: " ;
        for(const auto  &client : clienti)
            std::cout<<client<<" ";
        std::cout<< " masini: " ;
        for(const auto &masina : masini)
            std::cout<<masina<<" ";
    }

    void adauga_masina(const class client & client ){
        clienti.push_back(client);
    }
    void adauga_masina(const class masina & masina ){
        masini.push_back(masina);
    }
    void set_status_inchiriere(){//o functie care semnalizeaza cu 1 fa
        for(int i=0;i<masini.size();i++) {
           for(int j=0;j<clienti.size();j++)
               if(masina[i].getNrInmatriculare()==client[j].masina.getNrInmatriculare())
                   status_inchirieri[i]=1;
               else
                   status_inchirieri[i]=0;

        }


    }

};
int main() {
    client dorel{1,"Dorel",02323141241,"Str Mamei lui nr 25","dorel95","dorelejmek"};
    client andrei{2,"Andrei",04124141,"Str tatalui nr 45","andrei12","andrei12345"};
   // std::cout<<dorel;
    //sesiune pac{"parc auto",{dorel,andrei}};
    //int x=1;
    /*while(x!=0)
        pac.cautare(x);
    std::cout<<pac.afis_user(1);*/
    masina nr1{"negru","PH27POC","7","Ford","Mustang","50","1000"};
    masina nr2=nr1;
    nr1.setNrInmatriculare(12445555);
    nr1.setCuloare("rosu");
    aplicatie1 parc_auto{{dorel,andrei},{nr1}};
    parc_auto.afis_baza_de_date();
    //std::cout<<"\n"<<nr1;
    //client c1{"501234","Andrei","023455566","mareseanu nr1"};
    //std::cout<<c1;
    //aplicatie car{"t1",{nr1}};
    //car.search();
    //car.afis_nr(0);
    //if(nr1.getNr()==1)
        //std::cout<<"\nNu exista nicio masina cu acest numar";
    //return 0;
}//
// Created by Steff on 11/15/2021.
//

