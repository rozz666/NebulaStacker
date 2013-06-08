#include <Nebula/Gui/QFileDialog.hpp>

namespace Nebula
{

QStringList QFileDialog::getOpenFileNames(
    QWidget *parent,
    const QString &caption,
    const QString &dir,
    const QString &filter,
    QString *selectedFilter,
    Options options)
{
    return ::QFileDialog::getOpenFileNames(parent, caption, dir, filter, selectedFilter, options);
}

}