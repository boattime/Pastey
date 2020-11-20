#include <QApplication>

#ifndef QT_NO_SYSTEMTRAYICON

#include <QMessageBox>
#include <QDialog>

int main(int argc, char *argv[])
{
    //Q_INIT_RESOURCE(resource);

    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication app(argc, argv);

    //if (!QSystemTrayIcon::isSystemTrayAvailable()) {
    //    QMessageBox::critical(nullptr, QObject::tr("Systray"),
    //                          QObject::tr("I couldn't detect any system tray "
    //                                      "on this system."));
    //    return 1;
    //}

    //QApplication::setQuitOnLastWindowClosed(false);
    
    QDialog *window = new QDialog();
    window->show();

    return app.exec();
}

#else

#include <QLabel>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString text("QSystemTrayIcon is not supported on this platform");

    QLabel *label = new QLabel(text);
    label->setWordWrap(true);

    label->show();
    qDebug() << text;

    app.exec();
}

#endif
