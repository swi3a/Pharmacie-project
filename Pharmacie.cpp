#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

 
class Client{ //Declaration de la class Client
private:
    string nom;
    double credit;
public:
    void initClient(string nm, double c) // Initialisation des attrebuts
    {
        this-> nom = nm;
        this-> credit = c;
    }
    string getnom()
    {
        return nom;
    }  
    double getcredit()
    {
        return credit;
    }
    void destcredit(double cr)
    {
        credit -= cr;
    } 
    void affichageClient()  // Affichage des client + leurs credits
    {
        if(!nom.empty())
            cout<<"Nom : "<<nom<<"\n"<<"credit : "<<credit<<endl;
    }
};

class Medicament{ //Declaration de la class Medicament
private:
    string libelle;
    double prix;
    int qteStock;
public:
    void initMedicament(string lib, double p, int qs) // Initialisation des attrebuts
    {
        this->libelle = lib;
        this->prix = p;
        this->qteStock = qs;
    }
    string getlibelle()
    {
        return libelle;
    }
    int getStock()
    {
        return qteStock;
    }
    void addquantity(int aq)
    {
        qteStock += aq;
    }
    void destMed(int dq)
    {
        qteStock -= dq;
    }
    void affichageMedicament() // Affichage des Medicament
    {
        if(!libelle.empty())
            cout<<"Libelle : "<<libelle<<"\n"<<"Prix : "<<prix<<"\n"<<"QteStock : "<<qteStock<<endl;
    }
    

};
class Pharmacie{

public:
    Client *clients;
    Medicament * medicaments; 
    int taille1;
    int taille;
    int NbC ;
    int NbM ;
    void initPharmacie(int t,int t1) //initialisation des clients et medicaments
    {
        this->taille = t;
        this->taille1 = t1;
        clients = new Client[taille];
        medicaments = new Medicament[taille1];
        NbC = 0;
        NbM = 0;
    }
     
    void enregistrerClient(Client c)
    {
        if (NbC < taille)
        {
            NbC++;
            clients[taille - NbC] = c;
        }
        else
            cout<<"Impossible d'ajouter un client"<<endl;
    }
    void enregistrerMedicament(Medicament m)
    {
        if (NbM < taille1)
        {
            NbM++;
            medicaments[taille1 - NbM] = m;             
        }
        else
            cout<<"Impossible d'ajouter un Medicament"<<endl;
    }
    void affichageClient(){
		if(NbC>0){
			for(int i = 0; i < taille; i++)
				clients[i].affichageClient();
		}
	}
    void affichageMedicament(){
		if(NbM>0){
			for(int i = 0; i < taille1; i++)
				medicaments[i].affichageMedicament();
		}
	}
    int verifierClient(Pharmacie ph, string nm)
    {
        for (int i = 0 ; i < taille ; i++)
        {
           if(ph.clients[i].getnom() == nm)//le nom de le parametre avec le nom dans le tableau
            {
                cout<<"l'address de client : "<<i<<endl;
                return i++;
            }
        }
        cout<<"Le client n'exist pas"<<endl;
        return -1;
    }
    int verifierMedicament(Pharmacie ph, string lib)
    {
        int j = 0;
        for (int i = 0 ; i < taille1 ; i++)
        {
            string med = ph.medicaments[i].getlibelle();

            if(!med.empty()){
                j++;
                if(med == lib)//le libelle de le parametre avec le nom dans le tableau
                {
                    cout<<"l'address de medicament de libelle : "<<j<<endl;
                    return j;
                }
            }
           
        }
        cout<<"Le medicament n'exist pas"<<endl;
        return -1;
    }
    void approvisionner(Pharmacie * adrPh, string lib, int q)
    {
        int j = 0;
        for (int i = 0 ; i < taille1 ; i++)
        {   
            j = i + 1;
            string med = adrPh->medicaments[i].getlibelle();
            if(!med.empty()){
                if(med == lib)//le libelle de le parametre avec le nom dans le tableau
                {
                    cout << med<< endl;
                    adrPh->medicaments[i].addquantity(q);
                    cout<<adrPh->medicaments[i].getStock()<<endl;
                    j = 0;
                }
            }
            if (j == taille1){
                cout<<"Le medicament n'exist pas"<<endl;
            }
        }
        
    }
    int verifierAchat(Pharmacie ph, string lib, int q)
    {
        for (int i = 0 ; i < taille1 ; i++)
        {   
            string med = ph.medicaments[i].getlibelle();
            if(!med.empty()){
                if(med == lib && ph.medicaments[i].getStock() >= q )//le libelle de le parametre avec le nom dans le tableau
                {
                    cout <<med<< endl;
                    cout <<ph.medicaments[i].getStock()<< endl;
                    return 1;
                }
            }
        }
        cout<<"Stock insuffisant"<<endl;
        return 0;
    }
    void achat(Pharmacie * adrPh, Client c, string lib, int q, double som)
    {
        c.destcredit(som);
        cout <<c.getcredit()<< endl;
        for (int i = 0 ; i < taille1 ; i++)
        {
            string med = adrPh->medicaments[i].getlibelle();

            if(!med.empty()){
                if(med == lib)//le libelle de le parametre avec le nom dans le tableau
                {
                    adrPh->medicaments[i].destMed(q);
                    cout <<adrPh->medicaments[i].getStock()<< endl;
                }
            }
        }
        
    }
};

