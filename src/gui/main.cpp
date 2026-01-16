#include "MainWindow.h"

#include <QApplication>
#include <QIcon>
#include <QLinearGradient>
#include <QPainter>
#include <QPalette>
#include <QPixmap>
#include <QStyleFactory>

static QIcon makeAppIcon() {
    QIcon icon;
    const QList<int> sizes{16, 24, 32, 48, 64, 128, 256};
    for (const int size : sizes) {
        QPixmap pm(size, size);
        pm.fill(Qt::transparent);

        QPainter p(&pm);
        p.setRenderHint(QPainter::Antialiasing, true);

        const QRectF r(0, 0, size, size);
        QLinearGradient g(r.topLeft(), r.bottomRight());
        g.setColorAt(0.0, QColor(64, 128, 255));
        g.setColorAt(1.0, QColor(128, 80, 255));

        p.setPen(Qt::NoPen);
        p.setBrush(g);
        p.drawRoundedRect(r.adjusted(size * 0.08, size * 0.08, -size * 0.08, -size * 0.08), size * 0.22, size * 0.22);

        QFont f = p.font();
        f.setBold(true);
        f.setPixelSize(static_cast<int>(size * 0.42));
        p.setFont(f);
        p.setPen(Qt::white);
        p.drawText(r, Qt::AlignCenter, "PFC");

        p.end();
        icon.addPixmap(pm);
    }
    return icon;
}

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    app.setApplicationName("PFC-Exp-GUI");
    app.setWindowIcon(makeAppIcon());

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
