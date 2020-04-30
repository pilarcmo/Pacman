///-----------------------------------------------------------------
///
/// @file      ProyectoFinalFrm.h
/// @author    GrupoPyN
/// Created:   27/04/2020 12:00:09
/// @section   DESCRIPTION
///            ProyectoFinalFrm class declaration
///
///------------------------------------------------------------------

#ifndef __PROYECTOFINALFRM_H__
#define __PROYECTOFINALFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/statbmp.h>
////Header Include End

#include <ctime>
#include <iostream>
using namespace std;

#include "juego.h"
#include "pacman.h"
#include "fantasma.h"
#include "movAleat.h"

////Dialog Style Start
#undef ProyectoFinalFrm_STYLE
#define ProyectoFinalFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class ProyectoFinalFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		ProyectoFinalFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Pacman"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = ProyectoFinalFrm_STYLE);
        virtual ~ProyectoFinalFrm();
		void OnKeyDown(wxKeyEvent& event);
		void movFantasma(wxTimerEvent& timer);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticBitmap *Fondo;
		wxStaticBitmap *fantasmaIcon;
		wxStaticBitmap *PacmanIcon;
		////GUI Control Declaration End
		
		wxTimer m_timer;

	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_FONDO = 1007,
			ID_FANTASMAICON = 1006,
			ID_PACMANICON = 1003,
			////GUI Enum Control ID End
			ID_TIMER=1002,
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