int main ()
{   
    Client c1 , c2;
    c1.initClient("Ali", 500);
    c2.initClient("Saida",300);

    // c1.affichageClient();
    // c2.affichageClient();
    // cout<<"------------------"<<endl;
    // m1.affichageMedicament(); 
    // m2.affichageMedicament();
    // m3.affichageMedicament();


    Medicament m1, m2, m3;
    m1.initMedicament("Aspro0",30,40);
    m2.initMedicament("Clartec",40,10);
    m3.initMedicament("Cardegic",80,20);

    Pharmacie ph;
    ph.initPharmacie(3,6);

    int choice ;
    
    cout<<"-------------------------------------------"<<endl;
    cout<< "    1 - Enregistrer Client."<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<< "    2 - Enregistrer Medicament."<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<< "    3 - Affichier les clients."<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<< "    4 - Affichier les medicaments."<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<< "    5 - Verifier Client."<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<< "    6 - Verifier Medicament."<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<< "    7 - Approvisionner."<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<< "    8 - Verifier Achat."<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<< "    9 - achat de medicaments."<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<< " Enter your choice and press return: "<<endl;
    cin >> choice;

    switch (choice)
    {
        case 1:   
            ph.enregistrerClient(c1);
            ph.enregistrerClient(c2);
        break;
        case 2:
            ph.enregistrerMedicament(m1);
            ph.enregistrerMedicament(m2);
            ph.enregistrerMedicament(m3);
        break;
        case 3:
            cout<<"-------------------------------------------"<<endl;
            ph.affichageClient();
            cout<<"-------------------------------------------"<<endl;
        break;
        case 4:  
            cout<<"-------------------------------------------"<<endl;
            ph.affichageMedicament();
            cout<<"-------------------------------------------"<<endl;
        break;
        case 5:
            cout<<"-------------------------------------------"<<endl;
            ph.verifierClient(ph,"Saida");
            cout<<"-------------------------------------------"<<endl;
            ph.verifierClient(ph,"Souada");
            cout<<"-------------------------------------------"<<endl;
        break;
        case 6:
            ph.verifierMedicament(ph,"Dolipran");
            cout<<"-------------------------------------------"<<endl;
            ph.verifierMedicament(ph,"Aspro0");
        break;
        case 7:
            ph.approvisionner(&ph,"zcdfwsdvAspro0",10);
            cout<<"-------------------------------------------"<<endl;
            ph.approvisionner(&ph,"Aspro0",10);
        break;
        case 8:
            cout<<"-------------------------------------------"<<endl;
            ph.verifierAchat(ph, "Aspro0", 5555);
            cout<<"-------------------------------------------"<<endl;
            ph.verifierAchat(ph, "Aspro0", 16);
            cout<<"-------------------------------------------"<<endl;
            ph.verifierAchat(ph, "Aspro0", 49);
            cout<<"-------------------------------------------"<<endl;
        break;
        case 9:
            ph.achat(&ph, c2, "Clartec", 2, 80);
        break;
        default:
        cout << "Not a Valid Choice. \n"
        << "Choose again.\n";
        break;
    }
}