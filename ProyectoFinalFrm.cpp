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
#include "Images/ProyectoFinalFrm_fantasmaIcon4_XPM.xpm"
#include "Images/ProyectoFinalFrm_fantasmaIcon3_XPM.xpm"
#include "Images/ProyectoFinalFrm_fantasmaIcon2_XPM.xpm"
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
	EVT_BUTTON(ID_INSTRUCCIONES,ProyectoFinalFrm::instrClick)
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

	WxMessageDialog2 =  new wxMessageDialog(this, _("GAME OVER"), _("FIN DEL JUEGO"), wxOK);

	WxMessageDialog3 =  new wxMessageDialog(this, _("PACMAN GAME\n\nInstrucciones del juego:\n*En el menú de opciones puede seleccionar la partida en modo manual o máquina\n*Para ganar la partida se deben conseguir 100 puntos\n*Cada fruta sumará 10 puntos\n*Cada vez que se encuentre un fantasma perderá una vida\n*En el modo máquina sólo habrá un fantasma para evitar que el juego finalice en un periodo corto\n\n¡Disfrute del juego!"), _("INICIO DEL JUEGO"), wxOK);

	WxMessageDialog1 =  new wxMessageDialog(this, _("¡Enhorabuena, has ganado!"), _("FIN DEL JUEGO"), wxOK);

	wxArrayString arrayStringFor_mensajeInicio;
	arrayStringFor_mensajeInicio.Add(_("Jugador"));
	arrayStringFor_mensajeInicio.Add(_("Modo maquina"));
	mensajeInicio =  new wxSingleChoiceDialog(this, _("Modo de juego:"), _("Single Choice List"), arrayStringFor_mensajeInicio,NULL, wxOK);

	instrucciones = new wxButton(this, ID_INSTRUCCIONES, _("Info"), wxPoint(264, 400), wxSize(105, 35), 0, wxDefaultValidator, _("instrucciones"));

	wxBitmap fondo_BITMAP(ProyectoFinalFrm_fondo_XPM);
	fondo = new wxStaticBitmap(this, ID_FONDO, fondo_BITMAP, wxPoint(0, 0), wxSize(475, 400));

	menu = new wxButton(this, ID_MENU, _("Menu"), wxPoint(372, 400), wxSize(102, 35), 0, wxDefaultValidator, _("menu"));

	Texto = new wxTextCtrl(this, ID_TEXTO, _("Score: 0    Vidas: 3"), wxPoint(0, 400), wxSize(263, 35), wxTE_READONLY, wxDefaultValidator, _("Texto"));
	Texto->SetForegroundColour(wxColour(255,255,0));
	Texto->SetBackgroundColour(wxColour(_("BLACK")));
	Texto->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxBOLD, false, _("Fixedsys")));

	wxBitmap fantasmaIcon4_BITMAP(ProyectoFinalFrm_fantasmaIcon4_XPM);
	fantasmaIcon4 = new wxStaticBitmap(this, ID_FANTASMAICON4, fantasmaIcon4_BITMAP, wxPoint(225, 150), wxSize(25, 25));
	fantasmaIcon4->Show(false);
	fantasmaIcon4->SetBackgroundColour(wxColour(_("BLACK")));

	wxBitmap fantasmaIcon3_BITMAP(ProyectoFinalFrm_fantasmaIcon3_XPM);
	fantasmaIcon3 = new wxStaticBitmap(this, ID_FANTASMAICON3, fantasmaIcon3_BITMAP, wxPoint(200, 25), wxSize(25, 25));
	fantasmaIcon3->Show(false);
	fantasmaIcon3->SetBackgroundColour(wxColour(_("BLACK")));

	wxBitmap fantasmaIcon2_BITMAP(ProyectoFinalFrm_fantasmaIcon2_XPM);
	fantasmaIcon2 = new wxStaticBitmap(this, ID_FANTASMAICON2, fantasmaIcon2_BITMAP, wxPoint(25, 25), wxSize(25, 25));
	fantasmaIcon2->Show(false);
	fantasmaIcon2->SetBackgroundColour(wxColour(_("BLACK")));

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

	SetTitle(_("PACMAN"));
	SetIcon(wxNullIcon);
	SetSize(8,8,491,480);
	Center();
	
	////GUI Items Creation End	

}

void ProyectoFinalFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}
 
Juego juego1;
Pacman pacman1;
Fantasma fantasma1, fantasma2, fantasma3, fantasma4;
Frutas fruta1;

int posx=pacman1.posPM.first; //Inicializar pos pacman
int posy=pacman1.posPM.second;
int marcador=0;
int respuesta,respuesta2;
int opcion=0;
bool pathFound=false;
int selec1,selec2;

wxPoint p(0,0);
wxPoint pF(0,0),pF2(0,0),pF3(0,0),pF4(0,0);
wxPoint pFr(0,0);

