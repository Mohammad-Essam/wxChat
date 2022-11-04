/***************************************************************
 * Name:      GUIServerMain.h
 * Purpose:   Defines Application Frame
 * Author:    nothing  (nothing@gmail.com)
 * Created:   2020-07-31
 * Copyright: nothing  (nothing.com)
 * License:
 **************************************************************/

#ifndef GUISERVERMAIN_H
#define GUISERVERMAIN_H



#include "GUIServerApp.h"


#include "GUIFrame.h"
#include <wx/msgdlg.h>
#include <wx/socket.h>

enum{
ID_CONN=1001,
ID_IN,
ID_DEL,
ID_UDP
};
class GUIServerFrame: public GUIFrame
{
    public:
        GUIServerFrame(wxFrame *frame);
        ~GUIServerFrame();
    private:
        wxSocketServer *serv;
        wxDatagramSocket *Dsock;
        wxSocketBase* sockArr[50];
        int connections;
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
        void onConnection(wxSocketEvent& event);
        void onInput(wxSocketEvent& event);
        void onListRightClick( wxListEvent& event );
        void onMonitor(wxCommandEvent& event);
};

#endif // GUISERVERMAIN_H
