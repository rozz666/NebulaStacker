#ifndef NEBULA_QFILEDIALOG_HPP
#define NEBULA_QFILEDIALOG_HPP

#include <QFileDialog>

namespace Nebula {

class QFileDialog : protected ::QFileDialog
{
public:

static QStringList getOpenFileNames(
    QWidget *parent = 0,
    const QString &caption = QString(),
    const QString &dir = QString(),
    const QString &filter = QString(),
    QString *selectedFilter = 0,
    Options options = 0);

static QString getSaveFileName(
    QWidget *parent = 0,
    const QString &caption = QString(),
    const QString &dir = QString(),
    const QString &filter = QString(),
    QString *selectedFilter = 0,
    Options options = 0);

};

}

#endif // NEBULA_QFILEDIALOG_HPP
