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
#include "Images/ProyectoFinalFrm_fondo_XPM.xpm"
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
	EVT_TIMER(ID_TIMER2, ProyectoFinalFrm::movastar)
	////Manual Code End
	
	EVT_CLOSE(ProyectoFinalFrm::OnClose)
	EVT_ACTIVATE(ProyectoFinalFrm::ProyectoFinalFrmActivate)
	EVT_BUTTON(ID_MENU,ProyectoFinalFrm::menuClick)
END_EVENT_TABLE()
////Event Table End


ProyectoFinalFrm::ProyectoFinalFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style),m_timer(this, ID_TIMER),m_timer2(this, ID_TIMER2)
{
    CreateGUIControls();	
    m_timer.Start(500); 
    m_timer2.Start(500); 
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

	wxBitmap fondo_BITMAP(ProyectoFinalFrm_fondo_XPM);
	fondo = new wxStaticBitmap(this, ID_FONDO, fondo_BITMAP, wxPoint(0, 0), wxSize(475, 400));

	wxArrayString arrayStringFor_mensajeInicio;
	arrayStringFor_mensajeInicio.Add(_("Jugador"));
	arrayStringFor_mensajeInicio.Add(_("Modo maquina"));
	mensajeInicio =  new wxSingleChoiceDialog(this, _("Modo de juego:"), _("Single Choice List"), arrayStringFor_mensajeInicio,NULL, wxOK);

	menu = new wxButton(this, ID_MENU, _("Menu opciones"), wxPoint(374, 399), wxSize(100, 39), 0, wxDefaultValidator, _("menu"));

	Texto = new wxTextCtrl(this, ID_TEXTO, _("Score: 0    Vidas: 3"), wxPoint(0, 399), wxSize(375, 40), wxTE_READONLY, wxDefaultValidator, _("Texto"));
	Texto->SetForegroundColour(wxColour(255,255,0));
	Texto->SetBackgroundColour(wxColour(_("BLACK")));
	Texto->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxBOLD, false, _("Fixedsys")));

	wxBitmap Fruta_BITMAP(ProyectoFinalFrm_Fruta_XPM);
	Fruta = new wxStaticBitmap(this, ID_FRUTA, Fruta_BITMAP, wxPoint(305, 262), wxSize(25, 25));
	Fruta->Show(false);
	Fruta->SetBackgroundColour(wxColour(_("BLACK")));

	wxBitmap fantasmaIcon_BITMAP(ProyectoFinalFrm_fantasmaIcon_XPM);
	fantasmaIcon = new wxStaticBitmap(this, ID_FANTASMAICON, fantasmaIcon_BITMAP, wxPoint(101, 175), wxSize(25, 25));
	fantasmaIcon->Show(false);
	fantasmaIcon->SetBackgroundColour(wxColour(_("BLACK")));

	wxBitmap PacmanIcon_BITMAP(ProyectoFinalFrm_PacmanIcon_XPM);
	PacmanIcon = new wxStaticBitmap(this, ID_PACMANICON, PacmanIcon_BITMAP, wxPoint(25, 55), wxSize(25, 25));
	PacmanIcon->Show(false);
	PacmanIcon->SetBackgroundColour(wxColour(_("BLACK")));

	SetTitle(_("Pacman5"));
	SetIcon(wxNullIcon);
	SetSize(8,8,491,479);
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

int posx=pacman1.posPM.first; //Inicializar pos pacman
int posy=pacman1.posPM.second;
int marcador=0;
int respuesta;
int opcion=0;
bool pathFound=false;

wxPoint p(0,0);
wxPoint pF(0,0);
wxPoint pFr(0,0);

wxBitmap Fruta_BITMAP(ProyectoFinalFrm_Fruta_XPM);
wxBitmap fantasmaIcon_BITMAP(ProyectoFinalFrm_fantasmaIcon_XPM);
wxBitmap PacmanIcon_BITMAP(ProyectoFinalFrm_PacmanIcon_XPM);

/*
 * ProyectoFinalFrmActivate
 */
void ProyectoFinalFrm::ProyectoFinalFrmActivate(wxActivateEvent& event)
{    
    //Inicializar pos pacman
	p.x= posx*25;
    p.y= posy*25;
    PacmanIcon->Move(p);
    PacmanIcon->Show();
    
    //Inicializar pos fruta
    pFr.x=fruta1.posFr.first*25;
    pFr.y=fruta1.posFr.second*25;
    Fruta->Move(pFr);
    Fruta->Show();
    
    //Inicializar pos fantasma
    pF.x=fantasma1.posF.first*25;
    pF.y=fantasma1.posF.second*25;
    fantasmaIcon->Move(pF); 
    fantasmaIcon->Show();
    
    mensajeInicio->Move(600,400);
}


