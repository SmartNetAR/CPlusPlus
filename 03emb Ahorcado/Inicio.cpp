//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Inicio.h"
#include "Principal.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfrmInicio *frmInicio;
//---------------------------------------------------------------------------
__fastcall TfrmInicio::TfrmInicio(TComponent* Owner)
	: TForm(Owner)
{
	frmPrincipal->Show();

}
//---------------------------------------------------------------------------
