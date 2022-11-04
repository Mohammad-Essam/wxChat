/***************************************************************
 * Name:      ChatClientMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    nothing  (nothing@gmail.com)
 * Created:   2020-07-27
 * Copyright: nothing  (nothing.com)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "ChatClientMain.h"

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

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



ChatClientFrame::ChatClientFrame(wxFrame *frame)
    : GUIFrame(frame)
{
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_("you should connect first"), 0);
    statusBar->SetStatusText("to be able to send messages", 1);
#endif
	
    sock=new wxSocketClient();
    sock->SetEventHandler(*this);
    sock->SetNotify(wxSOCKET_INPUT_FLAG|wxSOCKET_CONNECTION_FLAG|wxSOCKET_LOST_FLAG);
    sock->Notify(true);

    Bind(wxEVT_SOCKET,&ChatClientFrame::onRecieve,this);

    //initialize the form responsible to connection
    username= new wxString();
	userForm = new usernameFrame(this,m_menuItem3,sock);
    userForm->usr=username;
	//userForm->menuItem=m_menuItem3;
    userForm->Show(true);

}

ChatClientFrame::~ChatClientFrame()
{

}

void ChatClientFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void ChatClientFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void ChatClientFrame::OnAbout(wxCommandEvent &event)
{

    wxMessageBox(_("just a simple chat app to try to use sockets\nit uses wxWidget library"),"about..",wxICON_INFORMATION|wxOK_DEFAULT);
}

void ChatClientFrame::myTxtonEnter(wxCommandEvent& event)
{
    ChatClientFrame::onSend(event);
}

void ChatClientFrame::ConnectToServer(wxCommandEvent& event)
{
	
	
	if(sock==0)
	{
	
        sock=new wxSocketClient();
        sock->SetEventHandler(*this);
        sock->SetNotify(wxSOCKET_INPUT_FLAG|wxSOCKET_CONNECTION_FLAG|wxSOCKET_LOST_FLAG);
        sock->Notify(true);

//        Bind(wxEVT_SOCKET,&ChatClientFrame::onRecieve,this);

		userForm = new usernameFrame(this,m_menuItem3,sock);
        userForm->CenterOnScreen();
        userForm->usr=username;
        userForm->Show(true);	
	}	
	else if(sock->IsDisconnected())
	{
		userForm = new usernameFrame(this,m_menuItem3,sock);
        userForm->CenterOnScreen();
        userForm->usr=username;
        userForm->Show(true);	
	}
	else
    {
		wxMessageBox("you are already connected");
    }

//    wxIPV4address addr;
//    addr.Hostname("127.0.0.1");
//    addr.Service(9901);
//    ChatClientFrame::sock->Connect(addr,false);



}

void ChatClientFrame::onSend( wxCommandEvent& event )
{
    if(myTxt->IsEmpty())
    {

    }
    else
    if(sock->IsConnected()&&sock->Ok())
    {
        wxUint16 len;
        wxString str =*username+" : "+myTxt->GetValue()+'\n';
        wxCharBuffer buff=str.ToUTF8();
        len =strlen(buff.data())+1;
        myTxt->SetValue("");
        sock->Write(&len,sizeof(len));
        sock->Write(buff.data(),len);//the +1 is essential for arabic, i dont know why
		ChatClientFrame::myRich->AppendText(wxString(buff,wxConvUTF8));//send it to the richtextbox
    }
    else
    {
        wxMessageBox("you need to connect first \n goto the menu bar ->file \nthen select connect then try again");
    }
}
void ChatClientFrame::onRecieve(wxSocketEvent& event)
{
    switch(event.GetSocketEvent())
    {
    case wxSOCKET_CONNECTION:
    {
        //send information about the client to the server to store it
        //in the clientData function
        sockdata data;
        strncpy(data.os,(wxPlatformInfo::Get().GetOperatingSystemIdName().mbc_str()),strlen((wxPlatformInfo::Get().GetOperatingSystemIdName().mbc_str())));
        sock->Write(&data,sizeof(data));
        wxMessageBox("connection establised");
        m_menuItem3->Enable(false);


#if wxUSE_STATUSBAR
        statusBar->SetStatusText(_("Connected!"), 0);
        statusBar->SetStatusText("now you can send messages", 1);
#endif
        break;
    }
    case wxSOCKET_INPUT:
    {
        sock->SetFlags(wxSOCKET_WAITALL);
        sock->SetNotify(wxSOCKET_LOST_FLAG);
        int bytee;
        wxUint16 len;
        char buff[1024];
        sock->Read(&len,sizeof(len)).LastCount();
        bytee=sock->Read(buff,len).LastCount();

        if(!bytee)
        {
            wxMessageBox("some error has occured\ntry to connect another time");
            sock->Destroy();
        }

        ChatClientFrame::myRich->AppendText(wxString(buff,wxConvUTF8));
        sock->SetNotify(wxSOCKET_INPUT_FLAG|wxSOCKET_LOST_FLAG);
        break;
    }
    case wxSOCKET_LOST:
    {
        sock->Destroy();
		sock=0;
        wxMessageBox("no connection is established\n try to connect another time");
        m_menuItem3->Enable();
        break;
    }

  }
}


//username frame

usernameFrame::usernameFrame( wxWindow* parent,wxMenuItem* item,wxSocketClient* sock) : usernameFrameGUI( parent)
{
	usernameFrame::menuItem=item;
	usernameFrame::childSock=sock;
	menuItem->Enable(false);   
}

usernameFrame::~usernameFrame()
{
	menuItem->Enable(true);
}


void usernameFrame::onEnter( wxCommandEvent& event )
{
    onConnBtnClick(event);
}
void usernameFrame::onCancle( wxCommandEvent& event )
{
    this->Destroy();
}
void usernameFrame::onConnBtnClick( wxCommandEvent& event )
{
    if(usrTxt->IsEmpty())
    {
		wxMessageBox(_("you MUST choose a name to connect to the server"),_("error"),wxICON_ERROR);
    }
    else
    {
		//if(!childSock->IsOk())
		//{
			wxIPV4address addr;
			addr.Hostname("127.0.0.1");
			addr.Service(9901);
			childSock->Connect(addr,false);
			*usr=usrTxt->GetValue();
//			menuItem->Enable(true);
			this->Destroy();
		//}
		//else
		//{
		//	wxMessageBox("already connected");
		//	this->Destroy();
		//}
    }
}
