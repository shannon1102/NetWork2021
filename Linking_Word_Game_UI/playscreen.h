#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <QMainWindow>

namespace Ui {
class PlayScreen;
}

class PlayScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayScreen(QWidget *parent = nullptr);
    ~PlayScreen();

private:
    Ui::PlayScreen *ui;
};

#endif // PLAYSCREEN_H
