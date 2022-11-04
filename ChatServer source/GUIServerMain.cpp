/***************************************************************
 * Name:      GUIServerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    nothing  (nothing@gmail.com)
 * Created:   2020-07-31
 * Copyright: nothing  (nothing.com)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "GUIServerMain.h"
#include <cstdlib>
//helper functions

struct sockdata
{
    char os[20];
    sockdata(char o[20]="",char user[30]="")
    {
        memset(os,'\0',20);
    }
};



enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

GUIServerFrame::GUIServerFrame(wxFrame *frame)
    : GUIFrame(frame)
{
	SetIcon(wxICON(myicon));
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
    statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif

    myList->InsertColumn(0,_("SocketFD"),wxLIST_FORMAT_LEFT,100);
    myList->InsertColumn(1,_("Ip Address"),wxLIST_FORMAT_LEFT,100);
    myList->InsertColumn(2,_("System"),wxLIST_FORMAT_LEFT,100);

    connections=0;
    wxIPV4address addr;
    addr.AnyAddress();
    addr.Service(9901);
    serv = new wxSocketServer(addr);

    serv->SetEventHandler(*this,ID_CONN);
    serv->SetNotify(wxSOCKET_CONNECTION_FLAG);
    serv->Notify(true);
    Bind(wxEVT_SOCKET,&GUIServerFrame::onConnection,this,ID_CONN);
    Bind(wxEVT_SOCKET,&GUIServerFrame::onInput,this,ID_IN);

}

GUIServerFrame::~GUIServerFrame()
{

}
void GUIServerFrame::onConnection(wxSocketEvent& event)
{
    if(event.GetSocketEvent()==wxSOCKET_CONNECTION)
    {
    wxSocketBase* sockBase;
    sockBase=serv->Accept(false);

    //setting its information in the server list
    sockArr[connections]=sockBase;
    connections++;
    statusBar->SetStatusText(_( wxString::Format("connections: %d",connections)),1);

    sockBase->SetEventHandler(*this,ID_IN);
    sockBase->SetNotify(wxSOCKET_INPUT_FLAG|wxSOCKET_LOST_FLAG);
    sockBase->Notify(true);
    }

}

void GUIServerFrame::onInput(wxSocketEvent& event)
{
    if(event.GetSocketEvent()==wxSOCKET_INPUT)
    {
        wxSocketBase* mySock = event.GetSocket();
        char buff[1024];
        if(event.GetSocket()->GetClientData()!=NULL)
        {
            wxUint16 len;
            mySock->Read(&len,sizeof(len));
            mySock->Read(buff,len);

//            mySock->Write(&len,sizeof(len));
//            mySock->Write(buff,len);
            for(int i=0; i<connections; i++)
            {
				if(sockArr[i]->IsOk())
                {
					if(sockArr[i]!=mySock)
					{
                    sockArr[i]->Write(&len,sizeof(len));
                    sockArr[i]->Write(buff,len);
					}
                }

                else
                wxMessageBox("error at writing");
             }
        }
        else
        {
            sockdata data;
            mySock->Read(&data,sizeof(data));
            mySock->SetClientData(&data);
            wxIPV4address addr;
            mySock->GetPeer(addr);
            myList->InsertItem(connections-1,_("item"));
            myList->SetItemData(connections-1,wxPtrToUInt(mySock));
            myList->SetItem(connections-1,0,_(wxString::Format("%d",mySock->GetSocket())));
            myList->SetItem(connections-1,1,_(addr.IPAddress()));
            myList->SetItem(connections-1,2,_(data.os));
        }
    }

    else if(event.GetSocketEvent()==wxSOCKET_LOST)
    {
        for(int i=0; i<connections; i++)
        {
            if(event.GetSocket()==sockArr[i])
            {
                for(int j=i; j<connections;j++)
                {
                    sockArr[j]=sockArr[j+1];
                }
                myList->DeleteItem(i);
                break;
            }
        }
        connections--;
        statusBar->SetStatusText(_( wxString::Format("connections: %d",connections)),1);
    }
}

void GUIServerFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void GUIServerFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void GUIServerFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
