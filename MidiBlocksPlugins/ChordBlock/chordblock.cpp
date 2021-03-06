/*
    Copyright (C) 2013  Adam Nash

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

  */

#include "chordblock.h"
#include "ui_chordblockeditor.h"

ChordBlock::ChordBlock(QObject *parent) :
    editorUi(new Ui::ChordBlockEditor)
{
    if (parent)
    {
        setParent(parent);
    }
    
    editor = new QWidget();
    editorUi->setupUi(editor);
}

ChordBlock::~ChordBlock()
{
    delete editorUi;
    delete editor;
}

QString ChordBlock::getName()
{
    return "ChordBlock";
}

QString ChordBlock::getGroupName()
{
    return "My Control Blocks";
}

QWidget* ChordBlock::getEditorWidget()
{
    return editor;
}

ControlBlock* ChordBlock::createDefaultBlock()
{
    return new ChordBlock();
}

Q_EXPORT_PLUGIN2(chordblockplugin, ChordBlock)

