//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label1Click(TObject *Sender)
{
	Form1->ComboBox1->Text=Label1->Caption;
	Form1->Button1Click(this);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label2Click(TObject *Sender)
{
	Form1->ComboBox1->Text=Label2->Caption;
	Form1->Button1Click(this);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label3Click(TObject *Sender)
{
	Form1->ComboBox1->Text=Label3->Caption;
	Form1->Button1Click(this);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label4Click(TObject *Sender)
{
	Form1->ComboBox1->Text=Label4->Caption;
	Form1->Button1Click(this);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
	Label5->Caption = Date() + Time();

	TLabel  *labels[] = {Label1, Label2, Label3, Label4};
	TImage  *images[] = {Image4, Image3, Image2, Image1};
	TShape  *shapes[] = {Shape1, Shape3, Shape5, Shape7};

	for (int i = 0; i < 4; i++) {
		unsigned int adresse = Form1->ChaineHexaVersInt(
			AnsiString(labels[i]->Caption).c_str(), 4);
		if (Form1->sniffer.EnvoyerRequeteCapteur(adresse, 0x10)) {
			unsigned char *reponse = Form1->sniffer.Reponse();
			if (reponse[2] == 0) {
				images[i]->Visible = false;
				shapes[i]->Brush->Color = clGreen;
			} else {
				images[i]->Visible = true;
				shapes[i]->Brush->Color = clRed;
			}
		}
	}
}
//---------------------------------------------------------------------------
