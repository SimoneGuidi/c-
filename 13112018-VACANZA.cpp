
#include <iostream>
#define max 150
#define prezzo_pn 70.0
using namespace std;
struct pack {
	string nome;
	string nazione;
	string citta;
	int notti;
	int persone;
	float prezzo;
};

void f_caricamento (pack v[], int N){
	for(int i = 0; i < N; i++){
		cout<<"Inserisci il nome del pacchetto: ";
		cin>>v[i].nome;
		cout<<" "<<endl;
		cout<<"Inserisci la nazione: ";
		cin>>v[i].nazione;
		cout<<" "<<endl;
		cout<<"Inserisci la citta':  ";
		cin>>v[i].citta;
		cout<<" "<<endl;
		cout<<"Inserisci il numero di notti disponbili: ";
		cin>>v[i].notti;
		cout<<" "<<endl;
		cout<<"Inserisci il numero di persone che puo' partecipare al viaggio: ";
		cin>>v[i].persone;
		cout<<" "<<endl;
		cout<<"Inserisci il prezzo a persona per una notte: ";
		cin>>v[i].prezzo;
		system ("CLS");	
	}
}

void f_riempire(pack v[], int N, int i){
		cout<<"Inserisci il nome del pacchetto: ";
		cin>>v[i].nome;
		cout<<"Inserisci la nazione: ";
		cin>>v[i].nazione;
		cout<<"Inserisci la citta':  ";
		cin>>v[i].citta;
		cout<<"Inserisci il numero di notti disponbili: ";
		cin>>v[i].notti;
		cout<<"Inserisci il numero di persone che puo' partecipare al viaggio: ";
		cin>>v[i].persone;
		cout<<"Inserisci il prezzo a persona per una notte: ";
		cin>>v[i].prezzo;
		cout<<" "<<endl;
	}


void f_elimina (pack v[], int N, int i) {
	v[i].nazione = "Pacchetto vuoto";
	v[i].citta = "Pacchetto vuoto";
	v[i].notti = 0;
	v[i].persone = 0;
	v[i].prezzo = 0;
}

void f_stampa(pack v[], int N){
	for(int i = 0; i < N; i++){
		cout<<"Pacchetto numero: "<<i<<endl;
		cout<<v[i].nome<<endl;
		cout<<v[i].nazione<<endl;
		cout<<v[i].citta<<endl;
		cout<<v[i].notti<<" notti"<<endl;
		cout<<v[i].persone<<" persone"<<endl;
		cout<<v[i].prezzo<<" euro"<<endl;
		cout<<" "<<endl;
	}
}

void f_notti (pack v[], int i) {
	 float pn;
	 v[i].prezzo = v[i].notti * prezzo_pn;
	 }

float f_costototale (int persone, float pn) {
	float totale;
	totale = pn * persone;
	return totale;
}

void f_stampacliente (pack v[],int i) {
	system ("PAUSE");
	system ("CLS");
	cout<<"La nazione da te selezionata e' "<<v[i].nazione<<"."<<endl;
	cout<<"Con luogo di destinazione "<<v[i].citta<<"."<<endl;
	cout<<"Per un numero di "<<v[i].notti<< " notti."<<endl;
	cout<<"Il costo del viaggio e' "<<v[i].prezzo<<" euro "<<"per "<<v[i].persone<<" persone."<<endl;
}

