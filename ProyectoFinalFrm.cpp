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
#include "Images/ProyectoFinalFrm_Fruta_XPM.xpm"
#include "Images/ProyectoFinalFrm_fantasmaIcon_XPM.xpm"
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
	EVT_TIMER(ID_TIMER, ProyectoFinalFrm::movFantasma)
	////Manual Code End
	
	EVT_CLOSE(ProyectoFinalFrm::OnClose)
END_EVENT_TABLE()
////Event Table End


ProyectoFinalFrm::ProyectoFinalFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style),m_timer(this, ID_TIMER)
{
    CreateGUIControls();	
    m_timer.Start(500); 
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

	Texto = new wxTextCtrl(this, ID_TEXTO, _("Score: 0\tVidas: 3"), wxPoint(0, 525), wxSize(675, 40), wxTE_READONLY, wxDefaultValidator, _("Texto"));
	Texto->SetForegroundColour(wxColour(255,255,0));
	Texto->SetBackgroundColour(wxColour(_("BLACK")));
	Texto->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxBOLD, false, _("Fixedsys")));

	wxBitmap Fondo_BITMAP(ProyectoFinalFrm_Fondo_XPM);
	Fondo = new wxStaticBitmap(this, ID_FONDO, Fondo_BITMAP, wxPoint(0, 0), wxSize(675, 525));

	wxBitmap Fruta_BITMAP(ProyectoFinalFrm_Fruta_XPM);
	Fruta = new wxStaticBitmap(this, ID_FRUTA, Fruta_BITMAP, wxPoint(305, 262), wxSize(25, 25));
	Fruta->SetBackgroundColour(wxColour(_("BLACK")));

	wxBitmap fantasmaIcon_BITMAP(ProyectoFinalFrm_fantasmaIcon_XPM);
	fantasmaIcon = new wxStaticBitmap(this, ID_FANTASMAICON, fantasmaIcon_BITMAP, wxPoint(101, 175), wxSize(25, 25));
	fantasmaIcon->SetBackgroundColour(wxColour(_("BLACK")));

	wxBitmap PacmanIcon_BITMAP(ProyectoFinalFrm_PacmanIcon_XPM);
	PacmanIcon = new wxStaticBitmap(this, ID_PACMANICON, PacmanIcon_BITMAP, wxPoint(25, 55), wxSize(25, 25));
	PacmanIcon->SetBackgroundColour(wxColour(_("BLACK")));

	SetTitle(_("Pacman5"));
	SetIcon(wxNullIcon);
	SetSize(-2,0,682,596);
	Center();
	
	////GUI Items Creation End	
}

void ProyectoFinalFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}
 
Juego juego1;
Pacman pacman1;
Fantasma fantasma1;
Frutas fruta1;

//srand(time(NULL));
//srand(wxGetLocalTime());
int posx=pacman1.posPM.first; //Inicializar pos pacman
int posy=pacman1.posPM.second;
wxPoint p(posx*25,posy*25);
wxPoint pF(100, 175);
wxPoint pFr(50,50);

wxPoint moneda;
wxString palabra;

/*
 * OnKeyDown
 */
void ProyectoFinalFrm::OnKeyDown(wxKeyEvent& event)
{     
    //Modifica posicion segun teclas presionadas:
    switch (event.GetKeyCode()) {
    case WXK_LEFT: // Mov izq
        if (juego1.isBlocked(posy, posx-1)==false)
             posx =  posx-1;               
        break;
    case WXK_RIGHT: // Mov dcha
        if (juego1.isBlocked(posy, posx+1)==false)
             posx =  posx+1;
        break;
    case WXK_UP: // Mov up
        if (juego1.isBlocked(posy-1, posx)==false)
            posy = posy-1;
        break;
    case WXK_DOWN: // Mov down
        if (juego1.isBlocked(posy+1, posx)==false)
            posy = posy+1;
        break;
    case WXK_SPACE: // Salida juego espacio
        juego1.gameover();
        break;
    }  
    
    p.x= posx*25;
    p.y= posy*25;
    pacman1.posPM.first=posx;
    pacman1.posPM.second= posy;
    PacmanIcon->Move(p);
    juego1.vidas=pacman1.chequeaVida(pacman1.posPM,fantasma1.posF);
    juego1.puntuacion=fruta1.existeFruta(pacman1.posPM);
    pFr.x=fruta1.posFr.first*25;
    pFr.y=fruta1.posFr.second*25;
    Fruta->Move(pFr);
    wxString punc=wxString::Format("%d", juego1.puntuacion);
    wxString vid=wxString::Format("%d", juego1.vidas);
    Texto->ChangeValue("Score: ");
    Texto->AppendText(punc);
    Texto->AppendText("\tVidas: ");
    Texto->AppendText(vid);
    
        
//    moneda=moneda310->GetPosition();
//    if (p==moneda)
//    moneda310->Hide();
}

/*
 * movFantasma
 */
void ProyectoFinalFrm::movFantasma(wxTimerEvent& timer)
{ 
    fantasma1.posF=randomMov(juego1,fantasma1.posF.first, fantasma1.posF.second);
    pF.x=fantasma1.posF.first*25;
    pF.y=fantasma1.posF.second*25;
    fantasmaIcon->Move(pF); 
    
    juego1.vidas=pacman1.chequeaVida(pacman1.posPM,fantasma1.posF);
}
