//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Juego.h" ;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

TfrmInicio *frmInicio;
Juego j ;

//---------------------------------------------------------------------------
__fastcall TfrmInicio::TfrmInicio(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmInicio::Button1Click(TObject *Sender)
{
	j.setNivel( 1 ) ;
	frmPrincipal->Show( ) ;
}
//---------------------------------------------------------------------------