int main () {
	int modalita, N, i = 0, scop, mod, scelta, risp, persone;
	float pn;
	pack v[max];
	string risposta;
	cout<<"Benvenuto."<<endl;
	cout<<"Scegli una modalita': "<<endl;
	cout<<"1.Operatore"<<endl;
	cout<<"2.Cliente"<<endl;
	cout<<"Fai la tua scelta: ";
	cin>>modalita;
	system ("CLS");
	switch(modalita){
		case 1:
			cout<<"Benvenuto operatore! "<<endl;
			do {	
				cout<<"Inserisci il numero di pacchetti da aggiungere: ";
				cin>>N;
				if (N < 2) {
					cout<<"Devi inserire almeno due pacchetti!"<<endl;
				}
			}while (N < 2);
			f_caricamento (v,N);
			cout<<"Ora cosa vuoi fare? "<<endl;
			cout<<"1. Aggiungere un altro pacchetto"<<endl;
			cout<<"2. Modificare un pacchetto"<<endl;
			cout<<"3. Rimuovere un pacchetto"<<endl;
			cout<<"Fai la tua scelta: ";
			cin>>scop;
			switch (scop) {
				case 1: 
					cout<<"Inserisci il numero di pacchetti da aggiungere: ";
					cin>>N;
					f_caricamento (v,N);
				break;
				case 2:
					f_stampa (v,N);
					cout<<"Inserisci il numero del pacchetto da modificare: ";
					cin>>i;
					do {
					cout<<"Cosa vuoi modificare del pacchetto "<<i<<"? ";
					cout<<"1. Nazione e citta'"<<endl;
					cout<<"2. Notti"<<endl;
					cout<<"3. Persone"<<endl;
					cout<<"4. Prezzo per persona"<<endl;
					cout<<"Fai la tua scelta ";
					cin>>mod;
					if (mod == 1) {
						cout<<"Inserisci la nuova nazione: ";
						cin>>v[i].nazione;
						cout<<"Inserisci la nuova citta: ";
						cin>>v[i].citta;
					} if (mod == 2) {
						cout<<"Inserisci il nuovo numero di notti: ";
						cin>>v[i].notti;
					} if (mod == 3) {
						cout<<"Inserisci il nuovo numero di persone: ";
						cin>>v[i].persone;
					} if (mod == 4) {
						cout<<"Inserisci il nuovo numero di prezzo per persona: ";
						cin>>v[i].prezzo;
					}
					cout<<"Vuoi modificare altro? "<<endl;
					cin>>risposta;
					}while(risposta == "SI" || risposta == "Si" || risposta == "Si" || risposta == "si");
					break;
					case 3: 
					f_stampa (v,N);
					do {
						cout<<"Quale pacchetto vuoi eliminare? ";
						cin>>i;
						f_elimina (v,N,i);
						cout<<"Pacchetto eliminato"<<endl;
						cout<<"Vuoi riempire il pacchetto eliminato ? ";
						cin>>risposta;
						if(risposta == "SI" || risposta == "Si" || risposta == "Si" || risposta == "si"){
							N = 1;
							f_caricamento(v,N);
						}
						cout<<"Vuoi eliminare un altro pacchetto? ";
						cin>>risposta;
						}while (risposta == "SI" || risposta == "Si" || risposta == "Si" || risposta == "si");
					break;
					default:
						return 0;
					break;
				}
		case 2:
			cout<<"Benvenuto! "<<endl;
			cout<<"Queste sono le nazioni disponibili: "<<endl;
			cout<<"1.Italia"<<endl;
			cout<<"2.Germania"<<endl;
			cout<<"3.Spagna"<<endl;
		 
			cout<<"Inserisci la nazione di destinazione: ";
			cin>>scelta;
			system ("PAUSE");
			system ("CLS");
			switch(scelta) {
			case 1:
				cout<<"Hai selezionato come destinazione l'Italia."<<endl;
				i = 0;
				v[i].nazione = "Italia";
				cout<<"Ora seleziona la citta' che vuoi visitare:"<<endl;
				cout<<"1.Ischia"<<endl;
				cout<<"2.Napoli"<<endl;
				cout<<"3.Roma"<<endl;
				cout<<"Fai la tua scelta: ";
				cin>>scelta;
				if (scelta == 1) 
				v[i].citta = "Ischia";
				if (scelta == 2)
				v[i].citta = "Napoli";
				if (scelta == 3)
				v[i].citta = "Roma";
				cout<<"Le notti disponibili sono 5."<<endl;
				v[i].notti = 5;
				f_notti(v,i);
				cout<<"Quante persone parteciperanno al viaggio? ";
				cin>>v[i].persone;
				f_costototale(persone,pn);
			break;
			
			case 2:
				cout<<"Hai selezionato come destinazione la Germania."<<endl;
				i = 1;
				v[i].nazione = "Germania";
				cout<<"Ora seleziona la citta' che vuoi visitare:"<<endl;
				cout<<"1.Francoforte"<<endl;
				cout<<"2.Dortmund"<<endl;
				cout<<"3.Stoccarda"<<endl;
				cout<<"Fai la tua scelta: ";
				cin>>scelta;
				if (scelta == 1) 
				v[i].citta = "Francoforte";
				if (scelta == 2)
				v[i].citta = "Dortmund";
				if (scelta == 3)
				v[i].citta = "Stoccarda";
				cout<<"Le notti disponibili sono 4 "<<endl;
				v[i].notti = 4;
				f_notti(v,i);
				cout<<"Quante persone parteciperanno al viaggio ? "<<endl;
				cin>>v[i].persone;
				f_costototale(persone,pn);
			break;
			
			case 3:
				cout<<"Hai selezionato come destinazione la Spagna."<<endl;
				i = 2;
				v[i].nazione = "Spagna";
				cout<<"Ora seleziona la citta' che vuoi visitare:"<<endl;
				cout<<"1.Madrid"<<endl;
				cout<<"2.Barcellona"<<endl;
				cout<<"3.Siviglia"<<endl;
				cout<<"Fai la tua scelta: ";
				cin>>scelta;
				if (scelta == 1) 
				v[i].citta = "Madrid";
				if (scelta == 2)
				v[i].citta = "Barcellona";
				if (scelta == 3)
				v[i].citta = "Siviglia";
				cout<<"Le notti disponibili sono 7 "<<endl;
				v[i].notti = 7;
				f_notti(v,i);
				cout<<"Quante persone parteciperanno al viaggio ? "<<endl;
				cin>>v[i].persone;
				f_costototale(persone,pn);
			break;
			
		default:
			return 0;
		break;
	}
	f_stampacliente(v,i);
	default:
		return 0;
	break;
	}
	system ("PAUSE");
	system ("CLS");
	if (modalita == 1) {
		cout<<"Benvenuto cliente!";
		cout<<"Ora ti mostrero' tutti i pacchetti disponibili:"<<endl;
		f_stampa (v,N);
		
	}
	}

