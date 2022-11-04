/***************************************************************
 * Name:      GUIServerApp.cpp
 * Purpose:   Code for Application Class
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

#include "GUIServerApp.h"
#include "GUIServerMain.h"

IMPLEMENT_APP(GUIServerApp);

bool GUIServerApp::OnInit()
{
    GUIServerFrame* frame = new GUIServerFrame(0L);
    
    frame->Show();
    
    return true;
}
