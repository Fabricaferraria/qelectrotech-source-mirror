/*
	Copyright 2006-2015 The QElectroTech Team
	This file is part of QElectroTech.

	QElectroTech is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 2 of the License, or
	(at your option) any later version.

	QElectroTech is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with QElectroTech.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef ELEMENTINFOWIDGET_H
#define ELEMENTINFOWIDGET_H

#include <QWidget>
#include "diagramcontext.h"
#include "abstractelementpropertieseditorwidget.h"

class Element;
class QUndoCommand;
class ElementInfoPartWidget;
class ChangeElementInformationCommand;

namespace Ui {
	class ElementInfoWidget;
}

/**
 * @brief The ElementInfoWidget class
 * this class is a widget to edit an element informations.
 */
class ElementInfoWidget : public AbstractElementPropertiesEditorWidget
{
	Q_OBJECT

		//METHODS
	public:
		explicit ElementInfoWidget(Element *elmt, QWidget *parent = 0);
		~ElementInfoWidget();

		void setElement(Element *element);
		void apply();
		QUndoCommand *associatedUndo () const;
		QString title() const {return tr("Informations");}

	protected:
		virtual bool event(QEvent *event);

	private:
		void buildInterface();
		void fillInfo();

	private slots:
		void firstActivated();

		//ATTRIBUTES
	private:
		Ui::ElementInfoWidget           *ui;
		DiagramContext                   m_element_info;
		QList <ElementInfoPartWidget *>  eipw_list;
		bool m_first_activation;
};

#endif // ELEMENTINFOWIDGET_H
