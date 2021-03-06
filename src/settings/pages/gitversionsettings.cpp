/**
 ** This file is part of the uDevkit-IDE project.
 ** Copyright 2017-2020 UniSwarm
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program. If not, see <http://www.gnu.org/licenses/>.
 **/

#include "gitversionsettings.h"

#include <QFormLayout>

GitVersionSettings::GitVersionSettings()
    : SettingsPage(QIcon(":/icons/img/dark/icons8-git.png"), tr("Git version"))
{
    _settingsClass = rtset()->registerClass("gitversion");
    createWidgets();
}

void GitVersionSettings::execCommit()
{
    _settingsClass->setSetting("path", _pathEditWidget->path());
    _settingsClass->commit();
}

void GitVersionSettings::createWidgets()
{
    QFormLayout *layout = new QFormLayout();
    layout->setLabelAlignment(Qt::AlignVCenter | Qt::AlignLeft);

    _pathEditWidget = new PathEditWidget();
    _pathEditWidget->setProgramm("git");
    _pathEditWidget->setPath(_settingsClass->setting("path").toString());
    _pathEditWidget->setVersionArg("--version");
    _pathEditWidget->checkProgramm();
    layout->addRow(tr("Git path"), _pathEditWidget);
    layout->labelForField(_pathEditWidget)->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setLayout(layout);
}
