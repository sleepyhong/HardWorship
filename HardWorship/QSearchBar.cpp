#include "QSearchBar.h"

QSearchBar::QSearchBar(QWidget *parent) : QLineEdit(parent)
{

}

QSearchBar::~QSearchBar()
{

}

void QSearchBar::focusInEvent(QFocusEvent *e)
{
      QLineEdit::focusInEvent(e);
      emit focussed();
}

void QSearchBar::focusOutEvent(QFocusEvent *e)
{
      QLineEdit::focusOutEvent(e);
      emit unfocussed();
}
