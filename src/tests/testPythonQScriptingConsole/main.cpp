/*
 *
 *  Copyright (C) MeVis Medical Solutions AG All Rights Reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  Further, this software is distributed without any warranty that it is
 *  free of the rightful claim of any third person regarding infringement
 *  or the like.  Any license provided herein, whether implied or
 *  otherwise, applies only to this software file.  Patent licenses, if
 *  any, provided herein do not apply to combinations of this program with
 *  other software, or any other product whatsoever.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Contact information: MeVis Medical Solutions AG, Universitaetsallee 29,
 *  28359 Bremen, Germany or:
 *
 *  http://www.mevis.de
 *
 */

//----------------------------------------------------------------------------------
/*!
// \file    PythonQtTests.cpp
// \author  Florian Link
// \author  Last changed by $Author: florian $
// \date    2006-05
*/
//----------------------------------------------------------------------------------

#include "PythonQt.h"

#include "PyExampleObject.h"
#include "gui/PythonQtScriptingConsole.h"

#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QLayout>


int main( int argc, char **argv )
{
    QApplication qapp(argc, argv);

    PythonQt::init(PythonQt::IgnoreSiteModule | PythonQt::RedirectStdOut );

    PythonQtObjectPtr  mainContext = PythonQt::self()->getMainModule();
    PythonQtScriptingConsole console(NULL, mainContext);
    console.resize(640,480);
    console.appendWelcomeMessage("Welcome");
    QStringList inv;
    inv << "connect" << "delete" << "deleteLater" << "destroyed" ;
    //console.setInvisibleCompletitionMethods(inv);
    // add a QObject to the namespace of the main python context
    PyExampleObject example;
    mainContext.addObject("example", &example);

    console.show();
    return qapp.exec();
}

