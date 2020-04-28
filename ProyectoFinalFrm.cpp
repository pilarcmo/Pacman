///-----------------------------------------------------------------
///
/// @file      ProyectoFinalFrm.cpp
/// @author    GrupoPyN
/// Created:   27/04/2020 12:00:09
/// @section   DESCRIPTION
///            ProyectoFinalFrm class implementation
///
///------------------------------------------------------------------

#include "ProyectoFinalFrm.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
#include "Images/ProyectoFinalFrm_Fondo_XPM.xpm"
#include "Images/ProyectoFinalFrm_PacmanIcon_XPM.xpm"
////Header Include End

//----------------------------------------------------------------------------
// ProyectoFinalFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(ProyectoFinalFrm,wxFrame)
	////Manual Code Start
	EVT_KEY_DOWN(ProyectoFinalFrm::OnKeyDown)
	////Manual Code End
	
	EVT_CLOSE(ProyectoFinalFrm::OnClose)
END_EVENT_TABLE()
////Event Table End

ProyectoFinalFrm::ProyectoFinalFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

ProyectoFinalFrm::~ProyectoFinalFrm()
{
}

void ProyectoFinalFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	wxBitmap Fondo_BITMAP(ProyectoFinalFrm_Fondo_XPM);
	Fondo = new wxStaticBitmap(this, ID_FONDO, Fondo_BITMAP, wxPoint(0, 0), wxSize(675, 525));

	wxBitmap PacmanIcon_BITMAP(ProyectoFinalFrm_PacmanIcon_XPM);
	PacmanIcon = new wxStaticBitmap(this, ID_PACMANICON, PacmanIcon_BITMAP, wxPoint(25, 25), wxSize(25, 25),wxALWAYS_SHOW_SB);
	PacmanIcon->SetBackgroundColour(wxColour(_("BLACK")));

	SetTitle(_("Pacman5"));
	SetIcon(wxNullIcon);
	SetSize(8,8,690,563);
	Center();
	
	////GUI Items Creation End	
}

void ProyectoFinalFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

Juego juego1;
Pacman pacman1;
int row=pacman1.posPM.first; //Inicializar pos pacman
int col=pacman1.posPM.second;
wxPoint p(col,row);

/*
 * OnKeyDown
 */
void ProyectoFinalFrm::OnKeyDown(wxKeyEvent& event)
{     
    //Modifica posicion segun teclas presionadas:
        switch (event.GetKeyCode()) {
        case WXK_LEFT: // Mov izq
            if (juego1.isBlocked(row,col-1)==false)
                col = col-1;               
            break;
        case WXK_RIGHT: // Mov dcha
            if (juego1.isBlocked(row,col+1)==false)
                col = col+1;
            break;
        case WXK_UP: // Mov up
            if (juego1.isBlocked(row-1,col)==false)
                row = row-1;
            break;
        case WXK_DOWN: // Mov down
            if (juego1.isBlocked(row+1,col)==false)
                row = row+1;
            break;
        case WXK_SPACE: // Salida juego espacio
            juego1.gameover();
            break;
        }  
    p.x=col*25;
    p.y=row*25;
    pacman1.posPM.first=row;
    pacman1.posPM.second=col;
    
    PacmanIcon->Move(p);
}
