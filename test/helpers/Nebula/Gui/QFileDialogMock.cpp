#include <Nebula/Gui/QFileDialogMock.hpp>
#include <boost/make_shared.hpp>
#include <stdexcept>

namespace Nebula
{

QFileDialogMock::MockPtr QFileDialogMock::mock;

void QFileDialogMock::setUp()
{
    mock = boost::make_shared<testing::StrictMock<QFileDialogMock>>();
}

void QFileDialogMock::tearDown()
{
    mock.reset();
}

QFileDialogMock& QFileDialogMock::get()
{
    if (!mock)
        throw std::invalid_argument("QFileDialogMock not reset");
    return *mock;
}

QStringList QFileDialog::getOpenFileNames(
    QWidget *parent,
    const QString &caption,
    const QString &dir,
    const QString &filter,
    QString *selectedFilter,
    Options options)
{
    return QFileDialogMock::get().getOpenFileNames(parent, caption, dir, filter, selectedFilter, options);
}

QString QFileDialog::getSaveFileName(
    QWidget *parent,
    const QString &caption,
    const QString &dir,
    const QString &filter,
    QString *selectedFilter,
    Options options)
{
    return QFileDialogMock::get().getSaveFileName(parent, caption, dir, filter, selectedFilter, options);
}

}
