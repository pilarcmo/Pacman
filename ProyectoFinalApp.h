//---------------------------------------------------------------------------
//
// Name:        ProyectoFinalApp.h
// Author:      GrupoPyN
// Created:     27/04/2020 12:00:09
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __PROYECTOFINALFRMApp_h__
#define __PROYECTOFINALFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class ProyectoFinalFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