/*
 * OnKeyDown
 */
void ProyectoFinalFrm::OnKeyDown(wxKeyEvent& event){     
if (opcion==0){ //Movimiento manual
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
    }  
    
    p.x= posx*25;
    p.y= posy*25;
    pacman1.posPM.first=posx;
    pacman1.posPM.second= posy;
    PacmanIcon->Move(p);
    
    juego1.puntuacion=fruta1.existeFruta(pacman1.posPM);
    if (marcador!=juego1.puntuacion){
        pFr.x=fruta1.posFr.first*25;
        pFr.y=fruta1.posFr.second*25;
        Fruta->Move(pFr);
        Fruta->SetBitmap(Fruta_BITMAP);   
        marcador+=10;
        writeScore();
    }
    
    juego1.vidas=pacman1.chequeaVida(pacman1.posPM,fantasma1.posF);
    if (pacman1.posPM==fantasma1.posF){
        fantasmaIcon->SetBitmap(fantasmaIcon_BITMAP);
        PacmanIcon->SetBitmap(PacmanIcon_BITMAP);
        writeScore();
    }
}  

    if (event.GetKeyCode()== WXK_SPACE)// Salida juego espacio (aparte para que se pueda salir en cualquier caso)
        juego1.gameover();
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
    if (pacman1.posPM==fantasma1.posF){
        PacmanIcon->SetBitmap(PacmanIcon_BITMAP);
        writeScore();
    }
    
    fantasmaIcon->SetBitmap(fantasmaIcon_BITMAP);
    Fruta->SetBitmap(Fruta_BITMAP); 
       
}

wxString punc;
wxString vid;

/*
 * writeScore
 */
void ProyectoFinalFrm::writeScore()
{
    punc=wxString::Format("%d", juego1.puntuacion);
    vid=wxString::Format("%d", juego1.vidas);
    Texto->ChangeValue("Score: ");
    Texto->AppendText(punc);
    Texto->AppendText("    Vidas: ");
    Texto->AppendText(vid);
} 

/*
 * menuClick
 */
void ProyectoFinalFrm::menuClick(wxCommandEvent& event)
{   
    while (respuesta != wxID_OK)  
        respuesta=mensajeInicio->ShowModal();
    
    respuesta = 0; 
    opcion=mensajeInicio->GetSelection();
    
}


point posInst(0,0);
list<point> path1;
list<point>::iterator it;   

/*
 * findPathAstar
 */
void ProyectoFinalFrm::findPathAstar()
{ 
    aStar as;
    point s(posy, posx), e(fruta1.posFr.second,fruta1.posFr.first);       
    as.search(s,e);
    int c=as.path(path1);
    it=path1.begin();
	pathFound=true;
}


/*
 * movastar
 */
void ProyectoFinalFrm::movastar(wxTimerEvent& timer)
{ 
if (opcion==1){ //Movimiento a*
    if(pathFound==false){
        path1.clear();
        findPathAstar();
    }
    
    else{ //Movimiento: estan cambiados la x y la y!!!
		posInst=*it;
		posx=posInst.y; //orden cambiado!!
        posy=posInst.x;
        p.x= posx*25;
        p.y= posy*25;
        pacman1.posPM.first=posx;
        pacman1.posPM.second=posy;
        PacmanIcon->Move(p);
        it++;
        
        juego1.vidas=pacman1.chequeaVida(pacman1.posPM,fantasma1.posF);
        if (pacman1.posPM==fantasma1.posF){
            fantasmaIcon->SetBitmap(fantasmaIcon_BITMAP);
            PacmanIcon->SetBitmap(PacmanIcon_BITMAP);
            writeScore();
        }
        
    	juego1.puntuacion=fruta1.existeFruta(pacman1.posPM);
        if (marcador!=juego1.puntuacion){
            m_timer2.Stop();
    
            pFr.x=fruta1.posFr.first*25;
            pFr.y=fruta1.posFr.second*25;
            Fruta->Move(pFr);
            Fruta->SetBitmap(Fruta_BITMAP);   
            marcador+=10;
            writeScore();
        
            pathFound=false;
            m_timer2.Start();
        }
    }
}     
else{
    pathFound=false;
}
}


