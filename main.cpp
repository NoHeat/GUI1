#include "welcomescreen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //Main is an static function which is the first to be executed in a program.
    //Notice that we are creating a pointer to a window called "WelcomeScreen". This will be the first window that will show on our program.
    //Suppose insead we wanted to have a number lock pad, or a lock utility window that needs a password to give access to the application.
    //We can go to File->New File or Project->Qt->"Qt Designer Form Class"... pick an approprite layout like Dialog without buttons. Then
    //Give it a name like "NumberLockClass" and finish. Three files will be added to the project. (.ui, .h and .cpp)
    //In the .ui we can set lineedit boxes for the user to enter a username and a password.
    //The .h file will contain all important headers to be included and all slots and functions.
    //The .cpp will contain the logic for the functions being implemented.
    //To make main go to the new NumberLock window simply include here or in the header file "#include "numberlock.h"
    //Then replace WelcomeScreen declaration by NumberLock. You will know is right if it appears pink. Otherwise either you forgot to
    //include the header files or typed the name of the class wrong.

    //QApplication is an entry point which can use the parameters argc and argv to include extra needed functionality by the application.
    QApplication a(argc, argv);
    //WelcomeScreen is the class as I typed it when I created the project. Notice that the header file (first line) is all lower case,
    //however since durign creation I typed "WelcomeScreen", to call this class correctly I have to type W and S in capital. Otherwise
    //it will appear black and it will give an error when you run the appication saying "welcomescreen" was not declared in the scope.
    WelcomeScreen *w = new WelcomeScreen;
    w->show();
    //fusion is an stylesheet which is very popular. It can enhance the looks of an application by simply typing that.
    a.setStyle("fusion");
    //This is the place where the application is executed
    return a.exec();
}
