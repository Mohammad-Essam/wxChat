/***************************************************************
 * Name:      ChatClientMain.h
 * Purpose:   Defines Application Frame
 * Author:    nothing  (nothing@gmail.com)
 * Created:   2020-07-27
 * Copyright: nothing  (nothing.com)
 * License:
 **************************************************************/

#ifndef CHATCLIENTMAIN_H
#define CHATCLIENTMAIN_H



#include "ChatClientApp.h"


#include "GUIFrame.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <wx/msgdlg.h>
#include <wx/socket.h>
#include <wx/timer.h>
struct sockdata
{
    char os[20];

    sockdata()
    {
        memset(os,'\0',20);
    }
};

class usernameFrame : public usernameFrameGUI
{
    public:
		usernameFrame( wxWindow* parent,wxMenuItem* item,wxSocketClient *sock);
		~usernameFrame();

        wxSocketClient *childSock;
        wxString* usr;
		wxMenuItem * menuItem;
        private:
        // Virtual event handlers, overide them in your derived class
        void onEnter( wxCommandEvent& event );
        void onCancle( wxCommandEvent& event );
        void onConnBtnClick( wxCommandEvent& event );


};

///////////////////////////////////////////////////////////////////////////////
/// Class usernameFrame
///////////////////////////////////////////////////////////////////////////////

class ChatClientFrame: public GUIFrame
{
    public:
        ChatClientFrame(wxFrame *frame);
        ~ChatClientFrame();
    private:
        usernameFrame * userForm ;
        wxSocketClient* sock;
        wxString* username;
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void myTxtonEnter( wxCommandEvent& event );
        void ConnectToServer(wxCommandEvent& event);
		void onSend( wxCommandEvent& event );
		void onRecieve(wxSocketEvent& event);

};

#endif // CHATCLIENTMAIN_H
