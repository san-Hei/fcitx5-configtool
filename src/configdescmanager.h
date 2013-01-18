/***************************************************************************
 *   Copyright (C) 2011~2011 by CSSlayer                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#ifndef CONFIGDESCMANAGER_H
#define CONFIGDESCMANAGER_H

// Qt
#include <QHash>

// Fcitx
#include <fcitx-config/fcitx-config.h>
#include <fcitx-qt/fcitxqtinputmethodproxy.h>
#include <fcitx-qt/fcitxqtkeyboardproxy.h>

class FcitxQtKeyboardProxy;
class FcitxQtInputMethodProxy;
class FcitxQtConfigUIFactory;
class FcitxQtConnection;
namespace Fcitx
{

class ConfigDescManager : public QObject
{
    Q_OBJECT
public:
    static ConfigDescManager* instance();
    static void deInit();
    virtual ~ConfigDescManager();
    FcitxConfigFileDesc* GetConfigDesc(const QString& name);
    FcitxQtConfigUIFactory* factory() { return m_factory; }
    FcitxQtConnection* connection() { return m_connection; }
    FcitxQtInputMethodProxy* inputMethodProxy() { return  (m_inputmethod && m_inputmethod->isValid()) ? m_inputmethod : 0; }
    FcitxQtKeyboardProxy* keyboardProxy() { return  (m_keyboard && m_keyboard->isValid()) ? m_keyboard : 0; }

public slots:
    void connected();
    void disconnected();

private:
    ConfigDescManager();
    QHash<QString, FcitxConfigFileDesc*>* m_hash;
    FcitxQtConfigUIFactory* m_factory;
    FcitxQtConnection* m_connection;
    FcitxQtInputMethodProxy* m_inputmethod;
    FcitxQtKeyboardProxy* m_keyboard;
    static ConfigDescManager* inst;
};

}

#endif
