/***************************************************************
 * Name:      ChatClientApp.cpp
 * Purpose:   Code for Application Class
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

#include "ChatClientApp.h"
#include "ChatClientMain.h"

IMPLEMENT_APP(ChatClientApp);

bool ChatClientApp::OnInit()
{
    ChatClientFrame* frame = new ChatClientFrame(0L);
	frame->SetIcon(wxICON(myicon));
    frame->Show();
    
    return true;
}
