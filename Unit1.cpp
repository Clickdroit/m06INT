//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "IRSnifferCirpark.h"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RechercherClick(TObject *Sender)
{
	sniffer.ParametrerLeServeurCirpark(AnsiString(Edit1->Text).c_str(),10001);
	int n=sniffer.DetecterLesCapteurs(0x6454,0x6470);
	sniffer.EnregistrerSous("fichierCapteurs.txt");
	for (int i=0; i < n; i++) {
		ComboBox1->AddItem(sniffer.CapteursHexa(i).c_str(),this);
	}
	ComboBox1->ItemIndex=0;
	Label1->Caption=(String)n+" capteurs";
    Form2->Timer1->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	sniffer.LireConfigurationCapteur(ChaineHexaVersInt(AnsiString(ComboBox1->Text).c_str(),4));
	Label3->Caption=sniffer.Mode().c_str();

	Label5->Caption=sniffer.Bril().c_str();

	Label7->Caption=sniffer.Mddt().c_str();

	Label9->Caption=sniffer.Pote();

	Label11->Caption=sniffer.Dist().c_str();

	Label13->Caption=sniffer.Type().c_str();

	Label15->Caption=sniffer.Vers();

	if (sniffer.Etat()==1) {
		Shape2->Brush->Color = clGreen;
		Label17->Caption="Disponible";

	}else{
		Shape2->Brush->Color = clRed;
        Label17->Caption="Occup�e";
	}


	Label19->Caption=sniffer.C_ok();

	Label21->Caption=sniffer.Cnok();

	Label23->Caption=sniffer.Cout();

	Label25->Caption=sniffer.Inp();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Form2->Show();
}
//---------------------------------------------------------------------------

