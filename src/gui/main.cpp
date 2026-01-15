#include "MainWindow.h"

#include <QApplication>
#include <QPalette>
#include <QStyleFactory>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    app.setApplicationName("PFC-Exp-GUI");

    if (QStyleFactory::keys().contains("Fusion")) {
        QApplication::setStyle(QStyleFactory::create("Fusion"));
    }

    // A simple, modern dark palette.
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(30, 30, 30));
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Base, QColor(20, 20, 20));
    palette.setColor(QPalette::AlternateBase, QColor(30, 30, 30));
    palette.setColor(QPalette::ToolTipBase, Qt::white);
    palette.setColor(QPalette::ToolTipText, Qt::white);
    palette.setColor(QPalette::Text, Qt::white);
    palette.setColor(QPalette::Button, QColor(45, 45, 45));
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::BrightText, Qt::red);
    palette.setColor(QPalette::Highlight, QColor(64, 128, 255));
    palette.setColor(QPalette::HighlightedText, Qt::black);
    app.setPalette(palette);

    MainWindow w;
    w.show();
    return app.exec();
}

