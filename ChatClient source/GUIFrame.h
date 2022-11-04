///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>

///////////////////////////////////////////////////////////////////////////

#define idMenuQuit 1000
#define idMenuAbout 1001

///////////////////////////////////////////////////////////////////////////////
/// Class usernameFrameGUI
///////////////////////////////////////////////////////////////////////////////
class usernameFrameGUI : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel2;
		wxStaticText* m_staticText2;
		wxTextCtrl* usrTxt;
		wxButton* connBtn;
		wxButton* m_button3;

		// Virtual event handlers, overide them in your derived class
		virtual void onEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void onConnBtnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCancle( wxCommandEvent& event ) { event.Skip(); }


	public:

		usernameFrameGUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("choose a  username to connect"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 414,267 ), long style = wxCAPTION|wxSTAY_ON_TOP|wxTAB_TRAVERSAL );

		~usernameFrameGUI();

};

///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame
{
	private:

	protected:
		wxMenuBar* mbar;
		wxMenu* fileMenu;
		wxMenuItem* m_menuItem3;
		wxMenu* helpMenu;
		wxStatusBar* statusBar;
		wxPanel* m_panel1;
		wxTextCtrl* myRich;
		wxTextCtrl* myTxt;
		wxButton* myBtn;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void ConnectToServer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void myTxtonEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSend( wxCommandEvent& event ) { event.Skip(); }


	public:

		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("a simple chat client"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 541,649 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~GUIFrame();

};