wxBitmap Fruta_BITMAP(ProyectoFinalFrm_Fruta_XPM);
wxBitmap fantasmaIcon_BITMAP(ProyectoFinalFrm_fantasmaIcon_XPM);
wxBitmap PacmanIcon_BITMAP(ProyectoFinalFrm_PacmanIcon_XPM);
wxBitmap fantasmaIcon2_BITMAP(ProyectoFinalFrm_fantasmaIcon2_XPM);
wxBitmap fantasmaIcon3_BITMAP(ProyectoFinalFrm_fantasmaIcon3_XPM);
wxBitmap fantasmaIcon4_BITMAP(ProyectoFinalFrm_fantasmaIcon4_XPM);

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
    
    pF2.x=fantasma2.posF.first*25;
    pF2.y=fantasma2.posF.second*25;
    fantasmaIcon2->Move(pF2); 
    fantasmaIcon2->Show();
    
    pF3.x=fantasma3.posF.first*25;
    pF3.y=fantasma3.posF.second*25;
    fantasmaIcon3->Move(pF3); 
    fantasmaIcon3->Show();
    
    pF4.x=fantasma4.posF.first*25;
    pF4.y=fantasma4.posF.second*25;
    fantasmaIcon4->Move(pF4); 
    fantasmaIcon4->Show();
    
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
    juego1.vidas=pacman1.chequeaVida(pacman1.posPM,fantasma2.posF);
    juego1.vidas=pacman1.chequeaVida(pacman1.posPM,fantasma3.posF);
    juego1.vidas=pacman1.chequeaVida(pacman1.posPM,fantasma4.posF);
    if (pacman1.posPM==fantasma1.posF || pacman1.posPM==fantasma2.posF || pacman1.posPM==fantasma3.posF || pacman1.posPM==fantasma4.posF){
        fantasmaIcon->SetBitmap(fantasmaIcon_BITMAP);
        fantasmaIcon2->SetBitmap(fantasmaIcon2_BITMAP);
        fantasmaIcon3->SetBitmap(fantasmaIcon3_BITMAP);
        fantasmaIcon4->SetBitmap(fantasmaIcon4_BITMAP);
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
    fantasma1.posF=randomMov(juego1,fantasma1.posF.first, fantasma1.posF.second, fantasma2.posF,fantasma3.posF,fantasma4.posF);
    pF.x=fantasma1.posF.first*25;
    pF.y=fantasma1.posF.second*25;
    fantasmaIcon->Move(pF); 
    
    fantasma2.posF=randomMov(juego1,fantasma2.posF.first, fantasma2.posF.second,fantasma1.posF,fantasma3.posF,fantasma4.posF);
    pF2.x=fantasma2.posF.first*25;
    pF2.y=fantasma2.posF.second*25;
    fantasmaIcon2->Move(pF2); 
    
    fantasma3.posF=randomMov(juego1,fantasma3.posF.first, fantasma3.posF.second,fantasma2.posF,fantasma1.posF,fantasma4.posF);
    pF3.x=fantasma3.posF.first*25;
    pF3.y=fantasma3.posF.second*25;
    fantasmaIcon3->Move(pF3);
    
    fantasma4.posF=randomMov(juego1,fantasma4.posF.first, fantasma4.posF.second,fantasma2.posF,fantasma3.posF,fantasma1.posF);
    pF4.x=fantasma4.posF.first*25;
    pF4.y=fantasma4.posF.second*25;
    fantasmaIcon4->Move(pF4);
    
    juego1.vidas=pacman1.chequeaVida(pacman1.posPM,fantasma1.posF);
    if(opcion==0){
        // Con esto sólo se restarán vidas todos los fantasmas si estamos en modo manual
        juego1.vidas=pacman1.chequeaVida(pacman1.posPM,fantasma2.posF);
        juego1.vidas=pacman1.chequeaVida(pacman1.posPM,fantasma3.posF);
        juego1.vidas=pacman1.chequeaVida(pacman1.posPM,fantasma4.posF);
    }
    if (pacman1.posPM==fantasma1.posF || pacman1.posPM==fantasma2.posF || pacman1.posPM==fantasma3.posF || pacman1.posPM==fantasma4.posF){
        PacmanIcon->SetBitmap(PacmanIcon_BITMAP);
        writeScore();
    }
    
    fantasmaIcon->SetBitmap(fantasmaIcon_BITMAP);
    fantasmaIcon2->SetBitmap(fantasmaIcon2_BITMAP);
    fantasmaIcon3->SetBitmap(fantasmaIcon3_BITMAP);
    fantasmaIcon4->SetBitmap(fantasmaIcon4_BITMAP);
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
    if(juego1.puntuacion==100){
            endGame1();
            juego1.gameover();
    }
    if(juego1.vidas==0){
            endGame2();
            juego1.gameover();
    }
    
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

    fantasmaIcon2->Hide();
    fantasmaIcon3->Hide();
    fantasmaIcon4->Hide();

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

        if (pacman1.posPM==fantasma1.posF ){
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

/*
 * endGame1
 */
void ProyectoFinalFrm::endGame1()
{   
    while (selec1 != wxID_OK)  
        selec1=WxMessageDialog1->ShowModal();
  
}

/*
 * endGame2
 */
void ProyectoFinalFrm::endGame2()
{   
    while (selec2 != wxID_OK)  
        selec2=WxMessageDialog2->ShowModal();
  
}

/*
 * instrClick
 */
void ProyectoFinalFrm::instrClick(wxCommandEvent& event)
{   
    while (respuesta2 != wxID_OK)  
        respuesta2=WxMessageDialog3->ShowModal();
    
    respuesta2 = 0; 
}
