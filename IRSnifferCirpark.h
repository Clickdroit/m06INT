#ifndef IRSNIFFERCIRPARK_H
#define IRSNIFFERIRPARK_H

#include <string>
#include "IRClientUDP.h"

class IRSnifferCirpark 
{
    private :
        std::string adresseIPServeurCirpark;
        unsigned short portServeurCirpark;
        IRClientUDP clientCirpark;
        unsigned char requete[10];
		unsigned char reponse[20];
		unsigned short tabCapteurs[100];
		std::string tabCapteursHexa[100];
        int nbCapteurs;
		std::string mode,bril,mddt,dist,type,txtEtat;
		bool etat;
		int pote,intDist,vers,c_ok,cnok,cout,inp;
	public :
        IRSnifferCirpark();
		bool ParametrerLeServeurCirpark(std:: string adresseIP, unsigned short port);
		bool DetecterUnCapteur(unsigned short adresseCapteur);
		int DetecterLesCapteurs(unsigned short adresseCapteurDepart, unsigned short adresseCapteurFin);
		inline int NombreCapteurTrouve() {return nbCapteurs;};
		inline unsigned short CapteurTrouve(int num) {if(num<nbCapteurs) return tabCapteurs[num]; else return 0;};
		std::string CapteursHexa(int num){if(num<nbCapteurs) return tabCapteursHexa[num]; else return 0;};
		void EnregistrerSous(std::string nomFichier);
		bool EnvoyerRequeteCapteur(unsigned short adresseCapteur,unsigned char codeFonction);
		bool EnvoyerDonneeCapteur(unsigned short adresseCapteur,unsigned char codeFonction,unsigned char donnee);
		void LireConfigurationCapteur(unsigned short adresseCapteur);
		std::string Mode(){return mode;};
		std::string Bril(){return bril;};
		std::string Mddt(){return mddt;};
		int Pote(){return pote;};
		std::string Dist(){return dist;};
		int IntDist(){return intDist;};
		std::string Type(){return type;};
		std::string TxtEtat(){return txtEtat;};
		bool Etat(){return etat;};
		int Vers(){return vers;};
		int C_ok(){return c_ok;};
		int Cnok(){return cnok;};
		int Cout(){return cout;};
		int Inp(){return inp;};
    	void DecoderReponse(unsigned char codeF);
		unsigned char* Reponse(){return reponse;};
};

#endif