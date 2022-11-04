///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

usernameFrameGUI::usernameFrameGUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 410,260 ), wxSize( 414,267 ) );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	m_staticText2 = new wxStaticText( m_panel2, wxID_ANY, wxT("choose your nickname"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer12->Add( m_staticText2, 0, wxLEFT|wxTOP, 40 );

	usrTxt = new wxTextCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer12->Add( usrTxt, 0, wxALL|wxEXPAND, 20 );

	connBtn = new wxButton( m_panel2, wxID_ANY, wxT("Connect"), wxDefaultPosition, wxSize( 200,40 ), 0 );
	bSizer12->Add( connBtn, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_button3 = new wxButton( m_panel2, wxID_ANY, wxT("cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_button3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizer11->Add( bSizer12, 1, wxEXPAND, 5 );


	m_panel2->SetSizer( bSizer11 );
	m_panel2->Layout();
	bSizer11->Fit( m_panel2 );
	bSizer6->Add( m_panel2, 1, wxALL|wxEXPAND, 0 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	usrTxt->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( usernameFrameGUI::onEnter ), NULL, this );
	connBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( usernameFrameGUI::onConnBtnClick ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( usernameFrameGUI::onCancle ), NULL, this );
}

usernameFrameGUI::~usernameFrameGUI()
{
	// Disconnect Events
	usrTxt->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( usernameFrameGUI::onEnter ), NULL, this );
	connBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( usernameFrameGUI::onConnBtnClick ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( usernameFrameGUI::onCancle ), NULL, this );

}

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 541,649 ), wxDefaultSize );

	mbar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	m_menuItem3 = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("connect\tCtrl+o") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( m_menuItem3 );

	fileMenu->AppendSeparator();

	wxMenuItem* menuFileQuit;
	menuFileQuit = new wxMenuItem( fileMenu, idMenuQuit, wxString( wxT("&Quit") ) + wxT('\t') + wxT("Alt+F4"), wxT("Quit the application"), wxITEM_NORMAL );
	fileMenu->Append( menuFileQuit );

	mbar->Append( fileMenu, wxT("&File") );

	helpMenu = new wxMenu();
	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( helpMenu, idMenuAbout, wxString( wxT("&About") ) + wxT('\t') + wxT("F1"), wxT("Show info about this application"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpAbout );

	mbar->Append( helpMenu, wxT("&Help") );

	this->SetMenuBar( mbar );

	statusBar = this->CreateStatusBar( 2, wxSTB_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	myRich = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH );
	myRich->SetFont( wxFont( 16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );
	myRich->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	myRich->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );

	bSizer5->Add( myRich, 1, wxALL|wxEXPAND, 10 );


	bSizer4->Add( bSizer5, 6, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	myTxt = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB );
	bSizer6->Add( myTxt, 6, wxALL|wxEXPAND, 20 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	myBtn = new wxButton( m_panel1, wxID_ANY, wxT("send"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer7->Add( myBtn, 1, wxBOTTOM|wxEXPAND|wxTOP, 30 );


	bSizer6->Add( bSizer7, 1, wxALL|wxEXPAND, 5 );


	bSizer4->Add( bSizer6, 1, wxEXPAND, 5 );


	m_panel1->SetSizer( bSizer4 );
	m_panel1->Layout();
	bSizer4->Fit( m_panel1 );
	bSizer1->Add( m_panel1, 1, wxEXPAND | wxALL, 0 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::ConnectToServer ), this, m_menuItem3->GetId());
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ), this, menuFileQuit->GetId());
	helpMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ), this, menuHelpAbout->GetId());
	myTxt->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::myTxtonEnter ), NULL, this );
	myBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::onSend ), NULL, this );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	myTxt->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::myTxtonEnter ), NULL, this );
	myBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::onSend ), NULL, this );

}
