//---------------------------------------------------------------------------
//
// Name:        ProyectoFinalApp.cpp
// Author:      GrupoPyN
// Created:     27/04/2020 12:00:09
// Description: 
//
//---------------------------------------------------------------------------

#include "ProyectoFinalApp.h"
#include "ProyectoFinalFrm.h"

IMPLEMENT_APP(ProyectoFinalFrmApp)


bool ProyectoFinalFrmApp::OnInit()
{
    ProyectoFinalFrm* frame = new ProyectoFinalFrm(NULL);
    SetTopWindow(frame); 
    frame->Show();
    return true;
}
 
int ProyectoFinalFrmApp::OnExit()
{
	return 0;
}


