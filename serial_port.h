/*
 * Copyright (C) 2021 Igor Misic, <igy1000mb@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 *
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H

#include <QSerialPort>
#include <QFile>
#include <QTimer>
#include "mainwindow.h"
#include "settingsdialog.h"

class SettingsDialog;

QT_BEGIN_NAMESPACE

class SerialPort : public QSerialPort {

    Q_OBJECT

public:
    SerialPort();
    ~SerialPort(){}
    void openConn();
    void openConnBlocking();
    void closeConn();
    bool isOpen();
    bool tryOpenPort();
    manufact_name getManufactName() {return m_port.manufactNameEnum;}

private:
    SettingsDialog *m_settings = nullptr;
    bool m_isOpen;
    SettingsDialog::Settings m_port;
    QTimer m_timer;
};


#endif // SERIAL_PORT_H
